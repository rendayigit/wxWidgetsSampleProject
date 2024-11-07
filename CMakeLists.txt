cmake_minimum_required(VERSION 3.22)
project(wxWidgetsSampleProject)

# Set target directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/bin/)

add_subdirectory(deps/wxWidgets-3.2.6)
add_executable(wxWidgetsSampleProject src/main.cpp)

target_link_libraries(wxWidgetsSampleProject wx::net wx::core wx::base)