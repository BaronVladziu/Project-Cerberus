#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cassert>
#include <list>
#include <memory>

class Game;

enum Direction4;
enum Direction8;
class Vector2;

class WindowAdapter;
class CameraMoveFilter;
class EventAdapter;
enum EventType;

class Scene;
class CreatureScene;
class EffectScene;
class LightScene;
class Map;
class SquareArray;
class Square;
enum SquareLayerType;
class SpriteAdapter;
class Animation;

class TextureAdapter;
class TextureArray;

class Creature;
class CreatureRenderer;
class CreaturePlayer;
class CreatureZombie;
enum CreatureType;
enum CreatureState;

class AI;
class AIZombiePassive;

class Abilities;
class Order;
enum OrderType;

class Tile;
class TileRenderer;
enum TileType;

class SpriteEffect;
class SpriteEffectRenderer;
enum SpriteEffectType;

class LightTile;
class LightRenderer;
struct LightColor;

class Hud;
class HudRenderer;
enum HudOption;

class TesterHud;
class TesterHudRenderer;
enum TesterHudOption;