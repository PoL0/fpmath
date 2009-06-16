cmake_minimum_required (VERSION 2.6)
project (unit_test)

SET(source_files
	fixed_point.cpp 
	)

source_group("Source Files" FILES ${source_files})
add_executable(unit_test runner.cpp ${source_files} )
