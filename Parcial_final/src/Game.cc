#include "CommonHeaders.hh"
#include "Player.hh"
#include "TileGroup.hh"


sf::CircleShape* circle{new sf::CircleShape()};

TextObject* textObj1{new TextObject(ASSETS_FONT_ARCADECLASSIC, 14, sf::Color::White, sf::Text::Bold)};

sf::Clock* gameClock{new sf::Clock()};
float deltaTime{};
Player* player1{};
GameObject* chest1{};
GameObject* chest2{};
GameObject* chest3{};
GameObject* chest4{};
GameObject* chest5{};
GameObject* chest6{};
GameObject* chest7{};
GameObject* chest8{};
GameObject* chest9{};
GameObject* chest10{};
GameObject* bomb1{};
GameObject* bomb2{};
GameObject* upperWalls1{};
GameObject* upperWalls2{};
GameObject* upperWalls3{};
GameObject* upperWalls4{};
GameObject* upperWalls5{};
GameObject* upperWalls6{};
GameObject* upperWalls7{};
GameObject* leftSideWall{};
GameObject* leftSideWal2{};
GameObject* leftSideWal3{};
GameObject* leftSideWal4{};
GameObject* leftSideWal5{};
GameObject* leftSideWal6{};
GameObject* rightSideWall{};
GameObject* rightSideWal2{};
GameObject* rightSideWal3{};
GameObject* rightSideWal4{};
GameObject* rightSideWal5{};
GameObject* rightSideWal6{};
GameObject* downWal1{};
GameObject* downWal2{};
GameObject* downWal3{};
GameObject* downWal4{};
GameObject* downWal5{};
GameObject* downWal6{};
GameObject* downWal7{};
GameObject* middleWal1{};
GameObject* middleWal2{};
GameObject* middleWal3{};
GameObject* middleWal5{};
GameObject* middleWal6{};
GameObject* middleWal7{};
GameObject* middleWal9{};
GameObject* middleWal10{};
GameObject* middleWal11{};
GameObject* middleWal12{};
GameObject* middleWal13{};
GameObject* middleWal14{};
GameObject* middleWal15{};
GameObject* middleWal16{};
GameObject* middleWal17{};
GameObject* middleWal18{};
GameObject* middleWal19{};
GameObject* middleWal20{};
GameObject* middleWal22{};
GameObject* middleWal23{};
GameObject* middleWal24{};
GameObject* middleWal26{};
GameObject* middleWal27{};
GameObject* middleWal28{};

TileGroup* tileGroup{};
Tile* tile1{};

uint32 flags{};
    //flags += b2Draw::e_aabbBit;
    //flags += b2Draw::e_shapeBit;
    //flags += b2Draw::e_centerOfMassBit;
    //flags += b2Draw::e_pairBit;
    //flags += b2Draw::e_jointBit;

Game::Game()
{
  window = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), GAME_NAME);
  event = new sf::Event();
  gravity = new b2Vec2(0.f, 0.f);
  world = new b2World(*gravity);
  drawPhysics = new DrawPhysics(window);
  gameObjects = new std::vector<GameObject*>();
  gameObjectsDeleteList = new std::vector<GameObject*>();

  player1 = new Player(ASSETS_SPRITES, 3.f, 16, 16, 0, 5, 500, 300, 200.f, b2BodyType::b2_dynamicBody, world, window);
  player1->SetTagName("Player");

  chest1 = new GameObject(ASSETS_SPRITES, 3.f, 16, 16, 6, 1, 20, 100, b2BodyType::b2_staticBody, world, window);
  chest1->SetTagName("chest");
  chest2 = new GameObject(ASSETS_SPRITES, 3.f, 16, 16, 6, 1, 20, 250, b2BodyType::b2_staticBody, world, window);
  chest2->SetTagName("chest");
  chest3 = new GameObject(ASSETS_SPRITES, 3.f, 16, 16, 6, 1, 20, 400, b2BodyType::b2_staticBody, world, window);
  chest3->SetTagName("chest");
  chest4 = new GameObject(ASSETS_SPRITES, 3.f, 16, 16, 6, 1, 20, 550, b2BodyType::b2_staticBody, world, window);
  chest4->SetTagName("chest");
  
  chest5 = new GameObject(ASSETS_SPRITES, 3.f, 16, 16, 6, 1, 735, 100, b2BodyType::b2_staticBody, world, window);
  chest5->SetTagName("chest");
  chest6 = new GameObject(ASSETS_SPRITES, 3.f, 16, 16, 6, 1, 735, 250, b2BodyType::b2_staticBody, world, window);
  chest6->SetTagName("chest");
  chest7 = new GameObject(ASSETS_SPRITES, 3.f, 16, 16, 6, 1, 735, 400, b2BodyType::b2_staticBody, world, window);
  chest7->SetTagName("chest");
  chest8 = new GameObject(ASSETS_SPRITES, 3.f, 16, 16, 6, 1, 735, 550, b2BodyType::b2_staticBody, world, window);
  chest8->SetTagName("chest");
  
  chest9 = new GameObject(ASSETS_SPRITES, 3.f, 16, 16, 6, 1, 20, 700, b2BodyType::b2_staticBody, world, window);
  chest9->SetTagName("chest");
  chest10 = new GameObject(ASSETS_SPRITES, 3.f, 16, 16, 6, 1, 735, 700, b2BodyType::b2_staticBody, world, window);
  chest10->SetTagName("chest");
  


  bomb1 = new GameObject(ASSETS_SPRITES, 1.f, 16, 16, 5, 0, 35, 90, b2BodyType::b2_staticBody, world, window);
  bomb1->SetTagName("bomb");
  bomb2 = new GameObject(ASSETS_SPRITES, 1.f, 16, 16, 5, 0, 725, 540, b2BodyType::b2_staticBody, world, window);
  bomb2->SetTagName("bomb");

  upperWalls1 = new GameObject(ASSETS_TILES, 3.f, 32, 32, 0, 0, 105, 30, b2BodyType::b2_staticBody, world, window);
  upperWalls1->SetTagName("wall");
  upperWalls2 = new GameObject(ASSETS_TILES, 3.f, 32, 32, 0, 0, 200, 30, b2BodyType::b2_staticBody, world, window);
  upperWalls2->SetTagName("wall");
  upperWalls3 = new GameObject(ASSETS_TILES, 3.f, 32, 32, 0, 0, 295, 30, b2BodyType::b2_staticBody, world, window);
  upperWalls3->SetTagName("wall");
  upperWalls4 = new GameObject(ASSETS_TILES, 3.f, 32, 32, 0, 0, 390, 30, b2BodyType::b2_staticBody, world, window);
  upperWalls4->SetTagName("wall");
  upperWalls5 = new GameObject(ASSETS_TILES, 3.f, 32, 32, 0, 0, 485, 30, b2BodyType::b2_staticBody, world, window);
  upperWalls5->SetTagName("wall");
  upperWalls6 = new GameObject(ASSETS_TILES, 3.f, 32, 32, 0, 0, 580, 30, b2BodyType::b2_staticBody, world, window);
  upperWalls6->SetTagName("wall");
  upperWalls7 = new GameObject(ASSETS_TILES, 3.f, 32, 32, 0, 0, 675, 30, b2BodyType::b2_staticBody, world, window);
  upperWalls7->SetTagName("wall");

  leftSideWall = new GameObject(ASSETS_TILES, 3.f, 32, 32, 0, 0, 5, 30, b2BodyType::b2_staticBody, world, window);
  leftSideWall->SetTagName("wall");
  leftSideWal2 = new GameObject(ASSETS_TILES, 3.f, 32, 32, 0, 0, 5, 180, b2BodyType::b2_staticBody, world, window);
  leftSideWal2->SetTagName("wall");
  leftSideWal3 = new GameObject(ASSETS_TILES, 3.f, 32, 32, 0, 0, 5, 330, b2BodyType::b2_staticBody, world, window);
  leftSideWal3->SetTagName("wall");
  leftSideWal4 = new GameObject(ASSETS_TILES, 3.f, 32, 32, 0, 0, 5, 480, b2BodyType::b2_staticBody, world, window);
  leftSideWal4->SetTagName("wall");
  leftSideWal5 = new GameObject(ASSETS_TILES, 3.f, 32, 32, 0, 0, 5, 630, b2BodyType::b2_staticBody, world, window);
  leftSideWal5->SetTagName("wall");
  leftSideWal6 = new GameObject(ASSETS_TILES, 3.f, 32, 32, 0, 0, 5, 780, b2BodyType::b2_staticBody, world, window);
  leftSideWal6->SetTagName("wall");

  rightSideWall = new GameObject(ASSETS_TILES, 3.f, 32, 32, 0, 0, 775, 30, b2BodyType::b2_staticBody, world, window);
  rightSideWall->SetTagName("wall");
  rightSideWal2 = new GameObject(ASSETS_TILES, 3.f, 32, 32, 0, 0, 775, 180, b2BodyType::b2_staticBody, world, window);
  rightSideWal2->SetTagName("wall");
  rightSideWal3 = new GameObject(ASSETS_TILES, 3.f, 32, 32, 0, 0, 775, 330, b2BodyType::b2_staticBody, world, window);
  rightSideWal3->SetTagName("wall");
  rightSideWal4 = new GameObject(ASSETS_TILES, 3.f, 32, 32, 0, 0, 775, 480, b2BodyType::b2_staticBody, world, window);
  rightSideWal4->SetTagName("wall");
  rightSideWal5 = new GameObject(ASSETS_TILES, 3.f, 32, 32, 0, 0, 775, 630, b2BodyType::b2_staticBody, world, window);
  rightSideWal5->SetTagName("wall");
  rightSideWal6 = new GameObject(ASSETS_TILES, 3.f, 32, 32, 0, 0, 775, 780, b2BodyType::b2_staticBody, world, window);
  rightSideWal6->SetTagName("wall");

  downWal1 = new GameObject(ASSETS_TILES, 3.f, 32, 32, 0, 0, 105, 780, b2BodyType::b2_staticBody, world, window);
  downWal1->SetTagName("wall");
  downWal2 = new GameObject(ASSETS_TILES, 3.f, 32, 32, 0, 0, 200, 780, b2BodyType::b2_staticBody, world, window);
  downWal2->SetTagName("wall");
  downWal3 = new GameObject(ASSETS_TILES, 3.f, 32, 32, 0, 0, 295, 780, b2BodyType::b2_staticBody, world, window);
  downWal3->SetTagName("wall");
  downWal4 = new GameObject(ASSETS_TILES, 3.f, 32, 32, 0, 0, 390, 780, b2BodyType::b2_staticBody, world, window);
  downWal4->SetTagName("wall");
  downWal5 = new GameObject(ASSETS_TILES, 3.f, 32, 32, 0, 0, 485, 780, b2BodyType::b2_staticBody, world, window);
  downWal5->SetTagName("wall");
  downWal6 = new GameObject(ASSETS_TILES, 3.f, 32, 32, 0, 0, 580, 780, b2BodyType::b2_staticBody, world, window);
  downWal6->SetTagName("wall");
  downWal7 = new GameObject(ASSETS_TILES, 3.f, 32, 32, 0, 0, 675, 780, b2BodyType::b2_staticBody, world, window);
  downWal7->SetTagName("wall");

  middleWal1 = new GameObject(ASSETS_TILES, 3.f, 32, 32, 0, 0, 105, 180, b2BodyType::b2_staticBody, world, window);
  middleWal1->SetTagName("wall");
  middleWal2 = new GameObject(ASSETS_TILES, 3.f, 32, 32, 0, 0, 200, 180, b2BodyType::b2_staticBody, world, window);
  middleWal2->SetTagName("wall");
  middleWal3 = new GameObject(ASSETS_TILES, 3.f, 32, 32, 0, 0, 295, 180, b2BodyType::b2_staticBody, world, window);
  middleWal3->SetTagName("wall");
  middleWal5 = new GameObject(ASSETS_TILES, 3.f, 32, 32, 0, 0, 485, 180, b2BodyType::b2_staticBody, world, window);
  middleWal5->SetTagName("wall");
  middleWal6 = new GameObject(ASSETS_TILES, 3.f, 32, 32, 0, 0, 580, 180, b2BodyType::b2_staticBody, world, window);
  middleWal6->SetTagName("wall");
  middleWal7 = new GameObject(ASSETS_TILES, 3.f, 32, 32, 0, 0, 675, 180, b2BodyType::b2_staticBody, world, window);
  middleWal7->SetTagName("wall");
  
  
  middleWal9 = new GameObject(ASSETS_TILES, 3.f, 32, 32, 0, 0, 200, 330, b2BodyType::b2_staticBody, world, window);
  middleWal9->SetTagName("wall");
  middleWal10 = new GameObject(ASSETS_TILES, 3.f, 32, 32, 0, 0, 295, 330, b2BodyType::b2_staticBody, world, window);
  middleWal10->SetTagName("wall");
  middleWal11 = new GameObject(ASSETS_TILES, 3.f, 32, 32, 0, 0, 390, 330, b2BodyType::b2_staticBody, world, window);
  middleWal11->SetTagName("wall");
  middleWal12 = new GameObject(ASSETS_TILES, 3.f, 32, 32, 0, 0, 485, 330, b2BodyType::b2_staticBody, world, window);
  middleWal12->SetTagName("wall");
  middleWal13 = new GameObject(ASSETS_TILES, 3.f, 32, 32, 0, 0, 580, 330, b2BodyType::b2_staticBody, world, window);
  middleWal13->SetTagName("wall");
  middleWal14 = new GameObject(ASSETS_TILES, 3.f, 32, 32, 0, 0, 675, 330, b2BodyType::b2_staticBody, world, window);
  middleWal14->SetTagName("wall");
  
  middleWal15 = new GameObject(ASSETS_TILES, 3.f, 32, 32, 0, 0, 105, 480, b2BodyType::b2_staticBody, world, window);
  middleWal15->SetTagName("wall");
  middleWal16 = new GameObject(ASSETS_TILES, 3.f, 32, 32, 0, 0, 200, 480, b2BodyType::b2_staticBody, world, window);
  middleWal16->SetTagName("wall");
  middleWal17 = new GameObject(ASSETS_TILES, 3.f, 32, 32, 0, 0, 295, 480, b2BodyType::b2_staticBody, world, window);
  middleWal17->SetTagName("wall");
  middleWal18 = new GameObject(ASSETS_TILES, 3.f, 32, 32, 0, 0, 390, 480, b2BodyType::b2_staticBody, world, window);
  middleWal18->SetTagName("wall");
  middleWal19 = new GameObject(ASSETS_TILES, 3.f, 32, 32, 0, 0, 485, 480, b2BodyType::b2_staticBody, world, window);
  middleWal19->SetTagName("wall");
  middleWal20 = new GameObject(ASSETS_TILES, 3.f, 32, 32, 0, 0, 580, 480, b2BodyType::b2_staticBody, world, window);
  middleWal20->SetTagName("wall");
  

  middleWal22 = new GameObject(ASSETS_TILES, 3.f, 32, 32, 0, 0, 105, 630, b2BodyType::b2_staticBody, world, window);
  middleWal22->SetTagName("wall");
  middleWal23 = new GameObject(ASSETS_TILES, 3.f, 32, 32, 0, 0, 200, 630, b2BodyType::b2_staticBody, world, window);
  middleWal23->SetTagName("wall");
  middleWal24 = new GameObject(ASSETS_TILES, 3.f, 32, 32, 0, 0, 295, 630, b2BodyType::b2_staticBody, world, window);
  middleWal24->SetTagName("wall");
  middleWal26 = new GameObject(ASSETS_TILES, 3.f, 32, 32, 0, 0, 485, 630, b2BodyType::b2_staticBody, world, window);
  middleWal26->SetTagName("wall");
  middleWal27 = new GameObject(ASSETS_TILES, 3.f, 32, 32, 0, 0, 580, 630, b2BodyType::b2_staticBody, world, window);
  middleWal27->SetTagName("wall");
  middleWal28 = new GameObject(ASSETS_TILES, 3.f, 32, 32, 0, 0, 675, 630, b2BodyType::b2_staticBody, world, window);
  middleWal28->SetTagName("wall");

  tileGroup = new TileGroup(window, 12, 12, ASSETS_MAPS, 4.f, 16, 16, ASSETS_TILES);

  contactEventManager = new ContactEventManager(gameObjects, gameObjectsDeleteList);
}

Game::~Game()
{
}

//Starting things
void Game::Start()
{
  flags += b2Draw::e_shapeBit;
  world->SetDebugDraw(drawPhysics);
  drawPhysics->SetFlags(flags);
  world->SetContactListener(contactEventManager);

  AddGameObject(player1);
  AddGameObject(chest1);
  AddGameObject(chest2);
  AddGameObject(chest3);
  AddGameObject(chest4);
  AddGameObject(chest5);
  AddGameObject(chest6);
  AddGameObject(chest7);
  AddGameObject(chest8);
  AddGameObject(chest9);
  AddGameObject(chest10);
  AddGameObject(bomb1);
  AddGameObject(bomb2);
  AddGameObject(upperWalls1);
  AddGameObject(upperWalls2);
  AddGameObject(upperWalls3);
  AddGameObject(upperWalls4);
  AddGameObject(upperWalls5);
  AddGameObject(upperWalls6);
  AddGameObject(upperWalls7);
  AddGameObject(leftSideWall);
  AddGameObject(leftSideWal2);
  AddGameObject(leftSideWal3);
  AddGameObject(leftSideWal4);
  AddGameObject(leftSideWal5);
  AddGameObject(leftSideWal6);
  AddGameObject(rightSideWall);
  AddGameObject(rightSideWal2);
  AddGameObject(rightSideWal3);
  AddGameObject(rightSideWal4);
  AddGameObject(rightSideWal5);
  AddGameObject(rightSideWal6);
  AddGameObject(downWal1);
  AddGameObject(downWal2);
  AddGameObject(downWal3);
  AddGameObject(downWal4);
  AddGameObject(downWal5);
  AddGameObject(downWal6);
  AddGameObject(downWal7);
  AddGameObject(middleWal1);
  AddGameObject(middleWal2);
  AddGameObject(middleWal3);
  AddGameObject(middleWal5);
  AddGameObject(middleWal6);
  AddGameObject(middleWal7);
  AddGameObject(middleWal9);
  AddGameObject(middleWal10);
  AddGameObject(middleWal11);
  AddGameObject(middleWal12);
  AddGameObject(middleWal13);
  AddGameObject(middleWal14);
  AddGameObject(middleWal15);
  AddGameObject(middleWal16);
  AddGameObject(middleWal17);
  AddGameObject(middleWal18);
  AddGameObject(middleWal19);
  AddGameObject(middleWal20);
  AddGameObject(middleWal22);
  AddGameObject(middleWal23);
  AddGameObject(middleWal24);
  AddGameObject(middleWal26);
  AddGameObject(middleWal27);
  AddGameObject(middleWal28);

  textObj1->SetTextStr("Hello game engine");

  /*circle->setRadius(2.f);
  circle->setFillColor(sf::Color::Green);
  circle->setOutlineColor(sf::Color::Green);*/
}

void Game::Initialize()
{
  Start();
  MainLoop();
}

void Game::UpdatePhysics()
{
  world->ClearForces();
  world->Step(deltaTime, 8, 8);
}

//Logic, animations, etc
void Game::Update()
{
  deltaTime = gameClock->getElapsedTime().asSeconds();
  gameClock->restart();

  for(auto &gameObject : *gameObjects)
  {
    gameObject->Update(deltaTime);
  }

  //circle->setPosition(player1->GetSprite()->getPosition());

  //lightIdle->Play(deltaTime);

  /*if(std::abs(InputSystem::Axis().x) > 0 || std::abs(InputSystem::Axis().y) > 0)
  {
    runAnimation->Play(deltaTime);
  }
  else
  {
    idleAnimation->Play(deltaTime);
  }*/
}

void Game::MainLoop()
{
  while (window->isOpen())
  {
    while(window->pollEvent(*event))
    {
      if(event->type == sf::Event::Closed)
      {
        window->close();
      }
    }

    UpdatePhysics();
    Input();
    Update();
    Render();
  }
  Destroy();
}

void Game::Render()
{
  for(auto& gameobject: *gameObjectsDeleteList)
  {
      gameObjects->erase(std::remove(gameObjects->begin(), gameObjects->end(), gameobject), gameObjects->end());
      delete gameobject;
  }
  gameObjectsDeleteList->clear();

  window->clear(sf::Color::Black);
  Draw();
  window->display();
}

//Drawing sprites or geometry.
void Game::Draw()
{
  //player1->Draw();
  //window->draw(*circle);

  tileGroup->Draw();

  for(auto &gameObject : *gameObjects)
  {
    gameObject->Draw();
  }

  window->draw(*textObj1->GetText());
  //world->DebugDraw();
}

//Keyboard, joysticks, etc.
void Game::Input()
{
}

void Game::Destroy()
{
  delete window;
  delete event;
}

void Game::AddGameObject(GameObject* gameObject)
{
  gameObjects->push_back(gameObject);
}