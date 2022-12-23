/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperrama <jperrama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 03:15:45 by jperrama          #+#    #+#             */
/*   Updated: 2022/12/18 15:20:41 by jperrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/get_next_line.h"

char	*ft_read(char *line, int fd)
{
	char	buf[BUFFER_SIZE + 1];
	ssize_t	i;

	while (ft_strchr_gnl(line, '\n') == 1)
	{
		i = read(fd, buf, BUFFER_SIZE);
		if (i == -1)
			return (NULL);
		buf[i] = '\0';
		if (i < BUFFER_SIZE)
		{
			line = ft_update_strjoin(line, buf, i);
			break ;
		}
		line = ft_strjoin(line, buf);
	}
	return (line);
}

char	*ft_update_buf(char *line)
{
	int		full_len;
	int		line_len;
	int		k;
	char	*ret;

	full_len = ft_strlen_gnl(line, UNTIL_BACKSLASH_ZERO);
	line_len = ft_strlen_gnl(line, UNTIL_BACKSLASH_N);
	k = 0;
	ret = malloc((full_len - line_len + 1) * sizeof(char));
	if (ret == NULL)
		return (NULL);
	while (full_len - line_len > 0)
	{
		ret[k] = line[line_len];
		line_len++;
		k++;
	}
	ret[k] = '\0';
	free(line);
	return (ret);
}

char	*ft_split_for_so_long(char *line)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = malloc(ft_strlen_gnl(line, UNTIL_BACKSLASH_N) + 2);
	if (tmp == NULL)
		return (NULL);
	if (ft_strlen_gnl(line, UNTIL_BACKSLASH_N) == 0)
		return (free(tmp), NULL);
	while (line[i] != '\n' && line[i])
	{
		tmp[i] = line[i];
		i++;
	}
	if (line[i] == '\n')
	{
		tmp[i] = '\n';
		tmp[i + 1] = '\0';
	}
	else
		tmp[i] = '\0';
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*next_line;

	next_line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (line != NULL)
		next_line = ft_update_buf(line);
	line = ft_read(next_line, fd);
	if ((line != NULL && line[0] == '\0') || line == NULL)
	{
		free(line);
		line = NULL;
		return (NULL);
	}
	return (ft_split_for_so_long(line));
}
