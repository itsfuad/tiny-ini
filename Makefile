all:
	cc -std=c99 -Wall -Wextra -pedantic -O2 -o tiny-ini main.c

test: all
	sh tests/test.sh

clean:
	rm -f tiny-ini
