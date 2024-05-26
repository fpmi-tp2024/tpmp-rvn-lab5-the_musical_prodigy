set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_LIST_DIR}/../include/Model)

# Add SQLiteCpp subdirectory
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/SQLiteCpp)

file(GLOB SOURCES "../src/Model/*.cpp")

# Link runTests with what we want to test and the GTest and pthread library
add_executable(runTests tests.cpp ${SOURCES})
target_link_libraries(runTests gtest gtest_main pthread SQLiteCpp sqlite3 dl)

# Add --coverage flag
target_compile_options(runTests PRIVATE -fprofile-arcs -ftest-coverage -O0 -g)
target_link_libraries(runTests PRIVATE -fprofile-arcs -ftest-coverage)
