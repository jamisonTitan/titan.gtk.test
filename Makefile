OBJS = test.o 
PROG = test

%.o: %.c
	# $@ is the target
	# $< is the first dependency
	gcc $$( pkg-config --cflags gtk4 ) -c -g -o $@ $< $$( pkg-config --libs gtk4 )

$(PROG): $(OBJS)
	gcc $$( pkg-config --cflags gtk4 ) -g -o $@ $^ $$( pkg-config --libs gtk4 )

clean:
	rm -f test .*.sw* *.o
