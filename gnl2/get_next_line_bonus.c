/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmourid <zmourid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 17:08:05 by zmourid           #+#    #+#             */
/*   Updated: 2023/12/21 15:01:30 by zmourid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	has_nline(char *str)
{
	while (*str)
	{
		if (*str == '\n')
			return (1);
		str++;
	}
	return (0);
}

char	*read_line(int fd, char *buffer)
{
	ssize_t	len;
	char	*buff;

	buff = malloc(((size_t)BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	while (1)
	{
		len = read(fd, buff, BUFFER_SIZE);
		if (len == -1)
		{
			free(buffer);
			buffer = NULL;
			break ;
		}
		buff[len] = 0;
		if (!*buff)
			break ;
		buffer = ft_strjoin(buffer, buff);
		if (!buffer || has_nline(buffer))
			break ;
	}
	free(buff);
	return (buffer);
}

char	*get_the_line(char *buffer)
{
	char	*line;
	int		len;
	int		i;

	i = 0;
	len = 0;
	if (!buffer || !*buffer)
		return (NULL);
	while (buffer[len] && buffer[len] != '\n')
		len++;
	if (buffer[len] == '\n')
		len++;
	line = malloc((len + 1) * sizeof(char));
	if (!line)
		return (NULL);
	while (buffer[i] && len)
	{
		line[i] = buffer[i];
		i++;
		len--;
	}
	line[i] = 0;
	return (line);
}

char	*get_rest(char *buffer, char *line)
{
	int		i;
	char	*new;

	i = 0;
	if (!buffer || !*buffer)
		return (free(buffer), free(line), (NULL));
	new = ft_strdup(buffer + ft_strlen(line));
	free(buffer);
	return (new);
}

char	*get_next_line(int fd)
{
	static char	*buffer[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX || fd > 1024)
		return (NULL);
	buffer[fd] = read_line(fd, buffer[fd]);
	line = get_the_line(buffer[fd]);
	buffer[fd] = get_rest(buffer[fd], line);
	return (line);
}

//int	main(void)
//{
//	int		fd;
//	char	*str;
//
//	fd = open("test.txt", O_RDWR);
//	str = get_next_line(fd);
//	printf("str =%s", str);
//	free(str);
//	str = get_next_line(fd);
//	printf("str =%s", str);
//	free(str);
//	str = get_next_line(fd);
//	printf("str =%s", str);
//	free(str);
//	str = get_next_line(fd);
//	printf("str =%s", str);
//	free(str);
//}
