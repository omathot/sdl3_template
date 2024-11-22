#pragma once

#include <SDL3/SDL.h>
#include <iostream>

class Vector2;
std::ostream& operator<<(std::ostream& os, const Vector2& src);

class Vector2 {
public:
  Vector2();
  Vector2(float x, float y);
  ~Vector2();
  Vector2(const Vector2 &src);

  Vector2 &operator*(const Vector2 &src);
  Vector2 &operator*(float n);             // scales by n
  Vector2 &operator/(const Vector2 &src);
  Vector2 &operator+(const Vector2 &src);  // add Vector2
  Vector2 &operator+(float n);             // add value
  Vector2 &operator-(const Vector2 &src);  // subtract Vector2
  Vector2 &operator-(float n);             // subtract value
  Vector2 &operator=(const Vector2 &src);
  bool operator==(const Vector2 &src);

  float x() const;
  float y() const;
  void setX(float x);
  void setY(float y);

  float len() const;
  float dotProduct(Vector2 &src) const;
  float crossProduct(Vector2 &src) const;
  float distanceTo(Vector2 &src) const;
  float angleWith(Vector2 &src) const;
  Vector2 normalize() const;
  

private:
  float _x;
  float _y;
};
