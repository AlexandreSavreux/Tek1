/*
** EPITECH PROJECT, 2018
** map
** File description:
** map changing
*/

#ifndef MAP_H_
#define MAP_H_

#include "my.h"

void check_spawn(elem *elem, sfVector2f pos);
void check_warehouse(elem *elem, sfVector2f pos);
void check_kitchen(elem *elem, sfVector2f pos);
void check_cafet(elem *elem, sfVector2f pos);
void check_hall(elem *elem, sfVector2f pos);

void (*change_map[NB_ROOMS])(elem*, sfVector2f) = {check_spawn, check_kitchen,
						check_warehouse, check_cafet,
						check_hall};

#endif
