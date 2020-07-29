#include "Window.h"
#include "Grid.h"
#include <iostream>

int main()
{
	int screen_width = 600, screen_height = 600;
	Window w ("Tic Tac Toe", screen_width, screen_height);
	

	Grid grid (screen_width, screen_height, w.rend());

	SDL_Event e;
	bool running = true;

	while(running)
	{
		while(SDL_PollEvent(&e))
		{
			switch(e.type)
			{
				case SDL_QUIT:
					running = false;
					break;
				case SDL_MOUSEBUTTONDOWN:
					int x, y;
					SDL_GetMouseState(&x,&y);
					grid.click(x,y);
					break;
			}
		}
	}

	return 0;
}
