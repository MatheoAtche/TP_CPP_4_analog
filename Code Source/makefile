ECHO = echo
EDL = g++ 
EXE = main
COMP = g++ -c 
P =  

DEC = Catalogue.h TrajetSimple.h TrajetCompose.h ListeDeTrajets.h Trajet.h
DEF = Catalogue.cpp TrajetSimple.cpp TrajetCompose.cpp ListeDeTrajets.cpp Trajet.cpp
OBJ = Catalogue.o TrajetSimple.o TrajetCompose.o ListeDeTrajets.o Trajet.o 

LIBS = -lm 
CPPFLAGS = -ansi -pedantic -Wall -std=c++11 $(P) -g 

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
	rm main 


