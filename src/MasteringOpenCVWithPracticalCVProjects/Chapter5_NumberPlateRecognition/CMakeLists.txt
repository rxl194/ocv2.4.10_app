cmake_minimum_required (VERSION 2.6) 

PROJECT(M_PCVP_05_ANPR)
SET(PROJECT_VERSION "0.1")

# Opencv Package
FIND_PACKAGE( OpenCV REQUIRED )
IF (${OpenCV_VERSION} VERSION_LESS 2.3.0)
	MESSAGE(FATAL_ERROR "OpenCV version is not compatible : ${OpenCV_VERSION}")
ENDIF()

ocv_include_directories("${OpenCV_INCLUDE_DIRS}" "${PROJECT_SOURCE_DIR}/include" )#for opencv.hpp

SET(SRC
 main.cpp
 DetectRegions.cpp
 OCR.cpp
 Plate.cpp
)

ADD_EXECUTABLE( ${PROJECT_NAME} ${SRC} )
TARGET_LINK_LIBRARIES( ${PROJECT_NAME}  ${OpenCV_LIBS} )

ADD_EXECUTABLE( M_PCVP_05_trainSVM trainSVM.cpp )
TARGET_LINK_LIBRARIES( M_PCVP_05_trainSVM  ${OpenCV_LIBS} )

ADD_EXECUTABLE( M_PCVP_05_trainOCR trainOCR.cpp OCR.cpp )
TARGET_LINK_LIBRARIES( M_PCVP_05_trainOCR  ${OpenCV_LIBS} )

ADD_EXECUTABLE( M_PCVP_05_evalOCR evalOCR.cpp OCR.cpp )
TARGET_LINK_LIBRARIES( M_PCVP_05_evalOCR  ${OpenCV_LIBS} )

SET(RESOURCES
	SVM.xml
	OCR.xml
	test
)
foreach(f ${RESOURCES})
file( COPY ${f} DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/)
endforeach(f)
