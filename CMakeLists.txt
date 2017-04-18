cmake_minimum_required(VERSION 3.6)
project(read_line_test)

set(CMAKE_CXX_COMPILER "g++")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -lreadline ")

set(SOURCE_FILES main.cpp ThiefLisp.cpp ThiefLisp.h ThiefLisp_Reader.cpp ThiefLisp_Reader.h
        ThiefLisp_Evaler.cpp ThiefLisp_Evaler.h ThiefLisp_Printer.cpp ThiefLisp_Printer.h
        ThiefLisp_Utils.cpp ThiefLisp_Utils.h ThiefLisp_Expr.h ThiefLisp_Expr.cpp
        )
add_executable(read_line_test ${SOURCE_FILES})