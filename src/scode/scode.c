#include "private.h"

scode_context_t scode_new(scode_backend_t backend)
{
    scode_context_t ctx = malloc(sizeof(struct scode));
    return ctx;
}

void scode_free(scode_context_t ctx)
{
    free(ctx);
}

void scode_paint(scode_context_t ctx, int key)
{

}

void scode_keydown(scode_context_t ctx, int key)
{

}

void scode_keyup(scode_context_t ctx, int key)
{

}

void scode_mousemove(scode_context_t ctx, const scode_point_t *pos)
{

}

void scode_mousedown(scode_context_t ctx, int key)
{

}

void scode_mouseup(scode_context_t ctx, int key)
{

}

void scode_mousescroll(scode_context_t ctx, int delta)
{

}

void scode_resize(scode_context_t ctx, const scode_size_t* size)
{

}
