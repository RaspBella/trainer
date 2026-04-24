BIN=trainer

.PHONY: default clean

default: $(BIN)
	./$<

$(BIN): ../crs.o

clean:
	rm -f $(BIN)
