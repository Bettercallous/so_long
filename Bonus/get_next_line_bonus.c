/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oubelhaj <oubelhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 00:38:11 by oubelhaj          #+#    #+#             */
/*   Updated: 2023/03/14 00:39:42 by oubelhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*fill_and_join(int fd, char **saved, char *line, char *tmp)
{
	while (!ft_strchr(*saved, '\n'))
	{
		tmp = fill_buff(fd);
		if (!tmp)
		{
			line = *saved;
			*saved = NULL;
			return (line);
		}
		*saved = ft_strjoin(*saved, tmp);
		free(tmp);
	}
	line = ft_substr(*saved, 0, ft_strchr(*saved, '\n') - *saved + 1);
	tmp = *saved;
	*saved = ft_substr(ft_strchr(*saved, '\n') + 1, 0,
			ft_strlen(ft_strchr(*saved, '\n')));
	free(tmp);
	return (line);
}

char	*get_next_line(int fd)
{
	char		*tmp;
	char		*line;
	static char	*saved;

	tmp = NULL;
	line = NULL;
	if (read(fd, NULL, 0) == -1 || BUFFER_SIZE <= 0)
	{
		free(saved);
		saved = NULL;
		return (NULL);
	}
	return (fill_and_join(fd, &saved, line, tmp));
}
