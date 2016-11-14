# Project: floodFill2

CPP  = g++
RES  = 
OBJ  = flood_fill2.o $(RES)
LINKOBJ  = flood_fill2.o $(RES)
BIN  = flood_fill2
CXXFLAGS = $(CXXINCS)  
CFLAGS = $(INCS)  
RM = rm -f


all: flood_fill2

clean: 
	${RM} $(OBJ) $(BIN)

$(BIN): $(OBJ)
	$(CPP) $(LINKOBJ) -o flood_fill2 $(LIBS)

flood_fill2.o: flood_fill2.cpp
	$(CPP) -c flood_fill2.cpp -o flood_fill2 $(CXXFLAGS)