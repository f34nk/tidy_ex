cmake_minimum_required(VERSION 3.0)
project(tidy_worker)

# resolve wildcard
file(GLOB ERL_INTERFACE "${ERLANG_PATH}/../lib/erl_interface-*")
# make absolute
get_filename_component(ERL_INTERFACE ${ERL_INTERFACE} ABSOLUTE)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -O2 -std=c99") # c
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -pedantic -Wcomment -Wall")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -D_REENTRANT")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wno-unused-parameter")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -D_GNU_SOURCE")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wno-write-strings")

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -I${ERLANG_PATH}/include")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -I${ERL_INTERFACE}/include")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -L${ERL_INTERFACE}/lib")

set(TIDY_HTML5_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../tidy-html5")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -I${TIDY_HTML5_PATH}/include")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -L${TIDY_HTML5_PATH}/build/cmake")

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -I${CMAKE_CURRENT_SOURCE_DIR}/../vec/src")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -I${CMAKE_CURRENT_SOURCE_DIR}/../map/src")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -I${CMAKE_CURRENT_SOURCE_DIR}/../dmt/src")

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -I${CMAKE_CURRENT_SOURCE_DIR}/handlers")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -I${CMAKE_CURRENT_SOURCE_DIR}/utils")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -I${CMAKE_CURRENT_SOURCE_DIR}/tidy")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -I${CMAKE_CURRENT_SOURCE_DIR}")

message("CMAKE_CURRENT_SOURCE_DIR = ${CMAKE_CURRENT_SOURCE_DIR}")

# make sure that erlang and pthread gets linked as last
# https://cmake.org/pipermail/cmake/2009-February/026779.html
set(CMAKE_C_LINK_EXECUTABLE "${CMAKE_C_LINK_EXECUTABLE} -lerl_interface -lei -lpthread")
set(CMAKE_C_LINK_EXECUTABLE "${CMAKE_C_LINK_EXECUTABLE} -ltidys")


file(GLOB_RECURSE HANDLERS "handlers/*.c")
file(GLOB_RECURSE UTILS "utils/*.c")
file(GLOB_RECURSE TIDY "tidy/*.c")

add_executable(
  ${PROJECT_NAME}
  ${UTILS}
  ${TIDY}
  ${HANDLERS}
  tidy_worker.c
  handle_send.c
  ../vec/src/vec.c
  ../map/src/map.c
  ../dmt/src/dmt.c
)

# add target tests

add_subdirectory(test)
enable_testing()
file(GLOB_RECURSE TESTS "${CMAKE_CURRENT_SOURCE_DIR}/test/*.c")
foreach(TEST ${TESTS})
  get_filename_component(TEST ${TEST} NAME_WE)
  add_test(NAME ${TEST} COMMAND ${TEST})
endforeach()