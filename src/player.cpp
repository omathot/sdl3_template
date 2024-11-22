#include "Player.hpp"
#include "SDL3/SDL_log.h"
#include "SDL3/SDL_render.h"
#include "SDL3/SDL_surface.h"
#include <SDL3_image/SDL_image.h>

Player::Player() {
  SDL_Log("Player constructor called");
  this->_animations = new Animations();
  this->_location = new std::vector<int>();
  this->_location->push_back(0);
  this->_location->push_back(0);
}

Player::Player(const Player &src) {
  if (this != &src) {
    this->_animations = src._animations;
    this->_location = src._location;
  }
}

Player &Player::operator=(const Player &src) {
  if (this != &src) {
    this->_animations = src._animations;
    this->_location = src._location;
  }

  return (*this);
}

Player::~Player() {
  SDL_Log("Player destructor called");
}

void Player::loadAnimations(SDL_Renderer *renderer) {
  SDL_Surface *s_dwalk_1 = IMG_Load("../assets/dwalk_one.png");
  SDL_Surface *s_dwalk_2 = IMG_Load("../assets/dwalk_two.png");
  SDL_Surface *s_dwalk_3 = IMG_Load("../assets/dwalk_three.png");
  if (!s_dwalk_1 || !s_dwalk_2 || !s_dwalk_3) {
    SDL_Log("Error: Failed to load player assets: %s\n", SDL_GetError());
  }

  SDL_Texture *dwalk_1 = SDL_CreateTextureFromSurface(renderer, s_dwalk_1);
  SDL_Texture *dwalk_2 = SDL_CreateTextureFromSurface(renderer, s_dwalk_2);
  SDL_Texture *dwalk_3 = SDL_CreateTextureFromSurface(renderer, s_dwalk_3);
  if (!dwalk_1 || !dwalk_2 || !dwalk_3) {
    SDL_Log("Error: Failed to create texture from surface: %s\n", SDL_GetError());
  }
  SDL_DestroySurface(s_dwalk_1);
  SDL_DestroySurface(s_dwalk_2);
  SDL_DestroySurface(s_dwalk_3);
  SDL_Texture **hold = new SDL_Texture*[3];
  hold[0] = dwalk_1;
  hold[1] = dwalk_2;
  hold[2] = dwalk_3;
  std::string name = "walk down";
  this->_animations->addAnimation(name, hold, 100, 3);
}

SDL_Texture *Player::getCurrentFrame() const {
  return this->_animations->getCurrentFrame();
}

Animations *Player::getAnimations() const {
  return this->_animations;
}

const Animation &Player::getAnimation(std::string name) const {
  return this->_animations->getAnimation(name);
}

std::vector<int> *Player::getLocation() const {
  return this->_location;
}

void Player::updateFrameIndex() {
  std::string tmp = "walk down";
  this->_animations->getAnimation(tmp).setIndex();
}
