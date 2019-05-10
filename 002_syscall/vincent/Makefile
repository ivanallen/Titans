all:write_demo print_demo
%.o: %.c
	gcc -c -o $@ $< 
write_demo:write_demo.o
	gcc -o $@ $<
print_demo:print_demo.o
	gcc -o $@ $<
clean:
	rm *.o print_demo write_demo
	

