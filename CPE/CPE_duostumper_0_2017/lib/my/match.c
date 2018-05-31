/*
** EPITECH PROJECT, 2017
** match.c
** File description:
** Returns 1 if s2 string is a part of s1 string and return 0 if is not
*/
int match(char const *s1, char const *s2)
{
	int rec1;
	int rec2;
	int result;
	int result2;
	int result3;

	if (*s1 == '\0' && *s2 == '\0')
		return (1);
	if (*s2 == '*' && *s1 != '\0') {
		rec1 = match(s1 + 1, s2);
		rec2 = match(s1, s2 + 1);
		result = rec1 || rec2;
		return (result);
	}
	if (*s1 != '\0' && *s2 != '\0') {
		result2 = match(s1 + 1, s2 + 1);
		return (result2);
	}
	if (*s2 == '*' && *s1 == '\0') {
		result3 = match(s1, s2 + 1);
		return (result3);
	}
	return (0);
}
