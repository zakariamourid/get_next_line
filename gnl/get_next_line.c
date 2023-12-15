/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmourid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:15:00 by zmourid           #+#    #+#             */
/*   Updated: 2023/12/14 19:48:27 by zmourid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>
#include "get_next_line.h"
int	ft_strlen_plus(const char *s,char c)
{
	size_t	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	if(!s[i])
		return 0;
	if(c  =='\n')
		i++;
	return (i);
}
char	*ft_strdup_plus(const char *s1,char c)
{
	size_t	s_len;
	char	*data;
	int i;
	i = 0;

	s_len = ft_strlen_plus(s1,c);
	data = malloc(s_len + 1);
	if (!data)
		return (NULL);
	while(s1[i] != c)
	{
		data[i] = s1[i];
		i++;
	}
	if(c == '\n')
		data[i++] = '\n';
	data[i] = 0;
	return (data);
}
char	*split_buffer(char **buffer)
{
	char *temp;
	char *new;
	temp = *buffer;
    new = ft_strdup_plus(*buffer,'\n');
    *buffer = ft_strdup_plus(*buffer + ft_strlen_plus(*buffer,'\n'),0);
	free(temp);
	return new;
}

char	*get_next_line(int fd)
{
	static char *buffer;
	char *temp_buff;
	char *temp;
	char *line;
	ssize_t	read_len;
	read_len = 0;
	line = NULL;
	temp_buff = malloc(BUFFER_SIZE * sizeof(char));
	if( fd < 0 || BUFFER_SIZE <= 0 || fd >= OPEN_MAX) 
		return NULL;
	while(1)
	{
		read_len = read(fd,temp_buff,BUFFER_SIZE);
		temp_buff[read_len] = 0;
		if(read_len == 0)
		{
			free(temp_buff);
			return buffer;
		}
		temp = buffer;
		buffer = ft_strjoin(buffer,temp_buff);
		free(temp);
		if(ft_strlen_plus(buffer,'\n'))
		{
			line = split_buffer(&buffer);
			break;
		}
	}
	free(temp_buff);
	return line;
}
//int main()by
//{
//	char *str = "hello world\ncomo estas brothers\n";
//	static char *buffer;
//	buffer = ft_strdup_plus(str,0);
//	char *p1;
//	printf("buffer=%s\n",buffer);
//	p1 = split_buffer(&buffer);
//    printf("str=%s\n",p1);
//	printf("new buffer=%s\n",buffer);
//	system("leaks a.out");
//}

int main()
{
	int fd;
	fd = open("test.txt",O_RDWR);
	char *str;
	while((str = get_next_line(fd)))
	{
		printf("str=%s",str);
		free(str);
	}
	system("leaks a.out");
}

