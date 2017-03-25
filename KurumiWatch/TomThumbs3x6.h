/*
 *
 * TomThumbs3x6
 *
 *
 * File Name           : TomThumbs3x6.h
 * Notes               : Based on "tom-thumb.bdf" from https://robey.lag.net/2010/01/23/tiny-monospace-font.html
 * Font width          : 3
 * Font height         : 6
 */
#ifndef TomThumbs3x6_H
#define TomThumbs3x6_H

#define TomThumbs3x6_WIDTH 3
#define TomThumbs3x6_HEIGHT 6

GLCDFONTDECL(TomThumbs3x6) = {
    0x0, 0x0, // size of zero indicates fixed width font, actual length is width * height
    0x03, // width
    0x06, // height
    0x20, // first char
    0x60, // char count
    
    // Fixed width; char width table not used !!!!
    
    // font data
    0x00, 0x00, 0x00,                  // Code for char  
    0x00, 0x17, 0x00,                  // Code for char !
    0x03, 0x00, 0x03,                  // Code for char "
    0x1F, 0x0A, 0x1F,                  // Code for char #
    0x0A, 0x1F, 0x05,                  // Code for char $
    0x09, 0x04, 0x12,                  // Code for char %
    0x0F, 0x17, 0x1C,                  // Code for char &
    0x00, 0x03, 0x00,                  // Code for char '
    0x0E, 0x11, 0x00,                  // Code for char (
    0x11, 0x0E, 0x00,                  // Code for char )
    0x05, 0x02, 0x05,                  // Code for char *
    0x04, 0x0E, 0x04,                  // Code for char +
    0x10, 0x08, 0x00,                  // Code for char ,
    0x04, 0x04, 0x04,                  // Code for char -
    0x00, 0x10, 0x00,                  // Code for char .
    0x18, 0x04, 0x03,                  // Code for char /
    0x1E, 0x11, 0x0F,                  // Code for char 0
    0x02, 0x1F, 0x00,                  // Code for char 1
    0x19, 0x15, 0x12,                  // Code for char 2
    0x11, 0x15, 0x0A,                  // Code for char 3
    0x07, 0x04, 0x1F,                  // Code for char 4
    0x17, 0x15, 0x09,                  // Code for char 5
    0x1E, 0x15, 0x1D,                  // Code for char 6
    0x19, 0x05, 0x03,                  // Code for char 7
    0x1F, 0x15, 0x1F,                  // Code for char 8
    0x17, 0x15, 0x0F,                  // Code for char 9
    0x00, 0x0A, 0x00,                  // Code for char :
    0x10, 0x0A, 0x00,                  // Code for char ;
    0x04, 0x0A, 0x11,                  // Code for char <
    0x0A, 0x0A, 0x0A,                  // Code for char =
    0x11, 0x0A, 0x04,                  // Code for char >
    0x01, 0x15, 0x03,                  // Code for char ?
    0x0E, 0x15, 0x16,                  // Code for char @
    0x1E, 0x05, 0x1E,                  // Code for char A
    0x1F, 0x15, 0x0A,                  // Code for char B
    0x0E, 0x11, 0x11,                  // Code for char C
    0x1F, 0x11, 0x0E,                  // Code for char D
    0x1F, 0x15, 0x15,                  // Code for char E
    0x1F, 0x05, 0x05,                  // Code for char F
    0x0E, 0x15, 0x1D,                  // Code for char G
    0x1F, 0x04, 0x1F,                  // Code for char H
    0x11, 0x1F, 0x11,                  // Code for char I
    0x08, 0x10, 0x0F,                  // Code for char J
    0x1F, 0x04, 0x1B,                  // Code for char K
    0x1F, 0x10, 0x10,                  // Code for char L
    0x1F, 0x06, 0x1F,                  // Code for char M
    0x1F, 0x0E, 0x1F,                  // Code for char N
    0x0E, 0x11, 0x0E,                  // Code for char O
    0x1F, 0x05, 0x02,                  // Code for char P
    0x0E, 0x19, 0x1E,                  // Code for char Q
    0x1F, 0x0D, 0x16,                  // Code for char R
    0x12, 0x15, 0x09,                  // Code for char S
    0x01, 0x1F, 0x01,                  // Code for char T
    0x0F, 0x10, 0x1F,                  // Code for char U
    0x07, 0x18, 0x07,                  // Code for char V
    0x1F, 0x0C, 0x1F,                  // Code for char W
    0x1B, 0x04, 0x1B,                  // Code for char X
    0x03, 0x1C, 0x03,                  // Code for char Y
    0x19, 0x15, 0x13,                  // Code for char Z
    0x1F, 0x11, 0x11,                  // Code for char [
    0x02, 0x04, 0x08,                  // Code for char BackSlash
    0x11, 0x11, 0x1F,                  // Code for char ]
    0x02, 0x01, 0x02,                  // Code for char ^
    0x10, 0x10, 0x10,                  // Code for char _
    0x01, 0x02, 0x00,                  // Code for char `
    0x1A, 0x16, 0x1C,                  // Code for char a
    0x1F, 0x12, 0x0C,                  // Code for char b
    0x0C, 0x12, 0x12,                  // Code for char c
    0x0C, 0x12, 0x1F,                  // Code for char d
    0x0C, 0x1A, 0x16,                  // Code for char e
    0x04, 0x1E, 0x05,                  // Code for char f
    0x0C, 0x2A, 0x1E,                  // Code for char g
    0x1F, 0x02, 0x1C,                  // Code for char h
    0x00, 0x1D, 0x00,                  // Code for char i
    0x10, 0x20, 0x1D,                  // Code for char j
    0x1F, 0x0C, 0x12,                  // Code for char k
    0x11, 0x1F, 0x10,                  // Code for char l
    0x1E, 0x0E, 0x1E,                  // Code for char m
    0x1E, 0x02, 0x1C,                  // Code for char n
    0x0C, 0x12, 0x0C,                  // Code for char o
    0x3E, 0x12, 0x0C,                  // Code for char p
    0x0C, 0x12, 0x3E,                  // Code for char q
    0x1C, 0x02, 0x02,                  // Code for char r
    0x14, 0x1E, 0x0A,                  // Code for char s
    0x02, 0x1F, 0x12,                  // Code for char t
    0x0E, 0x10, 0x1E,                  // Code for char u
    0x0E, 0x18, 0x0E,                  // Code for char v
    0x1E, 0x1C, 0x1E,                  // Code for char w
    0x12, 0x0C, 0x12,                  // Code for char x
    0x06, 0x28, 0x1E,                  // Code for char y
    0x1A, 0x1E, 0x16,                  // Code for char z
    0x04, 0x1B, 0x11,                  // Code for char {
    0x00, 0x1B, 0x00,                  // Code for char |
    0x11, 0x1B, 0x04,                  // Code for char }
    0x02, 0x03, 0x01,                  // Code for char ~
    0x1F, 0x1F, 0x1F                   // Code for char 
};

#endif
