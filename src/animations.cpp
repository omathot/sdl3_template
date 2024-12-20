#include "Animations.hpp"
#include "SDL3/SDL_render.h"

Animations::Animations() {
  SDL_Log("Animations constructor called\n");
  this->_animations = std::map<std::string, Animation>();
}

Animations::Animations(const Animations &src) {
  SDL_Log("Animations copy constructor called");
  if (this != &src) {
    this->_animations = src._animations;
  }
}

Animations &Animations::operator=(const Animations &src) {
  SDL_Log("Animations copy operator called");
  if (this != &src) {
    this->_animations = std::map<std::string, Animation>(src._animations);
  }
  return *this;
}

Animations::~Animations() {
  SDL_Log("Animations destructor called\n");
}

void Animations::addAnimation(std::string &name, std::vector<SDL_Texture*> &textures, int delay, int textureCount) {
  Animation anim = Animation(textures, delay);

  (this->_animations)[name] = (anim);
}

SDL_Texture *Animations::getCurrentFrame() const {
  return this->_animations.begin()->second.getCurrentFrame();
}

int Animations::getDelay() const {
  return this->_animations.begin()->second.getDelay();
}

const Animation &Animations::getAnimation(std::string name) const {
  return (this->_animations).at(name);
}

Animation &Animations::getAnimation(std::string name) {
  return this->_animations.at(name);
}

const std::map<std::string, Animation> &Animations::getAllAnimations() const {
  return _animations;
} 
