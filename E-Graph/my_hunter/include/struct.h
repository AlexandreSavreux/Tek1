/*
** EPITECH PROJECT, 2017
** struc.c
** File description:
** Structures for CSFML
*/

struct framebuffer {
	unsigned int width;
	unsigned int height;
	sfUint8 *pixels;
};

typedef struct framebuffer framebuffer_t;
