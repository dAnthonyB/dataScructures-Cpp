# Project: mathStuff

CPP  = g++
RES  = 
OBJ  = mathStuff.o $(RES)
LINKOBJ  = mathStuff.o $(RES)
BIN  = mathStuff
CXXFLAGS = $(CXXINCS)  
CFLAGS = $(INCS)  
RM = rm -f


all: mathStuff

clean: 
	${RM} $(OBJ) $(BIN)

$(BIN): $(OBJ)
	$(CPP) $(LINKOBJ) -o mathStuff $(LIBS)

mathStuff.o: mathStuff.cpp
	$(CPP) -c mathStuff.cpp -o mathStuff $(CXXFLAGS)