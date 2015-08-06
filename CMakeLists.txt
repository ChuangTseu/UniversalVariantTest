project(UniversalVariantTest)
cmake_minimum_required(VERSION 2.8)
cmake_policy(SET CMP0020 NEW)

aux_source_directory(. SRC_LIST)

include_directories(.)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

IF (MSVC)

ELSE(MSVC)
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra") # Warnings
        SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fms-extensions -g") # features
        #SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pipe") # pipe
ENDIF(MSVC)

IF(WIN32)
    add_definitions(-DDOGE_WIN32=1)
ENDIF(WIN32)


add_executable(${PROJECT_NAME} ${SRC_LIST})

if (WIN32)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS -D_SCL_SECURE_NO_WARNINGS)
else(WIN32)

endif(WIN32)

target_link_libraries(${PROJECT_NAME})

