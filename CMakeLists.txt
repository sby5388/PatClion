cmake_minimum_required(VERSION 3.14.2)
project(PatClion C)
set(CMAKE_CXX_FLAGS “${CMAKE_CXX_FLAGS} -Wall -fexec-charset=UTF8”)

SET(SETS_12 false)
SET(SETS_12_1 true)
SET(SETS_15 false)
SET(DATA_STRUCTURE_BOOK false)
SET(SETS_434 true)


set(CMAKE_C_STANDARD 99)
if (SETS_12)
    add_subdirectory(sets12)
endif ()
if (SETS_12_1)
    add_subdirectory(sets12_1)
endif ()
if (SETS_15)
    add_subdirectory(SETS_15)
endif ()
if (DATA_STRUCTURE_BOOK)
    add_subdirectory(data_structure_book)
endif ()
if (SETS_434)
    add_subdirectory(sets_434)
endif ()

add_subdirectory(sets13)

if(fasle)

add_subdirectory(sets14)
add_subdirectory(sets17)

add_subdirectory(other)

add_subdirectory(temp)

endif()