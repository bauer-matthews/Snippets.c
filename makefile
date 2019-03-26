# ---------------------------------------------------------------------------
# Filename:    makefile
# Platform:    GNU Make for C and Objective-C on Mac OS X
# Application: Sweep Utility
# Author:      C. Fahlbusch
# Created:     08-Feb-2019
#
# History:     Description:
# -------      -----------
#
# ---------------------------------------------------------------------------

# ---------------------------------------------------------------------------
# Definitions
# ---------------------------------------------------------------------------

# Suffix definitions
.SUFFIXES:									# Delete the default suffixes
.SUFFIXES: .c .m .o .a			# Define our own suffix list

# Directory layout
HDRDIR=./hdr/
SRCDIR=./src/
OBJDIR=./

vpath %.h $(HDRDIR)
vpath %.c $(SRCDIR)
vpath %.o $(OBJDIR)
vpath %.a $(OBJDIR)

# Build definitions
CC=gcc
CCFLAGS=-Wall -std=gnu11 -g -I$(HDRDIR)
DEFINES=
LDFLAGS=

# Project definitions
EXEC=snippet
FILES=linkedlist.c
OBJFILES=$(addprefix $(OBJDIR),$(FILES:.c=.o))
LIBS=

# ---------------------------------------------------------------------------
# Targets
# ---------------------------------------------------------------------------

.PHONY: build rebuild clean

build: $(EXEC)

rebuild: clean build

clean:
	rm -f $(EXEC) $(OBJFILES)

# ---------------------------------------------------------------------------
# Dependencies
# ---------------------------------------------------------------------------

linkedlist.o: linkedlist.c

# ---------------------------------------------------------------------------
# Build rules
#
# $@ is the name of the file to be made.
# $? is the names of the changed dependents.
# $< the name of the related file that caused the action.
# $* the prefix shared by target and dependent files.
# ---------------------------------------------------------------------------

$(EXEC): $(OBJFILES)
	$(CC) $(LDFLAGS) -o $@ $(OBJFILES) $(LIBS)

# TODO: Archive a C object module
.c.a:
	$(CC) $(CCFLAGS) $(DEFINES) -c $< -o $@
	$(AR) r $@ $*.o
	$(RM) $*.o

# Compile C files
$(OBJDIR)%.o : %.c
	$(CC) $(CCFLAGS) $(DEFINES) -c $< -o $@

# Compile Objective-C files
$(OBJDIR)%.o : %.m
	$(CC) $(CCFLAGS) $(DEFINES) -c $< -o $@
