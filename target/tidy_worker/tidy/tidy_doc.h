#ifndef TIDY_DOC_H
#define TIDY_DOC_H

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

#include "tidy_includes.h"

/**
 * Map of string key and key value.
 */
typedef TidyDoc tidy_doc_t;

tidy_doc_t* tidy_init(html_map_str_t* options);

void tidy_destroy(tidy_doc_t* doc);

#endif