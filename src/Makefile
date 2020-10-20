IDIR =../include
CC=g++
CFLAGS=-I$(IDIR)

LDIR =../lib
ODIR=obj

LIBS =

_DEPS = 
DEPS = $(addprefix $(IDIR)/,$(_DEPS))

_OBJ = main.o
OBJ = $(addprefix $(ODIR)/,$(_OBJ))


$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

healthchk: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

all: $(OBJ)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 

$(OBJ): | $(ODIR)

$(ODIR): FORCE
	mkdir -p $(ODIR)

FORCE: