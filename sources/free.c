/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperrama <jperrama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 03:14:25 by jperrama          #+#    #+#             */
/*   Updated: 2022/12/18 15:24:27 by jperrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

/*This function free all the elements from the 2d map*/
void	free_2d_map(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i] && i < game->nb_row)
	{	
		free(game->map[i]);
		i++;
	}
	free(game->map);
}

/*This function free all the elements from the 1d map*/
void	free_1d_map(t_game *game)
{
	free(game->ber);
}

/*This function is used at the end of the game 
 * to free all the elements of the game*/
void	free_all(t_game *game)
{
	int	i;

	i = 0;
	mlx_destroy_window(game->mlx, game->win);
	game->win = NULL;
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	while (game->map && i < game->nb_row)
		free(game->map[i++]);
	free(game->map);
}
