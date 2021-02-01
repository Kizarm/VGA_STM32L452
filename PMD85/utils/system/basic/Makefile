APPL = basic2A
AS = as-z80
LD = ld-z80
OBJCOPY = objcopy-z80
OBJDUMP = objdump-z80
ASFLAGS = -z80
LDFLAGS = -T script.ld

OBJ = boot.o pmd_basic.o

all: $(APPL).rmm
%.rmm: %.elf
	$(OBJCOPY) -O binary $< $@
$(APPL).elf: $(OBJ)
	$(LD) $(OBJ) -o $@ -Map=$(APPL).map $(LDFLAGS)
	$(OBJDUMP) -D $(APPL).elf > $(APPL).lst
%.o: %.S
	$(AS) $(ASFLAGS) $< -o $@ -adlhn=$*.lst

clean:
	rm -f *.o *.lst $(APPL).elf $(APPL).map

.SUFFIXES:

.PHONY: all clean
