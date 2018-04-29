#ifndef TIDY_MEMORY_H
#define TIDY_MEMORY_H

#ifdef TIDY_HTML_USE_DMT

#include "dmt.h"

#define tidy_malloc(size) dmt_malloc(size)
#define tidy_realloc(data, size) dmt_realloc(data, size)
#define tidy_calloc(num, size) dmt_calloc(num, size)
#define tidy_free(data) if(data) { dmt_free(data); }

#else

#define tidy_malloc(size) malloc(size)
#define tidy_realloc(data, size) realloc(data, size)
#define tidy_calloc(num, size) calloc(num, size)
#define tidy_free(data) free(data)

#endif

#endif