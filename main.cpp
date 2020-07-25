#include "Window.h"
#include "DrawGrid.h"
#include "XO.h"
#include <iostream>

int main()
{
	Window w ("Tic Tac Toe", 600, 600);
	
	DrawGrid(w.rend(), 600, 600);
	draw_x(w.rend(), 0, 0, 200, 200);
	SDL_RenderPresent(w.rend());

	SDL_Event e;
	bool running = true;

	while(running)
	{
		while(SDL_PollEvent(&e))
		{
			if(e.type == SDL_QUIT)
			{
				running = false;
			}
		}
	}

	return 0;
}
