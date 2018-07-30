
#include <stdio.h>
#include <string.h>
#include <stdint.h>

const char ASCII[] = {
    '.',  '.',  '.',  '.',  '.',  '.',  '.',  '.',
    '.',  '.',  '.',  '.',  '.',  '.',  '.',  '.',
    '.',  '.',  '.',  '.',  '.',  '.',  '.',  '.',
    '.',  '.',  '.',  '.',  '.',  '.',  '.',  '.',

    ' ',  '!',  '"',  '#',  '$',  '%',  '&',  '\'',
    '(',  ')',  '*',  '+',  ',',  '-',  '.',  '/',
    '0',  '1',  '2',  '3',  '4',  '5',  '6',  '7',
    '8',  '9',  ':',  ';',  '<',  '=',  '>',  '?',

    '@',  'A',  'B',  'C',  'D',  'E',  'F',  'G',
    'H',  'I',  'J',  'K',  'L',  'M',  'N',  'O',
    'P',  'Q',  'R',  'S',  'T',  'U',  'V',  'W',
    'X',  'Y',  'Z',  '[',  '\\', ']',  '^',  '_',

    '`',  'a',  'b',  'c',  'd',  'e',  'f',  'g',
    'h',  'i',  'j',  'k',  'l',  'm',  'n',  'o',
    'p',  'q',  'r',  's',  't',  'u',  'v',  'w',
    'x',  'y',  'z',  '{',  '|',  '}',  '~',  '.',

    '.',  ' ',  ',',  '.',  '"',  '.',  '.',  '.',
    '^',  '%',  'S',  '<',  'E',  ' ',  'Z',  ' ',
    ' ',  '\'', '\'', '"',  '"',  '.',  '-',  '-',
    '~',  '.',  'S',  '>',  'e',  ' ',  'z',  'Y',

    ' ',  'i',  '.',  '.',  '.',  '.',  '|',  '.',
    '.',  '.',  '.',  '"',  '.',  '-',  '.',  '.',
    '.',  '.',  '2',  '3',  '\'', 'u',  '.',  '.',
    '.',  '1',  '.',  '"',  '.',  '.',  '.',  '?',

    'A',  'A',  'A',  'A',  'A',  'A',  'E',  'C',
    'E',  'E',  'E',  'E',  'I',  'I',  'I',  'I',
    '.',  'N',  'O',  'O',  'O',  'O',  'O',  'x',
    'O',  'U',  'U',  'U',  'U',  'Y',  '.',  'B',

    'a',  'a',  'a',  'a',  'a',  'a',  'e',  'c',
    'e',  'e',  'e',  'e',  'i',  'i',  'i',  'i',
    '.',  'n',  'o',  'o',  'o',  'o',  'o',  '/',
    'o',  'u',  'u',  'u',  'u',  'y',  '.',  'y'
};

char * eascii_to_ascii( char *str )
{
    int len = strlen( str );
    int i = 0;

    for ( ; i < len; i++ )
    {
        str[i] = ASCII[(uint8_t)str[i]];
    }

    return str;
}
