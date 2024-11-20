#pragma once

#include <SDL3/SDL.h>

class Animation {
public:
  Animation();
  Animation(SDL_Texture **textures, int textureCount, int delay);
  ~Animation();
  Animation(const Animation &src);
  Animation &operator=(const Animation &src);

  int getDelay() const;
  int getFrameCount() const;
  int getIndex() const;
  SDL_Texture *getCurrentFrame() const;

  void setIndex();

private:
  SDL_Texture **_textures;
  int _delay;
  int _textureCount;
  int _index;
  
};
