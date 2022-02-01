# Sudoku

Algoritmus této hry je poměrně jednoduchý, ale vyžaduje rekurzi. Když už
máme něco, na čem to jde vyzkoušet, tak proč ne. Kolik sežere rekurze
zásobníku aby se to nechalo provozovat na jednočipu s poměrně malou RAM,
to bylo hlavním předmětem zájmu. Proto to má svůj vlastní linker stript,
oblast video paměti je na konci sekce .bss, kde přetečení vadí nejméně.
A zároveň by to bylo vidět. Nakonec to není tak moc, ale pár KiB to stejně
zabere.

Funguje to tak, že se nejprve naplní celé hrací pole čísly, která jsou
generována rekurzívním algoritmem ve své podstatě stejným, jako je algoritmus
pro řešení Sudoku a následně se náhodně pole mažou a ověřuje se, zda je
celé pole jednoznačně řešitelné. To vyžaduje další rekurzi a na ARM to
může trvat delší dobu (řádově i desíky sekund). Jako generátor náhody je
na ARM použit interní TRNG, pro ladění systémový pseudonáhodný generátor.
Jsou zde zdrojáky jak pro ARM, pro ladění Qt4/5, a vyzkoušení na webu
i Emscripten. Jádro je úplně shodné.

Pokud si to někdo chce vyzkoušet, webová verze je k dispozici [zde](https://kizarm.github.io/math/sudoku/index.html).
Je úplně stejná jako ARM nebo Qt, není to vlastně hra, nemůžete chtít aby
jeden člověk hru napsal a zároveň i s chutí hrál. Ale jsou k tomu zdrojáky
a poznámky v souboru canvas.cpp umožní upravit hru tak, aby u toho bylo
nutné přemýšlet.

Na závěr ještě malá poznámka. Tahle hra se objevovala i na osmibitových
počítačích v počátcích mikroprocesorové éry. Rekurzívní algoritmus použitý
zde by na tomhle železe asi neběžel. Je však možné vygenerovat jednoznačně
řešitelné pole předem a pak používat jen jeho permutace. Pokud zaměníme
dva rádky (sloupce) ve stejné třetině pole, nic se nezmění. Totéž platí
i pro celé bloky jednotlivých třetin. Máme tak 6^8, t.j. 1679616 možností,
takže hráč nemá možnost poznat, že hraje vlastně jednu a tu samou hru,
která je jen různě zpřeházená.
