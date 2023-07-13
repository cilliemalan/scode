#pragma once

#ifdef SCODE_DIRECT2D
#ifdef __cplusplus
extern "C"
{
#endif

    scode_backend_t scode_direct2d_for_window(struct HWND__* window);
    scode_backend_t scode_direct2d_create_window();

#ifdef __cplusplus
}
#endif
#endif