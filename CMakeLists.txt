cmake_minimum_required(VERSION 2.6)

project(CppTools)

add_library(CppTools SHARED BufferTextConversions.cpp RealNumbersComparisons.cpp)

install(TARGETS CppTools DESTINATION lib)
install(FILES BufferTextConversions.h RealNumbersComparisons.h DESTINATION include/CppTools)
