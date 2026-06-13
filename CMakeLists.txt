cmake_minimum_required(VERSION 4.1)
project(GestorDeChamados C)

set(CMAKE_C_STANDARD 11)

add_executable(GestorDeChamados main.c
        Chamados.h
        Chamados.c
        Structs.h
        ListaDinEncad.c)
