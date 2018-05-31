/*
** EPITECH PROJECT, 2018
** create_quests
** File description:
** creates quests
*/

#include "quest.h"
#include "my.h"

void set_quests_position(quest_manager_t *quests)
{
	sfText_setPosition(quests->quests[0].title, QUESTS[0]);
	sfText_setPosition(quests->quests[1].title, QUESTS[1]);
	sfText_setPosition(quests->quests[0].tasks[0].task, QUESTS[2]);
	sfText_setPosition(quests->quests[0].tasks[1].task, QUESTS[3]);
	sfText_setPosition(quests->quests[0].tasks[2].task, QUESTS[4]);
	sfText_setPosition(quests->quests[1].tasks[0].task, QUESTS[5]);
	sfText_setPosition(quests->quests[1].tasks[1].task, QUESTS[6]);
	sfText_setPosition(quests->quests[1].tasks[2].task, QUESTS[7]);
}

void creation_quests(quest_manager_t *quests)
{
	sfText_setString(quests->quests[0].tasks[0].task, "Obtenir un couteau");
	sfText_setString(quests->quests[0].tasks[1].task,
			"Obtenir un fusil d'assaut");
	sfText_setString(quests->quests[0].tasks[2].task,
			"Obtenir un lance roquette");
	sfText_setString(quests->quests[1].tasks[0].task,
			"Eliminer tous les terroristes");
	sfText_setString(quests->quests[1].tasks[1].task,
			"Eliminer tous les talibans");
	sfText_setString(quests->quests[1].tasks[2].task,
			"Eliminer le chef");
}

void init_texts(quest_manager_t *quests)
{
	for (int quest = 0; quest < 2; quest++) {
		quests->quests[quest].title = sfText_create();
		sfText_setFont(quests->quests[quest].title, quests->font);
		sfText_setCharacterSize(quests->quests[quest].title, 30);
		sfText_setColor(quests->quests[quest].title, sfBlack);
		quests->quests[quest].completed = sfFalse;
		for (int task = 0; task < 3; task++) {
			quests->quests[quest].tasks[task].task = sfText_create
				();
			sfText_setFont(quests->quests[quest].tasks[task].task,
				quests->font);
			sfText_setCharacterSize(
				quests->quests[quest].tasks[task].task, 20);
			sfText_setColor(quests->quests[quest].tasks[task].task,
					sfBlack);
			quests->quests[quest].tasks[task].done = sfFalse;
		}
	}
	sfText_setString(quests->quests[0].title, "S'armer");
	sfText_setString(quests->quests[1].title, "Survivre");
}

int create_quests(quest_manager_t *quest)
{
	sfVector2f pos = {600, 100};

	quest->font = sfFont_createFromFile("assets/font/font.ttf");
	if (!quest->font)
		return (0);
	quest->texture = sfTexture_createFromFile
		("assets/textures/quests/quests.png", NULL);
	if (!quest->texture)
		return (0);
	quest->sprite = sfSprite_create();
	sfSprite_setTexture(quest->sprite, quest->texture, sfTrue);
	sfSprite_setPosition(quest->sprite, pos);
	quest->active = sfFalse;
	init_texts(quest);
	creation_quests(quest);
	set_quests_position(quest);
	return (1);
}
