mybc: main.c
	gcc main.c parser.c -o mybc -lm

clean:
	/bin/rm -rf ./mybc