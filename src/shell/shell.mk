# RT Shell files.
SHELLSRC = $(COREDIR)/src/shell/shell.c \
           $(COREDIR)/src/shell/shell_cmd.c

SHELLINC = $(COREDIR)/src/shell

# Shared variables
ALLCSRC += $(SHELLSRC)
ALLINC  += $(SHELLINC)
