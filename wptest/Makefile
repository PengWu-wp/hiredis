# SPDX-License-Identifier: (GPL-2.0 OR BSD-2-Clause)

all: test

.PHONY: all clean

test: test.c
	gcc test.c -lhiredis -o test

clean:
	rm test
