#ifndef XO_H
#define XO_H

#include <SDL2/SDL.h>

/*
 *	Rhys Trueman || 25/7/2020
 *
 *	draws x's and o's for tic tac toe
 *	
 */

//draw a green x
void draw_x(SDL_Renderer * renderer, int x, int y, int w, int h);

//x,y is the midpoint of the circle
struct SDL_Circle
{
	int x;//midpoint x pixel
	int y;//midpoint y pixel
	int r;//radius in pixels
};

//draw o would appear to be more involved
//SDL2 has no draw elipse/circle function
//so i'll be writing my own
void SDL_DrawCircle(SDL_Renderer * renderer, SDL_Circle * c);

void draw_o(SDL_Renderer * renderer, int x, int y, int r);
#endif
