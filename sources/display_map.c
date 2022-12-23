/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperrama <jperrama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 03:14:20 by jperrama          #+#    #+#             */
/*   Updated: 2022/12/18 15:24:12 by jperrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

/*This function send the image*/
void	*xpm_file(t_game *game, char *index)
{
	void	*image;

	image = mlx_xpm_file_to_image(game->mlx, index,
			&game->img_struct.width, &game->img_struct.height);
	if (!image)
	{
		ft_putstr_fd("Error\nValid xpm files needed\n", 2);
		exit(0);
	}
	return (image);
}

/*This function refresh the map by overwritting
 * the last image with the new one */
int	refresh_map(t_game *game, int i, int j, int index)
{
	const char	key[] = "10CEP";
	const char	*val[] = {WALL, ZERO, COLLECT, EXIT, PLAYER, NULL};

	if (game->win == NULL)
		return (EXIT_FAILURE);
	while (game->map[++i] && i < game->nb_row)
	{
		j = 0;
		while (game->map[i][j] && game->map[i][j] != '\n' && j < game->nb_col)
		{
			index = -1;
			while (key[++index])
			{
				if (game->map[i][j] == key[index])
				{
					game->img_struct.img = xpm_file(game, (char *)val[index]);
					break ;
				}
			}
			mlx_put_image_to_window(game->mlx, game->win,
				game->img_struct.img, (j++) * TILE_SIZE, i * TILE_SIZE);
			mlx_destroy_image(game->mlx, game->img_struct.img);
		}
	}
	return (EXIT_SUCCESS);
}
