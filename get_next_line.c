/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmourid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 09:14:33 by zmourid           #+#    #+#             */
/*   Updated: 2023/12/12 17:15:10 by zmourid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	char *big_buff;
	char *new_buff;
	char *buff;
	int read_len = 0;
	big_buff = NULL;
	new_buff = NULL;
	while(1)
	{
		buff = calloc(5 ,sizeof(char));
		read_len = read(fd,buff,5);
		if(read_len <= 0)
		{

			printf("ouuuut");
			free(buff);
			break;
		}
		big_buff = ft_strjoin(big_buff,buff);
		printf("buff = %s\n",big_buff);

	}
	printf("sub1");
      char str[] = "hello world";
      printf("sub = %s \n ",ft_substr(str,0,str + 5 - str));
	return NULL;
}
int main()
{
	char *test;
	int fd = open("test.txt",O_RDWR);
	test = get_next_line(fd);
	if(test)
		printf("new buff = %s\n",test);
}
