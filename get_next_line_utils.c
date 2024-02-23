/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lellong- < lellong-@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 15:17:41 by lellong-          #+#    #+#             */
/*   Updated: 2023/03/13 15:37:10 by lellong-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s)
{
	int		i;
	int		len;
	char	*str;

	i = 0;
	if (!s)
		return (NULL);
	len = ft_strlen(s);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
		{
			str[j] = s[i];
			j++;
		}
		i++;
	}
	str[j] = '\0';
	return (str);
}

char	*ft_strchr(const char *s, int i)
{
	while (*s)
	{
		if (*s == i)
			return ((char *)s);
		s++;
	}
	if (i == '\0')
		return ((char *)s);
	return (NULL);
}

int ft_strlen(const char *str)
{
    int i;

    i = 0;
	if (!str)
		return (0);
    while (str[i])
        i++;
    return (i);
}

/* joindre la ligne avec le contenu du buffer et retourner la juxtaposition des deux */

char	*ft_strjoin(char *line, char *buff)
{
	char	*result;
	int		i;
	int		j;
	int		len;

	i = -1;   
	len = ft_strlen(line) + ft_strlen(buff) + 1;
	if (!(result = (char *)malloc((sizeof(char)) * (len + 1))))
		return (NULL);
	if (!line && !buff)
		return (NULL);
	if (!line)
	{
		while (buff[++i])
			result[i] = buff[i];
		result[ft_strlen(buff)] = '\0';
		return (result);
	}
	while (line[++i])
			result[i] = line[i];
	j = -1;
	while (buff[++j])
		result[i + j] = buff[j];
	result[i + j] = '\0';
	return (result);
}