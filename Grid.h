#include <SDL2/SDL.h>
#include "XO.h"

//manager for the game
class Grid
{
	private:
		enum Player
		{
			NONE,
			CROSS,
			CIRCLE
		};

		Player player;
		Player grid [9];

		bool game_running;
		int screen_width, screen_height;
		SDL_Renderer * renderer;

		void init();//set the grid entrys to NONE
		//check if we won based on
		bool won_row(int r);
		bool won_col(int c);
		bool won_top_left_bottom_right();
		bool won_bottom_left_top_right();
		bool check_draw();
		//check row r and column c, if r==c check diagonals
		bool check(int r, int c);
	public:
		Grid(int screen_width, int screen_height, SDL_Renderer * renderer);//create a grid
		void click(int x, int y);//click on an x,y
};
