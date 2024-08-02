cmake_minimum_required(VERSION 3.7)

project(Custom_iterator
    VERSION 1.0.0
    LANGUAGES CXX
    DESCRIPTION "Custom_iterator Tests"
)

################################################################################
# Library
################################################################################
find_package(GTest REQUIRED)

################################################################################
# Sources
################################################################################
file(GLOB_RECURSE src_cpp ${CMAKE_SOURCE_DIR}/src/*.cpp)
file(GLOB_RECURSE test_cpp *.cpp)
file(GLOB_RECURSE test_h *.h)

add_executable(${PROJECT_NAME} ${test_cpp} ${test_h} ${src_cpp})
# add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})
add_test(NAME ${PROJECT_NAME} COMMAND $<TARGET_FILE:${PROJECT_NAME}>)

target_include_directories(${PROJECT_NAME} PRIVATE
  ${PROJECT_SOURCE_DIR}
  ${PROJECT_BINARY_DIR}
  ${CMAKE_SOURCE_DIR}/include
)
target_link_libraries(${PROJECT_NAME} 
  PRIVATE
    GTest::GTest GTest::Main
)

################################################################################
# Compilation flags
################################################################################
include (${CMAKE_SOURCE_DIR}/cmake/compilation_flags.cmake)

# ################################################################################
# # Resources
# ################################################################################
#