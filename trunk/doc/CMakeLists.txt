cmake_minimum_required (VERSION 2.6)

find_package(Doxygen)

if (DOXYGEN_FOUND)

	configure_file(${CMAKE_CURRENT_SOURCE_DIR}/doxy.config.in 
		${CMAKE_CURRENT_BINARY_DIR}/doxy.config
		@ONLY )
	set(DOXY_CONFIG "${CMAKE_CURRENT_BINARY_DIR}/doxy.config")
  
	add_custom_target(doc ${DOXYGEN_EXECUTABLE} ${DOXY_CONFIG})
  
else (DOXYGEN_FOUND)

    message(status "Doxygen not found. Not building reference documentation.")
    
endif (DOXYGEN_FOUND)
