cmake_minimum_required(VERSION 3.15.0)
project(Shop VERSION 0.1.0)
set(SHOP ${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 20)
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

# Dependency management
find_package(PkgConfig)
pkg_check_modules(GTK REQUIRED IMPORTED_TARGET gtkmm-3.0)

if(TARGET PkgConfig::GTK)
	message(STATUS "||> PkgConfig::GTK defined!")
endif()

add_executable(${SHOP}
	source/main.cpp
)

target_link_libraries(${SHOP}
	PRIVATE
	PkgConfig::GTK
)

set_target_properties(${SHOP}
	PROPERTIES
	LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin
	ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin
	RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin
)