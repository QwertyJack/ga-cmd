GA=google-authenticator/libpam
GA_OBJS=hmac.o sha1.o base32.o google_authenticator_gen.o
OBJS=keyhide.o verf.o cfgfile.o

.SUFFIXES:

.SUFFIXES: .o .c .h

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

ga-cmd.o: ga-cmd.c bin/prockey
	gcc -c -std=gnu99 $<

bin/prockey: $(GA_OBJS) $(OBJS) prockey.o
	@mkdir -p $(@D)
	gcc -o $@ $^

bin/ga-cmd: $(GA_OBJS) $(OBJS) ga-cmd.o
	@mkdir -p $(@D)
	gcc -o $@ $^
	strip $@

prockey: bin/prockey
	@true

ga-cmd: bin/ga-cmd
	@true

all: prockey ga-cmd

clean:
	rm -rf bin
	rm *.o
