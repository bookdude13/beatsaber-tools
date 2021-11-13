cmake_minimum_required(VERSION 3.14)

include(FetchContent)

# Set the project name
project(bs-tools)

# Configure Source & Binary Directories
SET (PROJECT_ROOT "${PROJECT_SOURCE_DIR}")
SET (PROJECT_SOURCE_DIR "${PROJECT_ROOT}/src")
SET (PROJECT_TEST_DIR "${PROJECT_ROOT}/test")
SET (PROJECT_BINARY_DIR "${PROJECT_BINARY_DIR}/bin")
SET (PROJECT_INCLUDE_DIR "${PROJECT_ROOT}/include")
MESSAGE ("Source path: ${PROJECT_SOURCE_DIR}")
MESSAGE ("Binary path: ${PROJECT_BINARY_DIR}")
MESSAGE ("Include path: ${PROJECT_INCLUDE_DIR}")
MESSAGE ("Test path: ${PROJECT_TEST_DIR}")

# Setup source files
set(LIB_SOURCES
  ${PROJECT_SOURCE_DIR}/CustomSongInfo.cpp
  ${PROJECT_SOURCE_DIR}/SongHashDataRepository.cpp
  ${PROJECT_SOURCE_DIR}/SongService.cpp
)

set(TEST_SOURCES
  ${PROJECT_TEST_DIR}/SongHashDataRepositoryTest.cpp
  ${PROJECT_TEST_DIR}/SongServiceTest.cpp
)

# Use C++ 17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Dependencies
## json
FetchContent_Declare(json
  GIT_REPOSITORY https://github.com/ArthurSonzogni/nlohmann_json_cmake_fetchcontent
  GIT_TAG v3.7.3)

FetchContent_GetProperties(json)
if(NOT json_POPULATED)
  FetchContent_Populate(json)
  add_subdirectory(${json_SOURCE_DIR} ${json_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()

## googletest
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
### For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)


# Main library
add_library(${PROJECT_NAME}-lib STATIC ${LIB_SOURCES})

# Includes
target_include_directories(${PROJECT_NAME}-lib PUBLIC
    "${PROJECT_INCLUDE_DIR}",
    "${PROJECT_ROOT}/build/_deps/json-src/include"
)

# Main executable
add_executable(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/main.cpp)
target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}-lib)

# Tests
enable_testing()

add_executable(${PROJECT_NAME}-test ${TEST_SOURCES})
target_link_libraries(${PROJECT_NAME}-test gtest_main ${PROJECT_NAME}-lib)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME}-test)
