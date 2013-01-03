SOURCES=${shell find . -type f}
CFLAGS=-O2 -nostdinc -nostartfiles -fno-builtin -I../../include/ -fomit-frame-pointer -nostdlib
SFLAGS=-shared -fPIC -DTEST=1
all: ${SOURCES:./%.c=build/%.o}

build/%.o: %.c
	${COMPILE.c} $< -o $@
lib:
	ar -cvq build/libc-string.a build/*.o
clean:
	@rm -f *.o
test: ${SOURCES:%.c=build/%.so}
	../../../bin/test $^
	
build/%.so: %.c
	cc $< ${SFLAGS} ${CFLAGS} -o $@
