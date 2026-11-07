Μεταγλωττιστής C για το Rogic / C compiler for Rogic
======================================================

ΕΛΛΗΝΙΚΑ
Αυτός ο φάκελος περιέχει τον μεταγλωττιστή C (avr-gcc) που χρησιμοποιεί το Rogic για τον
επεξεργαστή κώδικα. Έτσι δεν χρειάζεται να εγκαταστήσεις τίποτα στον υπολογιστή.
Ο φάκελος πρέπει να μείνει εδώ, μέσα στον φάκελο του Rogic, με το όνομα "Toolchain".
Αν τον σβήσεις, το Rogic θα χρησιμοποιήσει όποιον avr-gcc είναι εγκατεστημένος στον υπολογιστή.

ENGLISH
This folder holds the C compiler (avr-gcc) that Rogic's code editor uses, so nothing has to be
installed on the PC. Keep it inside the Rogic folder, named "Toolchain". If it is removed,
Rogic falls back to whatever avr-gcc is installed on the PC.

WHAT IS IN HERE
This is a trimmed copy of the Windows x86 build "avr-gcc 14.1.0" by Zak Kemble
(release v14.1.0-1), keeping only the files needed to build for the ATmega8:

  AVR-GCC       14.1.0   (GPL-3.0-or-later, with the GCC Runtime Library Exception for libgcc)
  AVR-Binutils  2.42     (GPL-3.0-or-later)       - as, ld, objcopy, objdump, size
  AVR-LibC      2.2.0    (modified BSD licence)   - C library and headers

Licence texts are in the LICENSES folder.

SOURCE CODE
  Build scripts and the full, untrimmed build:
    https://github.com/ZakKemble/avr-gcc-build/releases/tag/v14.1.0-1
  GCC 14.1.0:        https://ftp.gnu.org/gnu/gcc/gcc-14.1.0/
  Binutils 2.42:     https://ftp.gnu.org/gnu/binutils/
  AVR-LibC 2.2.0:    https://github.com/avrdudes/avr-libc/releases
