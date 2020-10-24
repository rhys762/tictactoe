#include "Grid.hpp"
#include "DrawGrid.hpp"

void Grid::init()//set the grid entrys to NONE
{
	for(auto & t : grid)
	{
		t = NONE;
	}
	game_running = true;
	DrawGrid(renderer, screen_width, screen_height);
	SDL_RenderPresent(renderer);
}
		
//check if we won based on
bool Grid::won_row(int r)
{
	//need to check if there is a win from row r
	return (grid[3*r] == grid[3*r + 1] && grid[3*r + 1] == grid[3*r + 2]);
}

bool Grid::won_col(int c)
{
	//need to check if there is a win from column c
	return (grid[c] == grid[3 + c] && grid[3 + c] == grid[6 + c]);
}

bool Grid::won_top_left_bottom_right()
{
	//check top left to bottom right diagonal
	return (grid[0] != NONE && grid[0] == grid[4] && grid[4] == grid[8]);
}

bool Grid::won_bottom_left_top_right()
{
	//check bottom left to top right diagonal
	return (grid[2] != NONE && grid[2] == grid[4] && grid[4] == grid[6]);
}

bool Grid::check_draw()
{
	int count = 0;
	for(auto & t : grid)
	{
		if(t == NONE)
		{
			count++;
		}
	}

	return !count;
}

#include <iostream>
//check row r and column c, if r==c check diagonals
//draw a line over the winning trio and freeze game
bool Grid::check(int r, int c)
{

	SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);
	if(won_row(r))
	{
		int y = screen_height/6 + r*screen_height/3;
		int x1 = screen_width/6;
		int x2 = 5*screen_width/6;
		for(int i = -1; i <= 1; i++)
		{
			SDL_RenderDrawLine(renderer, x1, y + i, x2, y + i);
		}
		return true;
	}

	if(won_col(c))
	{
		int x = screen_width/6 + c*screen_width/3;
		int y1 = screen_height/6;
		int y2 = 5*screen_height/6;
		for(int i = -1; i <= 1; i++)
		{
			SDL_RenderDrawLine(renderer, x + i, y1, x + i, y2);
		}
		return true;
	}

	if(won_top_left_bottom_right())
	{
		int x1 = screen_width/6;
		int y1 = screen_height/6;

		int x2 = 5*screen_width/6;
		int y2 = 5*screen_height/6;
		for(int i = -1; i <= 1; i++)
		{
			SDL_RenderDrawLine(renderer, x1 + i, y1, x2 + i, y2);
		}
		return true;
	}

	if(won_bottom_left_top_right())
	{
		int x1 = screen_width/6;
		int y1 = 5*screen_height/6;

		int x2 = 5*screen_width/6;
		int y2 = screen_height/6;
		for(int i = -1; i <= 1; i++)
		{
			SDL_RenderDrawLine(renderer, x1 + i, y1, x2 + i, y2);
		}
		return true;
	}

	return check_draw();
}

Grid::Grid(int screen_width, int screen_height, SDL_Renderer * renderer)//create a grid
{
	this->screen_width = screen_width;
	this->screen_height = screen_height;
	this->renderer = renderer;

	init();
	player = CIRCLE;
}

void Grid::click(int x, int y)//click on an x,y
{
	if(!game_running)
	{
		init();
		return;
	}

	int box_width = screen_width/3, box_height = screen_height/3;
	int row = y/box_height;
	int column = x/box_width;

	int tile_index = column + row*3;

	//we only have to do anything if an unclaimed box was clicked
	if(grid[tile_index] == NONE)
	{
		int min_dim = (box_width < box_height) ? box_width : box_height;

		if(player == CROSS)
		{
			draw_x(renderer, column*box_width, row*box_height, box_width, box_height);
			grid[tile_index] = player;
			player = CIRCLE;
		}
		else
		{
			draw_o(renderer, (column + 0.5)*box_width, (row + 0.5) * box_height, min_dim * 0.3);
			grid[tile_index] = player;
			player = CROSS;
		}

		if(check(row, column))
		{
			game_running = false;
		}
		SDL_RenderPresent(renderer);
	}	
}
