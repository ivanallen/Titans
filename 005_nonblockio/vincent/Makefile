all: block_io_ex nonblock_io allen.fifo

allen.fifo:
	mkfifo allen.fifo

block_io_ex:block_io_ex.c
	gcc -std=c99 -o $@ $<

nonblock_io:nonblock_io.c
	gcc -std=c99 -o $@ $<

clean:
	rm -rf *.o  block_io_ex nonblock_io allen.fifo

.PHONY:all
.PHONY:clean
