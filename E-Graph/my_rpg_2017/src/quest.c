/*
** EPITECH PROJECT, 2018
** quest
** File description:
** manages quests
*/

#include "my.h"

void display_tasks(sfRenderWindow *window, quest_manager_t quest, int i)
{
	for (int j = 0; j < 3; j++)
		sfRenderWindow_drawText
			(window, quest.quests[i].tasks[j].task, NULL);
}

void display_quest(sfRenderWindow *window, quest_manager_t quest)
{
	if (quest.active == sfTrue) {
		sfRenderWindow_drawSprite(window, quest.sprite, NULL);
		for (int i = 0; i < 2; i++) {
			sfRenderWindow_drawText(window, quest.quests[i].title,
						NULL);
			display_tasks(window, quest, i);
		}
	}
}

int check_if_all_tasks_are_done(quest_t quest)
{
	int done = 0;

	for (int task = 0; task < 3; task++) {
		if (quest.tasks[task].done == sfTrue) {
			sfText_setColor(quest.tasks[task].task, sfGreen);
			done++;
		}
	}
	return (done);
}

int check_if_completed(quest_manager_t *quests)
{
	for (int quest = 0; quest < 2; quest++) {
		if (check_if_all_tasks_are_done(quests->quests[quest]) != 3)
			return (0);
	}
	return (1);
}

void check_quests(elem *elem)
{
	if (elem->inv.item[KNIFE].nbr > 0)
		elem->quest.quests[0].tasks[0].done = sfTrue;
	if (elem->inv.item[AK47].nbr > 0)
		elem->quest.quests[0].tasks[1].done = sfTrue;
	if (elem->inv.item[ROCKET].nbr > 0)
		elem->quest.quests[0].tasks[2].done = sfTrue;
}
