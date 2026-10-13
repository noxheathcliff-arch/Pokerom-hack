# Build gbaplay against a static libmgba installed in $(MGBA_PREFIX).
# The binary is written OUTSIDE the repo, to $(BINDIR) (default /opt/mgba-tools/bin).
# See docs/hack/QA_TOOLING.md and tools/qa/install_mgba_tools.sh.
MGBA_PREFIX ?= /opt/mgba-tools
BINDIR ?= $(MGBA_PREFIX)/bin
CC ?= gcc
CFLAGS ?= -O2 -g -Wall -Wextra -Wno-unused-parameter
# Defines used to build libmgba (struct layouts depend on them!), saved by install_mgba_tools.sh
MGBA_DEFS ?= $(shell cat $(MGBA_PREFIX)/lib/mgba-cflags.txt 2>/dev/null)
CPPFLAGS += -I$(MGBA_PREFIX)/include $(MGBA_DEFS) -D_GNU_SOURCE
LDLIBS += $(MGBA_PREFIX)/lib/libmgba.a -lpng -lz -lelf -lzstd -lm -lpthread -ldl

all: $(BINDIR)/gbaplay

$(BINDIR)/gbaplay: gbaplay.c
	mkdir -p $(BINDIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) -o $@ $< $(LDLIBS)

clean:
	rm -f $(BINDIR)/gbaplay

.PHONY: all clean
