EXE := SetDefTool
VPATH := ../src
DATE := $(shell date +%d.%m.%Y || echo Unknown)
VER := -D__EXE__="\"$(EXE)\"" -D__AMIGADATE__="\"($(DATE))\""
OBJ := $(subst .c,.o,$(notdir $(wildcard $(VPATH)/*.c)))
CFLAGS = -Os -Wall -Wextra -Werror -Wno-pointer-sign $(VER)
LDFLAGS += -noixemul

$(EXE): $(OBJ) version.h
	$(CC) $^ -o $@ $(LDFLAGS)

.PHONY: clean
clean:
	$(RM) $(EXE) $(OBJ)
