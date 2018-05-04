#ifndef TIDY_HTML_H
#define TIDY_HTML_H

#define TIDY_HTML_VERSION "0.0.0"

#ifdef TIDY_HTML_DEBUG
#define TIDY_HTML_LOG fprintf(stdout, "[LOG]\t%s()\n", __func__);
#define TIDY_HTML_LOG_ERROR fprintf(stderr, "[ERROR]\t%s()\n\t%s:%d\n", __func__, __FILE__, __LINE__);
#else
// nothing
#define TIDY_HTML_LOG
#define TIDY_HTML_LOG_ERROR
#endif

#include "tidy_map.h"
#include "tidy_options.h"
#include "tidy_workspace.h"
#include "tidy_parse.h"
#include "tidy_clean_and_repair.h"
#include "tidy_diagnostics.h"

#endif