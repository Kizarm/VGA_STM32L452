PR = bin/sudoku.wasm
VPATH = ./ ../ ../common/
CC = clang
CX = clang++
# V Ubuntu 20.04 není v default LLVM wasm-ld, jinak by šlo použít clang jako ld
LD = wasm-ld-10
TARGET = --target=wasm32-unknown-unknown

OBJS  = main.o
OBJS += fmath.o
OBJS += canvas.o
OBJS += sudoku.o
OBJS += indicator.o
OBJS += Atari8x16SystemFont.o

CFLAGS = -Wall -Oz -flto $(TARGET) -I. -I.. -I../common -I./lib
CFLAGS+= -ffunction-sections -fdata-sections
#CFLAGS+= -Wno-incompatible-library-redeclaration
# Pro clang by muselo ještě přibýt -nostartfiles $(TARGET) a flagy by byly -Wl,
LFLAGS = --no-entry --import-memory --lto-O3 --gc-sections
LFLAGS+= --print-gc-sections
#LFLAGS+= --export-all
# vetsi stack znamena zvetsit i WebAssembly.Memory({ initial: n 64K block })
LFLAGS+= -z stack-size=65536
#LFLAGS+= --allow-undefined
LFLAGS+= --allow-undefined-file=symbols.txt 
LDLIBS = -L./lib -lWASM

all: $(PR)
%.o: %.cpp
	$(CX) -std=c++14 -c $(CFLAGS) -fno-exceptions -fno-rtti $< -o $@
%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@
$(PR): $(OBJS) ./lib/libWASM.a
	$(LD) $(LFLAGS) $(OBJS) -o $(PR) $(LDLIBS)
./lib/libWASM.a:
	cd ./lib && $(MAKE) all
clean:
	rm -f *.o
