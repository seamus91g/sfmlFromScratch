cmake_minimum_required(VERSION 3.3) 	
if(NOT CMAKE_BUILD_TYPE)	# If build type is not defined, set to Debug 
  set(CMAKE_BUILD_TYPE Debug CACHE STRING "Setting build type to Debug")
endif()
project(sfmlTut)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

### g++ sfmlTut1.o -o sfml-app -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system 		# Alternative: Make command 

#################### Source files 
set(SOURCES 
	src/pang.cpp 
	src/game.cpp 
	src/gameBall.cpp 
	src/stdafx.cpp 
	src/splashScreen.cpp 
	src/mainMenu.cpp 
	src/visibleGameObject.cpp 
	src/playerPaddle.cpp 
	src/SFMLSoundProvider.cpp 
	src/serviceLocator.cpp 
	src/soundFileCache.cpp 
	src/AIPaddle.cpp 
	src/gameObjectManager.cpp)	# Source files
####################
# Find includes 
include_directories(${PROJECT_SOURCE_DIR}/src)
# Create executable 
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build/bin)	# Location for binary exe
add_executable(sfml-app ${SOURCES})
#################### 
# Environment check 
# Find required components from SFML libraries 
if (WIN32)
	set(SFML_ROOT C:/dev/libs/SFML-2.4.2)		# IMPORTANT: Windows install path for SFML. Change to match your own system 

	message("== Configuring for Windows ==")
	set(SFML_STATIC_LIBRARIES TRUE)						# Use static. Not DLL 
	include_directories(${SFML_ROOT}/include)			# Header files for sfml libraries etc. 
	link_directories(${SFML_ROOT}/build/lib)			# Location of static libraries 
	set(CMAKE_MODULE_PATH ${SFML_ROOT}/cmake/Modules ${CMAKE_MODULE_PATH})
	find_package(SFML 2 REQUIRED COMPONENTS audio graphics window system)		# The order matters
	target_link_libraries(sfml-app -static-libstdc++)				# Static linking may be required if using MinGW.
	add_custom_command(	TARGET sfml-app POST_BUILD COMMAND ${CMAKE_COMMAND} -E 	# Copy openal32 dll into build directory. Required for audio 
						copy_if_different ${SFML_ROOT}/bin/openal32.dll ${EXECUTABLE_OUTPUT_PATH}/openal32.dll)  
else ()
	message("== Configuring for a *nix environment ==")
	set(SFML_LIBRARIES sfml-audio sfml-graphics sfml-window sfml-system)
endif()
#################### 
# link required libraries 
target_link_libraries(sfml-app ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
