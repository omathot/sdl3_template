#include "Matrix3.hpp"
#include <SDL3/SDL.h>
#include <cstring>
#include "Vector2.hpp"

Mat3::Mat3() : _rows(3), _col(3) {
  SDL_Log("Mat3 default constructor called\n");
  _data.fill(0);  // First zero everything
  _data[0] = 1;
  _data[4] = 1;
  _data[8] = 1;
}

Mat3::Mat3(float data[9]) : _rows(3), _col(3), _data() {
  std::memcpy(this->_data.data(), data, sizeof(float) * 9);
}

Mat3::Mat3(Vec2 &src) : _rows(3), _col(3) {
  float data[9] = {
    1.0f, 0.0f, src.x(),   // First column
    0.0f, 1.0f, src.y(),   // Second column
    0.0f, 0.0f, 1.0f         // Third column
  };
  std::memcpy(this->_data.data(), data, sizeof(float) * 9);
}

Mat3::Mat3(const Mat3 &src) : _rows(3), _col(3) {
  SDL_Log("Mat3 custom constructor called\n");
  std::memcpy(this->_data.data(), src._data.data(), sizeof(float) * 9);
}

Mat3::~Mat3() {
  SDL_Log("Mat3 destructor called\n");
}

// OPERATORS
Mat3 &Mat3::operator=(const Mat3 &src) {
  if (this != &src) {
    std::memcpy(this->_data.data(), src._data.data(), sizeof(float) * 9);
  }
  return *this;
}

Mat3 Mat3::operator+(const Mat3 &src) const {
  Mat3 result;
  for (int i = 0; i < 9; i++) {
    result._data[i] = this->_data[i] + src._data[i];
  }
  return result;
}

Mat3 &Mat3::operator+=(const Mat3 &src) {
  for (int i = 0; i < 9; i++) {
    this->_data[i] += src._data[i];
  }
  return *this;
}

Mat3 Mat3::operator-(const Mat3 &src) const {
  Mat3 result;
  for (int i = 0; i < 9; i++) {
    result._data[i] = this->_data[i] - src._data[i];
  }
  return result;
}

Mat3 &Mat3::operator-=(const Mat3 &src) {
  for (int i = 0; i < 9; i++) {
    this->_data[i] -= src._data[i];
  }
  return *this;
}

Mat3 Mat3::operator*(const Vec2 &src) const {
  float result[9] = {
    // First column
    (_data[0] * src.x()) + (_data[3] * src.y()) + (_data[6] * 1.0f),  // x component
    (_data[1] * src.x()) + (_data[4] * src.y()) + (_data[7] * 1.0f),  // y component
    (_data[2] * src.x()) + (_data[5] * src.y()) + (_data[8] * 1.0f),  // w component
    // Fill remaining columns with zeros
    0.0f, 0.0f,
    0.0f, 0.0f,
    0.0f, 0.0f
  };

  return Mat3(result);
}

const float &Mat3::operator()(int row, int col) const {
  return this->_data[row * 3 + col];
}

float &Mat3::operator()(int row, int col) {
  return this->_data[row * 3 + col];
}
