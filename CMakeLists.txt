cmake_minimum_required(VERSION 3.16)

project(Practica_2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Practica_2 main.cpp
    funciones.h
    funciones.cpp)

# 🔥 AGREGA ESTO
set_target_properties(Practica_2 PROPERTIES
    WIN32_EXECUTABLE OFF
)

include(GNUInstallDirs)
install(TARGETS Practica_2
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)