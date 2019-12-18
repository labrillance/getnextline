/*
** EPITECH PROJECT, 2019
** B-CPE-111
** File description:
** get_next_line.c
*/

#include "get_next_line.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>


char *realloca(char *str, char *buff, int nb)
{
    char *tmp;
    int i = 0;

    tmp = malloc(sizeof(char) * (READ_SIZE * nb + 2));
    while (str != NULL && str[i] != 0) {
        tmp[i] = str[i];
        i++;
    }
    for (int x = 0; buff[x] != 0; x++) {
        tmp[i] = buff[x];
        i++;
    }
    tmp[i + 1] = 0;
    return tmp;
}

char *first_alloc(int fd, int i, char *string, int w)
{
    char *buff = NULL;

    while (i != 0) {
        buff = malloc(sizeof(char) * READ_SIZE * w);
        i = read(fd, buff, i);
        buff[i] = 0;
        string = realloca(string, buff, w);
        if (READ_SIZE - i > 0)
            i = 0;
        w++;
        free(buff);
    }
    return string;
}

char *get_next_line(int fd)
{
    static int i = READ_SIZE;
    static int w = 1;
    static int cmp = 0;
    static char *string = NULL;
    int x = 0;
    char *buff = NULL;

    if (i != 0) {
        string = first_alloc(fd, i, string, w);
        i = 0;
    }
    for (int tmp = cmp; string[tmp] != 0 && string[tmp] != '\n'; tmp++, x++);
    buff = malloc(sizeof(char) * x);
    for (int y = 0; string[cmp] != '\n' && string[cmp] != 0; y++, cmp++) {
        buff[y] = string[cmp];
    }
    buff[x] = '\0';
    if (string[cmp] == 0 && my_strlen(buff) == 0 )
        buff = NULL;
    cmp++;
    return buff;
}

int main(int ac, char **av)
{
    int fd = open(av[1], O_RDONLY);
    char *s = get_next_line (fd);

    while (s) {
        my_putstr (s) ;
        my_putchar ('\n') ;
        free (s) ;
        s = get_next_line (fd);
    }
    return (0) ;
}

