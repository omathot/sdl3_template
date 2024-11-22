#include <SDL3/SDL.h>
#include "Animations.hpp"

class Player {
public:
  Player();
  ~Player();
  Player(const Player &src);
  Player &operator=(const Player &src);

  SDL_Texture       *getCurrentFrame() const;
  Animations        *getAnimations() const;
  std::vector<int>  *getLocation() const;
  const Animation   &getAnimation(std::string name) const;

  void loadAnimations(SDL_Renderer *renderer);
  void updateFrameIndex();
  void updateLocation();

private:
    Animations *_animations;
    std::vector<int> *_location;
    int _speed;
};

// refactor ideas:
// Movement Controller struct/class
//   - speed
//   - location
//   - direction angle
