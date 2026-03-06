#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <cmath>
#include <memory>
#include <string>

#include "Util/GameObject.hpp"

class Character : public Util::GameObject {
public:
  explicit Character(const std::string &ImagePath);

  Character(const Character &) = delete;

  Character(Character &&) = delete;

  Character &operator=(const Character &) = delete;

  Character &operator=(Character &&) = delete;

  [[nodiscard]] const std::string &GetImagePath() const { return m_ImagePath; }

  [[nodiscard]] const glm::vec2 &GetPosition() const {
    return m_Transform.translation;
  }

  [[nodiscard]] bool GetVisibility() const { return m_Visible; }

  void SetImage(const std::string &ImagePath);

  void SetPosition(const glm::vec2 &Position) {
    m_Transform.translation = Position;
  }

  [[nodiscard]] glm::vec2 GetSize() const {
    return m_Drawable->GetSize() * m_Transform.scale;
  }

  [[nodiscard]] bool IfCollides(const std::shared_ptr<Character> &other) const {
    auto posA = GetPosition();
    auto posB = other->GetPosition();
    auto sizeA = GetSize();
    auto sizeB = other->GetSize();

    float halfWidthA = sizeA.x / 2.0f;
    float halfHeightA = sizeA.y / 2.0f;
    float halfWidthB = sizeB.x / 2.0f;
    float halfHeightB = sizeB.y / 2.0f;

    return (std::abs(posA.x - posB.x) < (halfWidthA + halfWidthB)) &&
           (std::abs(posA.y - posB.y) < (halfHeightA + halfHeightB));
  }

private:
  void ResetPosition() { m_Transform.translation = {0, 0}; }

  std::string m_ImagePath;
};

#endif // CHARACTER_HPP
