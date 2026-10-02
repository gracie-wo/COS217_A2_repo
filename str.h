#ifndef STR_H
#define STR_H

//returns the length of the string
void Str_getLength(const char *string);

//copies the source string to the destination string
void Str_copy(const char *source, char *destination);

//appends a copy of the source string to the end of the destination string
//the destination string must be large enough to hold the result
void Str_concat(const char *source, char *destination);

//compares two strings and returns 0 if they are equal
//returns a negative value if the first non-matching char in string1 has a lower ASCII value than the corresponding char in string2
//returns a positive value if the first non-matching char in string1 has a higher ASCII value than the corresponding char in string2
void Str_compare(const char *string1, const char *string2);

//searches for the first occurrence of the substring in the string
//returns a pointer to the first occurrence of the substring in the string, or NULL if the substring is not found
void Str_search(const char *string, const char *substring);

#endif // STR_H