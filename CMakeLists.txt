cmake_minimum_required(VERSION 3.0.0)
project(splay VERSION 0.1.0)

include(CTest)
enable_testing()

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
add_executable(splay main.cpp splay_node.h splay.h)
add_executable(test1 test1.cpp splay_node.h splay.h)
add_executable(test2 test2.cpp splay_node.h splay.h)
add_executable(test3 test3.cpp splay_node.h splay.h)
add_executable(test4 test4.cpp splay_node.h splay.h)
add_executable(test5 test5.cpp splay_node.h splay.h)


add_test(NAME test_insert COMMAND test1)
add_test(NAME test_find1 COMMAND test2)
add_test(NAME test_find2 COMMAND test3)
add_test(NAME test_remove_1 COMMAND test4)
add_test(NAME test_remove_all COMMAND test5)


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)