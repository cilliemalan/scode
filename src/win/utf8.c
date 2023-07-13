#include "win.h"
#include <stdlib.h>
#include <malloc.h>

wchar_t *scode_make_wchar(const char *a)
{
    if (!a)
        return NULL;

    if (!a[0])
    {
        wchar_t *r = calloc(1, sizeof(wchar_t));
        return r;
    }

    int na = (int)strlen(a);

    int nb = scode_utf8_to_wchar(a, na, NULL, 0);
    if (nb == 0)
        return NULL;

    wchar_t *b = malloc((nb + 1) * sizeof(wchar_t));
    if (!b)
        return NULL;
    b[nb] = 0;

    int r = scode_utf8_to_wchar(a, na, b, nb);
    if (r == nb)
        return b;

    free(b);
    return NULL;
}

wchar_t *scode_make_wchar_n(const char *a, size_t na, size_t *outchars)
{
    if (!a)
        return NULL;

    if (na == 0)
    {
        wchar_t *r = calloc(1, sizeof(wchar_t));
        return r;
    }

    int nb = scode_utf8_to_wchar(a, na, NULL, 0);
    if (nb == 0)
        return NULL;

    // note: ALWAYS zero terminate
    wchar_t *b = malloc((nb + 1) * sizeof(wchar_t));
    if (!b)
        return NULL;
    b[nb] = 0;

    int r = scode_utf8_to_wchar(a, na, b, nb);
    if (r == nb)
    {
        if (outchars)
            *outchars = nb;
        return b;
    }

    free(b);
    return NULL;
}

char *scode_make_utf8(const wchar_t *a)
{
    if (!a)
        return NULL;

    if (!a[0])
    {
        char *r = calloc(1, 1);
        return r;
    }

    int na = (int)wcslen(a);

    int nb = scode_wchar_to_utf8(a, na, NULL, 0);
    if (nb == 0)
        return NULL;

    char *b = malloc(nb + 1);
    if (!b)
        return NULL;
    b[nb] = 0;

    int r = scode_wchar_to_utf8(a, na, b, nb);
    if (r == nb)
        return b;

    free(b);
    return NULL;
}

char *scode_make_utf8_n(const wchar_t *a, size_t na, size_t *outbytes)
{
    if (!a)
        return NULL;

    if (na == 0)
    {
        char *r = calloc(1, 1);
        return r;
    }

    int nb = scode_wchar_to_utf8(a, na, NULL, 0);
    if (nb == 0)
        return NULL;

    // note: ALWAYS zero terminate
    char *b = malloc(nb + 1);
    if (!b)
        return NULL;
    b[nb] = 0;

    int r = scode_wchar_to_utf8(a, na, b, nb);
    if (r == nb)
    {
        if (outbytes)
            *outbytes = nb;
        return b;
    }

    free(b);
    return NULL;
}

int scode_utf8_to_wchar(const char *a, size_t na, wchar_t *b, size_t nb)
{
    return MultiByteToWideChar(CP_UTF8, 0, a, (int)na, b, (int)nb);
}

int scode_wchar_to_utf8(const wchar_t *a, size_t na, char *b, size_t nb)
{
    return WideCharToMultiByte(CP_UTF8, 0, a, (int)na, b, (int)nb, NULL, NULL);
}
