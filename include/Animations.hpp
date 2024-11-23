#pragma once
#include <SDL3/SDL.h>
#include <stdlib.h>
#include <map>
#include "Animation.hpp"

class Animations {
public:
  Animations();
  ~Animations();
  Animations(const Animations &src);
  Animations &operator=(const Animations &src);

  void addAnimation(std::string &name, SDL_Texture **textures, int delay, int textureCount);
  SDL_Texture *getCurrentFrame() const;
  Animation &getAnimation(std::string name) const;

  int getDelay() const;

private:
  // !ERROR should be std::map<std::string, Animation>
  // no need for Vector, each animation has a unique name
  std::map<std::string, Animation> *_animations;
};
