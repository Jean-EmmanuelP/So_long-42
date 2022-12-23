/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperrama <jperrama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 03:14:11 by jperrama          #+#    #+#             */
/*   Updated: 2022/12/18 15:23:25 by jperrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"
/*This function check that there is only 1 all around the map
 * I don't understand the algorithm!*/
int	check_valid_rectangular(t_game *game, int i, int j, int k)
{
	while (game->ber[++i] && i < game->nb_col)
		if (game->ber[i] != '1')
			return (ft_putstr_fd("Error\nNot encircled by 1\n", 2), 1);
	while (game->ber[i++])
		if (i > game->nb_col * game->nb_row - game->nb_col
			&& i < game->nb_col * game->nb_row)
			if (game->ber[i] != '1')
				return (ft_putstr_fd("Error\nNot encircled by 1\n", 2), 1);
	i = -1;
	while (game->ber[++i])
	{
		if (i == game->nb_col * j)
		{
			if (game->ber[i] != '1')
				return (ft_putstr_fd("Error\nNot encircled by 1\n", 2), 1);
			j++;
		}
		if (i == ((2 * game->nb_col) - 1) + (k * game->nb_col))
		{
			if (game->ber[i] != '1')
				return (ft_putstr_fd("Error\nNot encircled by 1\n", 2), 1);
			k++;
		}
	}
	return (EXIT_SUCCESS);
}

/*This function check that there is only one Player by iterating in the map.*/
int	check_valid_player(t_game *game)
{
	int	i;
	int	count_players;

	i = 0;
	count_players = 0;
	while (game->ber[i])
		if (game->ber[i++] == 'P')
			count_players++;
	return (count_players);
}

/*This function check that the map has a 1, a E and a C*/
int	check_valid_map(t_game *game)
{
	if (ft_strchr(game->ber, '1') != NULL && ft_strchr(game->ber, 'C') != NULL
		&& ft_strchr(game->ber, 'E') != NULL)
		return (free(game->ber), EXIT_SUCCESS);
	return (free(game->ber), EXIT_FAILURE);
}

/*This function that the map is correct with the good parameters.*/
int	check_errors(t_game *game)
{
	int	j;

	j = -1;
	while (game->ber[++j])
	{
		if (game->ber[j] != '1' && game->ber[j] != '0' && game->ber[j] != 'P'
			&& game->ber[j] != 'C' && game->ber[j] != 'E')
		{
			ft_putstr_fd("Error\nInvalid map (contains unknown elements)\n", 2);
			return ((free_2d_map(game), free_1d_map(game)), EXIT_FAILURE);
		}
	}
	if (check_valid_player(game) != 1)
		return (((free_1d_map(game), free_2d_map(game)),
				ft_putstr_fd("Error\nMust contain 1 Player\n", 2)), 1);
	if (check_valid_rectangular(game, -1, 1, 0) == EXIT_FAILURE)
		return (((free_1d_map(game), free_2d_map(game)), EXIT_FAILURE));
	if (check_valid_map(game) == EXIT_FAILURE)
		return ((free_2d_map(game),
				ft_putstr_fd("Error\nMissing 1, E or C\n", 2)), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

/*This function check if the format is good*/
int	check_is_it_ber(int ac, char *av)
{
	int	len;

	if (ac != 2)
		return (printf("./so_long [map.ber]\n"), EXIT_FAILURE);
	len = ft_strlen(av, UNTIL_BACKSLASH_ZERO);
	if (len < 5)
		return (ft_putstr_fd("Error\nExtension must be [.ber]\n", 2), 1);
	if (av[len - 1] != 'r' || av[len - 2] != 'e' || av[len - 3] != 'b'
		|| av[len - 4] != '.')
		return (ft_putstr_fd("Error\nExtension must be [.ber]\n", 2), 1);
	return (EXIT_SUCCESS);
}
