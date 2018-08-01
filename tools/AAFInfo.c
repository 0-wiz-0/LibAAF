#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <math.h>
#include <getopt.h>

#include "../LibAAF/libAAF.h"
#include "./thirdparty/libTC.h"

// only for ANSI_COLORS
#include "../LibAAF/common/utils.h"



char * gainToStr( char *str, aafiAudioClip *aClip )
{
	memset( str, 0x00, 16 );

	if ( aClip->gain == NULL )
		snprintf( str, 16, " n/a    " );

	else if ( aClip->gain->flags & AAFI_AUDIO_GAIN_CONSTANT )
		snprintf( str, 16, "%+05.1lf dB",
				 20 * log10( (( aClip->gain->value[0].denominator == 0 ) ? 0 : ((float)aClip->gain->value[0].numerator/aClip->gain->value[0].denominator)) ) );
			  // 20 * log10( rationalToFloat( &(aClip->gain->value[0]) ) ) );

	else if ( aClip->gain->flags & AAFI_AUDIO_GAIN_VARIABLE )
		snprintf( str, 16, " automation " );

	return str;
}




void showHelp()
{
	printf(
		"\n"
		" AAFInfo 0.1\n"
		"\n"
		" Compound File Binary Analysis :\n"
		" ===============================\n"
		"   --cfb-header           Displays the CFB Header.\n"
		"   --cfb-fat              Displays the CFB FAT.\n"
		"   --cfb-minifat          Displays the CFB MiniFAT.\n"
		"   --cfb-difat            Displays the CFB DiFAT.\n"
		"   --cfb-nodes            Displays the CFB node Tree.\n"
		"\n"
		"   --get-node    <path>   Retrieves and displays the node\n"
		"                          located at the given <path>.\n"
		"\n"
		" Advanced Authoring File Analysis :\n"
		" ==================================\n"
		"   --aaf-summary          Displays AAF informations from both\n"
		"                          header and identification objects.\n"
		"   --aaf-essences         Lists AAF essences.\n"
		"   --aaf-clips            Lists AAF clips.\n"
		"   --aaf-classes          Lists AAF Classes. The ones from\n"
		"                          MetaDictionary are shown in yellow.\n"
		"   --aaf-meta             Lists Classes and Properties from\n"
		"                          the MetaDictionary.\n"
		"   --aaf-properties       Displays all Properties.\n"
		"\n\n"
	);

	exit( 0 );
}



int main( int argc, char *argv[] )
{

//	int cfb_summary    = 0;
	int cfb_header     = 0;
	int cfb_fat        = 0;
	int cfb_minifat    = 0;
	int cfb_difat      = 0;
	int cfb_nodes      = 0;

	int aaf_summary    = 0;
//	int aaf_origin     = 0;
	int aaf_essences   = 0;
	int aaf_clips      = 0;
	int aaf_classes    = 0;
	int aaf_meta       = 0;
	int aaf_properties = 0;

	char *get_node_str = NULL;

//	int cfb_get_node = 0;

	int cmd = 0;


	static struct option long_options[] = {

		{ "help",			no_argument,		0,	'h'  },

//		{ "cfb-summary",    no_argument,        0,  0x80 },
		{ "cfb-header",     no_argument,        0,  0x81 },
		{ "cfb-fat",        no_argument,        0,  0x82 },
		{ "cfb-minifat",    no_argument,        0,  0x83 },
		{ "cfb-difat",      no_argument,        0,  0x84 },
		{ "cfb-nodes",      no_argument,        0,  0x85 },

		{ "aaf-summary",    no_argument,        0,  0x86 },
//		{ "aaf-origin",     no_argument,        0,  0x87 },
		{ "aaf-essences",   no_argument,        0,  0x88 },
		{ "aaf-clips",      no_argument,        0,  0x89 },
		{ "aaf-classes",    no_argument,        0,  0x8a },
		{ "aaf-meta",       no_argument,        0,  0x8b },
		{ "aaf-properties", no_argument,        0,  0x8c },

		{ "get-node",   	required_argument,	0,	0x99 },
//		{ "get-node-id",	required_argument,	0,	0x87 },

		{ 0,                0,                  0,  0    }
	};


	int c = 0;

	while ( 1 )
	{
		int option_index = 0;

		c = getopt_long ( argc, argv, "h", long_options, &option_index );

		if ( c == -1 )
			break;

		switch ( c )
		{
//			case 0x80:  cfb_summary    = 1;         cmd++;       break;
			case 0x81:  cfb_header     = 1;         cmd++;       break;
			case 0x82:  cfb_fat        = 1;         cmd++;       break;
			case 0x83:  cfb_minifat    = 1;         cmd++;       break;
			case 0x84:  cfb_difat      = 1;         cmd++;       break;
			case 0x85:  cfb_nodes      = 1;         cmd++;       break;

			case 0x86:  aaf_summary    = 1;         cmd++;       break;
//			case 0x87:  aaf_origin     = 1;         cmd++;       break;
			case 0x88:  aaf_essences   = 1;         cmd++;       break;
			case 0x89:  aaf_clips      = 1;         cmd++;       break;
			case 0x8a:  aaf_classes    = 1;         cmd++;       break;
			case 0x8b:  aaf_meta       = 1;         cmd++;       break;
			case 0x8c:  aaf_properties = 1;         cmd++;       break;

			case 0x99:	get_node_str   = optarg;    cmd++;       break;

//			case 0x81:	get_node_id    = optarg;    cmd++;       break;

			case 'h':	showHelp();                 cmd++;       break;

			default:                                cmd++;       break;
		}
	}



	if ( optind == argc )
	{
		fprintf( stderr,
			"AAFInfo: missing file operand\n"
			"Try 'AAFInfo --help' for more informations.\n"
		);

		return 1;
	}



	if ( cmd == 0 )
	{
		fprintf( stderr,
			"Usage: AAFInfo [CMD] [FILE]\n"
			"Try 'AAFInfo --help' for more informations.\n"
		);

		return 1;
	}



	printf( "\n\n" );


	AAF_Data *aafd = aaf_alloc();

	if ( aaf_load_file( aafd, argv[argc-1] ) )
		return 1;


	AAF_Iface *aafi = NULL;

	if ( aaf_essences || aaf_clips )
	{
		aafi = aafi_alloc( aafd );

		aafi_retrieveData( aafi );
	}

	printf( "\n\n" );





	if ( get_node_str != NULL )
	{
		cfbNode *node = cfb_getNodeByPath( aafd->cfbd, get_node_str, 0 );

		if ( node == NULL )
		{
			printf( "Could not find node at \"%s\"\n", get_node_str );
		}
		else
		{
			cfb_dump_node( aafd->cfbd, node, 0 );

			char name[CFB_NODE_NAME_SZ];

			utf16toa( name, CFB_NODE_NAME_SZ, node->_ab, node->_cb );

			if ( strncmp( name, "properties", 10 ) == 0 )
			{
				aaf_dump_nodeStreamProperties( aafd, node );
			}
			else if ( node->_mse == STGTY_STREAM )
			{
				cfb_dump_nodeStream( aafd->cfbd, node );
			}
		}

		printf( "\n\n" );
	}


	if ( cfb_header )
	{
		cfb_dump_header( aafd->cfbd );
	}


	if ( cfb_fat )
	{
		cfb_dump_FAT( aafd->cfbd );
	}


	if ( cfb_minifat )
	{
		cfb_dump_MiniFAT( aafd->cfbd );
	}


	if ( cfb_difat )
	{
		cfb_dump_DiFAT( aafd->cfbd );
	}


	if ( cfb_nodes )
	{
		uint32_t i = 0;

		cfb_dump_nodePaths( aafd->cfbd, 0, NULL, &i, NULL );
	}






	if ( aaf_summary )
	{
		aaf_dump_Header( aafd );
		aaf_dump_Identification( aafd );
	}


	if ( aaf_classes )
	{
		aaf_dump_Classes( aafd );
	}


	if ( aaf_meta )
	{
		aaf_dump_MetaDictionary( aafd );
	}


	if ( aaf_properties )
	{
		aafObject *Object = aafd->Objects;

		for ( Object = aafd->Objects; Object != NULL; Object = Object->nextObj )
		{
			printf( "\n\n\n" ANSI_COLOR_MAGENTA " Object" ANSI_COLOR_RESET " @ %s\n", aaf_get_ObjectPath( Object ) );

			aaf_dump_ObjectProperties( aafd, Object );
		}
	}







	if ( aaf_essences )
	{

		aafiAudioEssence *audioEssence = NULL;

		uint32_t i = 0;

		foreachAudioEssence( audioEssence, aafi->Audio->Essences )
		{

			printf( " %s%u:  Type: %s  Duration: %u h  %02u mn  %02u s  %03u ms   %u Ch - %u Hz - %u bit  file : %s  file_name : %s\n",
				( i < 10 ) ? " " : "", i,
				( audioEssence->type == AAFI_TYPE_PCM  ) ? "PCM"  :
				( audioEssence->type == AAFI_TYPE_WAVE ) ? "WAVE" :
				( audioEssence->type == AAFI_TYPE_AIFC ) ? "AIFC" :
				( audioEssence->type == AAFI_TYPE_BWAV ) ? "BWAV" : "",
				aeDuration_h( audioEssence ),
				aeDuration_m( audioEssence ),
				aeDuration_s( audioEssence ),
				aeDuration_ms( audioEssence ),
				audioEssence->channels,
				audioEssence->samplerate,
				audioEssence->samplesize,
				( audioEssence->is_embedded ) ? "EMBEDDED" : audioEssence->original_file,
				audioEssence->unique_file_name
			);

			i++;
		}

		printf( "\n\n" );
	}




	if ( aaf_clips )
	{
		printf( "Composition Name     : %s\n", aafi->compositionName );
		printf( "======================\n" );

		enum TC_FORMAT format = tc_fps2format( (float)(aafi->Audio->tc->fps ), aafi->Audio->tc->drop );

		struct timecode tc_comp;
		tc_set_by_unitValue( &tc_comp, aafi->Audio->tc->start, (rational_t*)aafi->Audio->tc->edit_rate, format );


		printf("Composition TC Start : %s (%u fps %s)\n",
			tc_comp.string,
			// eu2tc_h( aafi->Audio->tc->edit_rate, 90004*1920 ),
			// eu2tc_m( aafi->Audio->tc->edit_rate, 90004*1920 ),
			// eu2tc_s( aafi->Audio->tc->edit_rate, 90004*1920 ),
			// eu2tc_f( aafi->Audio->tc->edit_rate, aafi->Audio->tc, 90004*1920),
			aafi->Audio->tc->fps,
			(aafi->Audio->tc->drop) ? "DF" : "NDF"
		);
		printf( "======================\n\n" );

		aafiUserComment *Comment = aafi->Comments;

		if ( Comment != NULL )
		{
			printf( "UserComments :\n==============\n" );

			while ( Comment != NULL )
			{
				printf( "   * %s : %s\n", Comment->name, Comment->text );

				Comment = Comment->next;
			}

			printf("\n\n");
		}

		aafiAudioTrack   *audioTrack = NULL;
		aafiTimelineItem *audioItem  = NULL;
		aafiAudioClip    *audioClip  = NULL;

		uint32_t i = 0;

		foreach_audioTrack( audioTrack, aafi )
		{

			printf( "Track (%u) - %s - edit_rate %i/%i (%02.2f)  -  \"%s\"\n",
					audioTrack->number,
					(audioTrack->format == AAFI_TRACK_FORMAT_MONO)   ? "MONO"   :
					(audioTrack->format == AAFI_TRACK_FORMAT_STEREO) ? "STEREO" :
					(audioTrack->format == AAFI_TRACK_FORMAT_5_1)    ? "5.1"    :
					(audioTrack->format == AAFI_TRACK_FORMAT_7_1)    ? "7.1"    : "Unknown",
					audioTrack->edit_rate->numerator, audioTrack->edit_rate->denominator,
					rationalToFloat(audioTrack->edit_rate),
					(audioTrack->name != NULL) ? audioTrack->name : ""
			 );

			foreach_audioItem( audioItem, audioTrack )
			{

				if ( audioItem->type == AAFI_TRANS )
				{

					aafiTransition *Trans = (aafiTransition*)&audioItem->data;

					if ( ! ( Trans->flags & AAFI_TRANS_XFADE ) )
						continue;


					printf( " xfade:   %s\n",
						(Trans->flags & AAFI_INTERPOL_NONE)     ? "CURV_NON" :
						(Trans->flags & AAFI_INTERPOL_LINEAR)   ? "CURV_LIN" :
						(Trans->flags & AAFI_INTERPOL_LOG)      ? "CURV_LOG" :
						(Trans->flags & AAFI_INTERPOL_CONSTANT) ? "CURV_CST" :
						(Trans->flags & AAFI_INTERPOL_POWER)    ? "CURV_PWR" :
						(Trans->flags & AAFI_INTERPOL_BSPLINE)  ? "CURV_BSP" :
						""
					);
	/*
					printf( "\n" );

	//					aafiTransition *Trans = (aafiTransition*)&audioItem->data;

					printf( " Fade     : %s\n",
						(Trans->flags & AAFI_TRANS_FADE_IN)  ? "AAFI_TRANS_FADE_IN"  :
						(Trans->flags & AAFI_TRANS_FADE_OUT) ? "AAFI_TRANS_FADE_OUT" :
						(Trans->flags & AAFI_TRANS_XFADE)    ? "AAFI_TRANS_XFADE"    :
						""
					);

					printf( " Interpol : %s\n",
						(Trans->flags & AAFI_INTERPOL_NONE)     ? "AAFI_INTERPOL_NONE"     :
						(Trans->flags & AAFI_INTERPOL_LINEAR)   ? "AAFI_INTERPOL_LINEAR"   :
						(Trans->flags & AAFI_INTERPOL_LOG)      ? "AAFI_INTERPOL_LOG"      :
						(Trans->flags & AAFI_INTERPOL_CONSTANT) ? "AAFI_INTERPOL_CONSTANT" :
						(Trans->flags & AAFI_INTERPOL_POWER)    ? "AAFI_INTERPOL_POWER"    :
						(Trans->flags & AAFI_INTERPOL_BSPLINE)  ? "AAFI_INTERPOL_BSPLINE"  :
						""
					);


					int  i = 0;
					for( i = 0; i < Trans->pts_cnt; i++ )
					{
	//						printf( "   PT:  _t: %i/%i   _v: %i/%i\n",
	//							Trans->time[i]->numerator,
	//							Trans->time[i]->denominator,
	//							Trans->value[i]->numerator,
	//							Trans->value[i]->denominator
	//						);

						printf( "   PT:  _t: %.0f   _v: %.0f\n",
							rationalToFloat( Trans->time[i] ),
							rationalToFloat( Trans->value[i] )
						);
					}

					printf( "\n" );
	*/

					continue;
				}

				audioClip = (aafiAudioClip*)&audioItem->data;

				aafiTransition *fadein  = get_fadein( audioItem );
				aafiTransition *fadeout = get_fadeout( audioItem );

				char str[16];

				struct timecode tc_in;
				struct timecode tc_out;
				struct timecode tc_len;

				// enum TC_FORMAT format = tc_fps2format( (float)(aafi->Audio->tc->fps ), aafi->Audio->tc->drop );

				// printf( "EditRate : %f\n", rationalToFloat(audioClip->track->edit_rate) );
				// printf( "EditRate : %f\n", rationalToFloat(audioClip->track->edit_rate) );

				// printf( "Format : %s\n", TC_FORMAT_STR[format] );

				tc_set_by_unitValue( &tc_in,  (audioClip->pos + audioClip->track->Audio->tc->start),                  (rational_t*)audioClip->track->edit_rate, format );
				tc_set_by_unitValue( &tc_out, (audioClip->pos + audioClip->len + audioClip->track->Audio->tc->start), (rational_t*)audioClip->track->edit_rate, format );
				tc_set_by_unitValue( &tc_len,  audioClip->len,                                                        (rational_t*)audioClip->track->edit_rate, format );

				printf( " Clip:%u%s  Track:%u  Gain:%s "
						" Start:%s  Len:%s  End:%s  "
						" Fadein: %s  Fadeout: %s  SourceFile: %s\n",
					i, ( i < 10 ) ? " " : "",
					audioClip->track->number,
					gainToStr( str, audioClip ),
					tc_in.string,
					tc_len.string,
					tc_out.string,
					// tc_in.hours,  tc_in.minutes,  tc_in.seconds,  tc_in.frames,
					// tc_len.hours, tc_len.minutes, tc_len.seconds, tc_len.frames,
					// tc_out.hours, tc_out.minutes, tc_out.seconds, tc_out.frames,
					// eu2tc_h( audioClip->track->edit_rate, (audioClip->pos + audioClip->track->Audio->tc->start) ),
					// eu2tc_m( audioClip->track->edit_rate, (audioClip->pos + audioClip->track->Audio->tc->start) ),
					// eu2tc_s( audioClip->track->edit_rate, (audioClip->pos + audioClip->track->Audio->tc->start) ),
					// eu2tc_f( audioClip->track->edit_rate, audioClip->track->Audio->tc, (audioClip->pos + audioClip->track->Audio->tc->start) ),
					// eu2tc_h( audioClip->track->edit_rate, (audioClip->len) ),
					// eu2tc_m( audioClip->track->edit_rate, (audioClip->len) ),
					// eu2tc_s( audioClip->track->edit_rate, (audioClip->len) ),
					// eu2tc_f( audioClip->track->edit_rate, audioClip->track->Audio->tc, (audioClip->len) ),
					// eu2tc_h( audioClip->track->edit_rate, (audioClip->pos + audioClip->len + audioClip->track->Audio->tc->start) ),
					// eu2tc_m( audioClip->track->edit_rate, (audioClip->pos + audioClip->len + audioClip->track->Audio->tc->start) ),
					// eu2tc_s( audioClip->track->edit_rate, (audioClip->pos + audioClip->len + audioClip->track->Audio->tc->start) ),
					// eu2tc_f( audioClip->track->edit_rate, audioClip->track->Audio->tc, (audioClip->pos + audioClip->len + audioClip->track->Audio->tc->start) ),
					// (audioClip->pos + audioClip->len + audioClip->track->Audio->tc->start),
					( fadein != NULL ) ?
						(fadein->flags & AAFI_INTERPOL_NONE)     ? "CURV_NON" :
						(fadein->flags & AAFI_INTERPOL_LINEAR)   ? "CURV_LIN" :
						(fadein->flags & AAFI_INTERPOL_LOG)      ? "CURV_LOG" :
						(fadein->flags & AAFI_INTERPOL_CONSTANT) ? "CURV_CST" :
						(fadein->flags & AAFI_INTERPOL_POWER)    ? "CURV_PWR" :
						(fadein->flags & AAFI_INTERPOL_BSPLINE)  ? "CURV_BSP" :
						"" :
					"none    ",
					( fadeout != NULL ) ?
						(fadeout->flags & AAFI_INTERPOL_NONE)     ? "CURV_NON" :
						(fadeout->flags & AAFI_INTERPOL_LINEAR)   ? "CURV_LIN" :
						(fadeout->flags & AAFI_INTERPOL_LOG)      ? "CURV_LOG" :
						(fadeout->flags & AAFI_INTERPOL_CONSTANT) ? "CURV_CST" :
						(fadeout->flags & AAFI_INTERPOL_POWER)    ? "CURV_PWR" :
						(fadeout->flags & AAFI_INTERPOL_BSPLINE)  ? "CURV_BSP" :
						"" :
					"none    ",
					(audioClip->Essence) ? audioClip->Essence->file_name : ""
				);


				i++;
			}

			printf( "\n\n" );
		}

		printf( "\n\n" );
	}


	





	if ( aafi != NULL )
	{
		aafi_release( &aafi );
	}
	else if ( aafd != NULL )
	{
		aaf_release( &aafd );
	}

	return 0;
}
