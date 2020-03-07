/*
** EPITECH PROJECT, 2019
** CPE_getnextline_2019
** File description:
** main.c
*/

# include "get_next_line.h"
#include <fcntl.h>


void my_putchar(char a)
{
    write(1, &a, 1);
}

void my_putstr(char *a)
{
    int i = 0;
    
    while (a[i] != 0) {
        my_putchar(a[i]);
        i++;
    }
}

int main ( void )
{
    int fd = open("test.txt", O_RDONLY);
    char * s = get_next_line (fd) ;
     while ( s ) {
         my_putstr ( s ) ;
         my_putchar ('\n') ;
         free ( s ) ;
         s = get_next_line (fd) ;
     }
    return (0) ;
}