cmake_minimum_required(VERSION 3.15)
project(ais2203_exercise2)

set(CMAKE_CXX_STANDARD 17)

############################ DEPENDENCIES

# Download Catch2 unit-test framework
Include(FetchContent)
FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v2.13.8
)
FetchContent_MakeAvailable(Catch2)

# Download nlohmann/json library
Include(FetchContent)
FetchContent_Declare(
        nlohmann_json
        GIT_REPOSITORY https://github.com/nlohmann/json.git
        GIT_TAG v3.11.2
)
FetchContent_MakeAvailable(nlohmann_json)

##############################


add_subdirectory(src)

enable_testing()
add_subdirectory(test)
