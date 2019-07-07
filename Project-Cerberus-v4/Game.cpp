#include "Game.h"
#include "EventType.h"
#include "Scene.h"
#include "WindowAdapter.h"

Game::Game()
	: _ifTesterMode(true),
	_TILE_LENGTH(16),
	_scene(_TILE_LENGTH),
	_hud(_window.getWindowSize(), _TILE_LENGTH),
	_testerHud(_window.getWindowSize(), _TILE_LENGTH)
{}
void Game::startLoop()
{
	while (_window.isOpen())
	{
		executeEvents();
		drawFrame();
	}
}
void Game::executeEvents()
{
	EventType event = _window.pollEvent();
	while (event != EventType::NoMoreEvents)
	{
		executeEvent(event);
		event = _window.pollEvent();
	}
}
void Game::executeEvent(EventType event)
{
	switch (event)
	{
	case EventType::WindowClosedEvent:
		_window.close();
		break;
	case EventType::EscButtonPressedEvent:
		_window.close();
		break;
	case EventType::LeftMouseButtonPressedEvent:
		if (_ifTesterMode == true)
		{
			writeMousePosition();
		}
		break;
	case EventType::RightMouseButtonPressedEvent:
		if (_ifTesterMode == true)
		{
			useTesterHudAction();
			_scene.addSpriteEffect(SpriteEffectType::SparksSpriteEffect, _window.getMousePosition(_TILE_LENGTH), Direction4::Up);
		}
		break;
	case EventType::Nr6ButtonPressedEvent:
		if (_ifTesterMode == true)
		{
			_testerHud.chooseOption(TesterHudOption::ChangeToFloorTesterHudOption);
		}
		break;
	case EventType::Nr7ButtonPressedEvent:
		if (_ifTesterMode == true)
		{
			_testerHud.chooseOption(TesterHudOption::ChangeToObstacleTesterHudOption);
		}
		break;
	case EventType::Nr8ButtonPressedEvent:
		if (_ifTesterMode == true)
		{
			_testerHud.chooseOption(TesterHudOption::ChangeToWallTesterHudOption);
		}
		break;
	case EventType::Nr9ButtonPressedEvent:
		if (_ifTesterMode == true)
		{
			_testerHud.chooseOption(TesterHudOption::ChangeToVoidTesterHudOption);
		}
		break;
	case EventType::Nr0ButtonPressedEvent:
		if (_ifTesterMode == true)
		{
			_testerHud.chooseOption(TesterHudOption::CreateZombieTesterHudOption);
		}
		break;
	case EventType::MinusButtonPressedEvent:
		_window.zoomOut();
		break;
	case EventType ::PlusButtonPressedEvent:
		_window.zoomIn();
		break;
	case EventType::AButtonPressedEvent:
		_hud.chooseOption(HudOption::MeleeAttackHudOption);
		break;
	case EventType::UpArrowPressedEvent:
		setPlayerOrder(Direction4::Up);
		break;
	case EventType::DownArrowPressedEvent:
		setPlayerOrder(Direction4::Down);
		break;
	case EventType::LeftArrowPressedEvent:
		setPlayerOrder(Direction4::Left);
		break;
	case EventType::RightArrowPressedEvent:
		setPlayerOrder(Direction4::Right);
		break;
	case EventType::SpaceButtonPressedEvent:
		setPlayerOrder(Direction4::Center);
		break;
	case EventType::UnknownEvent:
		break;
	default:
		std::cout << "This key has no function yet" << std::endl;
		break;
	}
}
void Game::writeMousePosition() const
{
	Vector2 pos = _window.getMousePosition(_TILE_LENGTH);
	std::cout << pos.x << " " << pos.y << std::endl;
}
void Game::useTesterHudAction()
{
	switch (_testerHud.getChosenOption())
	{
	case TesterHudOption::ChangeToFloorTesterHudOption:
		_scene.setTile(TileType::FloorTile, _window.getMousePosition(_TILE_LENGTH));
		break;
	case TesterHudOption::ChangeToObstacleTesterHudOption:
		_scene.setTile(TileType::ObstacleTile, _window.getMousePosition(_TILE_LENGTH));
		break;
	case TesterHudOption::ChangeToWallTesterHudOption:
		_scene.setTile(TileType::WallTile, _window.getMousePosition(_TILE_LENGTH));
		break;
	case TesterHudOption::ChangeToVoidTesterHudOption:
		_scene.setTile(TileType::EmptyTile, _window.getMousePosition(_TILE_LENGTH));
		break;
	case TesterHudOption::CreateZombieTesterHudOption:
		_scene.createCreature(CreatureType::Zombie, _window.getMousePosition(_TILE_LENGTH));
		break;
	case TesterHudOption::NoTesterHudOption:
		break;
	default:
		std::cout << "This tester hud option has no function yet" << std::endl;
		break;
	}
}
void Game::setPlayerOrder(Direction4 direction)
{
	if (direction == Direction4::Center)
	{
		_scene.setPlayerOrder(OrderType::NoOrder, Direction4::Up);
	}
	else
	{
		switch (_hud.getChosenOption())
		{
		case HudOption::NoHudOption:
			_scene.setPlayerOrder(OrderType::MoveOrder, direction);
			break;
		case HudOption::MeleeAttackHudOption:
			_scene.setPlayerOrder(OrderType::MeleeAttackOrder, direction);
			break;
		default:
			std::cout << "This hud option has no function yet" << std::endl;
			break;
		}
	}
	nextTurn();
}
void Game::nextTurn()
{
	_hud.reset();
	std::cout << "--- NEXT TURN ---" << std::endl; //<---
	_scene.nextTurn();
}
void Game::drawFrame()
{
	_window.clear();
	_window.setView((_scene.getViewCenterPosition() + Vector2(1, 1)) * _TILE_LENGTH); //nie wiem sk¹d wynika dodanie (1,1), ale tak jest dobrze
	_scene.draw(_window);
	_window.resetView();
	_hud.draw(_window);
	if (_ifTesterMode == true)
	{
		_testerHud.draw(_window);
	}
	_window.display();
}
Game::~Game()
{}