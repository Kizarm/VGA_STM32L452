PR = sudoku.js
CC = emcc
CXX= em++
VPATH  = ./ ../ ../common/
CFLAGS = -c -Wall -O3 -I../
LFLAGS = -O3 --bind -s WASM=1 -s ALLOW_MEMORY_GROWTH=1
#LFLAGS+= -s ASSERTIONS=1
LFLAGS+= -s EXTRA_EXPORTED_RUNTIME_METHODS=['addOnPostRun']

SOURCES  = main.cpp
SOURCES += fmath.cpp
SOURCES += canvas.cpp
SOURCES += sudoku.cpp
SOURCES += indicator.cpp
SOURCES += Atari8x16SystemFont.c

OBJB = $(basename  $(SOURCES))
OBJS = $(addsuffix .o,$(OBJB))

all: $(PR)

$(PR): $(OBJS)
	$(CXX) $(LFLAGS) $(OBJS) -o $(PR)

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@
%.o: %.cpp
	$(CXX) -std=c++11 $(CFLAGS) $< -o $@

clean:
	rm -f *.o
#	rm $(PR) $(PR:%.js=%.wasm)
