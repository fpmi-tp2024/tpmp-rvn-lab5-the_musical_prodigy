cmake_minimum_required(VERSION 3.22)
project(YourProjectName)

# Find OpenSSL package
find_package(OpenSSL REQUIRED)

# Include directories for OpenSSL headers
include_directories(${OPENSSL_INCLUDE_DIR})

# Add SQLiteCpp subdirectory
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/SQLiteCpp)

# Collect model, view, and controller source files
file(GLOB MODEL_SOURCES src/Model/*.cpp)
file(GLOB VIEW_SOURCES src/View/*.cpp)
file(GLOB CONTROLLER_SOURCES src/Controller/*.cpp)

# Add your source files and create the executable
add_executable(solution MusicSalon.cpp ${MODEL_SOURCES} ${VIEW_SOURCES} ${CONTROLLER_SOURCES})

# Link against libraries: SQLiteCpp, sqlite3, pthread, dl, and OpenSSL
target_link_libraries(solution PRIVATE SQLiteCpp sqlite3 pthread dl ${OPENSSL_LIBRARIES})
