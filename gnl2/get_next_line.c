#include "get_next_line.h"

int ft_strlen(const char *s)
{
	int i;

	i = 0;
	while(*s++)
		i++;
	return i;
}

char *ft_strdup(char *str)
{
	int len;
	int i;
	char *new;
	len = ft_strlen(str);
	printf("len = %d",len);
	i = 0;
	new = (char *) malloc(len + 1);
	if(!new)
		return NULL;
	while(*str)
		*new++ = *str++;
	*++new = 0;
	return new;
}
char *ft_strjoin(char *s1,char *s2)
{
	return NULL;
}

char *read_line(int fd ,char *buffer,char *buff)
{
	int len;
	while(1)
	{
		len = read(fd,buff,BUFFER_SIZE);
		if(!len)
			break;
		buffer = ft_strjoin(buffer,buff);
	}
	return buff;
}

char *get_next_line(int fd)
{
	static char *buffer;
	char *buff;
	buff = malloc(5 * sizeof(char));
	if(!buff || fd < 0 || BUFFER_SIZE <= 0)
	{
		free(buff);
		return NULL;
	}
	buffer = read_line(fd,buffer,buff);
	return buff;
}
int main()
{
	int fd = open("test.txt",O_RDWR);
//	printf("str =%s",get_next_line(fd));
	printf("str =%s",ft_strdup("hello world"));
}
