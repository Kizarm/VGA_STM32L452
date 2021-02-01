OUTPUT_ARCH("z80")
ENTRY(Start)
MEMORY {
  RAMBS (xrw)      : ORIGIN = 0x00000000, LENGTH = 0x0100
  RAMBB (xrw)      : ORIGIN = 0x00000080, LENGTH = 0x0100
  RAM00 (xrw)      : ORIGIN = 0x0000C470, LENGTH = 0x10
  RAM01 (xrw)      : ORIGIN = 0x0000C4B0, LENGTH = 0x10
  RAM02 (xrw)      : ORIGIN = 0x0000C4F0, LENGTH = 0x10
  RAM03 (xrw)      : ORIGIN = 0x0000C530, LENGTH = 0x10
  RAM04 (xrw)      : ORIGIN = 0x0000C570, LENGTH = 0x10
  RAM05 (xrw)      : ORIGIN = 0x0000C5B0, LENGTH = 0x10
  RAM06 (xrw)      : ORIGIN = 0x0000C5F0, LENGTH = 0x10
  RAM07 (xrw)      : ORIGIN = 0x0000C630, LENGTH = 0x10
  RAM08 (xrw)      : ORIGIN = 0x0000C670, LENGTH = 0x10
  RAM09 (xrw)      : ORIGIN = 0x0000C6B0, LENGTH = 0x10
  RAM0A (xrw)      : ORIGIN = 0x0000C6F0, LENGTH = 0x10
  RAM0B (xrw)      : ORIGIN = 0x0000C730, LENGTH = 0x10
  RAM0C (xrw)      : ORIGIN = 0x0000C770, LENGTH = 0x10
  RAM0D (xrw)      : ORIGIN = 0x0000C7B0, LENGTH = 0x10
  RAM0E (xrw)      : ORIGIN = 0x0000C7F0, LENGTH = 0x10
  RAM0F (xrw)      : ORIGIN = 0x0000C830, LENGTH = 0x10
  RAM10 (xrw)      : ORIGIN = 0x0000C870, LENGTH = 0x10
  RAM11 (xrw)      : ORIGIN = 0x0000C8B0, LENGTH = 0x10
  RAM12 (xrw)      : ORIGIN = 0x0000C8F0, LENGTH = 0x10
  RAM13 (xrw)      : ORIGIN = 0x0000C930, LENGTH = 0x10
  RAM14 (xrw)      : ORIGIN = 0x0000C970, LENGTH = 0x10
  RAM15 (xrw)      : ORIGIN = 0x0000C9B0, LENGTH = 0x10
  RAM16 (xrw)      : ORIGIN = 0x0000C9F0, LENGTH = 0x10
  RAM17 (xrw)      : ORIGIN = 0x0000CA30, LENGTH = 0x10
  RAM18 (xrw)      : ORIGIN = 0x0000CA70, LENGTH = 0x10
  RAM19 (xrw)      : ORIGIN = 0x0000CAB0, LENGTH = 0x10
  RAM1A (xrw)      : ORIGIN = 0x0000CAF0, LENGTH = 0x10
  RAM1B (xrw)      : ORIGIN = 0x0000CB30, LENGTH = 0x10
  RAM1C (xrw)      : ORIGIN = 0x0000CB70, LENGTH = 0x10
  RAM1D (xrw)      : ORIGIN = 0x0000CBB0, LENGTH = 0x10
  RAM1E (xrw)      : ORIGIN = 0x0000CBF0, LENGTH = 0x10
  RAM1F (xrw)      : ORIGIN = 0x0000CC30, LENGTH = 0x10
  RAM20 (xrw)      : ORIGIN = 0x0000CC70, LENGTH = 0x10
  RAM21 (xrw)      : ORIGIN = 0x0000CCB0, LENGTH = 0x10
  RAM22 (xrw)      : ORIGIN = 0x0000CCF0, LENGTH = 0x10
  RAM23 (xrw)      : ORIGIN = 0x0000CD30, LENGTH = 0x10
  RAM24 (xrw)      : ORIGIN = 0x0000CD70, LENGTH = 0x10
  RAM25 (xrw)      : ORIGIN = 0x0000CDB0, LENGTH = 0x10
  RAM26 (xrw)      : ORIGIN = 0x0000CDF0, LENGTH = 0x10
  RAM27 (xrw)      : ORIGIN = 0x0000CE30, LENGTH = 0x10
  RAM28 (xrw)      : ORIGIN = 0x0000CE70, LENGTH = 0x10
  RAM29 (xrw)      : ORIGIN = 0x0000CEB0, LENGTH = 0x10
  RAM2A (xrw)      : ORIGIN = 0x0000CEF0, LENGTH = 0x10
  RAM2B (xrw)      : ORIGIN = 0x0000CF30, LENGTH = 0x10
  RAM2C (xrw)      : ORIGIN = 0x0000CF70, LENGTH = 0x10
  RAM2D (xrw)      : ORIGIN = 0x0000CFB0, LENGTH = 0x10
  RAM2E (xrw)      : ORIGIN = 0x0000CFF0, LENGTH = 0x10
  RAM2F (xrw)      : ORIGIN = 0x0000D030, LENGTH = 0x10
  RAM30 (xrw)      : ORIGIN = 0x0000D070, LENGTH = 0x10
  RAM31 (xrw)      : ORIGIN = 0x0000D0B0, LENGTH = 0x10
  RAM32 (xrw)      : ORIGIN = 0x0000D0F0, LENGTH = 0x10
  RAM33 (xrw)      : ORIGIN = 0x0000D130, LENGTH = 0x10
  RAM34 (xrw)      : ORIGIN = 0x0000D170, LENGTH = 0x10
  RAM35 (xrw)      : ORIGIN = 0x0000D1B0, LENGTH = 0x10
  RAM36 (xrw)      : ORIGIN = 0x0000D1F0, LENGTH = 0x10
  RAM37 (xrw)      : ORIGIN = 0x0000D230, LENGTH = 0x10
  RAM38 (xrw)      : ORIGIN = 0x0000D270, LENGTH = 0x10
  RAM39 (xrw)      : ORIGIN = 0x0000D2B0, LENGTH = 0x10
  RAM3A (xrw)      : ORIGIN = 0x0000D2F0, LENGTH = 0x10
  RAM3B (xrw)      : ORIGIN = 0x0000D330, LENGTH = 0x10
  RAM3C (xrw)      : ORIGIN = 0x0000D370, LENGTH = 0x10
  RAM3D (xrw)      : ORIGIN = 0x0000D3B0, LENGTH = 0x10
  RAM3E (xrw)      : ORIGIN = 0x0000D3F0, LENGTH = 0x10
  RAM3F (xrw)      : ORIGIN = 0x0000D430, LENGTH = 0x10
  RAM40 (xrw)      : ORIGIN = 0x0000D470, LENGTH = 0x10
  RAM41 (xrw)      : ORIGIN = 0x0000D4B0, LENGTH = 0x10
  RAM42 (xrw)      : ORIGIN = 0x0000D4F0, LENGTH = 0x10
  RAM43 (xrw)      : ORIGIN = 0x0000D530, LENGTH = 0x10
  RAM44 (xrw)      : ORIGIN = 0x0000D570, LENGTH = 0x10
  RAM45 (xrw)      : ORIGIN = 0x0000D5B0, LENGTH = 0x10
  RAM46 (xrw)      : ORIGIN = 0x0000D5F0, LENGTH = 0x10
  RAM47 (xrw)      : ORIGIN = 0x0000D630, LENGTH = 0x10
  RAM48 (xrw)      : ORIGIN = 0x0000D670, LENGTH = 0x10
  RAM49 (xrw)      : ORIGIN = 0x0000D6B0, LENGTH = 0x10
  RAM4A (xrw)      : ORIGIN = 0x0000D6F0, LENGTH = 0x10
  RAM4B (xrw)      : ORIGIN = 0x0000D730, LENGTH = 0x10
  RAM4C (xrw)      : ORIGIN = 0x0000D770, LENGTH = 0x10
  RAM4D (xrw)      : ORIGIN = 0x0000D7B0, LENGTH = 0x10
  RAM4E (xrw)      : ORIGIN = 0x0000D7F0, LENGTH = 0x10
  RAM4F (xrw)      : ORIGIN = 0x0000D830, LENGTH = 0x10
  RAM50 (xrw)      : ORIGIN = 0x0000D870, LENGTH = 0x10
  RAM51 (xrw)      : ORIGIN = 0x0000D8B0, LENGTH = 0x10
  RAMES (xrw)      : ORIGIN = 0x0000D8F0, LENGTH = 0x1000
}
SECTIONS {
  .fixed : {
  init = .;
    *(.text.start)
  } >RAMBS
  _boot_end = .;
  .reloc_XX : AT(_boot_end) {
    *(.text.boot)
  } >RAMBB

  _fixed_end = _boot_end + BooterLen;
  .reloc_00 : AT(_fixed_end + 0x0000) {
    driver.o(.text.00S)
  } >RAM00
  .reloc_01 : AT(_fixed_end + 0x0010) {
    driver.o(.text.01S)
  } >RAM01
  .reloc_02 : AT(_fixed_end + 0x0020) {
    driver.o(.text.02S)
  } >RAM02
  .reloc_03 : AT(_fixed_end + 0x0030) {
    driver.o(.text.03S)
  } >RAM03
  .reloc_04 : AT(_fixed_end + 0x0040) {
    driver.o(.text.04S)
  } >RAM04
  .reloc_05 : AT(_fixed_end + 0x0050) {
    driver.o(.text.05S)
  } >RAM05
  .reloc_06 : AT(_fixed_end + 0x0060) {
    driver.o(.text.06S)
  } >RAM06
  .reloc_07 : AT(_fixed_end + 0x0070) {
    driver.o(.text.07S)
  } >RAM07
  .reloc_08 : AT(_fixed_end + 0x0080) {
    driver.o(.text.08S)
  } >RAM08
  .reloc_09 : AT(_fixed_end + 0x0090) {
    driver.o(.text.09S)
  } >RAM09
  .reloc_0A : AT(_fixed_end + 0x00A0) {
    driver.o(.text.0AS)
  } >RAM0A
  .reloc_0B : AT(_fixed_end + 0x00B0) {
    driver.o(.text.0BS)
  } >RAM0B
  .reloc_0C : AT(_fixed_end + 0x00C0) {
    driver.o(.text.0CS)
  } >RAM0C
  .reloc_0D : AT(_fixed_end + 0x00D0) {
    driver.o(.text.0DS)
  } >RAM0D
  .reloc_0E : AT(_fixed_end + 0x00E0) {
    driver.o(.text.0ES)
  } >RAM0E
  .reloc_0F : AT(_fixed_end + 0x00F0) {
    driver.o(.text.0FS)
  } >RAM0F
  .reloc_10 : AT(_fixed_end + 0x0100) {
    driver.o(.text.10S)
  } >RAM10
  .reloc_11 : AT(_fixed_end + 0x0110) {
    driver.o(.text.11S)
  } >RAM11
  .reloc_12 : AT(_fixed_end + 0x0120) {
    driver.o(.text.12S)
  } >RAM12
  .reloc_13 : AT(_fixed_end + 0x0130) {
    driver.o(.text.13S)
  } >RAM13
  .reloc_14 : AT(_fixed_end + 0x0140) {
    driver.o(.text.14S)
  } >RAM14
  .reloc_15 : AT(_fixed_end + 0x0150) {
    driver.o(.text.15S)
  } >RAM15
  .reloc_16 : AT(_fixed_end + 0x0160) {
    driver.o(.text.16S)
  } >RAM16
  .reloc_17 : AT(_fixed_end + 0x0170) {
    driver.o(.text.17S)
  } >RAM17
  .reloc_18 : AT(_fixed_end + 0x0180) {
    driver.o(.text.18S)
  } >RAM18
  .reloc_19 : AT(_fixed_end + 0x0190) {
    driver.o(.text.19S)
  } >RAM19
  .reloc_1A : AT(_fixed_end + 0x01A0) {
    driver.o(.text.1AS)
  } >RAM1A
  .reloc_1B : AT(_fixed_end + 0x01B0) {
    driver.o(.text.1BS)
  } >RAM1B
  .reloc_1C : AT(_fixed_end + 0x01C0) {
    driver.o(.text.1CS)
  } >RAM1C
  .reloc_1D : AT(_fixed_end + 0x01D0) {
    driver.o(.text.1DS)
  } >RAM1D
  .reloc_1E : AT(_fixed_end + 0x01E0) {
    driver.o(.text.1ES)
  } >RAM1E
  .reloc_1F : AT(_fixed_end + 0x01F0) {
    driver.o(.text.1FS)
  } >RAM1F
  .reloc_20 : AT(_fixed_end + 0x0200) {
    driver.o(.text.20S)
  } >RAM20
  .reloc_21 : AT(_fixed_end + 0x0210) {
    driver.o(.text.21S)
  } >RAM21
  .reloc_22 : AT(_fixed_end + 0x0220) {
    driver.o(.text.22S)
  } >RAM22
  .reloc_23 : AT(_fixed_end + 0x0230) {
    driver.o(.text.23S)
  } >RAM23
  .reloc_24 : AT(_fixed_end + 0x0240) {
    driver.o(.text.24S)
  } >RAM24
  .reloc_25 : AT(_fixed_end + 0x0250) {
    driver.o(.text.25S)
  } >RAM25
  .reloc_26 : AT(_fixed_end + 0x0260) {
    driver.o(.text.26S)
  } >RAM26
  .reloc_27 : AT(_fixed_end + 0x0270) {
    driver.o(.text.27S)
  } >RAM27
  .reloc_28 : AT(_fixed_end + 0x0280) {
    driver.o(.text.28S)
  } >RAM28
  .reloc_29 : AT(_fixed_end + 0x0290) {
    driver.o(.text.29S)
  } >RAM29
  .reloc_2A : AT(_fixed_end + 0x02A0) {
    driver.o(.text.2AS)
  } >RAM2A
  .reloc_2B : AT(_fixed_end + 0x02B0) {
    driver.o(.text.2BS)
  } >RAM2B
  .reloc_2C : AT(_fixed_end + 0x02C0) {
    driver.o(.text.2CS)
  } >RAM2C
  .reloc_2D : AT(_fixed_end + 0x02D0) {
    driver.o(.text.2DS)
  } >RAM2D
  .reloc_2E : AT(_fixed_end + 0x02E0) {
    driver.o(.text.2ES)
  } >RAM2E
  .reloc_2F : AT(_fixed_end + 0x02F0) {
    driver.o(.text.2FS)
  } >RAM2F
  .reloc_30 : AT(_fixed_end + 0x0300) {
    driver.o(.text.30S)
  } >RAM30
  .reloc_31 : AT(_fixed_end + 0x0310) {
    driver.o(.text.31S)
  } >RAM31
  .reloc_32 : AT(_fixed_end + 0x0320) {
    driver.o(.text.32S)
  } >RAM32
  .reloc_33 : AT(_fixed_end + 0x0330) {
    driver.o(.text.33S)
  } >RAM33
  .reloc_34 : AT(_fixed_end + 0x0340) {
    driver.o(.text.34S)
  } >RAM34
  .reloc_35 : AT(_fixed_end + 0x0350) {
    driver.o(.text.35S)
  } >RAM35
  .reloc_36 : AT(_fixed_end + 0x0360) {
    driver.o(.text.36S)
  } >RAM36
  .reloc_37 : AT(_fixed_end + 0x0370) {
    driver.o(.text.37S)
  } >RAM37
  .reloc_38 : AT(_fixed_end + 0x0380) {
    driver.o(.text.38S)
  } >RAM38
  .reloc_39 : AT(_fixed_end + 0x0390) {
    driver.o(.text.39S)
  } >RAM39
  .reloc_3A : AT(_fixed_end + 0x03A0) {
    driver.o(.text.3AS)
  } >RAM3A
  .reloc_3B : AT(_fixed_end + 0x03B0) {
    driver.o(.text.3BS)
  } >RAM3B
  .reloc_3C : AT(_fixed_end + 0x03C0) {
    driver.o(.text.3CS)
  } >RAM3C
  .reloc_3D : AT(_fixed_end + 0x03D0) {
    driver.o(.text.3DS)
  } >RAM3D
  .reloc_3E : AT(_fixed_end + 0x03E0) {
    driver.o(.text.3ES)
  } >RAM3E
  .reloc_3F : AT(_fixed_end + 0x03F0) {
    driver.o(.text.3FS)
  } >RAM3F
  .reloc_40 : AT(_fixed_end + 0x0400) {
    driver.o(.text.40S)
  } >RAM40
  .reloc_41 : AT(_fixed_end + 0x0410) {
    driver.o(.text.41S)
  } >RAM41
  .reloc_42 : AT(_fixed_end + 0x0420) {
    driver.o(.text.42S)
  } >RAM42
  .reloc_43 : AT(_fixed_end + 0x0430) {
    driver.o(.text.43S)
  } >RAM43
  .reloc_44 : AT(_fixed_end + 0x0440) {
    driver.o(.text.44S)
  } >RAM44
  .reloc_45 : AT(_fixed_end + 0x0450) {
    driver.o(.text.45S)
  } >RAM45
  .reloc_46 : AT(_fixed_end + 0x0460) {
    driver.o(.text.46S)
  } >RAM46
  .reloc_47 : AT(_fixed_end + 0x0470) {
    driver.o(.text.47S)
  } >RAM47
  .reloc_48 : AT(_fixed_end + 0x0480) {
    driver.o(.text.48S)
  } >RAM48
  .reloc_49 : AT(_fixed_end + 0x0490) {
    driver.o(.text.49S)
  } >RAM49
  .reloc_4A : AT(_fixed_end + 0x04A0) {
    driver.o(.text.4AS)
  } >RAM4A
  .reloc_4B : AT(_fixed_end + 0x04B0) {
    driver.o(.text.4BS)
  } >RAM4B
  .reloc_4C : AT(_fixed_end + 0x04C0) {
    driver.o(.text.4CS)
  } >RAM4C
  .reloc_4D : AT(_fixed_end + 0x04D0) {
    driver.o(.text.4DS)
  } >RAM4D
  .reloc_4E : AT(_fixed_end + 0x04E0) {
    driver.o(.text.4ES)
  } >RAM4E
  .reloc_4F : AT(_fixed_end + 0x04F0) {
    driver.o(.text.4FS)
  } >RAM4F
  .reloc_50 : AT(_fixed_end + 0x0500) {
    driver.o(.text.50S)
  } >RAM50
  .reloc_51 : AT(_fixed_end + 0x0510) {
    driver.o(.text.51S)
  } >RAM51
  .reloc_ES : AT(_fixed_end + 0x0520) {
    *(.text.fill)
  } >RAMES
}
