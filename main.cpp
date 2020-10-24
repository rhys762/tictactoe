#include "Window.hpp"
#include "Grid.hpp"
#include <iostream>

int main()
{
	const int screen_width = 600, screen_height = 600;
	//running is condition for the main loop, set by window constructor
	bool running;
	Window w ("Tic Tac Toe", screen_width, screen_height, &running);
	

	Grid grid (screen_width, screen_height, w.renderer());

	SDL_Event e;

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
