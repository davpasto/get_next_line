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

char	*get_next_line(int fd)
{
	static	char	*full_line;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	full_line = read_and_write(fd, full_line);
	if(!full_line)
		return (NULL);
	line = ft_extract_line(full_line);
	full_line = ft_get_rest(full_line);
	return(line);
}

char	*read_and_write(int fd, char *full_line)
{	
	char	*buffer;
	int	read_status;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	read_status = 1;
	if (!buffer)
		return (NULL);
	while (!ft_strchr(full_line, '\n') && read_status != 0)
	{
		read_status = read(fd, buffer, BUFFER_SIZE);
		if (read_status == -1)
			return (free(buffer), NULL);
		buffer[read_status] = 0;
		full_line = ft_strjoin(full_line, buffer);
		if (!full_line)
			return (free(buffer), NULL);
	}
	return (free(buffer), full_line);

int	main(void)
{
	#include <fcntl.h>

	int	fd;
	char	*line;

	fd = open("text.txt", O_RDONLY);
	while (line = get_next_line(fd))
	{
		printf("%s\n",line);
		free(line);
	}
	close(fd);
	return (0);
}
