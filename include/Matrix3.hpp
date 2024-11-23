#pragma once

#include <array>

class Mat3 {
public:
  Mat3();
  Mat3(float data[9]);
  ~Mat3();
  Mat3(const Mat3 &src);

  Mat3 &operator=(const Mat3 &src);
  Mat3 operator+(const Mat3 &src) const;
  Mat3 operator+=(const Mat3 &src) const;
  Mat3 operator-(const Mat3 &src) const;
  Mat3 operator-=(const Mat3 &src) const;
  Mat3 operator*(const Mat3 &src) const;
  Mat3 operator/(const Mat3 &src); const
  Mat3 &operator==(const Mat3 &src);
  const float &operator()(int row, int col) const;

private:
  const int _rows;
  const int _col;
  std::array<float, 9> _data;
};
