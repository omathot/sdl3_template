#include "SDL3/SDL_render.h"
#define SDL_MAIN_USE_CALLBACKS

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3_image/SDL_image.h>
#include <string>
#include <vector>

// those includes are found on compilation through cmake. avoiding relative path solutions such as: ../include/<x>. Works with LSP through .clangd flags
#include "AppState.h"

void draw_background(SDL_Renderer *renderer, int w, int h);

// called once before everything else
// can set a pointer to appstate if want to pass to functions
SDL_AppResult SDL_AppInit(void **appstate, int argc, char **argv) {
  //
  AppState *state = (AppState *)SDL_malloc(sizeof(AppState));
  if (!state) {
    SDL_Log("Error: Could not allocate AppState: %s\n", SDL_GetError());
    return SDL_APP_FAILURE;
  }
  SDL_memset(state, 0, sizeof(AppState));
  state->_animations = (SpriteAnim *)SDL_malloc(sizeof(SpriteAnim));
  if (!state->_animations) {
    SDL_Log("Error: Could not allocate state animation: %s\n", SDL_GetError());
    SDL_free(state);
    return SDL_APP_FAILURE;
  }
  SDL_memset(state->_animations, 0, sizeof(SpriteAnim));
  int result = SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS);
  if (result < 0) {
    SDL_Log("SDL_Init() error: %s\n", SDL_GetError());
    return SDL_APP_FAILURE;
  }

  state->_window = SDL_CreateWindow("Hello world", 800, 600, 0);
  if (state->_window == nullptr) {
    SDL_Log("SDL_CreateWindow error: %s\n", SDL_GetError());
    return SDL_APP_FAILURE;
  }

  state->_renderer = SDL_CreateRenderer(state->_window, nullptr);
  if (state->_renderer == nullptr) {
    SDL_Log("SDL_CreateRenderer error: %s\n", SDL_GetError());
    return SDL_APP_FAILURE;
  }


  state->_animations->_anim = IMG_LoadAnimation("../assets/layers_test.gif");
  if (!state->_animations->_anim) {
    SDL_Log("Error: Could not load anim: %s\n", SDL_GetError());
    return SDL_APP_FAILURE;
  }
  state->_animations->_textures = (SDL_Texture **)SDL_calloc(state->_animations->_anim->count, sizeof(state->_animations->_textures));
  if (!state->_animations->_textures) {
    SDL_Log("Error: Could not allocate textures: %s\n", SDL_GetError());
    IMG_FreeAnimation(state->_animations->_anim);
  }
  for (int i = 0; i < state->_animations->_anim->count; i++) {
    state->_animations->_textures[i] = SDL_CreateTextureFromSurface(state->_renderer, state->_animations->_anim->frames[i]);
  }
  state->_animations->_current_frame = 0;
  state->_animations->_delay = 0;

  state->_running = true;
  *appstate = state;
  SDL_Log("SDL3 appstate initialized\n");

  return SDL_APP_CONTINUE;
}

// called over and over, heart of the game. render frame here.
SDL_AppResult SDL_AppIterate(void *appstate) {
  AppState *state = (AppState *)appstate;


  float w, h;
  SDL_GetTextureSize(state->_animations->_textures[state->_animations->_current_frame], &w, &h);
  draw_background(state->_renderer, w, h);
  SDL_RenderTexture(state->_renderer, state->_animations->_textures[state->_animations->_current_frame], NULL, NULL);
  SDL_RenderPresent(state->_renderer);

  if (state->_animations->_anim->delays[state->_animations->_current_frame]) {
    state->_animations->_delay = state->_animations->_anim->delays[state->_animations->_current_frame];
  } else {
    state->_animations->_delay = 100;
  }
  SDL_Delay(state->_animations->_delay);
  state->_animations->_current_frame = (state->_animations->_current_frame+ 1) % state->_animations->_anim->count;
  return SDL_APP_CONTINUE;
}

// called everytime an SDL_event is received, event handling goes here.
SDL_AppResult SDL_AppEvent(void *appstate, SDL_Event *event) {
  AppState *state = (AppState *)appstate;
  switch (event->type) {
    case SDL_EVENT_QUIT:
      SDL_Log("SDL3 event quit\n");
      state->_running = false;
      return SDL_APP_SUCCESS;
    case SDL_EVENT_KEY_DOWN:
      if (event->key.key == SDLK_ESCAPE) {
        SDL_Log("SDL3 escape input\n");
        state->_running = false;
        return SDL_APP_SUCCESS;
      }
  }

  return SDL_APP_CONTINUE;
}

void SDL_AppQuit(void *appstate, SDL_AppResult result) {
  AppState *state = (AppState *)appstate;
  for (int i = 0; i < state->_animations->_anim->count; i++) {
    SDL_DestroyTexture(state->_animations->_textures[i]);
  }
  IMG_FreeAnimation(state->_animations->_anim);

  SDL_Log("SDL3 shutdown\n");
  SDL_DestroyRenderer(state->_renderer);
  SDL_DestroyWindow(state->_window);
  SDL_Log("result: %d", result);
}

