cmake_minimum_required (VERSION 2.6)
project (FPMATH)

set (FPML_VERSION_MAJOR 0)
set (FPML_VERSION_MINOR 1)
set (FPML_NAME "Fixed Point Math Library")

include_directories("${PROJECT_SOURCE_DIR}/include")

add_subdirectory(test)
add_subdirectory(doc)
