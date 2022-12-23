/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperrama <jperrama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 03:15:24 by jperrama          #+#    #+#             */
/*   Updated: 2022/12/18 20:06:45 by jperrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

/* This function is called each time the keyboard is touched */
int	deal_key(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
	{
		free_all(game);
		exit(EXIT_SUCCESS);
	}
	else if (keycode == KEY_W)
		key_w(game);
	else if (keycode == KEY_A)
		key_a(game);
	else if (keycode == KEY_S)
		key_s(game);
	else if (keycode == KEY_D)
		key_d(game);
	else
		return (printf("Available keys are W,A,S,D,esc\n"), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

/* This function initialize the user interface */
void	window_init(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx,
			TILE_SIZE * game->nb_col, TILE_SIZE * game->nb_row, "so_long");
}

/* This function close the game */
int	game_close(t_game *game)
{
	free_all(game);
	exit(EXIT_SUCCESS);
}

/* This function start the program */
int	main(int ac, char **av)
{
	t_game	game;

	if (check_is_it_ber(ac, av[1]) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	game = (t_game){0};
	count_nb_colrow(&game, av[1]);
	if (create_1d_map(&game, av[1]) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (create_2d_map(&game, av[1], 0, 0) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (check_errors(&game) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (check_valid_path(&game) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	window_init(&game);
	mlx_hook(game.win, KeyPress, KeyPressMask, &deal_key, &game);
	mlx_hook(game.win, DestroyNotify, LeaveWindowMask, &game_close, &game);
	refresh_map(&game, -1, 0, 0);
	mlx_loop(game.mlx);
}
