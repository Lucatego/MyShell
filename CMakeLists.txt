cmake_minimum_required(VERSION 3.29)
project(MyShell C)

set(CMAKE_C_STANDARD 17)

add_executable(MyShell src/main.c
		src/resources/io.c
		src/resources/Command.h
		src/resources/setup.c
		src/resources/setup.h)
