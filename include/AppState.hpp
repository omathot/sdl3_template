#pragma once

#include <SDL3/SDL.h>
#include "Player.hpp"
#include "SDL3/SDL_render.h"

class AppState {
public:
  AppState();
  ~AppState();
  AppState(const AppState &src);
  AppState &operator=(const AppState &src);

  void updateCount();
  void terminate();

  long int getCount() const;
  SDL_Renderer *getRenderer() const;
  SDL_Window *getWindow() const;
  bool isRunning() const;
  Player *getPlayer() const;

  
private:
  long int _count;
  bool _imgui_init;

  SDL_Window *_window;
  SDL_Renderer *_renderer;
  bool _running;
  Player *_player;

};
