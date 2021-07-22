cmake_minimum_required (VERSION 3.13)
project (ex506_cvu_prj)

IF (MSVC) 
	# require C++20
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++latest")

	# Activate C++ exception handling 
	IF (NOT CMAKE_CXX_FLAGS MATCHES "/EHsc") 
		SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /EHsc")
	ENDIF ()
ELSE ()
	SET(GCC_STD_CPP_2A_COMPILE_FLAGS "-std=c++2a")
	SET( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_STD_CPP_2A_COMPILE_FLAGS}")

	SET(GCC_STD_CPP_CONCEPTS_COMPILE_FLAGS "-fconcepts")
	SET( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_STD_CPP_CONCEPTS_COMPILE_FLAGS}")

	SET(GCC_STD_CPP_PERMISIV_COMPILE_FLAGS "-fpermissive")
	SET( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_STD_CPP_PERMISIV_COMPILE_FLAGS}")
ENDIF () 

set(INCLUDE_DIRS "test/inc" "lib/inc")

include_directories(${INCLUDE_DIRS})

# add the executable
add_executable(ex506_cvu

	test/inc/test_type_A.h
	test/src/test_type_A.cpp
	
	test/inc/read_sentence.h	
	test/src/read_sentence.cpp

	test/inc/test_133_3_line.h
	test/src/test_133_3_line.cpp

	lib/inc/type_A.h
	lib/src/type_A.cpp
	lib/inc/cvu_133_3_line.h

	main/main.cpp
)

