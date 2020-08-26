all:
	gcc main.c cpu.c -o 8085 -ggdb
clean:
	rm 8085
