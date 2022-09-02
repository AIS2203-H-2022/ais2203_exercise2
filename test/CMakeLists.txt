
add_executable(test1 test1.cpp)
add_test(NAME test1 COMMAND test1)
target_link_libraries(test1 PUBLIC exercise2lib Catch2::Catch2)
target_compile_definitions(test1 PRIVATE DATA_DIR="${CMAKE_CURRENT_SOURCE_DIR}/data")
