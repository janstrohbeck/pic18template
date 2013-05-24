# Author: Jan Strohbeck
# IMPORTANT: Makefile does not work if there are no
# header files!
# FIX: $ touch inc/dummy.h

# Executable name
PROJECT=test

# Commands
CC = /opt/microchip/xc8/v1.12/bin/xc8 
RM = rm -f
MKDIR = mkdir -p
RMDIR = rm -rf
MV = mv -f

# Input-/Header-/Output-Directories
SRC_DIR = ./src
INC_DIR = ./src/inc
OUT_DIR = /tmp/pic18-$(PROJECT)-build
OBJ_DIR_NAME = obj

# Compiler Settings
PIC = 18F4580
CFLAGS = -g

#optimization parameters (default = full optimization)
OPT_ENABLE_ALL =
OPT_DEBUG = -Ou- -Ot- -Ob- -Op- -Or- -Od- -Opa-
OPT = $(OPT_ENABLE_ALL)

# Linker options
LDFLAGS = 

# You shouldn't need to change anything from here on
PICFLAG = --chip=$(PIC)
DIR_GUARD = @$(MKDIR) $(@D)
DEFINES = 

#make a list of object files that match all C files
SOURCES = $(wildcard $(SRC_DIR)/*.c)
OBJECTS = $(patsubst $(SRC_DIR)/%.c, $(OUT_DIR)/$(OBJ_DIR_NAME)/%.p1, $(SOURCES))

# default: build the hex file
all: $(OUT_DIR)/$(PROJECT).hex

.PHONY: clean
.PHONY: doc

# generate documentation files
doc: 
	@$(MKDIR) /tmp/newdoc
	@$(RMDIR) $(OUT_DIR)/doc
	doxygen Doxyfile
	@$(MV) /tmp/newdoc $(OUT_DIR)/doc

# Recompile a file if it's c-file changes,
# OR recompile everything if ANY header file changes
$(OUT_DIR)/$(OBJ_DIR_NAME)/%.p1 : $(SRC_DIR)/%.c $(INC_DIR)/*.h
	$(DIR_GUARD)
	$(CC) $(PICFLAG) -I$(INC_DIR) --pass1 -C $< $(DEFINES) -O$@ --outdir=$(OUT_DIR)/$(OBJ_DIR_NAME)/ $(CFLAGS) $(OPT)

# re-link if any object file changed
$(OUT_DIR)/$(PROJECT).hex:  $(OBJECTS)
	$(DIR_GUARD)
	$(CC) $(OBJECTS) -O$@ $(DEFINES) $(PICFLAG) $(OPT)
	
# delete all built files so you can start from scratch. 
clean:
	$(RMDIR) $(OUT_DIR)/$(OBJ_DIR_NAME)
	$(RM) $(OUT_DIR)/$(PROJECT).hex
	$(RMDIR) $(OUT_DIR)/doc
