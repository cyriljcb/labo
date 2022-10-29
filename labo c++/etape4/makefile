


CLASSESM=Classes/Modele/
CLASSESV=Classes/Voiture/
CLASSESO=Classes/Option/

OBJSM=Classes/Modele/Modele.o
OBJSV=Classes/Voiture/Voiture.o
OBJSO=Classes/Option/Option.o
CO=g++ -I $(CLASSESM) -I $(CLASSESV) -I $(CLASSESO)    #quettier dit qu'on ne peut pas mettre le -d-D DEBUG à la fin


Test4:		Test4.cpp $(CLASSESM)Modele.o $(CLASSESV)Voiture.o $(CLASSESO)Option.o
	# g++ Test1.cpp $(CLASSE)Modele.o -I Classes/ -o Test1
	echo "Creation de Test4"
	$(CO) $(OBJSM) $(OBJSV) $(OBJSO) Test3.cpp -o Test3
	

$(CLASSESM)Modele.o:	$(CLASSESM)Modele.cpp
	echo "Creation de Modele.o"
	$(CO) $(CLASSESM)Modele.cpp -c -o $(CLASSESM)Modele.o


$(CLASSESV)Voiture.o:	$(CLASSESV)Voiture.cpp
	echo "Creation de Voiture.o"
	$(CO) $(CLASSESV)Voiture.cpp -c -o $(CLASSESV)Voiture.o


$(CLASSESO)Option.o:	$(CLASSESO)Option.cpp
	echo "Creation de Option.o"
	$(CO) $(CLASSESO)Option.cpp -c -o $(CLASSESO)Option.o
	

clean:
	rm $(CLASSESM)*.o $(CLASSESV)*.o $(CLASSESO)*.o