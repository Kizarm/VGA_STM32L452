APPL = basic
AS = as-z80
LD = ld-z80
BTP = bin2ptp
OBJCOPY = objcopy-z80
OBJDUMP = objdump-z80
ASFLAGS = -z80
LDFLAGS = -T script.ld
#
# Je to normální BASIC_G v 2A, jen se z .rmm odřízne začátek,
# takže zbude jen ta část, spustitelná od 0, potřebná pro RUN.COM
# Pak jde spouštět pod MIKROS (bez možnosti návratu zpět do OS).
# Pokud se od 0x2401 dále nahraje program v BASIC_G (a upraví délka v zápisníku),
# jdou spouštět i původní programy (utilita v bload). Nejdou však nijak uložit.
#
OBJ = pmd_basic.o

all: $(APPL).cod
%.cod: %.elf
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
