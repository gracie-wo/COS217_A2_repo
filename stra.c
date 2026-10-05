#include <stdio.h>
#include "str.h"

size_t Str_getLength(const char pcSrc[]){
   size_t uLength = 0;
   assert(pcSrc != NULL);
   while (pcSrc[uLength] != '\0')
      uLength++;
   return uLength;
}

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

char* Str_concat(char destination[], const char source[]){
    assert(source != NULL);
    assert(destination != NULL);

    Str_copy(destination + Str_getLength(destination), source);
    return destination;
}

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

char* Str_search(const char string[], const char substring[]){
    size_t i = 0;
    size_t sub_len = Str_getLength(substring);
    
    assert(string != NULL);
    assert(substring != NULL);

    if(sub_len == 0){
        return (char*)string;
    }

    while(string[i + sub_len - 1] != '\0'){
        if(Str_compare(string + i, substring) == 0){
            return (char*)(string + i);
        }
        i++;
    }
    return NULL;
}