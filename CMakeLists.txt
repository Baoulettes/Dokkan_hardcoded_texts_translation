cmake_minimum_required(VERSION 3.10)

set(PROJECT_NAME "Public_Translation_addon")
set(DOKKAN_SDK_REV "r8")
option(BUILD_COCOS2D "Include Cocos2D Library" ON)
set(PROJECT_LIBS dokkansdk)

#----------------------------------------------------------------------#
#=== DO NOT EDIT BELOW THIS LINE UNLESS YOU KNOW WHAT YOU ARE DOING ===#
#----------------------------------------------------------------------#
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
project(${PROJECT_NAME})
file(GLOB_RECURSE PROJECT_SRC "src/*.h" "src/*.cpp" "src/*.c")
get_filename_component(UD_SDK_ROOT "${CMAKE_SOURCE_DIR}/../.." REALPATH BASE_DIR "${CMAKE_BINARY_DIR}")
message(STATUS "UniDokkan SDK Root: ${UD_SDK_ROOT}")
add_subdirectory("${UD_SDK_ROOT}/dokkan-sdk-${DOKKAN_SDK_REV}" "${CMAKE_BINARY_DIR}/dokkan-sdk")
add_library(${PROJECT_NAME} SHARED ${PROJECT_SRC})
target_link_libraries(${PROJECT_NAME} ${PROJECT_LIBS})
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD COMMAND ${CMAKE_STRIP} $<TARGET_FILE_NAME:${PROJECT_NAME}>)