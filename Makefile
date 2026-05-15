INCLUDE := -I ~/include
LDFLAGS := -L ~/lib -lsense -lm

all:game

game: main.o output.o input.o
	@cc -o game main.o output.o input.o -g ${LDFLAGS}

clean: 
	@rm -f *.o game

run:game
	@./game

main.o: main.c project.h
	@cc -c main.c -I ~/include -g
output.o: output.c project.h
	@cc -c output.c -I ~/include -g
input.o: input.c project.h
	@cc -c input.c -I ~/include -g
