cmake_minimum_required(VERSION 3.16)

add_subdirectory(here-data-sdk-cpp)

project (mere_haps CXX)
add_executable(mere_haps main.cpp)

find_package(olp-cpp-sdk-core REQUIRED)
find_package(olp-cpp-sdk-authentication REQUIRED)
find_package(olp-cpp-sdk-dataservice-read REQUIRED)
find_package(olp-cpp-sdk-dataservice-write REQUIRED)

target_link_libraries(mere_haps
    olp-cpp-sdk-core
    olp-cpp-sdk-authentication
    olp-cpp-sdk-dataservice-read
    olp-cpp-sdk-dataservice-write
)

target_include_directories (mere_haps
	PRIVATE
	$<TARGET_PROPERTY:olp-cpp-sdk-core,INTERFACE_INCLUDE_DIRECTORIES>
	$<TARGET_PROPERTY:olp-cpp-sdk-authentication,INTERFACE_INCLUDE_DIRECTORIES>
	$<TARGET_PROPERTY:olp-cpp-sdk-dataservice-read,INTERFACE_INCLUDE_DIRECTORIES>
	$<TARGET_PROPERTY:olp-cpp-sdk-dataservice-write,INTERFACE_INCLUDE_DIRECTORIES>
)