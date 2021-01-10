OUTPUT = base-ram
OBJS   = base.o

CROSS_COMPILE = arm-none-eabi-
LD     = $(CROSS_COMPILE)ld
AS     = $(CROSS_COMPILE)as
SIZE   = $(CROSS_COMPILE)size
OBJCOPY = $(CROSS_COMPILE)objcopy
OBJDUMP = $(CROSS_COMPILE)objdump
##########################################################################
# Startup files - zde jen skript pro linker
##########################################################################
LDLIBS  = -L. -T script.ld
ASFLAGS =
# Odřež na výstupu vše nepotřebné (objcopy)
OCFLAGS = --strip-unneeded
LDMODS = -nostartfiles -nostdlib

all: $(OUTPUT).elf
# Ten je závislý na objektech $(OBJS) : po jeho vytvoření lze udělat hex, bin atd...
$(OUTPUT).elf: $(OBJS)
	$(LD) $(LDMODS) -o $(OUTPUT).elf $(OBJS) $(LDLIBS)
	-@echo "size:"
	$(SIZE) $(OUTPUT).elf
	-@echo "listing:"
	$(OBJDUMP) -d $(OUTPUT).elf > $(OUTPUT).lst
	$(OBJCOPY) $(OCFLAGS) -O binary $(OUTPUT).elf $(OUTPUT).bin
#	$(OBJCOPY) $(OCFLAGS) -O ihex   $(OUTPUT).elf $(OUTPUT).hex
	-@echo "OK."
%.o : %.s
	$(AS) $(ASFLAGS) -o $@ $<
# Vyčištění adresáře
clean:
	rm -f *.map *.o *.lst *.elf *.hex *.bin
.PHONY: all clean
