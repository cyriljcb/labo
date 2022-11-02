


CLASSESM=Classes/Modele/
CLASSESV=Classes/Voiture/
CLASSESO=Classes/Option/
CLASSESP=Classes/Personne/

OBJSM=Classes/Modele/Modele.o
OBJSV=Classes/Voiture/Voiture.o
OBJSO=Classes/Option/Option.o
OBJSP=Classes/Personne/Personne.o
OBJSI=Classes/Personne/Intervenant.o
OBJSE=Classes/Personne/Employe.o
OBJSC=Classes/Personne/Client.o

CO=g++ -I $(CLASSESM) -I $(CLASSESV) -I $(CLASSESO) -I $(CLASSESP)    #quettier dit qu'on ne peut pas mettre le -d-D DEBUG à la fin


Test4:		Test4.cpp $(CLASSESM)Modele.o $(CLASSESV)Voiture.o $(CLASSESO)Option.o $(CLASSESP)Personne.o $(CLASSESP)Intervenant.o $(CLASSESP)Client.o $(CLASSESP)Employe.o
	# g++ Test1.cpp $(CLASSE)Modele.o -I Classes/ -o Test1
	echo "Creation de Test4"
	$(CO) $(OBJSM) $(OBJSV) $(OBJSO) $(OBJSP) $(OBJSI) $(OBJSC) $(OBJSE) Test4.cpp -o Test4
	

$(CLASSESM)Modele.o:	$(CLASSESM)Modele.cpp
	echo "Creation de Modele.o"
	$(CO) $(CLASSESM)Modele.cpp -c -o $(CLASSESM)Modele.o


$(CLASSESV)Voiture.o:	$(CLASSESV)Voiture.cpp
	echo "Creation de Voiture.o"
	$(CO) $(CLASSESV)Voiture.cpp -c -o $(CLASSESV)Voiture.o


$(CLASSESO)Option.o:	$(CLASSESO)Option.cpp
	echo "Creation de Option.o"
	$(CO) $(CLASSESO)Option.cpp -c -o $(CLASSESO)Option.o

$(CLASSESP)Personne.o:	$(CLASSESP)Personne.cpp
	echo "Creation de Personne.o"
	$(CO) $(CLASSESP)Personne.cpp -c -o $(CLASSESP)Personne.o

$(CLASSESP)Intervenant.o:	$(CLASSESP)Intervenant.cpp
	echo "Creation de Intervenant.o"
	$(CO) $(CLASSESP)Intervenant.cpp -c -o $(CLASSESP)Intervenant.o

$(CLASSESP)Employe.o:	$(CLASSESP)Employe.cpp
	echo "Creation de Employe.o"
	$(CO) $(CLASSESP)Employe.cpp -c -o $(CLASSESP)Employe.o

$(CLASSESP)Client.o:	$(CLASSESP)Client.cpp
	echo "Creation de Client.o"
	$(CO) $(CLASSESP)Client.cpp -c -o $(CLASSESP)Client.o
	

clean:
	rm $(CLASSESM)*.o $(CLASSESV)*.o $(CLASSESO)*.o $(CLASSESP)*.o