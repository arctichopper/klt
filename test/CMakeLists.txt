# Prevent re-execution
include_guard( GLOBAL )

# Search for all sources in "src" dir and stores in TEST_SRCS variable
file( GLOB TEST_SRCS "${CMAKE_CURRENT_LIST_DIR}/*.cpp" )

# Add test binary
add_executable( tests ${TEST_SRCS} )

# Include upper directory header files
target_include_directories( tests PUBLIC ${CMAKE_CURRENT_LIST_DIR}/../inc )

# Link them with new sources
# target_link_libraries( TestTest PRIVATE teststudy )

# Add test using TestTest executable
add_test( klt_alg_test tests )
