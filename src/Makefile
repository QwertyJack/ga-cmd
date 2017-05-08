all: ga-cmd

GA=google-authenticator/libpam
GA_OBJS=hmac.o sha1.o base32.o google_authenticator_gen.o

.c.o :
	gcc -c $< 

hmac.o: $(GA)/hmac.c
	gcc -c -std=gnu99 $<

sha1.o: $(GA)/sha1.c
	gcc -c -std=gnu99 $<

base32.o: $(GA)/base32.c
	gcc -c -std=gnu99 $<

google_authenticator_gen.o: $(GA)/google_authenticator_gen.c
	gcc -c -std=gnu99 -DTESTING $<

ga-cmd: ga-cmd.c cfgfile.c $(GA_OBJS)
	$(CC) -o $@ $^
	strip $@

clean:
	rm ga-cmd
	rm *.o
