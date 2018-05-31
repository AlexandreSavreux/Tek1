/*
** EPITECH PROJECT, 2022
** Event
** File description:
** Created by f.louvet,
*/
#include "struct.h"

void manage_movement(void)
{
	int x = (int)event_t.duck_pos.x;
	int y = (int)event_t.duck_pos.y;

	if (x >= 1300) {
		if (y <= 720) {
			event_t.respawn_pos.y = (rand() % 52) * 10;
		}
		sfSprite_setPosition(assets_t.sprites[1], event_t.respawn_pos);
	}
}

void manage_aim(sfRenderWindow *window)
{
	event_t.mouse_pos = sfMouse_getPosition(window);
	event_t.aim_pos.x = event_t.mouse_pos.x - 50;
	event_t.aim_pos.y = event_t.mouse_pos.y - 50;
	sfSprite_setPosition(assets_t.sprites[2], event_t.aim_pos);
}

void my_clock(void)
{
	sfClock *clock = sfClock_create();
	sfTime time;
	float seconds;
	int i = 0;

	event_t.duck_pos = sfSprite_getPosition(assets_t.sprites[1]);
	event_t.duck_speed.y = 0;
	while (i < 1) {
		time = sfClock_getElapsedTime(clock);
		seconds = time.microseconds / 1000000.0;
		if (seconds > 0.09) {
			move_rect();
			sfSprite_move(assets_t.sprites[1], event_t.duck_speed);
			manage_movement();
			sfClock_restart(clock);
			i++;
		}
	}
}

void manage_mouse_click(int x, int y)
{
	sfVector2f begin = {-110, 0};
	int ax = (int)event_t.duck_pos.x;
	int ay = (int)event_t.duck_pos.y;

	srand (time (NULL));
	begin.y = (rand() % 52) * 10;
	if (x <= ax + 110 && x > ax && y <= ay + 95 && y > ay) {
		sfSprite_setPosition(assets_t.sprites[1], begin);
		event_t.duck_speed.x *= 1.1;
	}
}

void analyse_events(sfEvent *event, sfRenderWindow *window)
{
	if (event->type == sfEvtClosed)
		sfRenderWindow_close(window);
	if (event->type == sfEvtMouseButtonReleased)
		manage_mouse_click(event->mouseButton.x, event->mouseButton.y);
	if (event->type == sfEvtMouseMoved)
		manage_aim(window);
}