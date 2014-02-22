CC = clang
CFLAGS = -O0 -Wall -Werror -std=c99
DEBUG = -g -ggdb3
LIBRARIES = -lcs50 -lm

OUTPUT = mario
SOURCES = mario.c

$(OUTPUT): $(OBJECTS)
	$(CC) $(DEBUG) $(CFLAGS)    $(SOURCES) $(LIBRARIES) -o $(OUTPUT)

clean: $(OUTPUT)
	rm -f $(OUTPUT)
