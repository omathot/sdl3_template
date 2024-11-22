#include "Vector2.hpp"
#include "SDL3/SDL_stdinc.h"
#include <math.h>

// CONSTRUCTORS
Vector2::Vector2() {
  SDL_Log("Vector2 default constructor called\n");
  this->_x = 0;
  this->_y = 0;
}

Vector2::Vector2(float x, float y) {
  SDL_Log("Vector2 custom constructor called\n");
  this->_x = x;
  this->_y = y;
}

Vector2::Vector2(const Vector2 &src) {
  if (this != &src) {
    this->_x = src._x;
    this->_y = src._y;
  }
}

Vector2::~Vector2() {
  SDL_Log("Vector2 destructor called\n");
}

// OPERATOR OVERLOADS
Vector2 &Vector2::operator=(const Vector2 &src) {
  if (this != &src) {
    this->_x = src._x;
    this->_y = src._y;
  }
  return *this;
}

bool Vector2::operator==(const Vector2 &src) {
  float tolerence = 0.000001f;
  bool x = SDL_fabsf(_x - src._x) <=(tolerence*fmaxf(1.0f, fmaxf(fabsf(_x), fabsf(src._x))));
  bool y = SDL_fabsf(_y - src._y) <=(tolerence*fmaxf(1.0f, fmaxf(fabsf(_y), fabsf(src._y))));
  if (x && y) {
    return true;
  }
  return false;
}

Vector2 &Vector2::operator+(const Vector2 &src) {
  this->_x += src._x;
  this->_y += src._y;
  return *this;
}

Vector2 &Vector2::operator+(float n) {
  this->_x += n;
  this->_y += n;
  return *this;
}

Vector2 &Vector2::operator-(const Vector2 &src) {
  this->_x -= src._x;
  this->_y -= src._y;
  return *this;
}

Vector2 &Vector2::operator-(float n) {
  this->_x -= n;
  this->_y -= n;
  return *this;
}

Vector2 &Vector2::operator*(const Vector2 &src) {
  this->_x *= src._x;
  this->_y *= src._y;
  return *this;
}

Vector2 &Vector2::operator*(float n) {
  this->_x *= n;
  this->_y *= n;
  return *this;
}

Vector2 &Vector2::operator/(const Vector2 &src) {
  this->_x /= src._x;
  this->_y /= src._y;
  return *this;
}

std::ostream &operator<<(std::ostream &os, const Vector2 &src) {
  os << "(x: " << src.x() << ", y: " << src.y() << ")";
  return os;
}

// GETTERS
float Vector2::x() const {
  return this->_x;
}
float Vector2::y() const {
  return this->_y;
}

// SETTERS
void Vector2::setX(float x) {
  this->_x = x;
}

void Vector2::setY(float y) {
  this->_y = y;
}

// MATH
float Vector2::len() const {
  return SDL_sqrtf((this->_x * this->_x) + (this->_y * this->_y));
}

float Vector2::dotProduct(Vector2 &src) const {
  return ((this->_x * src._x) + (this->_y * src._y));
}

float Vector2::crossProduct(Vector2 &src) const {
  return ((this->_x * src._y) - (this->_y * src._x));
}

float Vector2::distanceTo(Vector2 &src) const {
  return SDL_sqrtf((_x - src._x)*(_x - src._x) + (_y - src._y)*(_y - src._y));
}

float Vector2::angleWith(Vector2 &src) const {
  float zero = 0.0f;
  float dot = (_x * src._x) + (_y * src._y);
  float det = (_x * src._y) - (_y * src._x);

  float result = SDL_atan2f(det, dot);
  return result;
}

Vector2 Vector2::normalize() const {
  Vector2 ret = Vector2();
  float len = this->len();
  if (len > 0) {
    float ilen = 1.0f/len;
    ret._x = this->_x * ilen;
    ret._y = this->_y * ilen;
  }
  return ret;
}
