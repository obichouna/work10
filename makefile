all: signal_stuff.c
	gcc -o signal_test.out signal_stuff.c


clean:
	-rm *.out
	-rm *.*~

run: all
	./signal_test.out
