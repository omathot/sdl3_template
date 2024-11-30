#pragma once
#include "Vector2.hpp"

// TRANSLATION(POSITION), ROTATION AND SCALE
class Transform {
public:
  Transform();
  Transform(Vec2 x, Vec2 y);
  ~Transform();
  Transform(const Transform &src);
  Transform &operator=(const Transform &src);

  Vec2 position() const;
  Vec2 scale() const;
  float rotation() const;
  void move(Vec2 &src);
  

private:
  Vec2 _position;
  Vec2 _scale;
  float _rotation;
};
