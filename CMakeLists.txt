cmake_minimum_required(VERSION 3.14)

if(NOT DEFINED VCPKG_ROOT)
  set(VCPKG_ROOT
      ${CMAKE_CURRENT_SOURCE_DIR}/vcpkg
      CACHE PATH "Path to vcpkg directory")
endif()

set(VCPKG_APPINSTALL_DEPS ON)
set(VCPKG_APPLOCAL_DEPS_INSTALL ON)
set(X_VCPKG_APPLOCAL_DEPS_INSTALL ON)

if(DEFINED VCPKG_ROOT)
  set(CMAKE_TOOLCHAIN_FILE
      "${VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake"
      CACHE PATH "Path to vcpkg toolchain")
  if(NOT EXISTS "${CMAKE_TOOLCHAIN_FILE}")
    message(
      FATAL_ERROR
        "Invalid CMAKE_TOOLCHAIN_FILE specified (${CMAKE_TOOLCHAIN_FILE}, ${VCPKG_ROOT}); please specify an absolute path"
    )
  endif()
endif()

set(APP_LOW_NAME "countit")
set(APP_URL "https://github.com/robertobernabe/countit")
set(APP_EMAIL "hello@fschaeffeler.de")
set(APP_COMPANY "Florian Schäffeler")

project(
  countit
  VERSION 0.0.1
  HOMEPAGE_URL ${APP_URL})
option(USE_NSIS "Use NSIS generator to produce installer" OFF)
include(GNUInstallDirs)

set(APP_VERSION ${CMAKE_PROJECT_VERSION})

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/include/countit/version.hpp.in
               ${CMAKE_CURRENT_SOURCE_DIR}/include/countit/version.hpp)

add_subdirectory(src)
include(CTest)
add_subdirectory(test)
