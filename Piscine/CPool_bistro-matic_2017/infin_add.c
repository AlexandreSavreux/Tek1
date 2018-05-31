/*
** EPITECH PROJECT, 2017
** infinite add
** File description:
** add a lot of things
*/
#include <stdlib.h>
#include "include/my.h"

char *verif(char *result, int retained)
{
	if (retained == 1)
		result[0] = '1';
	if (result[0] == '0' && my_strlen(result) > 1) {
		if (result[1] == '0' && my_strlen(result) > 2)
			result[1] = 127;
		result[0] = 127;
	}
	if (result[1] == 42)
		result[1] = 45;
	return (result);
}

char *inf_sub(char *s1, char *s2, int l1, int l2)
{
	int max_size = my_strlen(s1) - l1 >= my_strlen(s2) - l2 ?
		my_strlen(s1) + 1 - l1 : my_strlen(s2) + 1 - l2;
	char *result = malloc(sizeof(char) * (max_size));
	int nb1;
	int nb2;
	int retained = 0;
	int i;

	for (i = 0; i < max_size - 1; i++) {
		nb1 = char_to_int(s1[my_strlen(s1) - i - 1]);
		nb2 = char_to_int(s2[my_strlen(s2) - i - 1]);
		if (i >= my_strlen(s2) - l2)
			nb2 = 0;
		if (i >= my_strlen(s1) - l1)
			nb1 = 0;
		if (nb1 < nb2) {
			result[max_size - i - 2] = int_to_char(
				nb1 + 10 - (nb2 + retained));
			retained = 1;
		} else {
			result[max_size - i - 2] = int_to_char(
				nb1 - (nb2 + retained));
			retained = 0;
		}
	}
	return (verif(result, retained));
}

char *inf_add(char *s1, char *s2)
{
	int max_size =
		my_strlen(s1) >= my_strlen(s2) ? my_strlen(s1) : my_strlen(s2);
	char *result = malloc(sizeof(char) * (max_size + 2));
	int nb1;
	int nb2;
	int retained = 0;
	int i;

	if (result == NULL) {
		my_putstr("error maloc\n");
		return ("84");
	}
	for (i = 0; i < max_size + 2 - 1; i++) {
		nb1 = char_to_int(s1[my_strlen(s1) - i - 1]);
		nb2 = char_to_int(s2[my_strlen(s2) - i - 1]);
		if (i >= my_strlen(s2) || s2[my_strlen(s2) - i - 1] == '-')
			nb2 = 0;
		if (i >= my_strlen(s1) || s1[my_strlen(s1) - i - 1] == '-')
			nb1 = 0;
		if (nb1 + nb2 + retained >= 10) {
			result[max_size - i] = int_to_char(
				nb1 + nb2 + retained - 10);
			retained = 1;
		} else {
			result[max_size - i] = int_to_char(
				nb1 + nb2 + retained);
			retained = 0;
		}
	}
	return (verif(result, retained));
}

char *add(char *s1, char *s2)
{
	int l1 = 0;
	int l2 = 0;
	char *result = malloc(
		sizeof(char) * (my_strlen(s1) + my_strlen(s2) + 3));
	char *les = malloc(sizeof(char) * 2);
	int nb1 = my_getnbr(s1);
	int nb2 = my_getnbr(s2);

	les[0] = '-';
	if (my_str_isnum(s1) == 1 && my_str_isnum(s2) == 1) {
		if (s1[0] == '-')
			l1 = 1;
		if (s2[0] == '-')
			l2 = 1;
		if (l1 != l2 && (l2 == 1) && -nb1 > nb2)
			result = inf_sub(s2, s1, l1, l2);
		else if (l1 != l2 && (l1 == 1 || l2 == 1)) {
			if (nb1 == nb2 * -1)
				return ("0");
			else if (l2 == 0) {
				result = my_strcat(les,
					inf_sub(s1, s2, l1, l2));
			} else
				result = inf_sub(s1, s2, l1, l2);
		} else if (l1 == 1 ) {
			result = my_strcat(les, inf_add(s1, s2));
		} else
			return (inf_add(s1, s2));
		return (result);
	} else {
		my_putstr("invalid input\n");
		return ("84");
	}
}