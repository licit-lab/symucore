cmake_minimum_required (VERSION 3.10)


project (SymuCore VERSION 1.0.0)


set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)


set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)


find_package(Boost COMPONENTS
    date_time
    REQUIRED)
    
if(Boost_FOUND)
    message(STATUS "Library Boost is available")
    message(STATUS "\t ${Boost_DATE_TIME_LIBRARY}")
    include_directories(${Boost_INCLUDE_DIRS})
    message(STATUS "\t Boost headers included")
else()
    message(STATUS "\t Boost library is missing")
endif()


# Define libraries to link
SET(CMAKE_BUILD_WITH_INSTALL_RPATH FALSE)
SET(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

include("cmake/macro.cmake")

add_subdirectory(symucore)

install(EXPORT SymuCoreTarget DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/cmake/symucore)

include(CMakePackageConfigHelpers)
write_basic_package_version_file(${CMAKE_BINARY_DIR}/SymuCore/SymuCoreConfigVersion.cmake
  VERSION ${SymuCore_VERSION}
  COMPATIBILITY ExactVersion)

configure_package_config_file(${PROJECT_SOURCE_DIR}/cmake/SymuCoreConfig.cmake.in
  ${CMAKE_BINARY_DIR}/SymuCore/SymuCoreConfig.cmake
  INSTALL_DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/cmake/symucore)

install(
  FILES
  ${CMAKE_BINARY_DIR}/SymuCore/SymuCoreConfig.cmake
  ${CMAKE_BINARY_DIR}/SymuCore/SymuCoreConfigVersion.cmake
  DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/cmake/symucore
  COMPONENT Development)
