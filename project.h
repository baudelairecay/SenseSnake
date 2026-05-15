#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "sense.h"
#include <time.h>
#include <linux/input.h>
#define MAX 60
#define UP (coordinate){0,-1}
#define DOWN (coordinate){0,1}
#define RIGHT (coordinate){-1,0}
#define LEFT (coordinate){1,0}
#define START (coordinate){0,0}
#define DEF (coordinate){6,4}


typedef struct{
	int x;
	int y;
}coordinate;

void open_display();
void close_display();
void clear_display();
void open_input();
void close_input();
void check_input(void(*callback)(unsigned int code),int delay); 
void start_snake(coordinate snake[], int length);
void start_apple(coordinate apple);
coordinate update_snake(coordinate snake[], coordinate direction, int *length, coordinate apple);
coordinate update_apple(coordinate snake[], coordinate apple, int length);
int check_collision(coordinate snake[]);
void remove_apple();
void game_end();
void handler(unsigned int code);
