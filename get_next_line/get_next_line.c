/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajbari <ajbari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 19:48:58 by ajbari            #+#    #+#             */
/*   Updated: 2024/05/14 15:19:51 by ajbari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
//
#include <stdio.h>
//
char	*ft_re_line(char *line)
{
	char	*return_line;
	int		i;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\n')
		i++;
	return_line = malloc((i + 1) * sizeof(char));
	if (!return_line)
		return (NULL);
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		return_line[i] = line[i];
		i++;
	}
	if (line[i] == '\n')
	{
		return_line[i] = line[i];
		i++;
	}
	return_line[i] = '\0';
	return (return_line);
}

char	*rest(char *line)
{
	char	*rest;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\n')
		i++;
	rest = ft_join(NULL, &line[i]);
	ft_free(&line);
	return (rest);
}

int	check_nl(char *buffer)
{
	int i;

	i = 0;
	while (buffer[i])
	{
		if ((buffer[i]) == '\n')
		{
			if (buffer[i+1] == '\n')
			{
                write(2, "empty line\n", 11);
                exit(1);
			}

			return (1);
		}
		i++;
	}
	return (0);
}

void	ft_read(int fd, char **line)
{
	char	*buffer;
	int		flag;
	ssize_t	bytes_readed;

	flag = 0;
	buffer = malloc((BUFFER_SIZE + 1));
	if (!buffer)
	{
		ft_free(line);
		return ;
	}
	while (!flag)
	{
		bytes_readed = read(fd, buffer, BUFFER_SIZE);
		if (!bytes_readed)
		{
			ft_free(&buffer);
			return ;
		}
		buffer[bytes_readed] = '\0';
		// printf("buf === %s\n", buffer);
		flag = check_nl(buffer);
		
		*line = ft_join(*line, buffer);
	}
	ft_free(&buffer);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*new_line;
	new_line = NULL;
	if (read(fd, new_line, 0) == -1 || BUFFER_SIZE <= 0)
		return (ft_free(&line));
	ft_read(fd, &line);
	if (!line || *line == '\0')
		return (ft_free(&line));
	new_line = ft_re_line(line);
	if (!new_line)
		return (ft_free(&line));
	line = rest(line);
	return (new_line);
}
