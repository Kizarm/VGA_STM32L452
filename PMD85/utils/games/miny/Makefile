APPL = miny
AS = as-z80
LD = ld-z80
OBJCOPY = objcopy-z80
OBJDUMP = objdump-z80
ASFLAGS = -z80 -g
LDFLAGS = -T miny.ld

OBJ = miny.o blockworld.o definice.o generator.o print9x12.o grafika.o bitmapy.o
OBJ+= palety.o sluzby.o menu.o timer.o editor.o script.o hra.o mouse602v2.o

all: $(APPL).cod
%.hex: %.elf
	$(OBJCOPY) -O ihex $< $@
%.cod: %.elf
	$(OBJCOPY) -O binary $< $@
$(APPL).elf: $(OBJ)
	$(LD) $(OBJ) -o $@ -Map=$(APPL).map $(LDFLAGS)
	$(OBJDUMP) -D $(APPL).elf > $(APPL).lst
%.o: %.S
	$(AS) $(ASFLAGS) $< -o $@

clean:
	rm -f *.o *.lst $(APPL).elf *.map

.SUFFIXES:

.PHONY: all clean
