#pragma once

#include "SDL3/SDL_render.h"
#include <SDL3/SDL.h>
#include <vector>
#include <iostream>

class Animation {
public:
  Animation();
  Animation(std::vector<SDL_Texture*> &textures, int delay);
  ~Animation();
  Animation(const Animation &src);
  Animation &operator=(const Animation &src);

  int getDelay() const;
  int getFrameCount() const;
  int getIndex() const;
  SDL_Texture *getCurrentFrame() const;

  void setIndex();

private:
  std::vector<std::shared_ptr<SDL_Texture>> _textures;
  // SDL_Texture **_textures;
  int _delay;
  int _textureCount;
  int _index;

  struct TextureDeleter {
    void operator()(SDL_Texture *texture) {
      std::cout << "Texture custom deleter called" << std::endl; 
      if (texture) {
        SDL_DestroyTexture(texture);
      }
    }
  };
};

