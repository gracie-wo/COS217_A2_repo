/*--------------------------------------------------------------------*/
/* str.h                                                             */
/* Author: Grace Hua                                                  */
/*--------------------------------------------------------------------*/

#ifndef STR_H
#define STR_H
#include <stddef.h>
#include <assert.h>

/*returns the length of the string*/
size_t Str_getLength(const char *string);

/*copies the source string to the destination string and returns a pointer to the destination*/
char* Str_copy(char *destination, const char *source);

/*appends a copy of the source string to the end of the destination string
the destination string must be large enough to hold the result
returns a pointer to the destination string*/
char* Str_concat(char *destination, const char *source);

/*compares two strings and returns 0 if they are equal
returns a negative value if the first non-matching char in string1 has a lower ASCII value than the corresponding char in string2
returns a positive value if the first non-matching char in string1 has a higher ASCII value than the corresponding char in string2*/
int Str_compare(const char *string1, const char *string2);

/*searches for the first occurrence of the substring in the string
returns a pointer to the first occurrence of the substring in the string, or NULL if the substring is not found*/
char* Str_search(const char *string, const char *substring);

#endif /* STR_H */