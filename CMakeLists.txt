cmake_minimum_required(VERSION 3.30.5)

project(Doom-NCurses VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED 17)

add_compile_definitions(
  CMAP256
)

add_subdirectory(doomgeneric)

add_executable(doom
  src/main.c
  src/arguments.c
  src/colour.c
  src/default_palette.c
  src/image.c
  src/input.c
)

find_library(Lib_NCurses ncurses)

target_link_libraries(doom
  doomgeneric
  ${Lib_NCurses}
)
