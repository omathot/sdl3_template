#include "AppState.hpp"
#include "SDL3/SDL_error.h"
#include "SDL3/SDL_render.h"
#include "imgui_impl_sdl3.h"
#include "imgui_impl_sdlrenderer3.h"
#include <imgui/imgui.h>

AppState::AppState() {
  SDL_Log("AppState constructor called\n");
  int result = SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS);
  if (result < 0) {
    SDL_Log("SDL_Init() error: %s\n", SDL_GetError());
  }
  this->_count = 0;
  this->_imgui_init = false;
  IMGUI_CHECKVERSION();
  ImGui::CreateContext();
  ImGui::StyleColorsDark();  

  this->_window = SDL_CreateWindow("Hello world", 800, 600, 0);
  if (this->_window == nullptr) {
    SDL_Log("SDL_CreateWindow error: %s\n", SDL_GetError());
  }

  this->_renderer = SDL_CreateRenderer(this->_window, nullptr);
  if (this->_renderer == nullptr) {
    SDL_Log("SDL_CreateRenderer error: %s\n", SDL_GetError());
  }

  bool render_hint = SDL_SetHint("SDL_HINT_RENDER_SCALE_MODE", "nearest");
  if (!render_hint) {
    SDL_Log("Error: Failed to give render hint: %s\n", SDL_GetError());
  }

  if (!ImGui_ImplSDL3_InitForSDLRenderer(this->_window, this->_renderer)) {
    SDL_Log("Failed to init ImGui SDL3\n");
  }
  if (!ImGui_ImplSDLRenderer3_Init(this->_renderer)) {
    SDL_Log("Failed to init ImGui SDL3 Renderer");
  }
  this->_imgui_init = true;


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
    this->_imgui_init = src._imgui_init;
  }
}

AppState &AppState::operator=(const AppState &src) {
  if (this != &src) {
    this->_player = src.getPlayer();
    this->_renderer = src.getRenderer();
    this->_running = src.isRunning();
    this->_window = src.getWindow();
    this->_imgui_init = src._imgui_init;
  }
  return *this;
}

AppState::~AppState() {
  if (this->_player)
    delete this->_player;
}

// setters
void AppState::updateCount() {
  this->_count += 1;
}

void AppState::terminate() {
  this->_running = false;
}

// getters
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

long int AppState::getCount() const {
  return this->_count;
}
