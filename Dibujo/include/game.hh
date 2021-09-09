#pragma once

#include<SFML/Graphics.hpp>

class Game
{
private:
  sf::RenderWindow* window{};
  sf::Event* event{};
public:
  Game();
  ~Game();
  void Initialize();
  void Update();
  void Render();
  void Input();
  void Draw();
  void Start();
  void Loop();
  void Destroy();
};