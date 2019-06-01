all: mycp
	./mycp ../README.md file

mycp: mycp.c
	gcc -o $@ $<

clean:
	rm -rf mycp

.PHONY:all
.PHONY:clean
