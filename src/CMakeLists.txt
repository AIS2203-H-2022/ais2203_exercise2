
add_library(exercise2lib exercise/json_parser.cpp)
target_include_directories(exercise2lib PUBLIC "${CMAKE_SOURCE_DIR}/include")
target_link_libraries(exercise2lib PRIVATE nlohmann_json::nlohmann_json)
