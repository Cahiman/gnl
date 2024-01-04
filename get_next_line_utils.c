/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baiannon <baiannon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 18:46:47 by baiannon          #+#    #+#             */
/*   Updated: 2024/01/04 16:43:42 by baiannon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;
	
	c = 10;
	i = 0;
	while (s[i])
	{
		if (s[i] == ((unsigned char) c))
			return ((char *) &s[i]);
		i++;
	}
	if (s[i] == ((unsigned char) c))
		return ((char *) &s[i]);
	return (NULL);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	i;
	char	*t;

	i = 0;
	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (nmemb * size < nmemb || nmemb * size < size)
		return (NULL);
	t = malloc(nmemb * size);
	if (t == 0)
		return (NULL);
	while (nmemb * size > i)
	{
		t[i] = '\0';
		i++;
	}
	return (t);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (!s1 || !s2)
		return (NULL);
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (str);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i] = s2[j];
		j++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strdup(const char *s)
{
	int		i;
	char	*dest;
	size_t	len;

	i = 0;
	len = ft_strlen(s);
	dest = malloc((len + 1) * sizeof(char));
	if (!s)
		return (NULL);
	if (dest == NULL)
		return (NULL);
	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}