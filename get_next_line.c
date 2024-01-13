

void	ft_read(int fd, char *tmp)
{	
	char	*buffer;
	char	*aux;
	int	bytes;

	aux = tmp;
	free(tmp);
	while (condicion dificil)
	       {
	       		bytes = read(fd, &buffer, BUFFER_SIZE);
			if (bytes == -1)
				return (NULL);
			//concatenar lo que estoy leyendo ak:BUFFER con "lo que llevaba" ak:temp
			aux = ft_strjoin(aux, buffer, bytes);
	       }
	tmp = aux;
}


char *get_next_line(int fd)
{
	char		*line;
	char static	*tmp;
	//manipulation
	//ft_read devuelve string que contenga hasta la siguiente linea
	ft_read(fd, &tmp);
	//COPIa desde el principio hAT el finL SW LA LINEA EN LINE
	line = get_line(tmp);
	//ctuLIZA EL TEMP QUEDANDOSE CON LA SIGUIENTE LINEA, ya que es statici
	proces_temp(&tmp);

	return (line);
}
