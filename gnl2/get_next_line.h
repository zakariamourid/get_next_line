#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
#ifndef BUFFER_SIZE  
#define BUFFER_SIZE 5
#endif
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <limits.h>
char                            *ft_substr(char const *s, unsigned int start, size_t len);
int	                            ft_strlen(const char *s);
size_t                          ft_strlcpy(char *dst, const char *src, size_t dstsize);
char                            *ft_strchr(const char *s, int c);
char *get_next_line(int fd);
#endif
