if(MSVC)
  set(OPTIONS WIN32)
endif(MSVC)

add_executable(countit_gui ${OPTIONS} main.cpp)
target_include_directories(countit_gui PRIVATE ${PROJECT_SOURCE_DIR}/include
                                               ${wxWidgets_INCLUDE_DIRS})
target_compile_definitions(countit_gui PRIVATE WXUSINGDLL)

target_compile_features(countit_gui PRIVATE cxx_std_17)
find_package(fmt REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)
find_package(CLI11 CONFIG REQUIRED)
find_package(wxWidgets REQUIRED)

target_link_libraries(countit_gui PRIVATE fmt::fmt nlohmann_json::nlohmann_json
                                          CLI11::CLI11 ${wxWidgets_LIBRARIES})
