add_library(base64 "")

target_sources(base64
        PRIVATE
        base64.cpp
        PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/base64.h
        )


target_include_directories(base64 PUBLIC ${CMAKE_CURRENT_LIST_DIR})