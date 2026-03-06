#include "App.hpp"

#include "Util/Input.hpp"
#include "Util/Keycode.hpp"

void App::Update() {

  // --- Phase 2: Keyboard movement ---
  const float speed = 5.0f;
  glm::vec2 pos = m_Giraffe->GetPosition();
  if (Util::Input::IsKeyPressed(Util::Keycode::UP) ||
      Util::Input::IsKeyPressed(Util::Keycode::W)) {
    pos.y += speed;
  }
  if (Util::Input::IsKeyPressed(Util::Keycode::DOWN) ||
      Util::Input::IsKeyPressed(Util::Keycode::S)) {
    pos.y -= speed;
  }
  if (Util::Input::IsKeyPressed(Util::Keycode::LEFT) ||
      Util::Input::IsKeyPressed(Util::Keycode::A)) {
    pos.x -= speed;
  }
  if (Util::Input::IsKeyPressed(Util::Keycode::RIGHT) ||
      Util::Input::IsKeyPressed(Util::Keycode::D)) {
    pos.x += speed;
  }
  m_Giraffe->SetPosition(pos);

  // --- Phase 3: Collision detection - hide chest ---
  if (m_Chest->GetVisibility() && m_Giraffe->IfCollides(m_Chest)) {
    m_Chest->SetVisible(false);
  }

  // --- Phase 4: Bee animation (looping + playing) ---
  m_Bee->SetLooping(true);
  m_Bee->Play();

  // --- Phase 5: Open doors on collision ---
  if(m_Doors[0]->GetVisibility()) {
    for (auto &door : m_Doors) {
      if (m_Giraffe->IfCollides(door)) {
        door->SetImage(GA_RESOURCE_DIR "/Image/Character/door_open.png");
      }
    }
  }

  // --- Phase 6: Countdown ball plays once then stops at OK ---
  static bool isFirst = true;
  if (m_Phase == Phase::COUNTDOWN && isFirst) {
    m_Ball->SetVisible(true);
      m_Ball->Play();
    isFirst = false;
  }

  /*
   *  Do not touch the code below as they serve the purpose for validating the
   * tasks, rendering the frame, and exiting the game.
   */

  if (Util::Input::IsKeyPressed(Util::Keycode::ESCAPE) ||
      Util::Input::IfExit()) {
    m_CurrentState = State::END;
  }

  if (m_EnterDown) {
    if (!Util::Input::IsKeyPressed(Util::Keycode::RETURN)) {
      ValidTask();
    }
  }
  m_EnterDown = Util::Input::IsKeyPressed(Util::Keycode::RETURN);

  m_Root.Update();
}
