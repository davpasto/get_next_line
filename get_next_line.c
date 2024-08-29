/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davpasto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 22:43:53 by davpasto          #+#    #+#             */
/*   Updated: 2024/08/01 00:23:08 by davpasto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static	char	*full_line = NULL;
	char		*line;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	full_line = ft_read_and_write(fd, full_line);
	if(!full_line)
		return (NULL);
	line = ft_extract_line(full_line);
	full_line = ft_get_rest(full_line);
	return(line);
}

char	*ft_read_and_write(int fd, char *full_line)
{	
	char	*buffer;
	int	read_status;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	read_status = 1;
	if (!buffer)
		return (NULL);
	while (!ft_strchr(full_line, '\n') && (read_status != 0))
	{
		read_status = read(fd, buffer, BUFFER_SIZE);
		if (read_status == -1)
			return (free(buffer), NULL);
		buffer[read_status] = '\0';
		full_line = ft_strjoin(full_line, buffer);
		if (!full_line)
			return (free(buffer), NULL);
	}
	free(buffer);
	return (full_line);
}

char	*ft_extract_line(char *full_str)
{
	int	i;
	char	*line;

	i = 0;
	if (!full_str || !full_str[i])
		return (NULL);
	while (full_str[i] && full_str[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2)); //'\n' + '\0'
	if (!line)
		return (NULL);
	i = 0;
	while (full_str[i] && full_str[i] != '\n')
	{
		line[i] = full_str[i];
		i++;
	}
	if (full_str[i] == '\n')
	{
		line[i] = full_str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_get_rest(char *full_str)
{
	int	i;
	int	j;
	char	*restof;

	if (!full_str)
		return (NULL);
	i = 0;
	while (full_str[i] && full_str[i] != '\n')
		i++;
	if (!full_str[i]) // No encuentra linea
		return (free(full_str), NULL);
	restof = malloc(sizeof(char) * (ft_strlen(full_str) - i + 1));
	if (!restof)
		return (free(full_str), NULL);
	i++;	//Skipeas el salto de linea
	j = 0;
	while (full_str[i])
		restof[j++] = full_str[i++];
	restof[j] = '\0'; // Acabas el string
	free(full_str);
	return(restof);
}
int	main(void)
{
	#include <fcntl.h>

	int	fd;
	char	*line;

	fd = open("text.txt", O_RDONLY);
	while (line = get_next_line(fd))
	{
		printf("%s",line);
		free(line);
	}
	close(fd);
	return (0);
}
