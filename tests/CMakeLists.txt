# Specify the test executable name
set(TEST_EXECUTABLE test_${PROJECT_NAME})

# Find all unit test source files
file(GLOB_RECURSE TEST_FILES CONFIGURE_DEPENDS ${TEST_DIR}/*.cpp)

# Create the test executable
add_executable(${TEST_EXECUTABLE} ${TEST_FILES})

# Link GoogleTest and other needed libraries to the test executable
target_link_libraries(${TEST_EXECUTABLE} PRIVATE gtest gtest_main)

# Include directories for the tests
target_include_directories(${TEST_EXECUTABLE} PRIVATE ${SRC_DIR})

# Add compiler flags for coverage
if(CMAKE_CXX_COMPILER_ID MATCHES "Clang|AppleClang")
    target_compile_options(${TEST_EXECUTABLE} PRIVATE -fprofile-instr-generate -fcoverage-mapping)
    target_link_options(${TEST_EXECUTABLE} PRIVATE -fprofile-instr-generate -fcoverage-mapping)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(${TEST_EXECUTABLE} PRIVATE --coverage)
    target_link_libraries(${TEST_EXECUTABLE} PRIVATE --coverage)
endif()

# Add source files (except main.c) to the test executable
file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS ${SRC_DIR}/*.c)
list(REMOVE_ITEM SRC_FILES "${SRC_DIR}/main.c")
target_sources(${TEST_EXECUTABLE} PRIVATE ${SRC_FILES})

# Add a test target for running the tests with CTest
enable_testing()
add_test(NAME ${TEST_EXECUTABLE} COMMAND ${TEST_EXECUTABLE})
