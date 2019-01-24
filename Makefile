ECHO = echo
EDL = g++ 
EXE = Analog
COMP = g++ -c 

DEC = LectureLog.h
DEF = LectureLog.cpp 
OBJ = LectureLog.o 

LIBS = -lm 
CPPFLAGS = -ansi -pedantic -Wall -std=c++11 $(P) -g -DMAP

$(EXE) : $(OBJ) $(EXE).o
	@$(ECHO) "Edl de <main>"
	$(EDL) -o $(EXE) $(EXE).o $(OBJ) 

$(EXE).o : $(EXE).cpp
	@$(ECHO) "compil de <$@>"
	$(COMP) -o $@ $(CPPFLAGS) $^ 

%.o : %.cpp
	@$(ECHO) "compil de <$@>"
	$(COMP) -o $@ $(CPPFLAGS) $^ 

clean : 
	@$(ECHO) "Suppression des objets et de l'executable"
	rm *.o
	rm $(EXE) 
