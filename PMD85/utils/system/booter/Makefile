APPL = loader32
AS = as-z80
LD = ld-z80
OBJCOPY = objcopy-z80
OBJDUMP = objdump-z80
ASFLAGS = -z80
LDFLAGS = -T script.ld

OBJ = booter.o
OBJ+= driver.o

all: $(APPL).rmm
%.hex: %.elf
	$(OBJCOPY) -O ihex $< $@
%.rmm: %.elf
	$(OBJCOPY) -O binary $< $@
$(APPL).elf: $(OBJ)
	$(LD) $(OBJ) -o $@ -Map=$(APPL).map $(LDFLAGS)
	$(OBJDUMP) -D $(APPL).elf > $(APPL).lst
%.o: %.S
	$(AS) $(ASFLAGS) $< -o $@ -adlhn=$*.lst

clean:
	rm -f *.o *.lst $(APPL).elf $(APPL).ptp $(APPL).map
.PHONY: all clean
