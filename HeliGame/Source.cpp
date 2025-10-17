#include "game.hpp"

/**
 * @brief Entry point of the helicopter game application.
 * 
 * Creates an infinite loop that continuously runs game sessions. After each
 * game session ends, a new Game instance is created and started, allowing
 * the player to restart without closing the application.
 * 
 * @return int Exit code (0 for successful termination, though unreachable due to infinite loop)
 */
int main()
{
	// Main game loop - restarts the game after each session ends
	while (true)
	{
		Game game;
		game.run();
	}

	return 0;
}