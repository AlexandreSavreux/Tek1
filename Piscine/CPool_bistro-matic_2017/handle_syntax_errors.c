/*
** EPITECH PROJECT, 2022
** File description: Handling syntax errors
*/

int nb_of_parantheses(char *str)
{
	int a = 0;
	int b = 0;

	for (i = 0; str[i] != '\0'; i++) {
		if (str[i] == '(')
			a++;
		if (str[i] == ')')
			b++;
	}

	if (a == b)
		return (str);
	else {
		my_put_str("syntax error");
		my_putchar('\n');
		return (84);
	}
}

int op_next_to_op(char *str)
{
	for (i = 0; str[i] != '\0'; i++) {
		if (str[i] == '+' && str[i + 1] == '+' || str[i - 1] == '-')
			return (84);
		if (str[i] == '+' && str[i + 1] == '-' || str[i - 1] == '*')
			return (84);
		if (str[i] == '+' && str[i + 1] == '%' || str[i - 1] == '/')
			return (84);
		if (str[i] == '+' && str[i + 1] == '/' || str[i - 1] == '%')
			return (84);
		if (str[i] == '+' && str[i + 1] == '*')
			return (84);
	}

}

int string_empty(char *str)
{
	if (str[0] == '\0') {
		my_put_str("emptry string");
		my_putchar('\n');
		return (84);
	}
}