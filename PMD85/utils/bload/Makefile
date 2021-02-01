PRJ = run_basic
CC  = gcc
CXX = g++
DEL = rm -f
#DEL = del
VPATH = ./

CFLAGS = -Wall -Os
CFLAGS+= -I.
#CFLAGS+= -fno-exceptions
#CFLAGS+= -Wa,-adhlns=$(subst $(suffix $<),.lst,$(<F))

all: $(PRJ)
# zdrojaky
OBJS = main.o basic.o
# ... atd.
# linker
$(PRJ): $(OBJS)
	$(CXX) -o $(PRJ) $(OBJS)
# preloz co je potreba
%.o: %.s
	as  $< -o $@
%.o: %.c
	$(CC)  -c  $(CFLAGS) $< -o $@
%.o: %.cpp
	$(CXX) -std=c++11 -c  $(CFLAGS) $< -o $@
# vycisti
clean:
	$(DEL) *.o *.lst *~
.PHONY: all clean
