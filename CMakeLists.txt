cmake_minimum_required(VERSION 3.24)
project(sdizo_projekt_1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")
add_executable(sdizo_projekt_1 main.cpp Array.cpp Array.h ListElement.cpp ListElement.h List.cpp List.h Heap.cpp Heap.h Menu.cpp Menu.h RNG.cpp RNG.h)
