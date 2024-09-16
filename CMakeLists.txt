cmake_minimum_required(VERSION 3.28)
project(ArvoresBinarias C)

set(CMAKE_C_STANDARD 11)

add_executable(ArvoresBinarias main.c
        indiceDeOrdenacao.c
        chavePrimaria.c
        bancoDeDados.c
        arvoresBinarias.h)
