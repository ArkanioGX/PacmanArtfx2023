#include "Game.h"

int main(void) {
	const int screenWidth = 640;
	const int screenHeight = 665;

    Game game(screenWidth, screenHeight, "Pacman - ARTFX2023 - MOLLET Clarence", 60);

    while (!game.gameShouldClose()) {
        game.Update();
    }

    return 0;
}