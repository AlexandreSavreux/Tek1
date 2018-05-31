/*
** EPITECH PROJECT, 2022
** PSU_minishell2_2017
** File description:
** Created by Florian Louvet,
*/

int my_char_isalpha(char str)
{
	if ((str >= 'a' && str <= 'z') || (str >= 'A' && str <= 'Z') ||
		str == '_')
		return (1);
	else
		return (0);
}