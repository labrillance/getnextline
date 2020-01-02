/*
** EPITECH PROJECT, 2019
** B-CPE-111
** File description:
** get_next_line.h
*/

#include <stdlib.h>
#include <unistd.h>

#ifndef GET_NEXT_LINE_

#define READ_SIZE (5)

#endif

char *realloca(char *str, char *buff, int nb);
char *first_alloc(int fd, int i, char *string, int w);
char *get_next_line(int fd);
int my_strlen(char *a);
