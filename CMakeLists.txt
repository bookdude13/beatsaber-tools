cmake_minimum_required(VERSION 3.14)

include(FetchContent)

# set the project name
project(BeatSaberTools)

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

# Configure Source & Binary Directories
SET (PROJECT_ROOT "${PROJECT_SOURCE_DIR}")
SET (PROJECT_SOURCE_DIR "${PROJECT_SOURCE_DIR}/src")
SET (PROJECT_BINARY_DIR "${PROJECT_BINARY_DIR}/bin")
SET (PROJECT_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/include")
MESSAGE ("Source path: ${PROJECT_SOURCE_DIR}")
MESSAGE ("Binary path: ${PROJECT_BINARY_DIR}")
MESSAGE ("Include path: ${PROJECT_INCLUDE_DIR}")

# Includes
include_directories(
    ${PROJECT_INCLUDE_DIR},
    ${PROJECT_ROOT}/build/_deps/json-src/include
)

add_executable(BeatSaberTools ${PROJECT_SOURCE_DIR}/main.cpp)
