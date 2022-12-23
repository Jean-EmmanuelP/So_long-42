/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperrama <jperrama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 03:16:47 by jperrama          #+#    #+#             */
/*   Updated: 2022/12/18 15:32:24 by jperrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdlib.h>
# include <stdio.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "get_next_line.h"
# include "../minilibx-linux/mlx.h"
# define KEY_ESC				65307
# define KEY_W					119		
# define KEY_A					97
# define KEY_S					115
# define KEY_D					100
# define TILE_SIZE				50
# define UNTIL_BACKSLASH_ZERO	0
# define UNTIL_BACKSLASH_N		1
# define WALL					"./images/wall.xpm"
# define ZERO					"./images/zero.xpm"
# define COLLECT				"./images/collectible.xpm"
# define EXIT					"./images/exit.xpm"
# define PLAYER					"./images/player.xpm"
# define EXIT_NOTHING			42

typedef struct s_img
{
	void	*img;
	int		*data;

	int		size_l;
	int		bpp;
	int		endian;
}				t_img;

typedef struct s_img_struct
{
	int		width;
	int		height;
	void	*img;
}				t_img_struct;

typedef struct s_player
{
	int	col;
	int	row;
}				t_player;

typedef struct s_game
{
	void			*mlx;
	void			*win;
	int				move_count;
	char			**map;
	char			**copy_map;
	int				nb_col;
	int				nb_row;
	int				fd;
	char			*line;
	int				len_loop;
	char			*ber;
	t_player		player;
	t_img			img;
	t_img_struct	img_struct;
}				t_game;

int		check_valid_rectangular(t_game *game, int i, int j, int k);
int		check_valid_player(t_game *game);
int		check_valid_map(t_game *game);
int		check_is_it_ber(int ac, char *av);
int		check_errors(t_game *game);
int		refresh_map(t_game *game, int i, int j, int index);
void	key_w(t_game *game);
void	key_a(t_game *game);
void	key_s(t_game *game);
void	key_d(t_game *game);
void	free_all(t_game *game);
int		move_left(t_game *game);
int		move_right(t_game *game);
int		move_down(t_game *game);
int		move_up(t_game *game);
int		count_nb_colrow(t_game *game, char *av);
int		create_1d_map(t_game *game, char *av);
int		create_2d_map(t_game *game, char *av, int i, int j);
void	free_1d_map(t_game *game);
void	free_2d_map(t_game *game);
void	free_all(t_game *game);
int		game_close(t_game *game);
int		ft_strlen(char *str, int n);
char	*ft_strdup(const char *src);
char	*ft_strchr(char *s, int c);
void	ft_putstr_fd(char *string, int fd);
int		deal_key(int keycode, t_game *game);
#endif
