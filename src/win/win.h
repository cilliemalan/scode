#pragma once

#ifdef SCODE_WINDOWS

#include <stddef.h>

#define UNICODE
#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#ifdef __cplusplus
extern "C"
{
#endif

    wchar_t* scode_make_wchar(const char* a);
    wchar_t* scode_make_wchar_n(const char* a, size_t abytes, size_t *outchars);
    char* scode_make_utf8(const wchar_t* a);
    char* scode_make_utf8_n(const wchar_t* a, size_t achars, size_t *outbytes);
    int scode_utf8_to_wchar(const char* a, size_t abytes, wchar_t* b, size_t bchars);
    int scode_wchar_to_utf8(const wchar_t* a, size_t achars, char* b, size_t bbytes);

    HWND scode_win_create_window(int x, int y, int w, int h, const char* name, LPVOID lParam);

#ifdef __cplusplus
}
#endif
#endif