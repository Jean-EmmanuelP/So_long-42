/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_creation_maps.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperrama <jperrama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 03:14:55 by jperrama          #+#    #+#             */
/*   Updated: 2022/12/18 03:31:01 by jperrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

/* This function count the length of the rows 
 * RETURN VALUE : EXIT_SUCESS or EXIT_FAILURE */
int	count_nb_colrow(t_game *game, char *av)
{
	game->fd = open(av, O_RDONLY);
	if (game->fd == -1)
		return (ft_putstr_fd("Error\nOpen failed\n", 2), EXIT_FAILURE);
	game->line = get_next_line(game->fd);
	game->nb_col = ft_strlen(game->line, UNTIL_BACKSLASH_N);
	while (game->line)
	{						
		game->nb_row++;
		free(game->line);
		game->line = get_next_line(game->fd);
	}
	close(game->fd);
	return (EXIT_SUCCESS);
}

/* This function is gonna store in a 1d map the Map.ber 
 * RETURN VALUE : EXIT_SUCCESS */
int	create_1d_map(t_game *game, char *av)
{
	int	i;
	int	j;

	if (game->nb_col < 5 || game->nb_row < 3)
		return (ft_putstr_fd
			("Error\nThere's not even enough tiles to create a map..\n", 2), 1);
	game->ber = malloc(game->nb_col * game->nb_row + 1);
	if (!game->ber)
		return (ft_putstr_fd("Error\nMalloc failed\n", 2), EXIT_FAILURE);
	game->fd = open(av, O_RDONLY);
	if (game->fd == -1)
		return ((free(game->ber), ft_putstr_fd("Error\nOpen failed\n", 2)), 1);
	game->line = get_next_line(game->fd);
	j = 0;
	while (game->line)
	{
		i = 0;
		while (game->line && i < game->nb_col)
			game->ber[j++] = game->line[i++];
		free(game->line);
		game->line = get_next_line(game->fd);
	}
	game->ber[j] = '\0';
	close(game->fd);
	return (EXIT_SUCCESS);
}

/* This function find than define the position of the player 
 * and puts line into the map pointer */
void	player_coordinates(t_game *game, int i, int j)
{
	while (game->line[++j] && j < game->nb_col)
	{
		if (game->line[j] == 'P')
		{
			game->player.col = j;
			game->player.row = i;
		}
		game->map[i][j] = game->line[j];
	}
	game->map[i++][j] = '\0';
	free(game->line);
	game->line = get_next_line(game->fd);
}

/* This function allocate the map pointer to be able to receive 
 * the each line of the map.*/
void	create_2d_map_norm(t_game *game, char *av)
{
	game->map = malloc(sizeof(char *) * (game->nb_row + 1));
	game->copy_map = malloc(sizeof(char *) * (game->nb_row + 1));
	if (!game->map || !game->copy_map)
	{
		ft_putstr_fd("Error\nMalloc failed\n", 2);
		exit (EXIT_FAILURE);
	}
	game->map[game->nb_row] = NULL;
	game->copy_map[game->nb_row] = NULL;
	game->fd = open(av, O_RDONLY);
	if (game->fd == -1)
	{
		free(game->map);
		free(game->copy_map);
		ft_putstr_fd("Error\nOpen failed\n", 2);
		exit (0);
	}
	game->line = get_next_line(game->fd);
}

/* This function copy the map 
 * IT IS USED TO PARSE THE MAP WITHOUT CHANGING THE ORIGINAL ONE */
void	copy_map(t_game *game)
{
	int	i;
	int	j;

	while (i < game->nb_rows)
	{
		while (j < game->nb_col)
		{
			game->copy_map[i][j] = game->map[i][j];
			j++;
		}
		i++;
	}
	game->copy_map[i][j] = '\0';
}

/* This function puts all the lines in the 2d map 
 * RETURN VALUE : EXIT_SUCCESS or 1 or EXIT_FAILURE */
int	create_2d_map(t_game *game, char *av, int i, int j)
{
	create_2d_map_norm(game, av);
	while (game->line)
	{
		game->len_loop = ft_strlen(game->line, UNTIL_BACKSLASH_N);
		if (game->len_loop != game->nb_col)
			return ((free(game->map), ft_putstr_fd("Error\nNot rect\n", 2)), 1);
		game->map[i] = malloc(sizeof(char) * game->nb_col + 1);
		if (game->map == NULL)
			return (ft_putstr_fd("Error\nMalloc failed\n", 2), EXIT_FAILURE);
		j = -1;
		while (game->line[++j] && j < game->nb_col)
		{
			if (game->line[j] == 'P')
			{
				game->player.col = j;
				game->player.row = i;
			}
			game->map[i][j] = game->line[j];
		}
		game->map[i++][j] = '\0';
		free(game->line);
		game->line = get_next_line(game->fd);
	}
	close(game->fd);
	copy_map(game);
	return (EXIT_SUCCESS);
}
