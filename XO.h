/*
 *	Rhys Trueman || 25/7/2020
 *
 *	draws x's and o's for tic tac toe
 *	
 */

//draw a green x
void draw_x(SDL_Renderer * renderer, int x, int y, int w, int h)
{
	//set the render color to green
	SDL_SetRenderDrawColor(renderer, 0x00, 0xFF, 0x00, 0xFF);

	//top left to bottom right
	SDL_RenderDrawLine(renderer, x, y, x + w, y + h);

	//bottom left to top right
	SDL_RenderDrawLine(renderer, x, y + h, x + w, y);
}
