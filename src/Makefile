CC=gcc
CFLAGS= -Wall -Werror -Wextra # Эта строка определяет переменную CFLAGS , которая содержит флаги компиляции.
LDFLAGS=-lm # Эта строка определяет переменную LDFLAGS , которая содержит флаги линковки .
SOURCES=pong.c # Эта строка определяет переменную SOURCES, которая содержит исходный файл "pong.c".
OBJECTS=$(SOURCES:.c=.o) # Эта строка определяет переменную OBJECTS, которая содержит объектный файл "pong.o".
EXECUTABLE=pong # Эта строка определяет переменную EXECUTABLE, которая содержит имя исполняемого файла "pong".

all: $(SOURCES) $(EXECUTABLE) #Эта строка определяет цель "all", которая зависит от исходного файла "pong.c" и исполняемого файла "pong".

$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o ../build/$(EXECUTABLE) 
	../build/$(EXECUTABLE) 

.c.o:
	$(CC) $(CFLAGS) $< -o $@  

clean:
	rm -rf $(OBJECTS) ../build/$(EXECUTABLE) 
