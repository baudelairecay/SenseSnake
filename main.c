#include "project.h"

coordinate snake[MAX] = {{6,4}};
int running = 1;
int length = 1;
coordinate apple = {2,4};
coordinate direction = START;

void handler(unsigned int code){
        fprintf(stderr, "code: %u\t",code);
        if(code == KEY_UP){
                fprintf(stderr, "right");
                if(direction.x != 1){
                        direction = RIGHT;
                }
        }else if(code == KEY_DOWN){
                fprintf(stderr, "left");
                if(direction.x != -1){
                        direction = LEFT;
                }
        }else if(code == KEY_RIGHT){
                fprintf(stderr, "down");
                if(direction.y != -1){
                        direction = DOWN;
                }
        }else if(code == KEY_LEFT){
                fprintf(stderr, "up");
                if(direction.y != 1){
                        direction = UP;
                }
        }else if(code == KEY_ENTER){
                fprintf(stderr, "push");
                running = 1;
                snake[0] = DEF;
                direction = START;
                length = 1;
                start_snake(snake,length);
                usleep(100);
        }
        fprintf(stderr, "\n");
}

int main(){
	open_display();
	open_input();
	
	while(1){
		if(running){
			check_input(handler, 500);
			start_snake(snake, length);
			coordinate new_APPLE = update_snake(snake, direction, &length, apple);
			apple.x = new_APPLE.x;
			apple.y = new_APPLE.y;
			running = check_collision(snake);
			start_apple(apple);
		}
		else{
			check_input(handler,500);
			apple.x = 2;
			apple.y = 4;
		}
	}
	game_end();
	close_display();
	close_input();
	return 0;
}
