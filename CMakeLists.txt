cmake_minimum_required(VERSION 3.27)

project(Banking)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(BankAccount ${CMAKE_CURRENT_SOURCE_DIR}/BankAccount.cpp)
add_library(ConceptualExample01 ${CMAKE_CURRENT_SOURCE_DIR}/ConceptualExample01.cpp)
add_library(ConceptualExample02 ${CMAKE_CURRENT_SOURCE_DIR}/ConceptualExample02.cpp)

add_executable(Shapes ${CMAKE_CURRENT_SOURCE_DIR}/Program.cpp)

target_compile_definitions(ConceptualExample02 PRIVATE
    $<$<PLATFORM_ID:Windows>:USE_CTIME_S>
    $<$<PLATFORM_ID:Linux>:USE_CTIME_R>
    $<$<PLATFORM_ID:Darwin>:USE_CTIME_R>
)

target_link_libraries(Shapes BankAccount ConceptualExample01 ConceptualExample02)