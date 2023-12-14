/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmourid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 09:14:33 by zmourid           #+#    #+#             */
/*   Updated: 2023/12/14 15:07:57 by zmourid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	static char *big_buff;
	char *new_buff;
	char *temp;
	char *buff;
	ssize_t read_len = 0;
	new_buff = NULL;
	buff = malloc(BUFFER_SIZE * sizeof(char));
	if(fd < 0 || BUFFER_SIZE <= 0 || !buff)
	{
		free(buff);
		return NULL;
	}
	while(1)
	{
		read_len = read(fd,buff,BUFFER_SIZE);
		buff[read_len] = 0;
		if(read_len == 0)
		{
			new_buff = ft_strdup(big_buff);
			free(big_buff);
			big_buff = NULL;
			break;
		}
		if(read_len == -1)
		{
			free(buff);
			return NULL;
		}
		temp = big_buff;
		big_buff = ft_strjoin(big_buff,buff);
		free(temp);
		if(ft_strchr(big_buff,'\n'))
		{
			temp = big_buff;
			new_buff = ft_substr(big_buff,0,ft_strchr(big_buff,'\n') - big_buff + 1);
			big_buff = ft_strdup(big_buff + ft_strlen(new_buff) + 1);
			free(temp);
			break;
		}
	}
	free(buff);
	return new_buff;
}
//int main()
//{
//	char *test;
//	int fd = open("empty",O_RDWR);
//	while(test = get_next_line(fd))
//	{
//		printf("%s",test);
//		free(test);
//	}
//	system("leaks a.out");
//}
