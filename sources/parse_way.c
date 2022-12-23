#include "../header/so_long.h"


void	virus_col(t_game *game, int y, int x, int add)
{
	while (y >= 1 && y < game->nb_col - 1 && game->copy_map[y][x] != WALL)
	{
		if (!game->test)
			game->test = game->copy_map[y][x] != '*';
		game->copy_map[y][x] = '*';
		y += add;
	}
}

void	virus_row(t_game *game, int y, int x, int add)
{
	while (x >= 1 && x < game->nb_row - 1 && game->copy_map[y][x] != WALL)
	{
		if (!game->test)
			game->test = game->copy_map[y][x] != '*';
		game->copy_map[y][x] = '*';
		x += add;
	}
}

void	virus(int y, int x, t_game *game)
{
	virus_col(game, y, x, 1);
	virus_col(game, y, x, -1);
	virus_row(game, y, x, -1);
	virus_row(game, y, x, 1);
}

void	check_valid_path(t_game *game)
{
	int	x;
	int	y;

	virus(game->player.row, game->player.col, game);
	game->test = 0;
	y = -1;
	while (++y < game->nb_row)
	{
		x = -1;
		while (++x < game->nb_col)
		{
			if (game->copy_map[y][x] == '*')
				virus(y, x, game);
		}
	}
}
