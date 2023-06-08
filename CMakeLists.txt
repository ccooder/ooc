cmake_minimum_required(VERSION 3.25)
project(ooc C)

set(CMAKE_C_STANDARD 11)

aux_source_directory(./02 DIR_SRCS)
#message(${DIR_SRCS})
#list(REMOVE_ITEM DIR_SRCS ./01/Set.c)
#message(${DIR_SRCS})
add_executable(${PROJECT_NAME} ./02/main.c ${DIR_SRCS})
