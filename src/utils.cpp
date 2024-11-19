#include <SDL3/SDL.h>

void draw_background(SDL_Renderer *renderer, int w, int h)
{
    SDL_Color col[2] = {
        { 0x66, 0x66, 0x66, 0xff },
        { 0x99, 0x99, 0x99, 0xff },
    };
    int i, x, y;
    SDL_FRect rect;
    const int dx = 8, dy = 8;

    rect.w = (float)dx;
    rect.h = (float)dy;
    for (y = 0; y < h; y += dy) {
        for (x = 0; x < w; x += dx) {
            /* use an 8x8 checkerboard pattern */
            i = (((x ^ y) >> 3) & 1);
            SDL_SetRenderDrawColor(renderer, col[i].r, col[i].g, col[i].b, col[i].a);

            rect.x = (float)x;
            rect.y = (float)y;
            SDL_RenderFillRect(renderer, &rect);
        }
    }
}

