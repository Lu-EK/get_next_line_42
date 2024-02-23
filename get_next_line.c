#include <stdio.h>
#include <unistd.h>
#include "get_next_line.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

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
    if (!buff)
        return (line);
	if (!line)
		return (buff);
	while (line[++i])
			result[i] = line[i];
	j = -1;
	while (buff[++j])
		result[i + j] = buff[j];
	result[i + j] = '\0';
	return (result);
}

static char *trim_static(char *ligne)
{
    char *backup;
    size_t compteur;

    compteur = 0;
    while (ligne[compteur] != '\n' && ligne[compteur] != '\0')
        compteur++;
    if (ligne[compteur] == '\0' || ligne[1] == '\0')
        return (0);
    backup = ft_substr(ligne, compteur + 1, ft_strlen(ligne) - compteur);
    if (*backup == '\0')
    {
        free(backup);
        backup = NULL;
    }
    ligne[compteur + 1] = '\0';
    return (backup);
}

static char *remplir_static_str(int fd, char *buff, char *static_str)
{
    char *char_temp;
    int ret_fd;

    ret_fd = 1;
    while (ret_fd != 0)
    {
        ret_fd = read(fd, buff, BUFFER_SIZE);
        if (ret_fd == -1)
            return (0);
        else if (ret_fd == 0)
            break ;
        buff[ret_fd] = '\0';
        if (!static_str)
            static_str = ft_strdup("");
        if (!static_str)
            return (free(static_str), NULL);
        char_temp = static_str;
        static_str = ft_strjoin(char_temp, buff);
        if (!static_str)
            return (free(static_str), NULL);
        free(char_temp);
        if (ft_strchr (buff, '\n'))
            break ;
    }
    return (static_str);
    }

char *get_next_line(int fd)
{
char *ligne;
    char *buff;
    static char *static_str;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (0);
    buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buff)
        return (0);
    ligne = remplir_static_str(fd, buff, static_str);
    free(buff);
    buff = NULL;
    if (!ligne)
        return (NULL);
    static_str = trim_static(ligne);
    return (ligne);
}

int main()
{
	printf("BUFFER_SIZE=%d\n", BUFFER_SIZE);
	char    *line;
	int fd = open("test", O_RDONLY);
	int i = 0;
    line = get_next_line(fd);
	printf("ligne %d : %s\n", i, line);
    while (line)
	{
        free(line);
		line = get_next_line(fd);
		printf("ligne %d : %s\n", i, line);
	}
	close(fd);
}