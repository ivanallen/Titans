all:block_io block_io_ex nonblock_io allen.fifo

allen.fifo:
	mkfifo allen.fifo

block_io:block_io.c
	gcc -o $@ $<

block_io_ex:block_io_ex.c
	gcc -o $@ $<

nonblock_io:nonblock_io.c
	gcc -o $@ $<

clean:
	rm -rf *.o block_io block_io_ex nonblock_io allen.fifo

.PHONY:all
.PHONY:clean
