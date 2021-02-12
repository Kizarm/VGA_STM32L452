PR = rngd
CC = gcc
CFLAGS = -Wall -Os -DHAVE_CONFIG_H -I.
MFLAGS = -o $(PR)
LFLAGS = -lcrypto -lsysfs

all: $(PR)

OBJECTS = fips.o rngd.o rngd_entsource.o rngd_linux.o
OBJECTS+= util.o rngd_rdrand.o rdrand_asm.o

$(PR): $(OBJECTS)
	$(CC) $(MFLAGS) $(OBJECTS) $(LFLAGS)
clean:
	rm -f *.o *~
%.o: %.c
	$(CC) -c $(CFLAGS) $<
%.o: %.S
	$(CC) -c $(CFLAGS) $<
