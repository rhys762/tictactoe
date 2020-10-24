#include "XO.hpp"
#include <cmath>
#include <iostream>

//draw a green x
void draw_x(SDL_Renderer * renderer, int x, int y, int w, int h)
{
	//set the render color to green
	SDL_SetRenderDrawColor(renderer, 0x00, 0xFF, 0x00, 0xFF);
	
	//offset is the indent of the cross from the external of the box,
	//ie to stop the cross taking up the whole square
	int ratio = 5;
	int x_offset = w/ratio;
	int y_offset = h/ratio;

	//the times we iterate through this loop will dictate the width of the lines
	for(int i = 0; i < 5; i++)
	{
		//top left to bottom right
		SDL_RenderDrawLine(renderer, x + x_offset + i, y + y_offset, x + w + i - x_offset, y + h - y_offset);
		//bottom left to top right
		SDL_RenderDrawLine(renderer, x + x_offset + i, y + h - y_offset, x + w + i - x_offset, y + y_offset);
	}
}

//draw o would appear to be more involved
//SDL2 has no draw elipse/circle function
//so i'll be writing my own
void SDL_DrawCircle(SDL_Renderer * renderer, SDL_Circle * c)
{
	//equation of a circle is (x - x_midpoint)^2 + (y - y_midpoint)^2 = r^2
	//this gives y = sqrt(r^2 - (x - x_midpoint)^2) + y_midpoint
/*
	for(int i = c->x - c->r; i < c->x + c->r; i++)
	{
		int sqt = sqrt(pow(c->r, 2) - pow(i - c->x, 2));
		SDL_RenderDrawPoint(renderer, i, c->y + sqt);
		SDL_RenderDrawPoint(renderer, i, c->y - sqt);
	}
*/
	auto top_line = [&](int x)
	{
		return c->y - sqrt(pow(c->r, 2) - pow(x - c->x, 2));
	};
	auto bot_line = [&](int x)
	{
		return c->y + sqrt(pow(c->r, 2) - pow(x - c->x, 2));
	};

	int step_length = 3;
	int last_x = c->x - c->r;
	int x = last_x + step_length;
	for(; x < c->x + c->r; x+=step_length)
	{
		//top semicircle
		SDL_RenderDrawLine(renderer, last_x, top_line(last_x), x, top_line(x));
		//top semicircle
		SDL_RenderDrawLine(renderer, last_x, bot_line(last_x), x, bot_line(x));

		last_x = x;
	}

	//top semicircle
	SDL_RenderDrawLine(renderer, last_x, top_line(last_x), c->x + c->r, c->y);
	//top semicircle
	SDL_RenderDrawLine(renderer, last_x, bot_line(last_x), c->x + c->r, c->y);


}

void draw_o(SDL_Renderer * renderer, int x, int y, int r)
{
	//set render color to blue
	SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0xFF, 0xFF);

	//circle struct
	SDL_Circle c;
	c.x = x;
	c.y = y;

	for(int i = 0; i < 5; i++)
	{
		c.r = r + i;
		SDL_DrawCircle(renderer, &c);
	}
}
