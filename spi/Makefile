DEVICE=16f877a
FAMILY=pic14
PRJ=spi
# C compiler, assembler, device programmer:
CC=../sdcc-4.4.0/bin/sdcc --use-non-free -m$(FAMILY)
PK2=pk2cmd -Ppic$(DEVICE)

All: $(PRJ).hex

$(PRJ).hex: spi.c
	$(CC) -p$(DEVICE) $(PRJ).c

clean:
	rm -f *.o *.cod *.hex *.lst *.err *.asm
