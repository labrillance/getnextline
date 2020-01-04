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

<<<<<<< HEAD
=======
int my_strlen(char *a)
{
    int i = 0;

    while (a[i] != 0)
        i++;
    return i;
}

>>>>>>> be66a658d6022975425eef65b1e525b0d2867b43
char *realloca(char *str, char *buff, int nb)
{
    char *tmp = NULL;
    int i = 0;

    tmp = malloc(sizeof(char) * (READ_SIZE * nb * 2));
    if (str != NULL) {
        while (str[i] != 0) {
            tmp[i] = str[i];
            i++;
        }
    }
    for (int x = 0; buff[x] != 0; x++) {
        tmp[i] = buff[x];
        i++;
    }
    tmp[i] = 0;
    return tmp;
}

int check_n(char *buff, int i)
{
    if (buff == NULL)
        return 0;
    while (buff[i] != 0) {
        if (buff[i] == '\n')
            return 1;
        i++;
    }
    return 0;
}

char *first_alloc(int fd, int *i, char *string, int *w)
{
    char *buff = NULL;

    while (*i != 0) {
        buff = malloc(sizeof(char) * READ_SIZE * (*w) + 1);
        if (!malloc)
            return NULL;
        *i = read(fd, buff, *i);
        if (*i == -1)
            return NULL;
        buff[*i] = 0;
        string = realloca(string, buff, (*w));
        (*w)++;
        if (READ_SIZE - *i > 0)
            *i = 0;
        if (check_n(buff, 0) == 1) {
            free(buff);
            return string;
        }
        free(buff);
    }
    return string;
}

char *newline(char *string, int *cmp, char *buff)
{
    int x = 0;

    for (int tmp = (*cmp); string[tmp] != 0 && string[tmp] != '\n'; tmp++, x++);
    buff = malloc(sizeof(char) * x + 1);
    for (int y = 0; string[*cmp] != '\n' && string[*cmp] != 0; y++, (*cmp)++) {
        buff[y] = string[*cmp];
    }
    buff[x] = '\0';
    if (string[*cmp] == 0 && buff[0] == 0 )
        return NULL;
    if (string[*cmp] != 0)
        (*cmp)++;
    return buff;
}

char *get_next_line(int fd)
{
    static int i = READ_SIZE;
    static int w = 1;
    static int cmp = 0;
    static char *string = NULL;
    char *buff = NULL;

    if (fd == -1)
        return NULL;
<<<<<<< HEAD
    if (i != 0 && (check_n(string, cmp) == 0)) {
=======
    if (i != 0) {
>>>>>>> be66a658d6022975425eef65b1e525b0d2867b43
        string = first_alloc(fd, &i, string, &w);
        if (string == NULL)
            return NULL;
    }
    buff = newline(string, &cmp, buff);
    return buff;
}