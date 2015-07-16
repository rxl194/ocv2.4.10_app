# cmake for OpenCV2 Cookbook
# your opencv/build directory should be in your system PATH

# set minimum required version for cmake
cmake_minimum_required(VERSION 2.8)

# define the project name
set(project_name "APCookBook_Chapter01")

# set the project namee
project("${project_name}")

# add opencv package to the project
find_package( OpenCV REQUIRED )
MESSAGE(“OpenCV version : ${OpenCV_VERSION}”)

# add opencv include directories to the project
include_directories( ${OpenCV_INCLUDE_DIRS} ) 

# add executable
add_executable( APCB_01_loadDisplaySave loadDisplaySave.cpp)
add_executable( APCB_01_logo logo.cpp)
add_executable( APCB_01_mat mat.cpp)

# link libraries
target_link_libraries( APCB_01_loadDisplaySave ${OpenCV_LIBS})
target_link_libraries( APCB_01_logo ${OpenCV_LIBS})
target_link_libraries( APCB_01_mat ${OpenCV_LIBS})
