#include <stdio.h>
#include "str.h"

size_t Str_getLength(const char pcSrc[]){
   size_t uLength = 0;
   assert(pcSrc != NULL);
   while (pcSrc[uLength] != '\0')
      uLength++;
   return uLength;
}

char* Str_copy(const char source[], char destination[]){
    assert(source != NULL);
    assert(destination != NULL);
    size_t i = 0;
    while (source[i] != '\0') {
        destination[i] = source[i];
        i++;
    }
    destination[i] = '\0';
    return destination;
}

char* Str_concat(const char source[], char destination[]){
    assert(source != NULL);
    assert(destination != NULL);

    Str_copy(source, destination + Str_getLength(destination));
    return destination;
}

int Str_compare(const char string1[], const char string2[]){
    assert(string1 != NULL);
    assert(string2 != NULL);
    
    size_t i = 0;
    while (string1[i] != '\0' && string2[i] != '\0'){
        if(string1[i] < string2[i]){
            return -1;
        } else if(string1[i] > string2[i]){
            return 1; 
        }
    }
    return 0; 
}

char* Str_search(const char string[], const char substring[]){
    assert(string != NULL);
    assert(substring != NULL);

    size_t i= 0;

    while(string[i] != '\0'){
        if(Str_compare(string + i, substring) == 0){
            return (char*)(string + i);
        }
    
    }
    return NULL;
}