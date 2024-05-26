cmake_minimum_required(VERSION 3.27)

project(Banking)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(BUILD_TESTS "Build tests" OFF)

file(GLOB SOURCES "BankAccount.cpp" , "ConceptualExample01.cpp" , "ConceptualExample02.cpp" , "Program.cpp")
add_executable(${PROJECT_NAME} ${SOURCES})

if(BUILD_TESTS)
  enable_testing()
  add_subdirectory(third-party/gtest)
  file(GLOB TEST_SOURCES "tests.cpp")
  add_executable(check ${TEST_SOURCES})
  target_link_libraries(check gtest_main)
  add_test(NAME check COMMAND check)
endif()

option(PACK "pack" OFF)

include(CPack.cmake)