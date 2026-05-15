#include "project.h"
#define WHITE 0xFFFF
#define GREEN getColor(0,255,0);
#define RED getColor(255,0,0);
#define BLACK 0x000000

pi_framebuffer_t *fb = NULL;
sense_fb_bitmap_t *bm = NULL;

void open_display(){
	if(fb == NULL){
		fb = getFrameBuffer();
		if(fb != NULL){
			bm = fb->bitmap;
		}
	}
}
void clear_display(){
	if(bm != NULL){
		clearFrameBuffer(fb,0);
	}
}

void close_display(){
	if(fb != NULL){
		clearFrameBuffer(fb,0);
		freeFrameBuffer(fb);
		sleep(1);
	}
}

void start_snake(coordinate snake[], int length){
	clear_display();
	for(int i = 0; i < length; i++){
		bm->pixel[snake[i].x][snake[i].y] = GREEN;
	}
}

void start_apple(coordinate apple){
	bm->pixel[apple.x][apple.y] = RED;
}

void remove_apple(coordinate apple){
	bm->pixel[apple.x][apple.y]=BLACK;
}

coordinate update_snake(coordinate snake[], coordinate direction, int *length, coordinate apple){
	coordinate head = {snake[0].x + direction.x, snake[0].y + direction.y};
	for(int i = MAX-1; i>0; i--){
		snake[i] = snake[i-1];
	}
	snake[0] = head;
	if(snake[0].x == apple.x && snake[0].y == apple.y){
		*length += 1;
		bm->pixel[apple.x][apple.y] = GREEN;
		return update_apple(snake,apple,*length);
	}
	coordinate new_apple = {apple.x, apple.y};
	return new_apple;
}

coordinate update_apple(coordinate snake[], coordinate apple, int length){
	int x = rand()%7;
	int y = rand()%7;
	for(int i = 0; i < length; i++){
		if(snake[i].x == x && snake[i].y == y){
			x = rand()%7;
			y = rand()%7;
		}
	}
	coordinate new_apple = {x,y};
	return new_apple;
}

int check_collision(coordinate snake[]){
	if(snake[0].x > 7 || snake[0].x < 0){
		close_display();
		return 0;
	}
	else if(snake[0].y > 7 || snake[0].y < 0){
		close_display();
		return 0;
	}else{
		return 1;
	}
}

void game_end(){
	clear_display();	
}
