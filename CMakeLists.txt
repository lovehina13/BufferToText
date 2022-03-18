cmake_minimum_required(VERSION 2.6)

project(CppTools)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(CppTools SHARED BufferTextConversions.cpp RealNumbersComparisons.cpp)

install(TARGETS CppTools DESTINATION lib)
install(FILES Bimap.h BufferTextConversions.h RealNumbersComparisons.h DESTINATION include/CppTools)
