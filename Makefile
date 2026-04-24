CFLAGS=-Wall -Wextra -MMD

SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
DEPS=$(filter *.md, $(wildcard *d))
BIN=trainer

.PHONY: default clean

default: $(BIN)
	./$<

$(BIN): ../crs.o

../crs.o:
	make -C .. crs.o

-include $(DEPS)

clean:
	rm -f $(BIN)
	rm -f $(OBJ) $(DEPS)
	make -C .. clean
