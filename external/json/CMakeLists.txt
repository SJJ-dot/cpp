add_library(json json.hpp json.cpp)

target_include_directories(json PUBLIC ${CMAKE_CURRENT_LIST_DIR})