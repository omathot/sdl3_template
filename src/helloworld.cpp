#define SDL_MAIN_USE_CALLBACKS

#include <SDL3/SDL_hints.h>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3_image/SDL_image.h>
#include <string>
#include <iostream>

// those includes are found on compilation through cmake. avoiding relative path solutions such as: ../include/<x>. Works with LSP through .clangd flags
#include "AppState.hpp"
#include "Transform.hpp"
#include "Vector2.hpp"


SDL_FRect drect;

void draw_background(SDL_Renderer *renderer, int w, int h, long int x);

// called once before everything else
// can set a pointer to appstate if want to pass to functions
SDL_AppResult SDL_AppInit(void **appstate, int argc, char **argv) {
  // tests
  Vec2 tmp = Vec2(12.0f, 4.0f);
  std::cout << tmp << std::endl;
  Vec2 comparison = Vec2(0.0f, 23.0f);
  float angle = tmp.angleWith(comparison);
  Vec2 normal = tmp.normalize();
  std::cout << "angle: " << angle << ", normal vector: " << normal << std::endl;






  // init start  
  AppState *state = new AppState();
  if (!state) {
    SDL_Log("Error: Could not allocate AppState: %s\n", SDL_GetError());
    return SDL_APP_FAILURE;
  }

  *appstate = state;
  SDL_Log("SDL3 appstate initialized\n");

  return SDL_APP_CONTINUE;
}

// called over and over, heart of the game. render frame here.
SDL_AppResult SDL_AppIterate(void *appstate) {
  AppState *state = (AppState *)appstate;
  if (!state) {
    SDL_Log("Failed to retrieve appstat\n");
    return SDL_APP_FAILURE;
  }
  state->updateCount();
  Player *player = state->getPlayer();
  if (!player) {
    SDL_Log("Error: Failed to retrieve Player\n");
    return SDL_APP_FAILURE;
  }

  float w, h;
  SDL_GetTextureSize(player->getCurrentFrame(), &w, &h);
  SDL_RenderClear(state->getRenderer());
  // draw_background(state->getRenderer(), w, h, state->getCount());

  drect.h = 32;
  drect.w = 32;
  drect.x = state->getCount();
  SDL_RenderTexture(state->getRenderer(), player->getCurrentFrame(), NULL, &drect);
  SDL_RenderPresent(state->getRenderer());

  SDL_Delay(state->getPlayer()->getAnimation("walk down").getDelay());
  player->updateFrameIndex();
  return SDL_APP_CONTINUE;
}

// called everytime an SDL_event is received, event handling goes here.
SDL_AppResult SDL_AppEvent(void *appstate, SDL_Event *event) {
  AppState *state = (AppState *)appstate;
  switch (event->type) {
    case SDL_EVENT_QUIT:
      SDL_Log("SDL3 event quit\n");
      state->terminate();
      return SDL_APP_SUCCESS;
    case SDL_EVENT_KEY_DOWN:
      if (event->key.key == SDLK_ESCAPE) {
        SDL_Log("SDL3 escape input\n");
        state->terminate();
        return SDL_APP_SUCCESS;
      }
  }

  return SDL_APP_CONTINUE;
}

void SDL_AppQuit(void *appstate, SDL_AppResult result) {
  AppState *state = (AppState *)appstate;

  SDL_Log("SDL3 shutdown\n");
  SDL_DestroyRenderer(state->getRenderer());
  SDL_DestroyWindow(state->getWindow());
  SDL_Log("result: %d\n", result);
}
