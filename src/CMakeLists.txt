
if (WIN32)
  if (MSVC)
    set(OpenCV_DIR "${CMAKE_SOURCE_DIR}/../ocv2.4.10/msvc/install")
  else()
    set(OpenCV_DIR "${CMAKE_SOURCE_DIR}/../ocv2.4.10/MSys/install")
  endif()
endif()

add_subdirectory(tutorial)
add_subdirectory(ApplicationProgrammingCookbook_2nd)