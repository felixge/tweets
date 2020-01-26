SOURCES := $(shell find . -name '*.txt' -or -name '*.c')
PNGS := $(SOURCES:.txt=.png)
PNGS := $(PNGS:.c=.png)

.PHONY: all
all: $(PNGS)

.SECONDEXPANSION:
%.png: $$(wildcard %.txt) $$(wildcard %.c)
	carbon-now --config carbon-now.json -t $(basename $@) $<
