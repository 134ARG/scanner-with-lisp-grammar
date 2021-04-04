cmake_minimum_required(VERSION 3.17)
project(CScanner C)

set(CMAKE_C_STANDARD 11)

add_executable(CScanner main.c expression.c expression.h sstring.c sstring.h stack.c stack.h sscanner.c sscanner.h ctool.c ctool.h sparser.c sparser.h spredicate.c spredicate.h scanner_main.c scanner_main.h globals.c globals.h)