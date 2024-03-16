cmake_minimum_required(VERSION 3.2)

cmake_path(GET CMAKE_CURRENT_SOURCE_DIR FILENAME FolderName)   
string(REPLACE " " "_" FolderName ${FolderName})

project(${FolderName}_Project)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin/${CMAKE_BUILD_TYPE})

if (MSVC)
    add_compile_options(/W3)
else()
    add_compile_options(-Wall -Wextra -Wpedantic -pedantic-errors)
endif()

file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS "src/*.cpp")

# # Filter out main files
# list(FILTER SRC_FILES EXCLUDE REGEX "src/main_.*.cpp")

message(STATUS "SRC_FILES: ")
foreach(SRC_FILE ${SRC_FILES})
    message(STATUS "    ${SRC_FILE}")
endforeach()

message(STATUS "Creating executable: ${SRC_MAIN_FILE_NAME}")
add_executable(${FolderName} ${SRC_MAIN_FILE} ${SRC_FILES})
target_compile_features(${FolderName} PUBLIC cxx_std_17)
target_include_directories(${FolderName} PUBLIC "src/")