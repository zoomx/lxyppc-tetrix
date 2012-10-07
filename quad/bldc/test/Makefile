test:main.c data_process.c data_process.h
	gcc main.c data_process.c -otest
data_process.c: ../data_process.c
	cp ../data_process.c .
data_process.h: ../data_process.h
	cp ../data_process.h .
clean:
	rm test
