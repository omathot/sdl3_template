#include "Animation.hpp"
#include "SDL3/SDL_render.h"
#include <memory>

Animation::Animation(std::vector<SDL_Texture*> &textures, int delay) {
  SDL_Log("Animation constructor called\n");
  this->_textureCount = textures.size();
  this->_delay = delay;
  this->_textures.reserve(textures.size());
  for (const auto texture : textures) {
    this->_textures.push_back(std::shared_ptr<SDL_Texture>(texture, TextureDeleter()));
  }
  this->_index = 0;
}


Animation::Animation() {
  this->_textureCount = 0;
  this->_delay = 0;
  this->_index = 0;
  this->_textures = std::vector<std::shared_ptr<SDL_Texture>>();
}

Animation::Animation(const Animation &src) {
  this->_textureCount = src._textureCount;
  this->_delay = src._delay;
  this->_index = src._index;
  this->_textures = src._textures;
}

Animation &Animation::operator=(const Animation &src) {
  if (this != &src) {
    this->_textures = src._textures;
    this->_textureCount = src._textureCount;
    this->_delay = src._delay;
    this->_index = src._index;
  }
  return *this;
}

Animation::~Animation() {
  SDL_Log("Animation destructor called\n");
}

int Animation::getDelay() const {
  return this->_delay;
}

int Animation::getFrameCount() const {
  return this->_textureCount;
}

int Animation::getIndex() const {
  return this->_index;
}

SDL_Texture *Animation::getCurrentFrame() const {
  if (this->_index < this->_textureCount) {
    return this->_textures.at(this->_index).get();
    
  }
  return nullptr;
}

void Animation::setIndex() {
  this->_index = (this->_index + 1) % this->_textureCount;
}
