
add_subdirectory(utils)


add_executable(demo main.cpp)


target_link_libraries(demo
        PRIVATE
        json
        base64
        utils
        )