SRC = $(wildcard *.c)
HEAD = $(wildcard *.h)
TARGET = $(shell pwd | sed 's/\(.*\)[/]//g')
ifeq (,${TARGET})
	TARGET = a.out
endif

all:$(HEAD) $(SRC)
	gcc $(SRC) -o $(TARGET) `pkg-config --libs --cflags gtk+-2.0`

clean:
	rm $(TARGET)
