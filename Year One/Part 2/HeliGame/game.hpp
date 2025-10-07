#ifndef BOOK_GAME_HPP
#define BOOK_GAME_HPP

#include <SFML/Graphics.hpp>
#include <list>
#include <vector>

// Window dimensions
#define WIDTH 640
#define HEIGHT 480

// Helicopter dimensions
#define COPTER_HEIGHT (HEIGHT / 13)
#define COPTER_WIDTH ((HEIGHT / (62.f * 13)) * 132.f)

// Game constants
#define MAX_HEIGHT 12
#define WALL_PERIOD 6
#define GRAVITY 10

// Particle dimensions
#define SMOKE_WIDTH 15
#define SMOKE_HEIGHT 15

// Fortress dimensions
#define FORT_HEIGHT (HEIGHT / 10 * 3)

// Explosion dimensions
#define EXP_WIDTH 60
#define EXP_HEIGHT 60

// Smoke particle structure
struct SmokeParticle
{
	sf::RectangleShape body;
	int width;
	int height;
};

/**
 * @class Game
 * @brief Main game class that manages the helicopter game loop and state.
 * 
 * This class implements a side-scrolling helicopter game where the player navigates
 * through obstacles. It inherits from sf::NonCopyable to prevent copying of game instances.
 * 
 * The game features:
 * - Fixed timestep game loop with frame rate statistics
 * - Player-controlled helicopter with acceleration-based movement
 * - Procedurally generated walls with bricks and fortresses
 * - Particle effects (smoke trail and explosion)
 * - Collision detection and game over state
 * 
 * @note This class follows the SFML game architecture pattern with separate
 *       event processing, update, and render phases.
 */
class Game : private sf::NonCopyable
{
public:
	Game();
	void run();

private:
	// Core game loop functions
	void processEvents();
	bool update(sf::Time elapsedTime);
	void render();

	// Helper functions
	void updateStatistics(sf::Time elapsedTime);
	void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);
	void wall_draw();

private:
	// Game timing
	static const sf::Time TimePerFrame;

	// Player properties
	float mPlayerSpeed;
	float mAcceleration;
	int mHeight;
	bool mIsDead;

	// Movement flags
	bool mIsMovingUp;
	bool mIsMovingDown;
	bool mIsMovingRight;
	bool mIsMovingLeft;

	// Window and rendering
	sf::RenderWindow mWindow;
	
	// Textures
	sf::Texture mHelicopterTexture;
	sf::Texture mSmokeTexture;
	sf::Texture mExplosionTexture;

	// Game objects
	sf::RectangleShape mHelicopter;
	sf::RectangleShape mExplosion;
	std::list<SmokeParticle> mSmokeParticles;
	
	// Level objects
	std::list<int> mWallHeights;
	std::list<std::vector<sf::RectangleShape>> mTopBricks;
	std::list<std::vector<sf::RectangleShape>> mBottomBricks;
	std::list<sf::RectangleShape> mFortresses;
	sf::Vector2f mWallPosition;

	// Statistics and UI
	sf::Font mFont;
	sf::Text mStatisticsText;
	sf::Time mStatisticsUpdateTime;
	std::size_t mStatisticsNumFrames;
};

#endif // BOOK_GAME_HPP