#include "../header/so_long.h"


void	virus_col(t_map *map, int y, int x, int add)
{
	while (y >= 1 && y < map->height - 1 && map->map[y][x] != WALL)
	{
		if (!map->test)
			map->test = map->map[y][x] != '*';
		map->map[y][x] = '*';
		y += add;
	}
}

void	virus_row(t_map *map, int y, int x, int add)
{
	while (x >= 1 && x < map->width - 1 && map->map[y][x] != WALL)
	{
		if (!map->test)
			map->test = map->map[y][x] != '*';
		map->map[y][x] = '*';
		x += add;
	}
}

void	virus(int y, int x, t_map *map)
{
	virus_col(map, y, x, 1);
	virus_col(map, y, x, -1);
	virus_row(map, y, x, -1);
	virus_row(map, y, x, 1);
}

void	find_valid_path(t_map *map)
{
	int	y;
	int	x;

	virus(map->start_y, map->start_x, map);
	map->test = 0;
	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
		{
			if (map->map[y][x] == '*')
				virus(y, x, map);
		}
	}
}
