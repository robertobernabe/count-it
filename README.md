# count-it
## Building
Assuming you have vcpkg/ as submodule next to your git root, the following will work:

    cmake -B build -S . -DCMAKE_TOOLCHAIN_FILE=$VCPKG_ROOT/scripts/buildsystems/vcpkg.cmake
    cmake --build build

Change out the environment variable syntax for each system, and this should work everywhere.