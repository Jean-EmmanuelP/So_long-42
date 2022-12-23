/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperrama <jperrama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 03:14:48 by jperrama          #+#    #+#             */
/*   Updated: 2022/12/18 02:11:25 by jperrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

/*This function is used to count collectibles.
 * RETURN VALUE : the collectibles in the map. */
int	count_collectibles(t_game *game)
{
	int	i;
	int	j;
	int	count_collectibles;

	i = 0;
	count_collectibles = 0;
	while (game->map && i < game->nb_row)
	{
		j = 0;
		while (game->map[i][j] && j <= game->nb_col)
			if (game->map[i][j++] == 'C')
				count_collectibles++;
		i++;
	}
	return (count_collectibles);
}

/*This function modify the map with the movement of the player.
 * RETURN VALUE : EXIT_SUCCESS or EXIT_NOTHING 
 * TRADUCTION : (possible or not possible) */
int	move_left(t_game *game)
{	
	if (game->map[game->player.row][game->player.col - 1] == '1')
		return (EXIT_NOTHING);
	if (game->map[game->player.row][game->player.col - 1] == 'C')
		return ((game->map[game->player.row][game->player.col] = '0',
			game->map[game->player.row][game->player.col - 1] = 'P'),
			EXIT_SUCCESS);
	if (game->map[game->player.row][game->player.col - 1] == 'E')
	{
		if (count_collectibles(game) == 0)
		{
			game->map[game->player.row][game->player.col] = '0';
			return (game->map[game->player.row][game->player.col - 1] = 'P', 1);
		}
		return (EXIT_NOTHING);
	}
	if (game->map[game->player.row][game->player.col - 1] == '0')
	{
		game->map[game->player.row][game->player.col] = '0';
		return (game->map[game->player.row][game->player.col - 1] = 'P', 0);
	}
	return (EXIT_SUCCESS);
}

/* SAME THING than move_left */
int	move_right(t_game *game)
{
	if (game->map[game->player.row][game->player.col + 1] == '1')
		return (EXIT_NOTHING);
	if (game->map[game->player.row][game->player.col + 1] == 'C')
	{
		game->map[game->player.row][game->player.col] = '0';
		return (game->map[game->player.row][game->player.col + 1] = 'P', 0);
	}
	if (game->map[game->player.row][game->player.col + 1] == 'E')
	{
		if (count_collectibles(game) == 0)
		{
			game->map[game->player.row][game->player.col] = '0';
			return (game->map[game->player.row][game->player.col + 1] = 'P', 1);
		}
		return (EXIT_NOTHING);
	}
	if (game->map[game->player.row][game->player.col + 1] == '0')
	{
		game->map[game->player.row][game->player.col] = '0';
		return (game->map[game->player.row][game->player.col + 1] = 'P', 0);
	}
	return (EXIT_SUCCESS);
}

/* SAME THING than move_left */
int	move_up(t_game *game)
{
	if (game->map[game->player.row - 1][game->player.col] == '1')
		return (EXIT_NOTHING);
	if (game->map[game->player.row - 1][game->player.col] == 'C')
	{
		game->map[game->player.row][game->player.col] = '0';
		return (game->map[game->player.row - 1][game->player.col] = 'P', 0);
	}
	if (game->map[game->player.row - 1][game->player.col] == 'E')
	{
		if (count_collectibles(game) == 0)
		{
			game->map[game->player.row][game->player.col] = '0';
			return (game->map[game->player.row - 1][game->player.col] = 'P', 1);
		}
		return (EXIT_NOTHING);
	}
	if (game->map[game->player.row - 1][game->player.col] == '0')
	{
		game->map[game->player.row][game->player.col] = '0';
		return (game->map[game->player.row - 1][game->player.col] = 'P', 0);
	}
	return (EXIT_SUCCESS);
}

/* SAME THING than move_left */
int	move_down(t_game *game)
{
	if (game->map[game->player.row + 1][game->player.col] == '1')
		return (EXIT_NOTHING);
	if (game->map[game->player.row + 1][game->player.col] == 'C')
	{
		game->map[game->player.row][game->player.col] = '0';
		return (game->map[game->player.row + 1][game->player.col] = 'P', 0);
	}
	if (game->map[game->player.row + 1][game->player.col] == 'E')
	{
		if (count_collectibles(game) == 0)
		{
			game->map[game->player.row][game->player.col] = '0';
			return (game->map[game->player.row + 1][game->player.col] = 'P', 1);
		}
		return (EXIT_NOTHING);
	}
	if (game->map[game->player.row + 1][game->player.col] == '0')
	{
		game->map[game->player.row][game->player.col] = '0';
		return (game->map[game->player.row + 1][game->player.col] = 'P', 0);
	}
	return (EXIT_SUCCESS);
}
