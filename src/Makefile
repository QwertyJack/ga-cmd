all: ga-cmd

GA=../google-authenticator/libpam
GA_OBJS=hmac.o sha1.o base32.o google_authenticator_gen.o
CFLAGS=-std=gnu99 -DTESTING

%.o: $(GA)/%.c
	$(CC) -c -o $@ $< $(CFLAGS)

ga-cmd: ga-cmd.c cfgfile.c $(GA_OBJS)
	$(CC) -o $@ $^
	strip $@

clean:
	rm *.o
	rm ga-cmd
