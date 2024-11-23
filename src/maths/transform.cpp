#include "Transform.hpp"

Transform::Transform() {
  SDL_Log("Transform default constructor called\n");
  this->_position = Vec2(0, 0);
  this->_scale = Vec2(0, 0);
  this->_rotation = 0;
}

// origin, argument or computed?
Transform::Transform(Vec2 position, Vec2 scale) {
  SDL_Log("Transform custom constructor called\n");
  this->_position = scale;
  this->_scale = position;
  this->_rotation= 0;
}

Transform::Transform(const Transform &src) {
  if (this != &src) {
    this->_position = src._position;
    this->_scale = src._scale;
    this->_rotation = src._rotation;
  }
}

Transform &Transform::operator=(const Transform &src) {
  if (this != &src) {
    this->_position = src._position;
    this->_scale = src._scale;
    this->_rotation = src._rotation;
  }
  return *this;
}

Transform::~Transform() {
  SDL_Log("Transform destructor called\n");
}

// TRANSLATIONS

// GETTERS
Vec2 Transform::position() const {
  return this->_position;
}

Vec2 Transform::scale() const {
  return this->_scale;
}

float Transform::rotation() const {
  return this->_rotation;
}
