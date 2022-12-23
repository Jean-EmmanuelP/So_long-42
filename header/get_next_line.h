/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperrama <jperrama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 03:16:36 by jperrama          #+#    #+#             */
/*   Updated: 2022/12/17 03:16:38 by jperrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# ifndef UNTIL_BACKSLASH_ZERO
#  define UNTIL_BACKSLASH_ZERO 0
# endif
# ifndef UNTIL_BACKSLASH_N
#  define UNTIL_BACKSLASH_N 1
# endif
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>

int		ft_strchr_gnl(char *s, int c);
char	*ft_strdup_gnl(char *src);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen_gnl(char *str, int n);
char	*ft_update_strjoin(char *s1, char *s2, ssize_t i);
char	*get_next_line(int fd);
char	*ft_kindofsplitbutmorelikeacpy(char *line);
char	*ft_update_buf(char *line);
char	*ft_read(char *line, int fd);

#endif
