ifeq ($(PREFIX),)
	PREFIX := /usr/local
endif

all:
	$(CC) -static -s -o runbattd runbattd.c

clean:
	rm -f runbattd

install: all
	install -d $(DESTDIR)$(PREFIX)/bin/
	install -m 755 runbattd $(DESTDIR)$(PREFIX)/bin/
