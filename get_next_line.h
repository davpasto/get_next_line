/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davpasto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:29:46 by davpasto          #+#    #+#             */
/*   Updated: 2023/12/19 17:32:17 by davpasto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*get_next_line(int fd);
void	ft_read(int fd, char &tmp);
char 	*get_line(int fd);
void	proces_temp(char &tmp);
char	*ft_strjoin(char *aux, char *buffer, int bytes);
