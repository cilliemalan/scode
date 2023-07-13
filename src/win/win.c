#include "win.h"

EXTERN_C IMAGE_DOS_HEADER __ImageBase;
#define HINST_THISCOMPONENT ((HINSTANCE)&__ImageBase)

static LRESULT scode_win_wndproc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    return 0;
}

HWND scode_win_create_window(int x, int y, int w, int h, const char *name, LPVOID lParam)
{
    WNDCLASSEX wcex = {sizeof(WNDCLASSEX)};
    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = scode_win_wndproc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = sizeof(LONG_PTR);
    wcex.hInstance = HINST_THISCOMPONENT;
    wcex.hbrBackground = NULL;
    wcex.lpszMenuName = NULL;
    wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
    wcex.lpszClassName = L"scode_windows";

    RegisterClassEx(&wcex);

    wchar_t *wname = scode_make_wchar(name);
    HWND hWnd = CreateWindow(
        L"D2DDemoApp",
        wname,
        WS_OVERLAPPEDWINDOW | WS_VISIBLE,
        x,
        y,
        w,
        h,
        NULL,
        NULL,
        HINST_THISCOMPONENT,
        lParam);

    free(wname);

    return hWnd;
}
