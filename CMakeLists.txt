cmake_minimum_required(VERSION 4.0)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(OPTION_BUILD "" CACHE STRING "")

set(NAME_PROJECT game)

project(${NAME_PROJECT} VERSION 0.1)

# message(${OPTION_BUILD})

# Demo section
#[[ if(OPTION_BUILD MATCHES "WINDOWS64")
	set(CMAKE_C_COMPILER x86_64-w64-mingw32-gcc)
	set(CMAKE_CXX_COMPILER x86_64-w64-mingw32-g++)
	set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
	set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
	set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)

	message("Windows System")

	find_package(SDL2 REQUIRED)
	find_package(SDL2_image REQUIRED)

	file(GLOB_RECURSE SRC_FILES src/*.cpp)
	add_executable(${NAME_PROJECT}.exe ${SRC_FILES})
	# add_compile_options(-lmingw32 -lSDL2 -lSDL2_image)

	target_include_directories(${NAME_PROJECT}.exe PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include ${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INLUCDE_DIRS})
	target_link_libraries(${NAME_PROJECT}.exe PUBLIC ${SDL2_LIBRARIES} SDL2_image::SDL2_image SDL2::SDL2)
elseif(OPTION_BUILD MATCHES "LINUX64")
	message("Linux System")

	find_package(SDL2 REQUIRED)
	find_package(SDL2_image REQUIRED)
	find_package(SDL2_mixer REQUIRED)

	file(GLOB_RECURSE SRC_FILES src/*.cpp)
	add_executable(${NAME_PROJECT} ${SRC_FILES})

	target_include_directories(${NAME_PROJECT} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
	target_link_libraries(${NAME_PROJECT} PRIVATE SDL2::SDL2 SDL2_image::SDL2_image SDL2_mixer::SDL2_mixer)
else() ]]
	find_package(SDL2 REQUIRED)
	find_package(SDL2_image REQUIRED)
 	find_package(SDL2_mixer REQUIRED)

	file(GLOB_RECURSE SRC_FILES src/*.cpp)
	add_executable(${NAME_PROJECT} ${SRC_FILES})

	target_include_directories(${NAME_PROJECT} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
	target_link_libraries(${NAME_PROJECT} PRIVATE SDL2::SDL2 SDL2_image::SDL2_image SDL2_mixer::SDL2_mixer)
# endif()

message("End of Build")
