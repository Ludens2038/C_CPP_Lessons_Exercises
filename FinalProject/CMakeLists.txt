cmake_minimum_required(VERSION 3.31)
project(FinalProject)

set(CMAKE_CXX_STANDARD 20)

add_executable(FinalProject main.cpp)

# adding nana
add_subdirectory(libs/nana-master)

# linking nana
target_link_libraries(FinalProject PRIVATE nana)