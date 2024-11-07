cmake_minimum_required(VERSION 3.22)
project(wxWidgetsSampleProject)

add_subdirectory(wxWidgets-3.2.6)
add_executable(wxWidgetsSampleProject main.cpp)

target_link_libraries(wxWidgetsSampleProject wx::net wx::core wx::base)