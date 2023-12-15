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
	if(!str)
		return NULL;
	len = ft_strlen(str);
	i = 0;
	new = (char *) malloc(len + 1);
	if(!new)
		return NULL;
	while(str[i])
	{
		new[i] = str[i];
		i++;
	}
	new[i] = 0;
	return new;
}
char *ft_strjoin(char *s1,char *s2)
{
	int len;
	int i;
	char *str;
	i = 0;
	if(!s1)
		return ft_strdup(s2);
	if(!s2)
	{
		free(s1);
		return NULL;
	}
	len = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sizeof(char) * (len + 1));
	if(!str)
	{
		free(s1);
		return NULL;
	}
	str[len] = 0;
	while(*s1)
		str[i++] = *s1++;
	free(s1 - i);
	while(*s2)
		str[i++] = *s2++;
	return str;
}

int has_nline(char *str)
{
	while(*str)
	{
		if(*str == '\n')
			return 1;
		str++;
	}
	return 0;
}

char *read_line(int fd ,char *buffer)
{
	int len;
	char *buff;
	buff = malloc(5 * sizeof(char));
	if(!buff)
		return NULL;
	while(1)
	{
		len = read(fd,buff,BUFFER_SIZE);
		if(len == 0)
		{
			printf("rest is %s \n",buffer);
			if(!*buffer)
			{
				free(buff);
				free(buffer);
				return NULL;
			}
			break;
		}
		buff[len] = 0;
		buffer = ft_strjoin(buffer,buff);
		if(has_nline(buffer))
			break;
	}
	free(buff);
	return buffer;
}

char *get_line(char *buffer)
{
	char *line;
	int len;
	int i;
	i = 0;
	if(!buffer)
		return NULL;
	while(buffer[len] && buffer[len] != '\n')
		len++;
	if(buffer[len] == '\n')
		len++;
	line = malloc((len + 1) * sizeof(char));
	if(!line)
		return NULL;
	while(buffer[i] && len)
	{
		line[i] = buffer[i];
		i++;
		len--;
	}
	line[i] = 0;
	return line;
}

char *get_rest(char *buffer,int line_len)
{
	int i;
	char *new;
	i = 0;
	if(!buffer || !*buffer)
		return NULL;
	new = ft_strdup(buffer + line_len);
	free(buffer);
	return new;
	

}

char *get_next_line(int fd)
{
	static char *buffer;
	char *line;
	if(fd < 0 || BUFFER_SIZE <= 0)
		return NULL;
	buffer = read_line(fd,buffer);
	line = get_line(buffer);
	buffer = get_rest(buffer , ft_strlen(line));
	return line;
}
int main()
{
	int fd = open("test.txt",O_RDWR);
	char *sa = get_next_line(fd);
	printf("str =%s",sa);
	sa = get_next_line(fd);
	printf("str =%s",sa);
	sa = get_next_line(fd);
	printf("str =%s",sa);
	free(sa);
}
