#include "AppState.hpp"
#include "SDL3/SDL_render.h"

AppState::AppState() {
  SDL_Log("AppState constructor called\n");
  int result = SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS);
  if (result < 0) {
    SDL_Log("SDL_Init() error: %s\n", SDL_GetError());
  }


  this->_window = SDL_CreateWindow("Hello world", 800, 600, 0);
  if (this->_window == nullptr) {
    SDL_Log("SDL_CreateWindow error: %s\n", SDL_GetError());
  }

  this->_renderer = SDL_CreateRenderer(this->_window, nullptr);
  if (this->_renderer == nullptr) {
    SDL_Log("SDL_CreateRenderer error: %s\n", SDL_GetError());
  }

  this->_player = new Player();
  if (!this->_player) {
    SDL_Log("Error: Could not construct Player: %s\n", SDL_GetError());
  }
  this->_player->loadAnimations(this->_renderer);

  this->_running = true;
}

AppState::AppState(const AppState &src) {
  if (this != &src) {
    this->_player = src.getPlayer();
    this->_renderer = src.getRenderer();
    this->_running = src.isRunning();
    this->_window = src.getWindow();
  }
}

AppState &AppState::operator=(const AppState &src) {
  if (this != &src) {
    this->_player = src.getPlayer();
    this->_renderer = src.getRenderer();
    this->_running = src.isRunning();
    this->_window = src.getWindow();
  }
  return *this;
}

AppState::~AppState() {
  if (this->_player)
    delete this->_player;
}

SDL_Renderer *AppState::getRenderer() const {
  return this->_renderer;
}
SDL_Window *AppState::getWindow() const {
  return this->_window;
}

bool AppState::isRunning() const {
  return this->_running;
}

Player *AppState::getPlayer() const {
  return this->_player;
}

void AppState::terminate() {
  this->_running = false;
}
