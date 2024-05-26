# sfetch - suckless fetching utility

.POSIX:

include config.mk

all: sdisk

config.h:
	cp config.def.h config.h

sdisk: $(SRC)
	$(CC) $(SRC) -o sdisk
	
install: sdisk
	cp $(TARGETBIN) $(DESTDIR)

clean:
	rm -rf $(TARGETBIN)

uninstall:
	rm $(DESTDIR)/sdisk
