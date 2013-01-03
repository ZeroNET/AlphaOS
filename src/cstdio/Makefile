SOURCES=sprintf.c vsprintf.c
CFLAGS=-O2 -fno-builtin -I../include/ -fomit-frame-pointer

all: ${SOURCES:%.c=build/%.o}

build/%.o: %.c
	${COMPILE.c} $< -o $@
lib:
	ar -cvq build/libc-stdio.a build/*.o
clean:
	@rm -f *.o

test: ${SOURCES:%.c=build/%.so}
	
build/%.so: %.c
	cc ${CFLAGS} $< -o $@ -shared -fPIC -DTEST=1
	
