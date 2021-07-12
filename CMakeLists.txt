cmake_minimum_required (VERSION 3.10)


project (SymuCore VERSION 1.0.0)


set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)


set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)


find_package(Boost COMPONENTS
    chrono
    date_time
    locale
    log
    thread
    serialization
    wserialization
    filesystem
    system
    program_options
    REQUIRED)

    if(Boost_FOUND)
        message(STATUS "Library Boost is available")
        message(STATUS "\t ${Boost_CHRONO_LIBRARY}")
        message(STATUS "\t ${Boost_DATE_TIME_LIBRARY}")
        message(STATUS "\t ${Boost_LOCALE_LIBRARY}")
        message(STATUS "\t ${Boost_SERIALIZATION_LIBRARY}")
        message(STATUS "\t ${Boost_WSERIALIZATION_LIBRARY}")
        message(STATUS "\t ${Boost_LOG_LIBRARY}")
        message(STATUS "\t ${Boost_FILESYSTEM_LIBRARY}")
        message(STATUS "\t ${Boost_THREAD_LIBRARY}")
        message(STATUS "\t ${Boost_PROGRAM_OPTIONS}")
        message(STATUS "\t ${Boost_SYSTEM_LIBRARY}")
        include_directories(${Boost_INCLUDE_DIRS})
        message(STATUS "\t Boost headers included")
    else()
        message(STATUS "\t Boost library is missing")
    endif()


# Define libraries to link
SET(CMAKE_BUILD_WITH_INSTALL_RPATH FALSE)
SET(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)


add_subdirectory(symucore)

message(STATUS "${CMAKE_CURRENT_SOURCE_DIR}")
