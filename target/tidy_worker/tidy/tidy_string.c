#include "tidy_string.h"
#include "tidy_memory.h"

#include <stdio.h> /* needed for vsnprintf */
#include <stdlib.h> /* needed for malloc-free */
#include <stdarg.h> /* needed for va_list */

int tidy_string_vscprintf(const char* format, va_list pargs)
{
  int retval;
  va_list argcopy;
  va_copy(argcopy, pargs);
  retval = vsnprintf(NULL, 0, format, argcopy);
  va_end(argcopy);
  return retval;
}

int tidy_string_vasprintf(char** strp, const char* fmt, va_list ap)
{
  int len = tidy_string_vscprintf(fmt, ap);
  if (len == -1) {
    return -1;
  }
  char* str = tidy_malloc((size_t) len + 1);
  if (!str) {
    return -1;
  }
  int r = vsnprintf(str, len + 1, fmt, ap); /* "secure" version of vsprintf */
  if (r == -1) {
    tidy_free(str);
    return -1;
  }
  *strp = str;
  return r;
}

int tidy_string_asprintf(char* strp[], const char* fmt, ...)
{
  va_list ap;
  va_start(ap, fmt);
  int r = tidy_string_vasprintf(strp, fmt, ap);
  va_end(ap);
  return r;
}

// // concat str1 and str2
// char *concat_string(const char *str1, const char *str2)
// {
//   char *result = NULL;
//   size_t n = 0;

//   if(str1) n += strlen(str1);
//   if(str2) n += strlen(str2);

//   if((str1 || str2) && (result = tidy_malloc(n + 1)) != NULL)
//   {
//     *result = '\0';

//     if(str1) strcpy(result, str1);
//     if(str2) strcat(result, str2);
//   }

//   return result;
// }

// // https://stackoverflow.com/a/9210560
// char** split_string(char* string, const char delimiter)
// {
//   char** result    = 0;
//   size_t count     = 0;
//   char* tmp        = string;
//   char* last_comma = 0;
//   char delim[3];
//   delim[0] = delimiter;
//   delim[1] = 0;

//   /* Count how many elements will be extracted. */
//   while (*tmp)
//   {
//     if (delimiter == *tmp)
//     {
//       count++;
//       last_comma = tmp;
//     }
//     tmp++;
//   }

//   /* Add space for trailing token. */
//   count += last_comma < (string + strlen(string) - 1);

//   /* Add space for terminating null string so caller
//      knows where the list of returned strings ends. */
//   count++;

//   result = tidy_malloc(sizeof(char*) * count);

//   if (result)
//   {
//     size_t idx  = 0;
//     char* token = strtok(string, delim);

//     while (token)
//     {
//       // assert(idx < count);
//       *(result + idx++) = strdup(token);
//       token = strtok(0, delim);
//     }
//     // assert(idx == count - 1);
//     *(result + idx) = 0;
//   }

//   return result;
// }

// char* tidy_string_copy(const char* string, char* copy)
// {
// #if 1
//   if(string == NULL) {
//     return NULL;
//   }

//   char *data = tidy_malloc(strlen(string) + 1 * sizeof(char*));
//   if(data == NULL) {
//     return NULL;
//   }
//   *data = '\0';
//   strcpy(data, string);

//   copy = data;
  
//   return data;
// #endif

// #if 0
//   while(size) {
//     size--;
//     str1[size] = str2[size];
//   }
// #endif

// }