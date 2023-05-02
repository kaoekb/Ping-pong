CFLAGS=-c -Wall -Werror -Wextra
LDFLAGS=-lm
SOURCES=pong.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=pong

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o ../build/$(EXECUTABLE)
	../build/$(EXECUTABLE)

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf $(OBJECTS) ../build/$(EXECUTABLE)