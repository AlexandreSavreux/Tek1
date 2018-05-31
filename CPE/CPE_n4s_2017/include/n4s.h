/*
** EPITECH PROJECT, 2018
** n4s
** File description:
** n4s
*/

#ifndef N4S_H_
#define N4S_H_

typedef struct info {
	float speed;
	float speed_value;
	float rotation;
	float rotation_value;
	float *distance;
}info_s;

typedef struct command {
	char *command;
	int answer;
	int type;
} command_t;

#define NOTHING 0
#define INT 1
#define FLOAT 2

#define START 0
#define STOP 1
#define FORWARD 2
#define BACKWARD 3
#define WHEELS_DIR 4
#define INFO_LIDAR 5
#define CURRENT_SPEED 6
#define CURRENT_WHEELS 7
#define CYCLE_WAIT 8
#define SPEED_MAX 9
#define SPEED_MIN 10
#define SIMTIME 11

static const command_t com_command[] = {
	{"START_SIMULATION", 1, NOTHING},	//0
	{"STOP_SIMULATION", 1, NOTHING},	//1
	{"CAR_FORWARD:", 1, FLOAT},		//2
	{"CAR_BACKWARD:", 1, FLOAT},		//3
	{"WHEELS_DIR:", 1, FLOAT},		//4
	{"GET_INFO_LIDAR", 2, 0},		//5
	{"GET_CURRENT_SPEED", 3, 0},		//6
	{"GET_CURRENT_WHEELS", 3, 0},		//7
	{"CYCLE_WAIT:", 3, INT},		//8
	{"GET_CAR_SPEED_MAX", 3, NOTHING},	//9
	{"GET_CAR_SPEED_MIN", 3, NOTHING},	//10
	{"GET_CAR_SIMTIME", 4, NOTHING},	//11
};

float get_info_float(command_t command);
float *get_distance_sensor(float *number);
info_s *update_info(info_s *info);
info_s *init_struct(void);
void free_struct(info_s *info);
char **str_to_array(char const *str, char separator);
void free_array(char **array);
char *send_command(command_t command, float value);
float *take_lidar(float *value);

#endif //N4S_H_
