#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

#include <stddef.h>

char *get_next_line(int fd);
static char *test(char *line);
int ft_strlen(const char *str);
char	*ft_strjoin(char *line, char *buff);
char *resultat(char *line);
char	*ft_strchr(const char *s, int i);
char	*ft_strdup(const char *s);
char *test(char *line);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif