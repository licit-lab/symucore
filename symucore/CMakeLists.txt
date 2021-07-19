# Define property to hold all .cpp files
set_property(GLOBAL PROPERTY SYMUCORE_SRC "")

add_subdirectory("src")

get_property(SYMUCORE_SRC GLOBAL PROPERTY SYMUCORE_SRC)

# Define SymuCore target: library
add_library(SymuCore SHARED ${SYMUCORE_SRC})

set_property(TARGET SymuCore PROPERTY CXX_STANDARD 11)
set_property(TARGET SymuCore PROPERTY CXX_STANDARD_REQUIRED ON)


# Link dependencies
target_link_libraries(SymuCore PUBLIC ${Boost_DATE_TIME_LIBRARY})

# Visible
target_include_directories(SymuCore PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
    $<INSTALL_INTERFACE:include/SymuCore>
)

# Set processor flags
add_definitions(-DSYMUCORE_EXPORTS)


install(TARGETS SymuCore
        EXPORT SymuCoreTarget
        ARCHIVE DESTINATION ${CMAKE_INSTALL_PREFIX}/lib
        LIBRARY DESTINATION ${CMAKE_INSTALL_PREFIX}/lib
        RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)
