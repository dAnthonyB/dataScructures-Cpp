# Project: list_3358_arrays

CPP  = g++
RES  = 
OBJ  = list_test.o list_3358_arrays.o $(RES)
LINKOBJ  = list_test.o list_3358_arrays.o $(RES)
BIN  = list_test
CXXFLAGS = $(CXXINCS)  
CFLAGS = $(INCS)  
RM = rm -f


all: list_test 

clean: 
	${RM} $(OBJ) $(BIN)

$(BIN): $(OBJ)
	$(CPP) $(LINKOBJ) -o list_test $(LIBS)

list_3358_arrays.o: list_3358_arrays.cpp
	$(CPP) -c list_3358_arrays.cpp -o list_3358_arrays.o $(CXXFLAGS)