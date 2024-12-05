#pragma once

#include <glm/glm.hpp>

class Transform {
public:
  Transform();
  Transform(glm::fvec2 pos, glm::fvec2 scale, float rotation);
  ~Transform();
  Transform(const Transform &src);

  Transform &operator=(const Transform &src);

  glm::fvec2 pos() const;
  glm::fvec2 scale() const;
  float roatation() const;

private:
  glm::fvec2 _pos;
  glm::fvec2 _scale;
  float _rotation;
};
