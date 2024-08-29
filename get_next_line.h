#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stddef.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *s, char c);
int	ft_strlen(char *s);
char	*ft_read_and_write(int fd, char *str);
char	*ft_extract_line(char *fullStr);
char	*ft_get_rest(char *fullStr);

#endif
