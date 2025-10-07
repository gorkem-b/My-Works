#include "game.hpp"
#include "stringhelper.hpp"
#include <iostream>
#include <stdlib.h>
#include <time.h>

const sf::Time Game::TimePerFrame = sf::seconds(1.f / 60.f);
const float BLOCK_WIDTH = WIDTH / 10;
const float BLOCK_HEIGHT = HEIGHT / 40;

Game::Game()
	: mWindow(sf::VideoMode(640, 480), "SFML Application", sf::Style::Close)
	, mTexture()
	, helicopter(sf::Vector2f(COPTER_WIDTH, COPTER_HEIGHT))
	, exp(sf::Vector2f(EXP_WIDTH, EXP_HEIGHT))
	, mFont()
	, dead(false)
	, height(8)
	, mStatisticsText()
	, mStatisticsUpdateTime()
	, mStatisticsNumFrames(0)
	, mIsMovingUp(false)
	, mIsMovingDown(false)
	, mIsMovingRight(false)
	, mIsMovingLeft(false)
	, PlayerSpeed(0)
	, acc(9)
{
	loadTextures();
	initializeHelicopter();
	initializeWalls();
	initializeBricks();
	initializeFortresses();
}

void Game::loadTextures()
{
	if (!mTexture.loadFromFile("heli.png"))
	{
		// Handle loading error
	}
	if (!smoke_texture.loadFromFile("smoke.png"))
	{
		// Handle loading error
	}
	if (!exp_texture.loadFromFile("explosion.png"))
	{
		// Handle loading error
	}
	exp.setTexture(&exp_texture);
	helicopter.setTexture(&mTexture);
}

void Game::initializeHelicopter()
{
	helicopter.setPosition(100.f, 100.f);
	srand(time(NULL));
}

void Game::initializeWalls()
{
	for (int i = 0; i < WIDTH / BLOCK_WIDTH + 1; i++)
	{
		wall.push_back(height / 2);
	}
}

void Game::initializeBricks()
{
	std::vector<sf::RectangleShape> brickColumn(height / 2, sf::RectangleShape(sf::Vector2f(BLOCK_WIDTH, BLOCK_HEIGHT)));
	
	for (int i = 0; i <= wall.size(); i++)
	{
		top_bricks.push_back(brickColumn);
		bottom_bricks.push_back(brickColumn);
	}
	
	positionTopBricks();
	positionBottomBricks();
}

void Game::positionTopBricks()
{
	int columnIndex = 0;
	for (auto &column : top_bricks)
	{
		int rowIndex = 0;
		for (auto &brick : column)
		{
			brick.setPosition(columnIndex * BLOCK_WIDTH, rowIndex * BLOCK_HEIGHT);
			brick.setFillColor(sf::Color(137, 232, 162));
			rowIndex++;
		}
		columnIndex++;
	}
}

void Game::positionBottomBricks()
{
	int columnIndex = 0;
	for (auto &column : bottom_bricks)
	{
		int rowIndex = 0;
		for (auto &brick : column)
		{
			brick.setPosition(columnIndex * BLOCK_WIDTH, HEIGHT - BLOCK_HEIGHT - rowIndex * BLOCK_HEIGHT);
			brick.setFillColor(sf::Color(137, 232, 162));
			rowIndex++;
		}
		columnIndex++;
	}
}

void Game::initializeFortresses()
{
	fortresses.push_back(sf::RectangleShape(sf::Vector2f(BLOCK_WIDTH, FORT_HEIGHT)));
	fortresses.push_back(sf::RectangleShape(sf::Vector2f(BLOCK_WIDTH, FORT_HEIGHT)));
	
	fortresses.front().setPosition(10 * BLOCK_WIDTH, height / 3 + rand() % (height / 2));
	fortresses.back().setPosition(18 * BLOCK_WIDTH, height / 3 + rand() % (height / 2));
	
	fortresses.back().setFillColor(sf::Color(137, 232, 162));
	fortresses.front().setFillColor(sf::Color(137, 232, 162));
}

void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	
	while (mWindow.isOpen())
	{
		sf::Time elapsedTime = clock.restart();
		timeSinceLastUpdate += elapsedTime;
		
		while (timeSinceLastUpdate > TimePerFrame)
		{
			timeSinceLastUpdate -= TimePerFrame;
			processEvents();
			
			if (!update(TimePerFrame))
				return;
		}

		updateStatistics(elapsedTime);
		render();
	}
}

void Game::processEvents()
{
	sf::Event event;
	while (mWindow.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::KeyPressed:
			handlePlayerInput(event.key.code, true);
			break;

		case sf::Event::KeyReleased:
			handlePlayerInput(event.key.code, false);
			break;

		case sf::Event::Closed:
			mWindow.close();
			exit(0);
			break;
		}
	}
}

bool Game::update(sf::Time elapsedTime)
{
	static int animationFrame = 0;
	static int helicopterFrame = 0;
	
	if (!dead)
	{
		updateHelicopterPhysics(helicopterFrame);
		updateTerrainGeneration();
		moveTerrain();
		updateFortresses();
		updateSmoke(helicopterFrame);
		
		if (checkCollisions())
		{
			dead = true;
			exp.setPosition(helicopter.getPosition().x + 10, helicopter.getPosition().y);
			return true;
		}
		
		helicopter.move(sf::Vector2f(0, PlayerSpeed) * elapsedTime.asSeconds());
		helicopter.setTextureRect(sf::IntRect((helicopterFrame + 1) * 132, 0, -132, 62));
	}
	else
	{
		return updateExplosionAnimation(animationFrame);
	}
	
	return true;
}

void Game::updateHelicopterPhysics(int &helicopterFrame)
{
	if (mIsMovingUp)
	{
		acc = 20;
		helicopterFrame = (helicopterFrame + 1) % 4;
	}
	else
	{
		acc = 0;
	}
	
	PlayerSpeed += (GRAVITY - acc);
}

void Game::updateTerrainGeneration()
{
	static int targetHeight = rand() % (height - 2) + 1;
	static int frameCounter = 1;
	
	if ((frameCounter = (frameCounter + 1) % 1000) == 0)
	{
		if (height < MAX_HEIGHT)
			height++;
	}
	
	if (shouldGenerateNewColumn())
	{
		generateNewTerrainColumn(targetHeight);
	}
}

void Game::moveTerrain()
{
	const float scrollSpeed = -1 * BLOCK_WIDTH / 10;
	
	for (auto &column : top_bricks)
	{
		for (auto &brick : column)
		{
			brick.move(scrollSpeed, 0);
		}
	}
	
	for (auto &column : bottom_bricks)
	{
		for (auto &brick : column)
		{
			brick.move(scrollSpeed, 0);
		}
	}
}

bool Game::shouldGenerateNewColumn()
{
	return top_bricks.front().front().getPosition().x <= -1 * BLOCK_WIDTH;
}

void Game::generateNewTerrainColumn(int &targetHeight)
{
	// Adjust wall height towards target
	if (wall.back() < targetHeight)
	{
		wall.pop_front();
		wall.push_back(wall.back() + 1);
	}
	else if (wall.back() > targetHeight)
	{
		wall.pop_front();
		wall.push_back(wall.back() - 1);
	}
	else
	{
		targetHeight = rand() % (height - 2) + 1;
	}

	// Remove old columns
	top_bricks.pop_front();
	bottom_bricks.pop_front();
	
	// Create new columns
	createNewBrickColumns();
}

/**
 * @brief Creates new columns of bricks for both top and bottom walls.
 * 
 * This function generates two vertical columns of rectangular brick shapes based on
 * the last wall height value. The top column extends downward from the top of the screen,
 * while the bottom column extends upward from the bottom. Each brick is positioned
 * horizontally adjacent to the existing rightmost column and colored with a light green tint.
 * 
 * The number of bricks in each column is determined by the last element in the wall vector:
 * - Top column: wall.back() bricks
 * - Bottom column: (height - wall.back()) bricks
 * 
 * Each brick has dimensions of BLOCK_WIDTH x BLOCK_HEIGHT and is filled with
 * color RGB(137, 232, 162).
 * 
 * @pre top_bricks must contain at least one column with at least one brick
 * @pre wall vector must not be empty
 * @post Two new columns are added to top_bricks and bottom_bricks respectively
 */
void Game::createNewBrickColumns()
{
	int topBrickCount = wall.back();
	int bottomBrickCount = height - wall.back();
	
	std::vector<sf::RectangleShape> topColumn(topBrickCount, sf::RectangleShape(sf::Vector2f(BLOCK_WIDTH, BLOCK_HEIGHT)));
	std::vector<sf::RectangleShape> bottomColumn(bottomBrickCount, sf::RectangleShape(sf::Vector2f(BLOCK_WIDTH, BLOCK_HEIGHT)));
	
	float newColumnX = top_bricks.back().front().getPosition().x + BLOCK_WIDTH;
	
	for (int i = 0; i < topBrickCount; i++)
	{
		topColumn[i].setPosition(newColumnX, i * BLOCK_HEIGHT);
		topColumn[i].setFillColor(sf::Color(137, 232, 162));
	}
	
	for (int i = 0; i < bottomBrickCount; i++)
	{
		bottomColumn[i].setPosition(newColumnX, HEIGHT - BLOCK_HEIGHT - i * BLOCK_HEIGHT);
		bottomColumn[i].setFillColor(sf::Color(137, 232, 162));
	}
	
	top_bricks.push_back(topColumn);
	bottom_bricks.push_back(bottomColumn);
}

void Game::updateFortresses()
{
	const float scrollSpeed = -1 * BLOCK_WIDTH / 10;
	
	if (fortresses.front().getPosition().x < 0)
	{
		fortresses.pop_front();
		fortresses.push_back(sf::RectangleShape(sf::Vector2f(BLOCK_WIDTH, FORT_HEIGHT)));
		
		float newX = fortresses.front().getPosition().x + 8 * BLOCK_WIDTH;
		float newY = rand() % (HEIGHT - FORT_HEIGHT);
		fortresses.back().setPosition(newX, newY);
		fortresses.back().setFillColor(sf::Color(137, 232, 162));
	}
	
	fortresses.front().move(scrollSpeed, 0);
	fortresses.back().move(scrollSpeed, 0);
}

void Game::updateSmoke(int helicopterFrame)
{
	static int period = 0;
	
	for (auto &smokeParticle : smoke)
	{
		smokeParticle.body.move(sf::Vector2f(-1 * SMOKE_WIDTH, 0));
		smokeParticle.w = (smokeParticle.w + 1) % 10;
		smokeParticle.body.setTextureRect(sf::IntRect(smokeParticle.w * 128, 0, 128, 128));
	}
	
	period = (period + 1) % WALL_PERIOD;
	
	if (period == 0 && mIsMovingUp)
	{
		createSmokeParticle();
		
		if (smoke.front().body.getPosition().x < 0)
			smoke.pop_front();
	}
}

void Game::createSmokeParticle()
{
	smk smokeParticle;
	smokeParticle.body = sf::RectangleShape(sf::Vector2f(SMOKE_WIDTH, SMOKE_HEIGHT));
	smokeParticle.h = smokeParticle.w = 0;
	smokeParticle.body.setPosition(helicopter.getPosition());
	smokeParticle.body.setTexture(&smoke_texture);
	smoke.push_back(smokeParticle);
}

bool Game::checkCollisions()
{
	sf::FloatRect helicopterBounds = helicopter.getGlobalBounds();
	
	if (checkBrickCollisions(helicopterBounds))
		return true;
	
	if (checkFortressCollisions(helicopterBounds))
		return true;
	
	return false;
}

bool Game::checkBrickCollisions(const sf::FloatRect &helicopterBounds)
{
	for (auto &column : top_bricks)
	{
		for (auto &brick : column)
		{
			if (helicopterBounds.intersects(brick.getGlobalBounds()))
				return true;
		}
	}
	
	for (auto &column : bottom_bricks)
	{
		for (auto &brick : column)
		{
			if (helicopterBounds.intersects(brick.getGlobalBounds()))
				return true;
		}
	}
	
	return false;
}

bool Game::checkFortressCollisions(const sf::FloatRect &helicopterBounds)
{
	return helicopterBounds.intersects(fortresses.front().getGlobalBounds()) || 
		   helicopterBounds.intersects(fortresses.back().getGlobalBounds());
}

bool Game::updateExplosionAnimation(int &animationFrame)
{
	static int frameX = 0;
	static int frameY = 0;
	
	if (frameY == 5)
	{
		frameY = frameX = 0;
		return false;
	}
	
	exp.setTextureRect(sf::IntRect(frameX * 64, frameY * 64, 64, 64));
	frameX = (frameX + 1) % 5;
	
	if (frameX == 0)
		frameY++;
	
	return true;
}

void Game::render()
{
	mWindow.clear();
	
	renderSmoke();
	mWindow.draw(helicopter);
	renderBricks();
	renderFortresses();
	
	if (dead)
		mWindow.draw(exp);
	
	mWindow.draw(mStatisticsText);
	mWindow.display();
}

void Game::renderSmoke()
{
	for (auto &smokeParticle : smoke)
	{
		mWindow.draw(smokeParticle.body);
	}
}

void Game::renderBricks()
{
	for (auto &column : top_bricks)
	{
		for (auto &brick : column)
		{
			mWindow.draw(brick);
		}
	}
	
	for (auto &column : bottom_bricks)
	{
		for (auto &brick : column)
		{
			mWindow.draw(brick);
		}
	}
}

void Game::renderFortresses()
{
	mWindow.draw(fortresses.front());
	mWindow.draw(fortresses.back());
}

void Game::wall_draw()
{
	sf::RectangleShape brick(sf::Vector2f(BLOCK_WIDTH, BLOCK_HEIGHT));
	brick.setFillColor(sf::Color::Green);
	
	int columnIndex = 0;
	for (auto wallHeight = wall.begin(); wallHeight != wall.end(); wallHeight++)
	{
		for (int rowIndex = 0; rowIndex < *wallHeight; rowIndex++)
		{
			brick.setPosition(columnIndex * BLOCK_WIDTH, rowIndex * BLOCK_HEIGHT);
			mWindow.draw(brick);
		}
		
		for (int rowIndex = 0; rowIndex < (height - *wallHeight); rowIndex++)
		{
			brick.setPosition(columnIndex * BLOCK_WIDTH, HEIGHT - BLOCK_HEIGHT - rowIndex * BLOCK_HEIGHT);
			mWindow.draw(brick);
		}
		
		columnIndex++;
	}
}

void Game::updateStatistics(sf::Time elapsedTime)
{
	mStatisticsUpdateTime += elapsedTime;
	mStatisticsNumFrames += 1;

	if (mStatisticsUpdateTime >= sf::seconds(1.0f))
	{
		mStatisticsText.setString(
			"Frames / Second = " + toString(mStatisticsNumFrames) + "\n" +
			"Time / Update = " + toString(mStatisticsUpdateTime.asMicroseconds() / mStatisticsNumFrames) + "us");

		mStatisticsUpdateTime -= sf::seconds(1.0f);
		mStatisticsNumFrames = 0;
	}
}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{
	if (key == sf::Keyboard::W)
		mIsMovingUp = isPressed;
	else if (key == sf::Keyboard::S)
		mIsMovingDown = isPressed;
	else if (key == sf::Keyboard::A)
		mIsMovingLeft = isPressed;
	else if (key == sf::Keyboard::D)
		mIsMovingRight = isPressed;
}