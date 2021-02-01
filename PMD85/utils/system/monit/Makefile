APPL = monit2A
AS = as-z80
LD = ld-z80
OBJCOPY = objcopy-z80
OBJDUMP = objdump-z80
ASFLAGS = -z80
LDFLAGS = -T script.ld

OBJ = monit.o

all: $(APPL).rom
%.hex: %.elf
	$(OBJCOPY) -O ihex $< $@
%.rom: %.elf
	$(OBJCOPY) -O binary $< $@
$(APPL).elf: $(OBJ)
	$(LD) $(OBJ) -o $@ -Map=$(APPL).map $(LDFLAGS)
	$(OBJDUMP) -D $(APPL).elf > $(APPL).lst
%.o: %.S
	$(AS) $(ASFLAGS) $< -o $@ -adlhn=$*.lst

clean:
	rm -f *.o *.lst $(APPL).elf $(APPL).map
.PHONY: all clean
