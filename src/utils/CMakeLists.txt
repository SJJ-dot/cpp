add_library(utils "")

target_sources(utils
        PRIVATE
        ByteBuf.cpp
        Logger.cpp
        TimeUtil.cpp
        PUBLIC
        ByteBuf.h
        Logger.h
        TimeUtil.h
        )

target_include_directories(utils PUBLIC ${CMAKE_CURRENT_LIST_DIR})