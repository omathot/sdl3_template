#pragma once
#include <iostream>

class Vec3;
std::ostream &operator<<(std::ostream &os, const Vec3 &src);

class Vec3 {
public:
  Vec3();
  ~Vec3();
  Vec3(float x, float y, float z);
  Vec3(float n);
  Vec3(const Vec3 &src);

  float x() const;
  float y() const;
  float z() const;

  Vec3 &operator=(const Vec3 &src);
  Vec3 operator+(const Vec3 &src) const;
  Vec3 operator+(float n) const;
  Vec3 &operator+=(const Vec3 &src);
  Vec3 &operator+=(float n);
  Vec3 operator-(const Vec3 &src) const;
  Vec3 operator-(float n) const;
  Vec3 &operator-=(const Vec3 &src);
  Vec3 &operator-=(float n);
  Vec3 operator*(const Vec3 &src) const;
  Vec3 operator*(float n) const;
  Vec3 &operator*=(const Vec3 &src);
  Vec3 &operator*=(float n);
  Vec3 operator/(const Vec3 &src) const;
  Vec3 &operator/=(const Vec3 &src);
  bool operator==(const Vec3 &src) const;

  float len() const;
  float lenSqr() const;
  Vec3 crossProduct(Vec3 &src) const;
  float dotProduct(Vec3 &src) const;
  float distanceTo(Vec3 &src) const;
  float distanceToSqr(Vec3 &src) const;
  float angleWith(Vec3 &src) const;
  Vec3 negate() const;
  Vec3 normalize() const;

private:
  float _x;
  float _y;
  float _z;
};
