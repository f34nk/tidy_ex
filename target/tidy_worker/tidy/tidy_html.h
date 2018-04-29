#ifndef TIDY_HTML_H
#define TIDY_HTML_H

#define TIDY_HTML_VERSION "0.0.0"

// #define TIDY_HTML_DEBUG
// #define TIDY_HTML_USE_DMT

#ifdef TIDY_HTML_DEBUG
#define TIDY_HTML_LOG fprintf(stdout, "[LOG]\t%s()\n", __func__);
#define TIDY_HTML_LOG_ERROR fprintf(stderr, "[ERROR]\t%s()\n\t%s:%d\n", __func__, __FILE__, __LINE__);
#else
// nothing
#define TIDY_HTML_LOG
#define TIDY_HTML_LOG_ERROR
#endif

#include "tidy_options.h"
// #include "html_memory.h"
// #include "html_workspace.h"
// #include "html_clean_and_repair.h"

#endif