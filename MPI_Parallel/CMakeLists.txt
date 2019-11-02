cmake_minimum_required(VERSION 2.8)
project(Sequential)
find_package( OpenCV REQUIRED )
find_package(MPI REQUIRED)
include_directories(${MPI_INCLUDE_PATH})
add_definitions(-DOMPI_SKIP_MPICXX)



add_executable( gray gray.cpp )
target_link_libraries( gray ${OpenCV_LIBS} ${MPI_LIBRARIES})

if(MPI_COMPILE_FLAGS)
  set_target_properties(gray PROPERTIES
    COMPILE_FLAGS "${MPI_COMPILE_FLAGS}")
endif()

if(MPI_LINK_FLAGS)
  set_target_properties(gray PROPERTIES
    LINK_FLAGS "${MPI_LINK_FLAGS}")
endif()
