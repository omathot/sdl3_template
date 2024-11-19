#pragma once

#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

typedef struct SpriteAnim {
  // IMG_Animation *_anim;
  SDL_Texture **_textures;
  int _delay;
  int _current_frame;
} SpriteAnim;

typedef struct AppState {
  SDL_Window *_window;
  SDL_Renderer *_renderer;
  bool _running;
  SpriteAnim *_animations;
} AppState;
