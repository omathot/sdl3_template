#include "Matrix3.hpp"
#include <SDL3/SDL.h>
#include <cstring>

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

Mat3 Mat3::operator+=(const Mat3 &src) const {
  Mat3 result;
  for (int i = 0; i < 9; i++) {
    result._data[i] = this->_data[i] + src._data[i];
  }
  return result;
}

Mat3 Mat3::operator-(const Mat3 &src) const {
  Mat3 result;
  for (int i = 0; i < 9; i++) {
    result._data[i] = this->_data[i] - src._data[i];
  }
  return result;
}
Mat3 Mat3::operator-=(const Mat3 &src) const {
  Mat3 result;
  for (int i = 0; i < 9; i++) {
    result._data[i] = this->_data[i] - src._data[i];
  }
  return result;
}
