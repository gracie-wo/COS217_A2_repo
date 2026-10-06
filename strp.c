/*--------------------------------------------------------------------*/
/* strp.c                                                             */
/* Author: Grace Hua                                                  */
/*--------------------------------------------------------------------*/

#include <stdio.h>
#include "str.h"

/*gets a string and returns the length of the string*/
size_t Str_getLength(const char *string){
   const char *strEnd;
   assert(string != NULL);
   strEnd = string;
   while (*strEnd != '\0')
      strEnd++;
   return (size_t)(strEnd - string);
}

/*copies a string from a source to a destination and returns a pointer to the destination*/
char* Str_copy(char *destination, const char *source){
    char *strStart;
    assert(source != NULL);
    assert(destination != NULL);

    strStart = destination;
    while (*source != '\0') {
        *destination = *source;
        destination++;
        source++;
    }
    *destination = '\0';
    return strStart;
}

/*concatenates a string from a source to a destination and returns a pointer to the destination*/
char* Str_concat(char *destination, const char *source){
    assert(source != NULL);
    assert(destination != NULL);

    while (*destination != '\0') {
        destination++;
    }

    (void)Str_copy(destination, source);
    return destination;
}

/*compares two strings, returns -1 if string1 < string2, 0 if equal, 1 if string1 > string2*/
int Str_compare(const char *string1, const char *string2){
    assert(string1 != NULL);
    assert(string2 != NULL);

    while (*string1 != '\0' && *string2 != '\0'){
        if(*string1 < *string2){
            return -1;
        } else if(*string1 > *string2){
            return 1; 
        }
        string1++;
        string2++;
    }

    if(*string1 == '\0' && *string2 != '\0'){
        return -1;
    } else if(*string1 != '\0' && *string2 == '\0'){
        return 1;
    }

    return 0; 
}

/*searches for a substring within a string and returns a pointer to the first occurrence within the string*/
char* Str_search(const char *string, const char *substring){
    size_t matching_char = 0;
    size_t sub_len = Str_getLength(substring);
    size_t str_len = Str_getLength(string);

    assert(string != NULL);
    assert(substring != NULL);

    if(sub_len == 0){
        return (char*)string;
    }

    if(str_len == 0 || sub_len > str_len){
        return NULL;
    }

    /*iterate through the string and check for the substring 
    if found return a pointer to the first occurrence of the substring within the string*/
    while(*string != '\0'){
        if(*string == *substring){
            while(matching_char < sub_len && *(string + matching_char) == *(substring + matching_char)){
                matching_char++;
            }
            if(matching_char == sub_len){
                return (char*)string;
            }
        }
        matching_char = 0;
        string++;
    }

    return NULL;
}