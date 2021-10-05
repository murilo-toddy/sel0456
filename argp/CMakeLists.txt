cmake_minimum_required(VERSION 3.10)

# set the project name
project(argp)

add_compile_options(
  "-Wall" "-g"
  )

# add the executable
add_executable(example example.c)

