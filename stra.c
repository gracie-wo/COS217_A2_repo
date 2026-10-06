/*--------------------------------------------------------------------*/
/* stra.c                                                             */
/* Author: Grace Hua                                                  */
/*--------------------------------------------------------------------*/

#include <stdio.h>
#include "str.h"

/*gets a string and returns the length of the string*/
size_t Str_getLength(const char string[]){
   size_t uLength = 0;
   assert(string != NULL);
   while (string[uLength] != '\0')
      uLength++;
   return uLength;
}

/*copies a string from a source to a destination and returns a pointer to the destination*/
char* Str_copy(char destination[], const char source[]){
    size_t i = 0;

    assert(source != NULL);
    assert(destination != NULL);

    while (source[i] != '\0') {
        destination[i] = source[i];
        i++;
    }
    destination[i] = '\0';
    return destination;
}

/*concatenates a string from a source to a destination and returns a pointer to the destination*/
char* Str_concat(char destination[], const char source[]){
    assert(source != NULL);
    assert(destination != NULL);

    (void)Str_copy(destination + Str_getLength(destination), source);
    return destination;
}

/*compares two strings, returns -1 if string1 < string2, 0 if equal, 1 if string1 > string2*/
int Str_compare(const char string1[], const char string2[]){
    size_t i = 0;

    assert(string1 != NULL);
    assert(string2 != NULL);
    
    while (string1[i] != '\0' && string2[i] != '\0'){
        if(string1[i] < string2[i]){
            return -1;
        } else if(string1[i] > string2[i]){
            return 1; 
        }
        i++;
    }

    if(string1[i] == '\0' && string2[i] != '\0'){
        return -1;
    } else if(string1[i] != '\0' && string2[i] == '\0'){
        return 1;
    }

    return 0; 
}

/*searches for a substring within a string and returns a pointer to the first occurrence within the string*/
char* Str_search(const char string[], const char substring[]){
    size_t i = 0;
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
    while(string[i] != '\0'){
        if(string[i] == substring[0]){
            while(matching_char < sub_len && string[i + matching_char] == substring[matching_char]){
                matching_char++;
            }
            if(matching_char == sub_len){
                return (char*)&string[i];
            }
        } else {
            matching_char = 0;
        }
        i++;
    }
    return NULL;
}