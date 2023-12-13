#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
char                            *ft_strdup(const char *s1);
char                            *ft_substr(char const *s, unsigned int start, size_t len);
char                            *ft_strjoin(char const *s1, char const *s2);
size_t                          ft_strlen(const char *s);
size_t                          ft_strlcpy(char *dst, const char *src, size_t dstsize);
char                            *ft_strchr(const char *s, int c);
#endif
