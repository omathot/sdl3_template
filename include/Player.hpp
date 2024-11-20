#include <SDL3/SDL.h>
#include "Animations.hpp"

class Player {
public:
  Player();
  ~Player();
  Player(const Player &src);
  Player &operator=(const Player &src);

  void loadAnimations(SDL_Renderer *renderer);
  SDL_Texture *getCurrentFrame() const;
  Animations *getAnimations() const;
  const Animation &getAnimation(std::string name) const;

  void updateFrameIndex();

private:
    Animations *_animations;
};
