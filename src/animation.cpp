#include "Animation.hpp"
#include "SDL3/SDL_render.h"

Animation::Animation(SDL_Texture **textures, int textureCount, int delay) {
  SDL_Log("Animation constructor called\n");
  this->_textureCount = textureCount;
  this->_delay = delay;
  this->_textures = new SDL_Texture *[textureCount];
  for (int i = 0; i < textureCount; i++) {
    this->_textures[i] = textures[i];
  }
  this->_index = 0;
}


Animation::Animation() {
  this->_textureCount = 0;
  this->_delay = 0;
  this->_index = 0;
  this->_textures = new SDL_Texture *[5];
}

Animation::Animation(const Animation &src) {
  // if (this != &src)
  //   delete this->_textures;
  this->_textureCount = src._textureCount;
  this->_delay = src.getDelay();
  this->_index = src.getIndex();
  this->_textures = new SDL_Texture *[this->_textureCount];
  for (int i = 0; i < this->_textureCount; i++) {
    this->_textures[i] = src._textures[i];
  }
}

Animation &Animation::operator=(const Animation &src) {
  if (this != &src) {
    delete this->_textures;
    this->_textureCount = src._textureCount;
    this->_delay = src.getDelay();
    this->_index = src.getIndex();
    this->_textures = new SDL_Texture *[this->_textureCount];
    for (int i = 0; i < this->_textureCount; i++) {
      this->_textures[i] = src._textures[i];
    }
  }
  return *this;
}

Animation::~Animation() {
  for (int i = 0; i < this->_textureCount; i++) {
    SDL_DestroyTexture(this->_textures[i]);
  }
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
  if (this->_index < this->_textureCount)
    return this->_textures[this->_index];
  return nullptr;
}

void Animation::setIndex() {
  this->_index = (this->_index + 1) % this->_textureCount;
}
