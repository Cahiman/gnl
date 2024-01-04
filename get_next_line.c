/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baiannon <baiannon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 18:46:18 by baiannon          #+#    #+#             */
/*   Updated: 2024/01/04 18:57:41 by baiannon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_line(int fd, char *saved)
{
	char	*buff;
	char		*tmp;
	int			n;
	
	buff = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	n = 1;
	if (!saved)
		saved = ft_strdup("");
	while (n && !ft_strchr(buff, '\n'))
	{
		n = read(fd, buff, BUFFER_SIZE);
		buff[n] = '\0';
		tmp = saved;
		saved = ft_strjoin(saved, buff);
		free(tmp);
	}
	if (!*saved)
	{
		free(saved);
		free(buff);
		return (NULL);
	}
	free(buff);
	return (saved);
}

char	*after_return(char *stash)
{
	char *next;
	int	i;
	int	j;
	int	k;
	
	i = 0;
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;
	k = i;
	if (stash[i] == '\n')
		k = i + 1;
	j = i;
	while (stash[j] != '\0')
		j++;
	next = malloc(sizeof(char) * (j + 1));
	i = 0;
	while (stash[k] != '\0')
	{
		next[i] = stash[k];
		i++;
		k++;
	}
	next[i] = '\0';
	return (next);
}

char	*before_return(char *stash)
{
	char	*line;
	int	i;

	i = 0;
	while(stash[i] != '\n' && stash[i] != '\0')
		i++;
	if (stash[i] == '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	i = 0;
	while (stash[i] != '\n' && stash[i] != '\0')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	free(stash);
	return (line);
}

char *get_next_line(int fd)
{
	static char	*stash;
	char	*tmp;

	stash = get_line(fd, stash);
	if (!stash)
		return (NULL);
	tmp = stash;
	stash = after_return(stash);
	if (!*stash)
		free(stash);
	return (before_return(tmp));
}

int	main(int ac,)
{
	char *line;
	
	int	fd = open("test.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
}