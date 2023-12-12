/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmourid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 09:14:33 by zmourid           #+#    #+#             */
/*   Updated: 2023/12/12 16:03:08 by zmourid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "libft.h"

char *get_next_line(int fd)
{
	char *big_buff;
	char *new_buff;
	char *buff;
	int read_len = 0;
	big_buff = NULL;
	while(1)
	{
		buff = calloc(11 ,sizeof(char));
		read_len = read(fd,buff,10);
		if(read_len <= 0)
		{
			free(buff);
			break;
		}
		big_buff = ft_strjoin(big_buff,buff);
		if(ft_strchr(big_buff,'\n'))
		{
			new_buff = ft_substr(big_buff,0,ft_strchr(big_buff,'\n') - big_buff);	
			break;
		}
	}
	return new_buff;;
}
int main()
{
	char *test;
	int fd = open("test.txt",O_RDWR);
	test = get_next_line(fd);
	printf("new buff = %s\n",test);
}
