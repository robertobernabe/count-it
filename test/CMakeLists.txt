enable_testing()

find_package(GTest CONFIG REQUIRED)
include(GoogleTest)

find_package(fmt REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)

add_executable(test_countit test_countit.cpp test_tap_counter.cpp)

target_include_directories(test_countit PRIVATE ${PROJECT_SOURCE_DIR}/src/lib
                                                ${PROJECT_SOURCE_DIR}/include)
# I'm using C++17 in the test
target_compile_features(test_countit PRIVATE cxx_std_17)
target_link_libraries(
  test_countit PRIVATE GTest::gtest GTest::gtest_main
                       nlohmann_json::nlohmann_json fmt::fmt)

# gtest_add_tests(TARGET test_whour)
gtest_discover_tests(test_countit)
