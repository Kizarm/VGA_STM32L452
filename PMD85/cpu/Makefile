##########################################################################
# Uživatelské definice - pro dané nastavení zde lze vytvořit projekt
# jednoduše tak, že zadáme jméno výstupu a vstupní objekty.
##########################################################################
TARGET = stm32l4
OUTPUT = ../common/$(TARGET)/ld/libcpu
# S/C/C++ files
#SOURCES += Memory.s
SOURCES += ChipCpu8080.cpp ChipMemory.cpp ChipPIO8255.cpp ChipUSART8251.cpp ChipPIT8253.cpp SystemPIO.cpp
SOURCES += IifGPIO.cpp IifTape.cpp IifTimer.cpp RomModule.cpp
SOURCES += PMD85v2A.cpp

##########################################################################
BLD = ./build/
# VPATH je cesta ke zdrojovým souborům, zde jen hlavní adresář
VPATH = ./ ../$(TARGET)
# A cesty k hlavičkám
INCLUDE_PATHS = ./ ../
##########################################################################
# GNU GCC OR clang compiler - verze pro ARM - crosscompiler
##########################################################################
# Instrukční sada thumb, cpu Cortex-Mx
# Jadro cortex-Mx, thumb
 CPU_TYPE = cortex-m4
 MFLAGS   = -mthumb -mcpu=$(CPU_TYPE)
#Pro použití float je dobré použít FPU, ale výpočty float bývají často zbytečné.
#MFLAGS  += -mfpu=fpv4-sp-d16 -mfloat-abi=hard

 CROSS_COMPILE = arm-none-eabi-
# Můžeme zkusit použít i clang - pak COMPILER = clang
COMPILER = 
ifeq ($(COMPILER),clang)
# Pro clang je lépe nastavit vyšší optimalizaci, -fshort-enums je kvůli kompatibititě s ld.
# Ta verze clang-3.x jako příkaz je z Ubuntu, prostě to tak vymysleli, tak to nechme
# Pozor různé verze mají odlišné přepínače cílové architektury (-target) !!!
CLVER =-3.8
CC  = clang$(CLVER)
CXX = clang++$(CLVER)
CFLAGS += --target=thumbv7em-none-eabi -mfloat-abi=soft -fshort-enums -Oz
#CFLAGS += --target=thumbv7em-none-eabi -mfpu=fpv4-sp-d16 -mfloat-abi=hard -fshort-enums -Oz
# Linkování se obvykle provádí pomocí gcc, lze přímo ld, ale mohou být problémy s knihovnami
 LD = $(CROSS_COMPILE)ld
#LD = $(CROSS_COMPILE)gcc
else
CC  = $(CROSS_COMPILE)gcc
CXX = $(CROSS_COMPILE)g++
# Optimalizace
CFLAGS += -Os $(MFLAGS)
LD  = $(CC)
endif
# Assembler (*.s) lze překládat i pomocí gcc (-x assembler-with-cpp)
AS   = $(CROSS_COMPILE)as
SIZE = $(CROSS_COMPILE)size
OBJCOPY = $(CROSS_COMPILE)objcopy
OBJDUMP = $(CROSS_COMPILE)objdump
#DEFINES = USE_USB=1
# Podmineny preklad, cesta k hlavičkám
CFLAGS += $(addprefix -D,$(DEFINES)) $(addprefix -I,$(INCLUDE_PATHS))
#MFLAGS = -m32
ifneq ($(COMPILER),clang)
# Vytvořit listing s příponou .lst (divné, ale - kouzlit se dá všelijak)
# clang tento přepínač neakceptuje, protože funguje trochu jinak
CFLAGS += -Wa,-adhlns=$(@:%.o=%.lst)
endif
#CFLAGS += $(MFLAGS)
# přelož, všechna varování, debug info
CFLAGS += -c -Wall -g -fshort-wchar
# Umístit kód funkcí i proměnné do zvláštních sekcí
CFLAGS += -ffunction-sections -fdata-sections
# pro C++ nutno ještě vypnout obsluhu výjimek (v C taky i když je to jedno)
CFLAGS += -fno-exceptions
# 2. Linker
# 3. Ostatní
# Assembler nepotřebuje žádné parametry, pokud je vše ve zdrojovém textu
ASFLAGS =
# Odřež na výstupu vše nepotřebné (objcopy)
OCFLAGS = --strip-unneeded
# 4. Různé pomocné funkce pro líné lidi
# Extra nastavení překladače (není nutné, pokud nepřekládám hovadiny)
#CXXEXT+= -Wno-deprecated-register
CXXEXT+=-std=c++14 -fno-rtti
#CEXTRA+= -std=c11
OBJS   = $(addsuffix .o,$(basename $(SOURCES)))
BOBJS  = $(addprefix $(BLD),$(OBJS))
##########################################################################
# Rules - pravidla pro tvorbu výstupu.
##########################################################################
# Výsledek všeho (all) má být soubor *.elf - z něj se odvodí další
all: $(BLD) $(OUTPUT).a
# Ten je závislý na objektech $(OBJS) : po jeho vytvoření lze udělat hex, bin atd...
$(OUTPUT).a: $(BOBJS)
	rm -f $(OUTPUT).a
	$(AR) rcs $(OUTPUT).a $(BOBJS)
	-@echo "OK."
# Divná makra $@ $< lze najít v dokumentaci make
# Každý objekt *.o je závislý na zdroji - zde *.c
$(BLD)%.o : %.c
	$(CC) -std=gnu99 $(CFLAGS) $(CEXTRA) -o $@ $<
# nebo c++
$(BLD)%.o : %.cpp
	$(CXX) $(CFLAGS) $(CXXEXT) -o $@ $<
# nebo *.s
$(BLD)%.o : %.s
	$(AS) $(ASFLAGS) -o $@ $<
$(BLD):
	mkdir $(BLD)
# Vyčištění adresáře
clean:
	rm -f $(BLD)* *.a
# debug bude jen mít definováno něco navíc

.PHONY: all clean
#-include makefile.inc
