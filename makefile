all: stat.c
	gcc stat.c -o stat  

clean:
	rm stat
	rm *~

run: stat
	./stat