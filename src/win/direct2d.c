#define WIN32_LEAN_AND_MEAN
#define UNICODE

#include <Windows.h>

#include <d2d1.h>
#include <d2d1helper.h>
//#include <dwrite.h>
#include <wincodec.h>


#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <wchar.h>
#include <math.h>

#define SCODE_BACKEND
#include "scode.h"

typedef interface IDWriteFactory IDWriteFactory;

struct scode_backend_d2d {
    struct scode_backend b;
    
    ID2D1Factory *pd2df;
    IWICImagingFactory *wicf;
    IDWriteFactory *dwf;
};
