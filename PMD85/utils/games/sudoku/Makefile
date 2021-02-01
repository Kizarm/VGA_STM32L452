APPL = sudoku
OBJ = main.o board.o puzzles.o transform.o random.o
AS = as-z80
LD = ld-z80
OBJCOPY = objcopy-z80
ASFLAGS = -z80 -I ../lib
LDFLAGS = -L ../lib -T script.ld

build: $(APPL).cod

%.cod: %.elf
	$(OBJCOPY) -O binary $< $@
../lib/libpmd85.a:
	cd ../lib/ && $(MAKE)
$(APPL).elf: $(OBJ) lang-en.o ../lib/libpmd85.a
	$(LD) $(LDFLAGS) $(OBJ) lang-en.o -l pmd85 -o $@ -Map=$(APPL)-en.map
%.o: %.s $(APPL).inc ../lib/pmd85.inc Makefile
	$(AS) $(ASFLAGS) $< -o $@ -aglms=$*.lst

clean:
	rm -f *.o *.lst $(APPL)*.map $(APPL).elf

.SUFFIXES:

.PHONY: build clean
