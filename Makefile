.PHONY: all debug check clean

OCT := render_text.oct

MKOCTFILE  ?= mkoctfile
MKOCTFLAGS ?= -Wall -v

all: $(OCT)

debug : MKOCTFLAGS += -g
debug : all

%.oct: %.cc
	$(MKOCTFILE) $(MKOCTFLAGS) -I/usr/include/freetype2 $^ -o $@

check: $(OCT)
	octave -q -f --eval 'render_text ("hello world", "none");'

clean:
	rm -f *.oct *.o
	rm -f octave-core octave-workspace


