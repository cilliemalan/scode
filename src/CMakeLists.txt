


add_library(scode scode/scode.c)
target_include_directories(scode PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include)

add_library(scode_direct2d
    win/direct2d.c
    win/utf8.c
    win/win.c)
target_link_libraries(scode_direct2d PUBLIC scode)
target_compile_definitions(scode_direct2d PUBLIC SCODE_DIRECT2D SCODE_WINDOWS)
