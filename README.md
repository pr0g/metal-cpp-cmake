# metal-cpp-cmake

## Modifications

This repo contains a copy of [Metal-cpp](https://developer.apple.com/metal/cpp/) (current version [metal-cpp_macOS12_iOS15](https://developer.apple.com/metal/cpp/files/metal-cpp_macOS12_iOS15.zip)) with minor modifications/additions by [Alex Betts (gorzin)](https://github.com/gzorin) and myself [Tom Hulton-Harrop (pr0g)](https://github.com/pr0g).

The addition of `CAMetalLayer.hpp` is the work of Alex Betts with a minor addition made by myself (Tom Hulton-Harrop). The changes are explicitly referenced at the top of the modified files (see `// Modifications Notice` in [CAPrivate.hpp](/metal-cpp/QuartzCore/CAPrivate.hpp), [QuatzCore.hpp](/metal-cpp/QuartzCore/QuartzCore.hpp) and [CAMetalLayer.hpp](/metal-cpp/QuartzCore/CAMetalLayer.hpp).

Please see [sdl-metal-cpp-example](https://github.com/gzorin/sdl-metal-cpp-example) by Alex Betts for the original changes and example project.

## Usage

This repository provides an easy to use CMake integration for [Metal-cpp](https://developer.apple.com/metal/cpp/).

To use the library, either install it manually or use `ExternalProject_Add`.

e.g.

```cmake
# third-party CMakeLists.txt file

ExternalProject_Add(
  metal-cpp-cmake
  GIT_REPOSITORY https://github.com/pr0g/metal-cpp-cmake.git
  GIT_TAG a5ef08d590d3ad35c818fe2a43911a15d4f33c25
  BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR}/metal-cpp/build
  INSTALL_DIR ${CMAKE_CURRENT_BINARY_DIR}
  CMAKE_ARGS -D CMAKE_INSTALL_PREFIX=<INSTALL_DIR>)

...

# main CMakeLists.txt file

find_package(metal-cpp-cmake REQUIRED CONFIG)

...

target_link_libraries(
  <target_name> PRIVATE metal-cpp-cmake::metal-cpp-cmake)
```

Remembering to pass the location of the install folder to `-DCMAKE_PREFIX_PATH` when configuring.

```cmake
-DCMAKE_PREFIX_PATH="path/to/metal-cpp/build"
```

or (as this is a header-only/interface library) use `FetchContent`.

```cmake
include(FetchContent)

FetchContent_Declare(
  metal-cpp-cmake
  GIT_REPOSITORY https://github.com/pr0g/metal-cpp-cmake.git
  GIT_TAG 2e855c23e04dd71bcfdd32cca4586cbb3ac89675)

FetchContent_MakeAvailable(metal-cpp-cmake)

...

target_link_libraries(<target_name> PRIVATE metal-cpp-cmake)
```

It's then possible to include the required files as you normally would (described [here](https://developer.apple.com/metal/cpp/)).

```c++
#define NS_PRIVATE_IMPLEMENTATION
#define CA_PRIVATE_IMPLEMENTATION
#define MTL_PRIVATE_IMPLEMENTATION
#include <Foundation/Foundation.hpp>
#include <Metal/Metal.hpp>
#include <QuartzCore/QuartzCore.hpp>
```
