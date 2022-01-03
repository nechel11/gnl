/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbyrd <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 13:00:17 by nbyrd             #+#    #+#             */
/*   Updated: 2021/12/03 15:17:37 by nbyrd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_read_remainder(int	fd, char *temp_line)
{
	char	*buffer;
	int		flag;

	flag = 1;
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	while (!ft_strchr(temp_line, '\n') && flag != 0)
	{
		flag = read(fd, buffer, BUFFER_SIZE);
		if (flag < 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[flag] = '\0';
		temp_line = gnl_enter(temp_line, buffer);
	}
	free(buffer);
	return (temp_line);
}

char	*gnl_enter(char *temp_line, char *buffer)
{
	char	*line;
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (!temp_line)
	{
		temp_line = (char *)malloc(1 * sizeof(char));
		temp_line[0] = '\0';
	}
	if (!temp_line || !buffer)
		return (NULL);
	line = (char *)malloc(sizeof(char)
			* ((ft_strlen(temp_line) + ft_strlen(buffer)) + 1));
	if (!line)
		return (NULL);
	if (temp_line)
		while (temp_line[++i] != '\0')
			line[i] = temp_line[i];
	while (buffer[j] != '\0')
		line[i++] = buffer[j++];
	line[i] = '\0';
	free(temp_line);
	return (line);
}

char	*gnl_liner(char *temp_line)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	if (!temp_line[i])
		return (NULL);
	while (temp_line[i] != '\n' && temp_line[i])
		i++;
	line = (char *)malloc((i + 2) * (sizeof (char)));
	if (!line)
		return (NULL);
	while (j < i)
	{
		line[j] = temp_line[j];
		j++;
	}
	line[j] = temp_line[j];
	line[++j] = '\0';
	return (line);
}

char	*gnl_reading(char *temp_line)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	while (temp_line[i] != '\n' && temp_line[i])
		i++;
	if (!temp_line[i])
	{
		free (temp_line);
		return (NULL);
	}
	line = malloc(sizeof(char) * (ft_strlen(temp_line) - i + 1));
	if (!line)
		return (NULL);
	i++;
	while (temp_line[i])
		line[j++] = temp_line[i++];
	line[j] = '\0';
	free (temp_line);
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*temp_line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	temp_line = gnl_read_remainder(fd, temp_line);
	if (!temp_line)
		return (NULL);
	line = gnl_liner(temp_line);
	temp_line = gnl_reading(temp_line);
	return (line);
}	
