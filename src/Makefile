IDIR =../include
CC=gcc
CFLAGS=-I$(IDIR)

LDIR =../lib
ODIR=obj

LIBS = -lcurl

_DEPS = 
DEPS = $(addprefix $(IDIR)/,$(_DEPS))

_OBJ = main.o http_checker.o
OBJ = $(addprefix $(ODIR)/,$(_OBJ))


$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

healthchk: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

all: $(OBJ) 
	$(CC) -o healthchk $^ $(CFLAGS) $(LIBS)

packages:
	sudo apt-get install libcurl4-gnutls-dev

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 

$(OBJ): | $(ODIR)

$(ODIR): FORCE
	mkdir -p $(ODIR)

FORCE: