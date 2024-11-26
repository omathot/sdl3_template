#pragma once

#include "Matrix3.hpp"
#include <SDL3/SDL.h>
#include <iostream>

class Vec2;
std::ostream& operator<<(std::ostream& os, const Vec2& src);

class Vec2 {
public:
  Vec2();
  Vec2(float x, float y);
  Vec2(float n);
  ~Vec2();
  Vec2(const Vec2 &src);

  Vec2 &operator=(const Vec2 &src);
  Vec2 operator+(const Vec2 &src) const;
  Vec2 operator+(float n) const;
  Vec2 &operator+=(const Vec2 &src);
  Vec2 &operator+=(float n);
  Vec2 operator-(const Vec2 &src) const;
  Vec2 operator-(float n) const;
  Vec2 &operator-=(const Vec2 &src);
  Vec2 &operator-=(float n);
  Vec2 operator*(const Vec2 &src) const;
  Vec2 operator*(float n) const;
  Vec2 &operator*=(const Vec2 &src);
  Vec2 &operator*=(float n);
  Vec2 operator/(const Vec2 &src) const;
  Vec2 &operator/=(const Vec2 &src);
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
  Vec2 transform(Mat3 &src) const;
  

private:
  float _x;
  float _y;
};
