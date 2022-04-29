cmake_minimum_required(VERSION 3.22)
project(WaterCalculation)


set(CMAKE_CXX_STANDARD 14)

add_executable(WaterCalculation Cat.cpp WaterContainerCalculator.cpp WaterContainerCalculator.h Storage.cpp Storage.h CalculateWater.cpp WaterCalculatorTest.cpp WaterCalculatorTest.h Point.cpp Point.h CalculateWater.h)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/e2239ee6043f73722e7aa812a459f54a28552929.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)


enable_testing()

include(GoogleTest)

target_link_libraries(
        WaterCalculation
        gtest_main
)
