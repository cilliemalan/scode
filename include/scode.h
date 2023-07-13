#pragma once

#ifdef __cplusplus
extern "C"
{
#endif
    typedef const void *scode_brush_t;
    typedef const void *scode_pen_t;
    typedef const void *scode_font_t;
    typedef struct scode *scode_context_t;

    typedef struct scode_point
    {
        int x;
        int y;
    } scode_point_t;

    typedef unsigned long scode_color_t;

    typedef struct scode_size
    {
        int w;
        int h;
    } scode_size_t;

    typedef struct scode_rectangle
    {
        int x;
        int y;
        int w;
        int h;
    } scode_rectangle_t;

    typedef struct scode_backend *scode_backend_t;

#ifdef SCODE_BACKEND
    struct scode_backend
    {
        int (*fill_rect)(scode_context_t ctx, const scode_rectangle_t *rectangle, scode_brush_t brush);
        int (*draw_line)(scode_context_t ctx, const scode_point_t *start, const scode_point_t *end, scode_pen_t pen);
        int (*draw_text)(scode_context_t ctx, const scode_point_t *start, const char *, scode_brush_t brush);

        void (*free)(scode_backend_t me);
    };
#endif

    // create a new scode instance using the given backend
    scode_context_t scode_new(scode_backend_t backend);
    // free a scode instance
    void scode_free(scode_context_t ctx);

    // tell scode to paint
    void scode_paint(scode_context_t ctx, int key);
    // tell scode a key went down
    void scode_keydown(scode_context_t ctx, int key);
    // tell scode a key went up
    void scode_keyup(scode_context_t ctx, int key);
    // tell scode the mouse moved
    void scode_mousemove(scode_context_t ctx, const scode_point_t *pos);
    // tell scode a mouse button was pressed
    void scode_mousedown(scode_context_t ctx, int key);
    // tell scode a mouse button was released
    void scode_mouseup(scode_context_t ctx, int key);
    // tell scode the mouse was scrolled
    void scode_mousescroll(scode_context_t ctx, int delta);
    // tell scode the drawing area (i.e. window) was resized
    void scode_resize(scode_context_t ctx, const scode_size_t* size);

#ifdef __cplusplus
}
#endif

#include "scode_direct2d.h"
