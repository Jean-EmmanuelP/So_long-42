/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperrama <jperrama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 03:15:07 by jperrama          #+#    #+#             */
/*   Updated: 2022/12/17 03:15:08 by jperrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int	ft_strlen(char *str, int n)
{
	int	i;

	if (str == NULL)
		return (0);
	i = 0;
	if (n == UNTIL_BACKSLASH_ZERO)
		while (str[i] != '\0')
			i++;
	else
		while (str[i] != 0 && str[i] != '\n')
			i++;
	return (i);
}

char	*ft_strdup(const char *src)
{
	int		i;
	int		len;
	char	*str;

	len = 0;
	while (src[len])
		len++;
	str = malloc(sizeof(*str) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strchr(char *s, int c)
{
	char	*str;

	str = (char *)s;
	if (c == 0)
		return (s + ft_strlen(s, UNTIL_BACKSLASH_ZERO));
	while (*str != (char)c)
	{
		if (*str == '\0')
			return (NULL);
		str++;
	}
	return ((char *)str);
}

void	ft_putstr_fd(char *string, int fd)
{
	write(fd, string, ft_strlen(string, 0));
}
