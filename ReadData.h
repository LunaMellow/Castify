
/**
 *      Simple library for reading data
 *
 *      @file ReadData.h
 *
 */

#ifndef CASTIFY_READDATA_H
#define CASTIFY_READDATA_H

// Includes
#include <ctype.h>              //  toupper
#include <stdio.h>              //  printf, scanf
#include <stdlib.h>             //  sizeof, malloc
#include <string.h>             //  strlen, strcpy

/**
 *  Reads and returns a (upcasted) character.
 *
 *  @param   t  - Text asking user for a character
 *
 *  @return  A (upcasted) character.
 */
char readChar(const char* t)  {
    char character;
    printf("%s:  ", t);
    scanf(" %c", &character);   getchar();
    return (toupper(character));
}

#endif //CASTIFY_READDATA_H
