#include <SDL3/SDL.h>
#include "Animations.hpp"
#include "Transform.hpp"
#include <memory>

class Player {
public:
  Player();
  ~Player();
  Player(const Player &src);
  Player &operator=(const Player &src);

  SDL_Texture       *getCurrentFrame() const;
  const Animations  &getAnimations() const; // read only
  Animations        &getAnimations();       // write but maintain ownership
  const Animation   &getAnimation(std::string name) const;

  void loadAnimations(SDL_Renderer *renderer);
  void updateFrameIndex();
  void updateLocation();

private:
  std::unique_ptr<Animations> _animations;
  std::unique_ptr<Transform> _transform;
  int _speed;
    // Animations *_animations;
};

// unique_ptr for transform and animations

// refactor ideas:
// Movement Controller struct/class
//   - speed
//   - location
//   - direction angle
