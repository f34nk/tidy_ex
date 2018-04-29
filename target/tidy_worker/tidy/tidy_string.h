#ifndef TIDY_STRING_H
#define TIDY_STRING_H

/*
 Copyright (C) 2018 Frank Eickhoff

 This library is free software; you can redistribute it and/or
 modify it under the terms of the GNU Lesser General Public
 License as published by the Free Software Foundation; either
 version 2.1 of the License, or (at your option) any later version.

 This library is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 Lesser General Public License for more details.

 You should have received a copy of the GNU Lesser General Public
 License along with this library; if not, write to the Free Software
 Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
*/

// char *concat_string(const char *str1, const char *str2);
// char** split_string(char* string, const char delimiter);

// char* tidy_string_copy(const char* string);

/**
 * Copy a string.
 * @param string [source string]
 * @param copy   [destination string]
 */
#define tidy_string_copy(string, copy) \
  if(string != NULL) { \
    copy = tidy_malloc(strlen(string) + 1 * sizeof(char*)); \
    if(copy != NULL) { \
      *copy = '\0'; \
      strcpy(copy, string); \
    } \
  } \
  else { \
    copy = NULL; \
  }

// char* tidy_string_copy(const char* string, char* copy);

/*
#define tidy_string_copy(string, copy) \
  if(string != NULL) { \
    size_t size = strlen(string) + 1; \
    copy = tidy_malloc(size * sizeof(char*)); \
    if(copy != NULL) { \
      *copy = '\0'; \
      while(size) { \
        size--; \
        copy[size] = string[size]; \
      } \
    } \
  } \
  else { \
    copy = NULL; \
  }
*/

int tidy_string_asprintf(char* strp[], const char* fmt, ...);

#endif