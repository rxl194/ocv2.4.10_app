# cmake for OpenCV2 Cookbook
# your opencv/build directory should be in your system PATH

# set minimum required version for cmake
cmake_minimum_required(VERSION 2.8)

# define the project name
set(project_name "APCookBook_Chapter02")

# set the project namee
project("${project_name}")

# add opencv package to the project
find_package( OpenCV REQUIRED )
MESSAGE(“OpenCV version : ${OpenCV_VERSION}”)

# ${PROJECT_SOURCE_DIR} is the name of the root directory of the project
# TO_NATIVE_PATH converts the path ${PROJECT_SOURCE_DIR}/data/ to a full path and the file() command stores it in DATA_FOLDER
file(TO_NATIVE_PATH "${PROJECT_SOURCE_DIR}/.." DATA_ROOT_FOLDER)
set(DATA_FOLDER "${DATA_ROOT_FOLDER}/data")
# set TRAIN_FOLDER to DATA_FOLDER/train_images - this is where we will put our templates for constructing the vocabulary
set(TRAIN_FOLDER "${DATA_ROOT_FOLDER}/train_images")
# set TEMPLATE_FOLDER to DATA_FOLDER/templates - this is where we will put our traininfg images, in folders organized by category
set(TEMPLATE_FOLDER "${DATA_ROOT_FOLDER}/templates")
set(IMAGE_FOLDER "${DATA_ROOT_FOLDER}/images")

# set the configuration input file to ${PROJECT_SOURCE_DIR}/Config.h.in and the includable header file holding configuration information to ${PROJECT_SOURCE_DIR}/include/Config.h
configure_file("${PROJECT_SOURCE_DIR}/../Config.h.in" "${PROJECT_SOURCE_DIR}/include/Config.h")

# add opencv include directories to the project
# include_directories( ${OpenCV_INCLUDE_DIRS} "${PROJECT_SOURCE_DIR}/../include" ) 
ocv_include_directories("${OpenCV_INCLUDE_DIRS}" "${PROJECT_SOURCE_DIR}/include" )#for opencv.hpp

# add executable
add_executable( APCB_02_saltImage saltImage.cpp)
add_executable( APCB_02_colorReduce colorReduce.cpp)
add_executable( APCB_02_contrast contrast.cpp)
add_executable( APCB_02_addImages addImages.cpp)
add_executable( APCB_02_remapping remapping.cpp)

# link libraries
target_link_libraries( APCB_02_saltImage ${OpenCV_LIBS})
target_link_libraries( APCB_02_colorReduce ${OpenCV_LIBS})
target_link_libraries( APCB_02_contrast ${OpenCV_LIBS})
target_link_libraries( APCB_02_addImages ${OpenCV_LIBS})
target_link_libraries( APCB_02_remapping ${OpenCV_LIBS})
