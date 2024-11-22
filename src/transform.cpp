#include "Transform.hpp"

Transform::Transform() {
  SDL_Log("Transform default constructor called\n");
  this->_x = 0;
  this->_y = 0;
}

Transform::Transform(float x, float y) {
  SDL_Log("Transform custom constructor called\n");
  this->_x = x;
  this->_y = y;
}

Transform::Transform(const Transform &src) {
  if (this != &src) {
    this->_x = src._x;
    this->_y = src._y;
  }
}

Transform &Transform::operator=(const Transform &src) {
  if (this != &src) {
    this->_x = src._x;
    this->_y = src._y;
  }
  return *this;
}

Transform::~Transform() {
  SDL_Log("Transform destructor called\n");
}

// TRANSLATIONS
void Transform::translateX(float n) {
  this->_x += n;
}

void Transform::translateY(float n) {
  this->_y += n;
}

void Transform::translate(Vector2 &src) {
  this->_x += src.x();
  this->_y += src.y();
}

// GETTERS
float Transform::x() const {
  return this->_x;
}

float Transform::y() const {
  return this->_y;
}
