/*
** EPITECH PROJECT, 2017
** my_putchar.c
** File description:
** Displays a character
*/
void my_putchar(char c)
{
	write(1, &c, 1);
}
