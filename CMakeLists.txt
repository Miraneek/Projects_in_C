cmake_minimum_required(VERSION 3.29)
project(prc C)

set(CMAKE_C_STANDARD 23)

#[[add_executable(prc Kalkulačka/main.c)]]
#[[add_executable(prc house/main.c)]]
#[[add_executable(prc enum/main.c)]]
#[[add_executable(prc registračníSystem/main.c)]]
#[[add_executable(prc Playground/main.c)]]
#[[add_executable(prc KalkulačkaBetter/main.c)]]
#[[add_executable(prc UsersWithGender/main.c)]]

#[[add_executable(prc headerFiles/main.c
        headerFiles/calculator.h
        headerFiles/calculator.c
)]]
#[[
add_executable(prc bogoSort/main.c
        bogoSort/sorting.h
        bogoSort/sorting.c
        )]]

add_executable(prc Sortingalgorithms/main.c)
