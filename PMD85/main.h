#ifndef MAIN_H_DEFINED
#define MAIN_H_DEFINED
#include <stdint.h>
#include "STM32L4x2.h"
#include "common.h"
#include "core_cm4.h"
#include "system.h"
#include "gpio.h"
#include "vhsync.h"
#include "keyboard.h"
#include "PMD85v2A.h"
#include "loader.h"
/**
 * @mainpage PMD85 emulátor na STM32L452.
 * 
 * STM32L4x2 umožňuje generovat video signál pomocí SPI až do 36 MHz.
 * Pro emulaci PMD85v2A lze tuto frekvenci snížit na 18 MHz a pokud vynecháme obrazové atributy,
 * pak lze posílat přímo data z videopaměti po SPI po 6. bitech do VGA. To hodně zjednoduší zobrazování.
 * Funguje to stabilně jen pokud je procesor řízen krystalem a program běží z RAM. Protože je jí
 * celkem dost, není to problém. I když jsem se pokusil časově kritickou část přenést do RAM
 * (i když ostatní běží z FLASH), stále to není úplně stabilní, i když se to o něco zlepšilo.
 * 
 * Protože dopsat potřebné periferie bude dost obtížné, pro pokusy lze programy z PC nahrát
 * do paměti externě utilitou load (adresář utils). Lze nahrát binární data od adresy 0,
 * hexadecimální si počáteční adresu určí samy a fungují i textové programy v jazyce BASIC.
 * V tomto stadiu je to tedy jen hračka, která ukazuje, že to nějak jde. Samozřejmě v dnešní
 * době by bylo možné použít rychlejší procesor s větší pamětí a pomocí např. QSPI do toho
 * dostat i barvy, ale válel se mi doma nepotřebný Nucleo kit a VGA monitor, tak jsem si pohrál.
 * */

#endif // MAIN_H_DEFINED
