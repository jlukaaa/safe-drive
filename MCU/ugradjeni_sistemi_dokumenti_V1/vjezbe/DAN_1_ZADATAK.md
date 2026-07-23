# DAN 1 — Vježbe: Uvod u mikrokontrolere i osnovne periferije

Alati: VS Code + STM32 ekstenzija + STM32CubeMX + CMake/Ninja. Ploča: NUCLEO-F446ZE.
Kroz sve vježbe gradiš JEDAN projekat (`vjezbe_safe_drive`) koji raste iz dana u dan.

---

## Vježba 1.1 — Alati i dokumentacija
**Cilj:** podignuti razvojno okruženje i upoznati ploču.
**Zadatak:**
- Provjeri da su instalirani svi alati (`arm-none-eabi-gcc --version`, `cmake --version`).
- U User Manual-u ploče (UM1974) pronađi: pinove LED dioda (LD1/LD2/LD3), korisnički
  taster B1, i UART koji ide na ST-Link virtuelni COM port.
**Očekivani rezultat:** znaš gdje je koji pin i koji dokument (User Manual / Datasheet /
Reference Manual) služi za šta.

## Vježba 1.2 — Prvi CubeMX projekat: Blink
**Cilj:** napraviti projekat od nule i razumjeti strukturu generisanog koda.
**Zadatak:**
- Napravi novi CubeMX projekat za NUCLEO-F446ZE, toolchain **CMake**, ime
  `vjezbe_safe_drive`.
- Podesi LED diodu LD1 kao digitalni izlaz, generiši kod, build, flash.
- Napiši kod da LD1 treperi ~1 Hz.
**Očekivani rezultat:** LD1 treperi; umiješ objasniti čemu služe `main.c`, `MX_*_Init()`,
USER CODE blokovi i `.ioc` fajl.

## Vježba 1.3 — Tri LED diode
**Cilj:** raditi sa više izlaza i uočiti manu blokirajućeg kašnjenja.
**Zadatak:** proširi Vježbu 1.2 tako da sve tri LED (LD1/LD2/LD3) trepere u nekom
obrascu koristeći `HAL_Delay`.
**Očekivani rezultat:** tri LED u zadatom obrascu; umiješ objasniti zašto je `HAL_Delay`
loš za realan sistem.

## Vježba 1.4 — Ne-blokirajući blink (bez HAL_Delay)
**Cilj:** naučiti tajming bez blokiranja — obrazac koji koristi cijeli projekat.
**Zadatak:**
- Umjesto `HAL_Delay`, koristi `HAL_GetTick()` da LED trepere.
- Dodaj DRUGU LED sa DRUGIM periodom u istoj petlji, tako da rade "istovremeno".
**Očekivani rezultat:** dvije LED sa različitim periodima trepere istovremeno, a petlja
nikad ne "stoji".
