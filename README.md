# VGA_STM32L452 V2

## Motivace
Začaly se mi tu hromadit monitory VGA s rozměrem 4:3, tak jsem přemýšlel jak je využít.
Zkusil jsem generovat monochromatický signál na Nucleo kitu, osazeném STM32L452. Je to
dost na hraně, pro výstup je použito SPI pomocí DMA, časování je však natolik kritické,
že to funguje jen když je osazen krystal a kód běží z RAM. Ve verzi 2 byl vytvořen vlastní
hardware, protože ty dráty na kitu ve spojení s rychlými SPI sběrnicemi nedělají dobrotu.
V sekci hardware je tedy schema a celý návrh desky, včetně dat pro výrobu - skutečně
je to podle toho vyrobeno a dá se to poměrně primitivními prostředky osadit.

![schematic](./hardware/VgaOnSTM32L452.png)

Pro ladění (defaultní stav) je v procesoru nahrán do flash krátký kousek kódu z adresáře
base-ram. Vlastní kód je pak nahráván do RAM, odkud také běží. Je to jednoduchý hack,
který umožňuje ladit v RAM a nemusí se čarovat s BOOT options. I tak kód běží celý z RAM, tj. musí se tam vejít.
Zkoušel jsem dostat do RAM jen kritické části, ale příliš to nepomohlo, cache flash
asi není dostatečně deterministická a přerušení pak trochu rozmazávají pixely.

## bootloader

![hardware](./hardware/board.png)

Základní firmware, který by měl být nahrán do flash procesoru. Je možné ho trochu konfigurovat zkratovými propojkami,
slouží k tomu piny, vyvedené na konektor P1. Pokud není žádná z propojek osazena, program
funguje základním způsobem - po připojení napájecího napětí se pokusí enumerovat se jako USB MSC,
když se mu to nepovede, zkusí z kořenového adresáře FIRMWARE natáhnout do RAM od adresy 0x2000_0000
první soubor, který v tomto adresáři najde a pokud se mu to podaří, spustí ho. Propojky modifikují
chování zhruba následujícím způsobem:

* NO_FILE  - nenatáhne soubor do paměti - pro ladění, podobné jako hack base-ram
* NO_USB   - nečeká na enumeraci USB, je tedy možné spustit uživatelský program i když je to připojeno k PC
* NO_WRITE - MSC se chová jako read only zařízení - R/W přístup často zbytečně přepisuje blok 0 (dirty bit)


## PMD85
V tomto adresáři je jednoduchý emulátor PMD85v2A, včetně programů MONITOR2A a BASICGV2A. Je to jen základ,
emulace je založena na kódu z [githubu](https://github.com/mborik/GPMD85Emulator). Ve verzi 2 je přidána
jednotka PMD32 s daty ve SPI flash. To umožnilo přidat bootloader, který když nahrajeme do procesoru,
pak je zařízení schopné pracovat (po připojení k PC) jako USB mass storage device, na SPI flash
se dá vytvořit FAT filesystém příkazem
```
mkfs.vfat -I -v -F 12 -f 1 -r 128 -S 4096 -s 1 -n LOADER /dev/sdX
```
nakopírovat do flash souborovou strukturu PMD32 (př. /PMD85/cpu/image/fil) a do adresáře FIRMWARE dát
vlastní binárku (linkovanou pro běh z RAM). Pokud pak připojíme desku jen na USB napáječ (aby nedošlo k enumeraci USB),
binárka se nabootuje a spustí. Binárka může být třeba i ten voltmetr.
Pro ladění je přidán Qt4/5 projekt devel, který používá stejné soubory cpu jako firmware. Ladit to přímo v tom
ARM čipu není zase taková sranda a co funguje na jedné platformě, funguje zpravidla i na jiné, pokud se to překládá gcc.
Pozn. Ten FAT filesystém a i USB MSC je trochu nestardní, používá délku bloku 4096B (kvůli použití flash - NOR).

## Voltmeter
To je jen taková blbina, ale zajímavě vypadá. Čte to napětí na PA2 a zobrazuje ho

![Náhled](./Voltmeter/screen.png)

Má to FIR filtr, který napodobí kývání ručičky. Nastavovat tím nějakou veličinu je opravdu
příjemnější než při použití digitálního měřidla.

TODO: Textový displej něco jako VT52.
