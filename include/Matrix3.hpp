#pragma once

#include <array>

class Vec2;

class Mat3 {
public:
  Mat3();
  Mat3(float data[9]);
  Mat3(Vec2 &src);
  ~Mat3();
  Mat3(const Mat3 &src);

  Mat3 &operator=(const Mat3 &src);
  Mat3 operator+(const Mat3 &src) const;
  Mat3 &operator+=(const Mat3 &src);
  Mat3 operator-(const Mat3 &src) const;
  Mat3 &operator-=(const Mat3 &src);
  Mat3 operator*(const Mat3 &src) const;
  Mat3 operator*(const Vec2 &src) const;
  Mat3 operator/(const Mat3 &src); const
  Mat3 &operator==(const Mat3 &src);
  float &operator()(int row, int col);
  const float &operator()(int row, int col) const;

private:
  const int _rows;
  const int _col;
  std::array<float, 9> _data;
};

// A + ms B = C;
