#ifndef HTML_MAP_H
#define HTML_MAP_H

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

#include "map.h"

/**
 * Map of string key and key value.
 */
typedef map_t(char*) html_map_str_t;

#define html_map_set(m, key, value) map_set(m, key, value)
#define html_map_get(m, key) map_get(m, key)
#define html_map_next(m, iter) map_next(m, iter)
#define html_map_init(m) map_init(m)
#define html_map_iter(m) map_iter(m)
#define html_map_deinit(m) map_deinit(m)

#endif