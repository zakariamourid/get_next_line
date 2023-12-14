#include "get_next_line.h" 
int main()
{
	int fd;
	int a;
	char *buff;
	fd = open(NULL,O_RDWR);
	buff = malloc(20);
	a =	read(fd,buff,1000);
	printf("%d \n ",a);
}
