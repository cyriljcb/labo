


CLASSESM=Classes/Modele/
CLASSESV=Classes/Voiture/
CLASSESO=Classes/Option/

OBJSM=Classes/Modele/Modele.o
OBJSV=Classes/Voiture/Voiture.o
OBJSO=Classes/Option/Option.o
CO=g++ -D DEBUG -I $(CLASSESM) -I $(CLASSESV) -I $(CLASSESO)    #quettier dit qu'on ne peut pas mettre le -d-D DEBUG à la fin


all:	Test2a Test2b Test2c


Test2a:		Test2a.cpp $(CLASSESM)Modele.o $(CLASSESV)Voiture.o $(CLASSESO)Option.o
	# g++ Test1.cpp $(CLASSE)Modele.o -I Classes/ -o Test1
	echo "Creation de Test2a"
	$(CO) $(OBJSM) $(OBJSV) $(OBJSO) Test2a.cpp -o Test2a


Test2b:	Test2b.cpp $(CLASSESM)Modele.o $(CLASSESV)Voiture.o $(CLASSESO)Option.o
	# g++ Test1.cpp $(CLASSE)Modele.o -I Classes/ -o Test1
	echo "Creation de Test2b"
	$(CO) $(OBJSM) $(OBJSV) $(OBJSO) Test2b.cpp -o Test2b


Test2c:		Test2c.cpp $(CLASSESM)Modele.o $(CLASSESV)Voiture.o $(CLASSESO)Option.o
	# g++ Test1.cpp $(CLASSE)Modele.o -I Classes/ -o Test1
	echo "Creation de Test2c"
	$(CO) $(OBJSM) $(OBJSV) $(OBJSO) Test2c.cpp -o Test2c


	

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