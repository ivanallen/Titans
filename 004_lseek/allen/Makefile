all: mycp2
	./mycp2 ../README.md file
	bash ../check.sh

mycp2: mycp2.c
	gcc -o $@ $<

clean:
	rm -rf mycp2 file

.PHONY:all
.PHONY:clean

