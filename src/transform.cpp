#include "Transform.hpp"

Transform::Transform() {
  this->_pos = glm::fvec2(0);
  this->_scale = glm::fvec2(0);
  this->_rotation = 0;
}

Transform::Transform(glm::fvec2 pos, glm::fvec2 scale, float rotation) {
  this->_pos = pos;
  this->_scale = scale;
  this->_rotation = rotation;
}

Transform::Transform(const  Transform &src) {
  this->_pos = src._pos;
  this->_scale = src._scale;
  this->_rotation = src._rotation;
}

Transform &Transform::operator=(const Transform &src) {
  if (this != &src) {
    this->_pos = src._pos;
    this->_scale = src._scale;
    this->_rotation = src._rotation;
  }
  return *this;
}

Transform::~Transform() {
  //
}

glm::fvec2 Transform::pos() const {
  return this->_pos;
}

glm::fvec2 Transform::scale() const {
  return this->_scale;
}

float Transform::roatation() const {
  return this->_rotation;
}
