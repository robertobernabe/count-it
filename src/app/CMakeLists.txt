add_executable(countit main.cpp)
target_include_directories(countit PRIVATE ${PROJECT_SOURCE_DIR}/include)
target_compile_features(countit PRIVATE cxx_std_17)
find_package(fmt REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)
find_package(CLI11 CONFIG REQUIRED)

target_link_libraries(countit PRIVATE fmt::fmt nlohmann_json::nlohmann_json
                                    CLI11::CLI11)
