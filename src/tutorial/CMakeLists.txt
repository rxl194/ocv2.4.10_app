
cmake_minimum_required(VERSION 2.8)
project( t001_DisplayImage )

# ${PROJECT_SOURCE_DIR} is the name of the root directory of the project
# TO_NATIVE_PATH converts the path ${PROJECT_SOURCE_DIR}/data/ to a full path and the file() command stores it in DATA_FOLDER
file(TO_NATIVE_PATH "${PROJECT_SOURCE_DIR}/data" DATA_FOLDER)
# set TRAIN_FOLDER to DATA_FOLDER/train_images - this is where we will put our templates for constructing the vocabulary
set(IMAGE_FOLDER "${PROJECT_SOURCE_DIR}/images")

# set the configuration input file to ${PROJECT_SOURCE_DIR}/Config.h.in and the includable header file holding configuration information to ${PROJECT_SOURCE_DIR}/include/Config.h
configure_file("${PROJECT_SOURCE_DIR}/Config.h.in" "${PROJECT_SOURCE_DIR}/include/Config.h")

ocv_include_directories("${OpenCV_SOURCE_DIR}/include" "${PROJECT_SOURCE_DIR}/include" )#for opencv.hpp

find_package( OpenCV REQUIRED )
add_executable( t001_DisplayImage t001_DisplayImage.cpp )
target_link_libraries( t001_DisplayImage ${OpenCV_LIBS} )