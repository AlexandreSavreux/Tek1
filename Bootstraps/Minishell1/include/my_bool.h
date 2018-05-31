/*
** EPITECH PROJECT, 2022
** My_bool.h
** File description:
** Created by tiflo,
*/
#ifndef MY_BOOL_H
#define MY_BOOL_H

#ifndef _Bool
typedef unsigned char _Bool;
#endif /* _Bool */

#ifndef __bool_true_false_are_defined
	#define bool _Bool
	#define false 0
	#define true 1
	#define __bool_true_false_are_defined 1
#endif /* __bool_true_false_are_defined */

#endif //MY_BOOL_H
