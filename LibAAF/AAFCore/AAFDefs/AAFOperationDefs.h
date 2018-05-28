#ifndef __OperationDefinition_h__
#define __OperationDefinition_h__

#include "../AAFTypes.h"

// AAF well-known OperationDefinition instances
//

//{0c3bea40-fc05-11d2-8a29-0050040ef7d2}
static const aafUID_t AAFOperationDef_VideoDissolve =
{0x0c3bea40, 0xfc05, 0x11d2, {0x8a, 0x29, 0x00, 0x50, 0x04, 0x0e, 0xf7, 0xd2}};


//{0c3bea44-fc05-11d2-8a29-0050040ef7d2}
static const aafUID_t AAFOperationDef_SMPTEVideoWipe =
{0x0c3bea44, 0xfc05, 0x11d2, {0x8a, 0x29, 0x00, 0x50, 0x04, 0x0e, 0xf7, 0xd2}};


//{9d2ea890-0968-11d3-8a38-0050040ef7d2}
static const aafUID_t AAFOperationDef_VideoSpeedControl =
{0x9d2ea890, 0x0968, 0x11d3, {0x8a, 0x38, 0x00, 0x50, 0x04, 0x0e, 0xf7, 0xd2}};


//{9d2ea891-0968-11d3-8a38-0050040ef7d2}
static const aafUID_t AAFOperationDef_VideoRepeat =
{0x9d2ea891, 0x0968, 0x11d3, {0x8a, 0x38, 0x00, 0x50, 0x04, 0x0e, 0xf7, 0xd2}};


//{f1db0f32-8d64-11d3-80df-006008143e6f}
static const aafUID_t AAFOperationDef_Flip =
{0xf1db0f32, 0x8d64, 0x11d3, {0x80, 0xdf, 0x00, 0x60, 0x08, 0x14, 0x3e, 0x6f}};


//{f1db0f34-8d64-11d3-80df-006008143e6f}
static const aafUID_t AAFOperationDef_Flop =
{0xf1db0f34, 0x8d64, 0x11d3, {0x80, 0xdf, 0x00, 0x60, 0x08, 0x14, 0x3e, 0x6f}};


//{f1db0f33-8d64-11d3-80df-006008143e6f}
static const aafUID_t AAFOperationDef_FlipFlop =
{0xf1db0f33, 0x8d64, 0x11d3, {0x80, 0xdf, 0x00, 0x60, 0x08, 0x14, 0x3e, 0x6f}};


//{86f5711e-ee72-450c-a118-17cf3b175dff}
static const aafUID_t AAFOperationDef_VideoPosition =
{0x86f5711e, 0xee72, 0x450c, {0xa1, 0x18, 0x17, 0xcf, 0x3b, 0x17, 0x5d, 0xff}};


//{f5826680-26c5-4149-8554-43d3c7a3bc09}
static const aafUID_t AAFOperationDef_VideoCrop =
{0xf5826680, 0x26c5, 0x4149, {0x85, 0x54, 0x43, 0xd3, 0xc7, 0xa3, 0xbc, 0x09}};


//{2e0a119d-e6f7-4bee-b5dc-6dd42988687e}
static const aafUID_t AAFOperationDef_VideoScale =
{0x2e0a119d, 0xe6f7, 0x4bee, {0xb5, 0xdc, 0x6d, 0xd4, 0x29, 0x88, 0x68, 0x7e}};


//{f2ca330d-8d45-4db4-b1b5-136ab055586f}
static const aafUID_t AAFOperationDef_VideoRotate =
{0xf2ca330d, 0x8d45, 0x4db4, {0xb1, 0xb5, 0x13, 0x6a, 0xb0, 0x55, 0x58, 0x6f}};


//{21d5c51a-8acb-46d5-9392-5cae640c8836}
static const aafUID_t AAFOperationDef_VideoCornerPinning =
{0x21d5c51a, 0x8acb, 0x46d5, {0x93, 0x92, 0x5c, 0xae, 0x64, 0x0c, 0x88, 0x36}};


//{14db900e-d537-49f6-889b-012568fcc234}
static const aafUID_t AAFOperationDef_VideoAlphaWithinVideoKey =
{0x14db900e, 0xd537, 0x49f6, {0x88, 0x9b, 0x01, 0x25, 0x68, 0xfc, 0xc2, 0x34}};


//{e599cb0f-ba5f-4192-9356-51eb19c08589}
static const aafUID_t AAFOperationDef_VideoSeparateAlphaKey =
{0xe599cb0f, 0xba5f, 0x4192, {0x93, 0x56, 0x51, 0xeb, 0x19, 0xc0, 0x85, 0x89}};


//{38ff7903-69e5-476b-be5a-eafc2000f011}
static const aafUID_t AAFOperationDef_VideoLuminanceKey =
{0x38ff7903, 0x69e5, 0x476b, {0xbe, 0x5a, 0xea, 0xfc, 0x20, 0x00, 0xf0, 0x11}};


//{30a315c2-71e5-4e82-a4ef-0513ee056b65}
static const aafUID_t AAFOperationDef_VideoChromaKey =
{0x30a315c2, 0x71e5, 0x4e82, {0xa4, 0xef, 0x05, 0x13, 0xee, 0x05, 0x6b, 0x65}};


//{9d2ea894-0968-11d3-8a38-0050040ef7d2}
static const aafUID_t AAFOperationDef_MonoAudioGain =
{0x9d2ea894, 0x0968, 0x11d3, {0x8a, 0x38, 0x00, 0x50, 0x04, 0x0e, 0xf7, 0xd2}};


//{9d2ea893-0968-11d3-8a38-0050040ef7d2}
static const aafUID_t AAFOperationDef_MonoAudioPan =
{0x9d2ea893, 0x0968, 0x11d3, {0x8a, 0x38, 0x00, 0x50, 0x04, 0x0e, 0xf7, 0xd2}};


//{0c3bea41-fc05-11d2-8a29-0050040ef7d2}
static const aafUID_t AAFOperationDef_MonoAudioDissolve =
{0x0c3bea41, 0xfc05, 0x11d2, {0x8a, 0x29, 0x00, 0x50, 0x04, 0x0e, 0xf7, 0xd2}};


//{2311bd90-b5da-4285-aa3a-8552848779b3}
static const aafUID_t AAFOperationDef_TwoParameterMonoAudioDissolve =
{0x2311bd90, 0xb5da, 0x4285, {0xaa, 0x3a, 0x85, 0x52, 0x84, 0x87, 0x79, 0xb3}};


//{9bb90dfd-2aad-49af-b09c-8ba6cd5281d1}
static const aafUID_t AAFOperationDef_VideoOpacity =
{0x9bb90dfd, 0x2aad, 0x49af, {0xb0, 0x9c, 0x8b, 0xa6, 0xcd, 0x52, 0x81, 0xd1}};


//{2c50831c-572e-4042-b1dd-55ed0b7c49df}
static const aafUID_t AAFOperationDef_VideoTitle =
{0x2c50831c, 0x572e, 0x4042, {0xb1, 0xdd, 0x55, 0xed, 0x0b, 0x7c, 0x49, 0xdf}};


//{5aba98f8-f389-471f-8fee-dfde7ec7f9bb}
static const aafUID_t AAFOperationDef_VideoColor =
{0x5aba98f8, 0xf389, 0x471f, {0x8f, 0xee, 0xdf, 0xde, 0x7e, 0xc7, 0xf9, 0xbb}};


//{1575e350-fca3-11d2-8a2a-0050040ef7d2}
static const aafUID_t AAFOperationDef_Unknown =
{0x1575e350, 0xfca3, 0x11d2, {0x8a, 0x2a, 0x00, 0x50, 0x04, 0x0e, 0xf7, 0xd2}};


//{0c3bea43-fc05-11d2-8a29-0050040ef7d2}
static const aafUID_t AAFOperationDef_VideoFadeToBlack =
{0x0c3bea43, 0xfc05, 0x11d2, {0x8a, 0x29, 0x00, 0x50, 0x04, 0x0e, 0xf7, 0xd2}};


//{0a3c75e0-fd82-11d2-8a2b-0050040ef7d2}
static const aafUID_t AAFOperationDef_PictureWithMate =
{0x0a3c75e0, 0xfd82, 0x11d2, {0x8a, 0x2b, 0x00, 0x50, 0x04, 0x0e, 0xf7, 0xd2}};


//{9d2ea892-0968-11d3-8a38-0050040ef7d2}
static const aafUID_t AAFOperationDef_VideoFrameToMask =
{0x9d2ea892, 0x0968, 0x11d3, {0x8a, 0x38, 0x00, 0x50, 0x04, 0x0e, 0xf7, 0xd2}};


//{0c3bea42-fc05-11d2-8a29-0050040ef7d2}
static const aafUID_t AAFOperationDef_StereoAudioDissolve =
{0x0c3bea42, 0xfc05, 0x11d2, {0x8a, 0x29, 0x00, 0x50, 0x04, 0x0e, 0xf7, 0xd2}};


//{9d2ea895-0968-11d3-8a38-0050040ef7d2}
static const aafUID_t AAFOperationDef_StereoAudioGain =
{0x9d2ea895, 0x0968, 0x11d3, {0x8a, 0x38, 0x00, 0x50, 0x04, 0x0e, 0xf7, 0xd2}};


//{8d896ad0-2261-11d3-8a4c-0050040ef7d2}
static const aafUID_t AAFOperationDef_MonoAudioMixdown =
{0x8d896ad0, 0x2261, 0x11d3, {0x8a, 0x4c, 0x00, 0x50, 0x04, 0x0e, 0xf7, 0xd2}};


// AAF OperationDefinition legacy aliases
//
/*
static const aafUID_t AAFEffectVideoDissolve = AAFOperationDef_VideoDissolve;
static const aafUID_t AAFEffectSMPTEVideoWipe = AAFOperationDef_SMPTEVideoWipe;
static const aafUID_t AAFEffectVideoSpeedControl = AAFOperationDef_VideoSpeedControl;
static const aafUID_t AAFEffectVideoRepeat = AAFOperationDef_VideoRepeat;
static const aafUID_t AAFEffectMonoAudioGain = AAFOperationDef_MonoAudioGain;
static const aafUID_t AAFEffectMonoAudioPan = AAFOperationDef_MonoAudioPan;
static const aafUID_t AAFEffectMonoAudioDissolve = AAFOperationDef_MonoAudioDissolve;
static const aafUID_t AAFOperationUnknown = AAFOperationDef_Unknown;
static const aafUID_t AAFEffectVideoFadeToBlack = AAFOperationDef_VideoFadeToBlack;
static const aafUID_t AAFEffectPictureWithMate = AAFOperationDef_PictureWithMate;
static const aafUID_t AAFEffectVideoFrameToMask = AAFOperationDef_VideoFrameToMask;
static const aafUID_t AAFEffectStereoAudioDissolve = AAFOperationDef_StereoAudioDissolve;
static const aafUID_t AAFEffectStereoAudioGain = AAFOperationDef_StereoAudioGain;
static const aafUID_t AAFEffectMonoAudioMixdown = AAFOperationDef_MonoAudioMixdown;
*/
#endif // ! __OperationDefinition_h__
