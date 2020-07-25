
/*
 *	Rhys Trueman || 25/7/2020
 *
 *	A collection of functions that draw a 3 by 3 grid to a renderer for tic tac toe
 */

#include <SDL2/SDL.h>

//draw an individual box
void DrawBox(SDL_Renderer * renderer, int x, int y, int w, int h)
{
	SDL_Rect r;
	r.x = x;
	r.y = y;
	r.w = w;
	r.h = h;

	//first we draw the black outline of the box
	SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
	SDL_RenderFillRect(renderer, &r);

	//now fill it in with grey
	SDL_SetRenderDrawColor(renderer, 0x80, 0x80, 0x80, 0xFF);
	r.x += 2;
	r.y += 2;
	r.w -= 4;
	r.h -= 4;
	SDL_RenderFillRect(renderer, &r);
}

//now we just need to use above 9 times:
void DrawGrid(SDL_Renderer * renderer, int screen_width, int screen_height)
{
	int box_width = screen_width/3; 
	int box_height = screen_height/3;

	for(int x = 0; x < screen_width; x += box_width)
	{
		for(int y = 0; y < screen_height; y+= box_height)
		{
			DrawBox(renderer, x, y, box_width, box_height);
		}
	}	
}

