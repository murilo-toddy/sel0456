cmake_minimum_required(VERSION 3.10)

# set the project name
project(cmake_minimal)

# add the executable
add_executable(main main.c mult_acc.c sqr.c)

target_link_libraries(main pthread)
