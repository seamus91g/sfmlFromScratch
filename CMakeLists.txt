

cmake_minimum_required(VERSION 3.3) 	# No particular reason ..
if(NOT CMAKE_BUILD_TYPE)	# If build type is not defined, set to Debug 
  set(CMAKE_BUILD_TYPE Debug CACHE STRING "Setting build type to Debug")
endif()
project(sfmlTut)

### g++ sfmlTut1.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system 		# Alternative: Make command 

#################### Source files 
set(SOURCES src/pang.cpp src/game.cpp src/stdafx.cpp src/splashScreen.cpp src/mainMenu.cpp)	# Source files
#################### 
# Environment check 
# Find required components from SFML libraries 
if (WIN32)
	set(SFML_ROOT C:/dev/libs/SFML-2.4.2)		# IMPORTANT: Windows install path for SFML. Change to match your own system 

	message("== Configuring for Windows ==")
	set(SFML_STATIC_LIBRARIES TRUE)				# Use static. Not DLL 
	include_directories(${SFML_ROOT}/include)	# Header files for sfml libraries etc. 
	link_directories(${SFML_ROOT}/lib)			# Location of static libraries 
	set(CMAKE_MODULE_PATH ${SFML_ROOT}/cmake/Modules ${CMAKE_MODULE_PATH})
	find_package(SFML 2 REQUIRED COMPONENTS window system graphics)		# The order matters ... ??  :-/
else ()
	message("== Configuring for a *nix environment ==")
	set(SFML_LIBRARIES sfml-graphics sfml-window sfml-system)
endif()
#################### 
####################
# Find includes 
include_directories(${PROJECT_SOURCE_DIR}/src)
# Build and link executable 
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build/bin)	# Location for binary exe
add_executable(sfml-app ${SOURCES})
target_link_libraries(sfml-app ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})


