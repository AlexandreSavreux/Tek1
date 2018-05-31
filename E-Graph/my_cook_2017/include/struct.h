/*
** EPITECH PROJECT, 2017
** struc.c
** File description:
** Structures for CSFML
*/
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct menu_s {
	sfSprite *sprite[9];
	sfTexture *texture[9];
	char **string;
	sfMusic *click;
	sfMusic *music;
	int n;
} menu_t;

typedef struct game_s {
	sfSprite *sprite[15];
	sfTexture *texture[15];
	char string[12];
	int burger;
	int n;
	sfClock *clock;
	sfTime time;
	float second;
	sfIntRect rect;
	int level;
	sfFont *font;
	sfText *text;
} game_t;

typedef struct score_s {
	int score;
	int burger;
	sfFont *font[3];
	sfText *text[3];
} score_t;

void load_the_burgers(game_t *game);

char **char_array(void);

char *do_conv(int a, char **nombre);

void screen_score(score_t *score, char *nombre, sfRenderWindow *window,
	char *burger
);

void do_move(game_t *game, score_t *score);

int load_song(menu_t *menu);

void other_things(sfEvent *event, game_t *game, score_t *score);

void look_for_other(game_t *game, sfEvent *event, score_t *score);

void prepare_my_score(score_t *score);

int do_settings(sfRenderWindow *window, menu_t *menu);

int play_game(sfRenderWindow *window, menu_t *menu);

void change_button_settings(menu_t *menu);

char **char_array2(void);

void charge_game_assets2(game_t *game);

int charge_game_assets(menu_t *menu, game_t *game);

void give_assets_position(game_t *game);

void load_game_assets(menu_t *menu, game_t *game, score_t *score);

void analyse_events(sfEvent event, sfRenderWindow *window, menu_t *menu);

void display_game_assets(game_t *game, menu_t *menu, sfRenderWindow *window,
	score_t *score
);

void destroy_things(menu_t *menu);

void check_click(sfEvent event, sfRenderWindow *window, menu_t *menu);

void display_pictures(sfRenderWindow *window, menu_t *menu);

void display_game_assets(game_t *game, menu_t *menu, sfRenderWindow *window,
	score_t *score
);

void display_game_over(game_t *game, sfRenderWindow *window);

int do_game(void);

int settings_click(sfEvent event, menu_t *menu);

int analyse_settings(sfEvent event, menu_t *menu);

void change_button_plus(sfVector2i position, menu_t *menu);

void initialise_burger(game_t *game);

void do_pause(int *n, sfRenderWindow *window, menu_t *menu);

void analyse_pause(sfEvent event, int *n, int *i, sfRenderWindow *window,
	menu_t *menu
);

void analyse_game(sfEvent event, int *n, sfRenderWindow *window, menu_t *menu
);

void change_volume_plus(menu_t *menu);

void change_volume_minus(menu_t *menu);

void reboot_string(game_t *game);

void declare_string(menu_t *menu);

void event_burger(sfEvent *event, game_t *game, score_t *score);

void do_the_new_recipe(game_t *game, int n, score_t *score);

int check_pos(sfVector2f position, menu_t *menu, int *n, int *i);

void move_pictures(menu_t *menu);

void set_menu_play(game_t *game);

int set_menu(sfRenderWindow *window, menu_t *menu);

void change_button(menu_t *menu);

void event_bottom_bread(game_t *game);

void event_top_bread(game_t *game);

void event_tomato(game_t *game);

void event_cheese(game_t *game);

void event_steak(game_t *game);

void event_salad(game_t *game);

