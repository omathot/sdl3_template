#include "Vector2.hpp"
#include "SDL3/SDL_stdinc.h"
#include <math.h>

// CONSTRUCTORS
Vec2::Vec2() {
  SDL_Log("Vec2 default constructor called\n");
  this->_x = 0;
  this->_y = 0;
}

Vec2::Vec2(float x, float y) {
  SDL_Log("Vec2 custom constructor called\n");
  this->_x = x;
  this->_y = y;
}

Vec2::Vec2(const Vec2 &src) {
  if (this != &src) {
    this->_x = src._x;
    this->_y = src._y;
  }
}

Vec2::~Vec2() {
  SDL_Log("Vec2 destructor called\n");
}

// OPERATOR OVERLOADS
Vec2 &Vec2::operator=(const Vec2 &src) {
  if (this != &src) {
    this->_x = src._x;
    this->_y = src._y;
  }
  return *this;
}

bool Vec2::operator==(const Vec2 &src) const {
  float tolerence = 0.000001f;
  bool x = SDL_fabsf(_x - src._x) <=(tolerence*fmaxf(1.0f, fmaxf(fabsf(_x), fabsf(src._x))));
  bool y = SDL_fabsf(_y - src._y) <=(tolerence*fmaxf(1.0f, fmaxf(fabsf(_y), fabsf(src._y))));
  if (x && y) {
    return true;
  }
  return false;
}

Vec2 Vec2::operator+(const Vec2 &src) const {
  Vec2 result;
  result._x = this->_x + src._x;
  result._y = this->_y + src._y;
  return result;
}

Vec2 Vec2::operator+(float n) const {
  Vec2 result;
  result._x = this->_x + n;
  result._y = this->_y + n;
  return result;
}

Vec2 Vec2::operator-(const Vec2 &src) const {
  Vec2 result;
  result._x = this->_x - src._x;
  result._y = this->_y - src._y;
  return result;;
}

Vec2 Vec2::operator-(float n) const {
  Vec2 result;
  result._x = this->_x - n;
  result._y = this->_y - n;
  return result;
}

Vec2 Vec2::operator*(const Vec2 &src) const {
  Vec2 result;
  result._x = this->_x * src._x;
  result._y = this->_y * src._y;
  return result;
}

Vec2 Vec2::operator*(float n) const {
  Vec2 result;
  result._x = this->_x * n;
  result._y = this->_y * n;
  return result;
}

Vec2 Vec2::operator/(const Vec2 &src) const {
  Vec2 result;
  result._x = this->_x / src._x;
  result._y = this->_y / src._y;
  return result;
}

std::ostream &operator<<(std::ostream &os, const Vec2 &src) {
  os << "(x: " << src.x() << ", y: " << src.y() << ")";
  return os;
}

// GETTERS
float Vec2::x() const {
  return this->_x;
}
float Vec2::y() const {
  return this->_y;
}

// SETTERS
void Vec2::setX(float x) {
  this->_x = x;
}

void Vec2::setY(float y) {
  this->_y = y;
}

// MATH
float Vec2::len() const {
  return SDL_sqrtf((this->_x * this->_x) + (this->_y * this->_y));
}

float Vec2::dotProduct(Vec2 &src) const {
  return ((this->_x * src._x) + (this->_y * src._y));
}

float Vec2::crossProduct(Vec2 &src) const {
  return ((this->_x * src._y) - (this->_y * src._x));
}

float Vec2::distanceTo(Vec2 &src) const {
  return SDL_sqrtf((_x - src._x)*(_x - src._x) + (_y - src._y)*(_y - src._y));
}

float Vec2::angleWith(Vec2 &src) const {
  float zero = 0.0f;
  float dot = (_x * src._x) + (_y * src._y);
  float det = (_x * src._y) - (_y * src._x);

  float result = SDL_atan2f(det, dot);
  return result;
}

Vec2 Vec2::normalize() const {
  Vec2 ret = Vec2();
  float len = this->len();
  if (len > 0) {
    float ilen = 1.0f/len;
    ret._x = this->_x * ilen;
    ret._y = this->_y * ilen;
  }
  return ret;
}
