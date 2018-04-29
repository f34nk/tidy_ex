#ifndef HTML_MEMORY_H
#define HTML_MEMORY_H

#ifdef TIDY_HTML_USE_DMT

#include "dmt.h"

#define html_malloc(size) dmt_malloc(size)
#define html_realloc(data, size) dmt_realloc(data, size)
#define html_calloc(num, size) dmt_calloc(num, size)
#define html_free(data) if(data) { dmt_free(data); }

#else

#define html_malloc(size) malloc(size)
#define html_realloc(data, size) realloc(data, size)
#define html_calloc(num, size) calloc(num, size)
#define html_free(data) free(data)

#endif

#endif