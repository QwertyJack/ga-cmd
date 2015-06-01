#!/bin/sh

if [ ! -d google-authenticator ]; then
	git clone https://code.google.com/p/google-authenticator/
else
	#(cd google-authenticator; git pull)
	echo git pull
fi

if [ -e gmd-cmd.o ]
then
	rm gmd-cmd.o
fi

make all
