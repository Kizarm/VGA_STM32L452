## TRNG - využití hardwarového generátoru náhodných čísel.

Kdo generoval kryptografické klíče na Linuxu, ví že to může dlouho trvat.
Je to tím, že ta opravdu náhodná čísla musíme číst z /dev/random což je závislé
na entropii jádra. Nejlepší způsob jak tuto entropii korektně zvýšit je použít
nějaký hardwarový generátor. Před časem se objevovaly na webu konstrukce, které
využívaly šum závěrně orientovaného PN přechodu. Od té doby se situace změnila,
výrobci čipů začali tuto část hardware implementovat (trochu jiným způsobem)
přímo do SoC, takže další hardware není nutný. Další výhodou je, že tyto tzv.
TRNG jsou většinou již nějakým způsobem certifikovány (NIST...).

# Adresář source.

Firmware, který čte náhodná čísla z vestavěného TRNG a posílá je na USB.
Z hlediska USB se to pak chová jako standardní sériový port (ACM). Popravdě
by na to stačil holý čip + zdroj 3.3V připojený k USB.

# Adresář rngd.

Daemon pro použití STM32 RNG přes USB pro zvýšení entropie /dev/random.

Kód je převzat bez větších změn z [githubu](https://github.com/nhorman/rng-tools),
je vyházeno skoro vše, co není potřeba. Je nutná knihovna libcrypto a libsysfs.
Původní démon s USB jako /dev/ttyACMx funguje (parametr -r), ale bylo
by nutné předem totomuto zařízení správně nastavit parametry, takže zde
je to doplněno přímo do kódu, zařízení je pak
"/dev/serial/by-id/usb-Kizarm_Labs._USB_Serial_convertor_0001-if00", takže
nezávisí na pořadí zapojení do USB. Funkce init_entropy_source_kizarm() jej
pak nastaví korektně, takže stačí příkaz (jako superuser)
```
#./rngd
```
a zdroj entropie je připraven k použití. Příkaz
```
@cat /proc/sys/kernel/random/entropy_avail
```
vypíše entropii jádra - mělo by to být kolem 3000. Z /dev/random pak lze
vyčítat náhodná čísla v podstatě tak rychle, jak je stačí hardware dávat,
t.j. cca 70 kB/s.
```
@xxd /dev/random
```
tento proud vypíše, červená led na hardware indikuje, že probíhá čtení.

Pozn. Ty testy (z části psané v asm) vyházet nejde, démon je používá aby zjistil,
zda dané zařízení může skutečně použít jako zdroj entropie.
Co bylo upraveno viz rng-util.patch.

# Adresář double-split.

Na závěr nesmí chybět blbina. Tento firmware používá výstup VGA a na obrazovce
postupně vykresluje interferenční obrazec jaký by vznikl při dvouštěrbinovém experimentu
s jednotlivými částicemi. Rychlost "vystřelování" částic je možné regulovat
napětím na PA2. Je z něj docela dobře vidět, že generátor je opravdu náhodný.
