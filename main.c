/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davpasto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:28:03 by davpasto          #+#    #+#             */
/*   Updated: 2023/12/19 17:28:45 by davpasto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	main(int ac, char **av)
{
	int	fd;
	char	*line;

	fd = open(av[1], O_RDONLY);
	while (line = get_next_line(fd))
	{
		printf("%s",line);
		free(line);
	}
	line = get_next_line(fd);
	printf("%s", (line));
	free(line);
	close(fd);
	return (0);
}
