#pragma once
#include "Vector2.hpp"

class Transform {
public:
  Transform();
  Transform(float x, float y);
  ~Transform();
  Transform(const Transform &src);
  Transform &operator=(const Transform &src);

  float x() const;
  float y() const;
  
  void translateX(float n);
  void translateY(float n);
  void translate(Vector2 &src);

private:
  float _x;
  float _y;
};
