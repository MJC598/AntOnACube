cmake_minimum_required(VERSION 3.10)
project(AntOnACube)

set(CPP_SRC "AntOnACube.cpp" "src/Ant.cpp" "src/Graph.cpp" "src/RandomNumberGenerator.cpp" "src/Simulation.cpp" "src/ThreadPool.cpp")
set(CPP_HEADERS "AntOnACube.h" "include/Ant.h" "include/Graph.h" "include/RandomNumberGenerator.h" "include/Simulation.h" "include/ThreadPool.h")

include_directories("include")

add_executable(AntOnACube ${CPP_SRC} ${CPP_HEADERS})