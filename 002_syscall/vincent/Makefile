all:write_demo print_demo

write_demo:write_demo.c
	gcc -g -o $@ $<

print_demo:print_demo.c
	gcc -g -o $@ $<
clean:
	rm print_demo write_demo
