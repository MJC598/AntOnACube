# CMakeList.txt : CMake project for AntOnACube, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (AntOnACube "AntOnACube.cpp" "AntOnACube.h" "Graph.h" "Graph.cpp" "Ant.h" "Ant.cpp" "Simulation.h" "Simulation.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET AntOnACube PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
