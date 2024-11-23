#pragma once

#include <SDL3/SDL.h>
#include <iostream>

class Vec2;
std::ostream& operator<<(std::ostream& os, const Vec2& src);

class Vec2 {
public:
  Vec2();
  Vec2(float x, float y);
  ~Vec2();
  Vec2(const Vec2 &src);

  Vec2 operator*(const Vec2 &src) const;
  Vec2 operator*(float n) const;             // scales by n
  Vec2 operator/(const Vec2 &src) const;
  Vec2 operator+(const Vec2 &src) const;  // add Vec2
  Vec2 operator+(float n) const;             // add value
  Vec2 operator-(const Vec2 &src) const;  // subtract Vec2
  Vec2 operator-(float n) const;             // subtract value
  Vec2 &operator=(const Vec2 &src);
  bool operator==(const Vec2 &src) const;

  float x() const;
  float y() const;
  void setX(float x);
  void setY(float y);

  float len() const;
  float dotProduct(Vec2 &src) const;
  float crossProduct(Vec2 &src) const;
  float distanceTo(Vec2 &src) const;
  float angleWith(Vec2 &src) const;
  Vec2 normalize() const;
  

private:
  float _x;
  float _y;
};
