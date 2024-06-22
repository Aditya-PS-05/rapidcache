flags=-O2 -Wall -std=c2x

all: clean rapidcache

rapidcache: rapidcache.o
	cc ${flags} $^ -o $@ ${ldflags}

rapidcache.o: rapidcache.c
	cc ${flags} -c $^

clean:
	rm -f *.o rapidcache
