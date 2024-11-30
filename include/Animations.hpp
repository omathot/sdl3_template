#pragma once
#include <SDL3/SDL.h>
#include <memory>
#include <stdlib.h>
#include <map>
#include "Animation.hpp"

class Animations {
public:
  Animations();
  ~Animations();
  Animations(const Animations &src);
  Animations &operator=(const Animations &src);

  void addAnimation(std::string &name, std::vector<SDL_Texture*> &textures, int delay, int textureCount);
  SDL_Texture *getCurrentFrame() const;
  const Animation &getAnimation(std::string name) const;
  Animation &getAnimation(std::string name);
  const std::map<std::string, Animation> &getAllAnimations() const;

  int getDelay() const;

private:
  std::map<std::string, Animation> _animations;
};
