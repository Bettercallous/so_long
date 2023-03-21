/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oubelhaj <oubelhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:49:57 by oubelhaj          #+#    #+#             */
/*   Updated: 2022/11/18 18:34:36 by oubelhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(char *buff, char c)
{
	if (buff != NULL)
	{
		while (*buff && *buff != c)
			buff++;
		if (*buff == c)
			return (buff);
	}
	return (NULL);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	size_t	i;
	size_t	s1len;
	size_t	s2len;
	char	*str;

	i = 0;
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	str = malloc(s1len + s2len + 1);
	if (!str)
		return (NULL);
	while (i < s1len)
	{
		str[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < s2len)
	{
		str[i + s1len] = s2[i];
		i++;
	}
	str[s1len + s2len] = '\0';
	free(s1);
	return (str);
}

char	*fill_buff(int fd)
{
	char	*buff;
	ssize_t	rd_bytes;

	buff = malloc(BUFFER_SIZE + 1);
	rd_bytes = read(fd, buff, BUFFER_SIZE);
	if (rd_bytes > 0)
	{
		buff[rd_bytes] = '\0';
		return (buff);
	}
	free(buff);
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	rem;
	size_t	i;

	i = 0;
	rem = ft_strlen(s + start);
	if (len > rem)
		len = rem;
	if (len <= 0 || !s)
		return (NULL);
	sub = (char *)malloc((len + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	while (i < len)
	{
		sub[i] = (s + start)[i];
		i++;
	}
	sub[len] = 0;
	return (sub);
}
