


CLASSESM=Classes/Modele/
CLASSESV=Classes/Voiture/
CLASSESO=Classes/Option/
CLASSESP=Classes/Personne/
CLASSESE=Classes/Exception/

OBJSM=Classes/Modele/Modele.o
OBJSV=Classes/Voiture/Voiture.o
OBJSO=Classes/Option/Option.o
OBJSP=Classes/Personne/Personne.o
OBJSI=Classes/Personne/Intervenant.o
OBJSE=Classes/Personne/Employe.o
OBJSC=Classes/Personne/Client.o
OBJSEX=Classes/Exception/Exception.o
OBJSEOE=Classes/Exception/OptionException.o
OBJSEPE=Classes/Exception/PasswordException.o

EXEC= $(OBJSEX) $(OBJSEOE) $(OBJSEPE)

CO=g++ -D DEBUG -I $(CLASSESM) -I $(CLASSESV) -I $(CLASSESO) -I $(CLASSESP) -I $(CLASSESE)   #quettier dit qu'on ne peut pas mettre le -d-D DEBUG à la fin


Test5:		Test5.cpp $(CLASSESM)Modele.o $(CLASSESV)Voiture.o $(CLASSESO)Option.o $(CLASSESP)Personne.o $(CLASSESP)Intervenant.o $(CLASSESP)Client.o $(CLASSESP)Employe.o $(EXEC)
	# g++ Test1.cpp $(CLASSE)Modele.o -I Classes/ -o Test1
	echo "Creation de Test5"
	$(CO) $(OBJSM) $(OBJSV) $(OBJSO) $(OBJSP) $(OBJSI) $(OBJSC) $(OBJSE) $(EXEC) Test5.cpp -o Test5
	

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

$(CLASSESE)Exception.o:		$(CLASSESE)Exception.cpp
	echo "Creation de Exception.o"
	$(CO) $(CLASSESE)Exception.cpp -c -o $(CLASSESE)Exception.o

$(CLASSESE)OptionException.o:		$(CLASSESE)OptionException.cpp
	echo "Creation de OptionException.o"
	$(CO) $(CLASSESE)OptionException.cpp -c -o $(CLASSESE)OptionException.o

$(CLASSESE)PasswordException.o:		$(CLASSESE)PasswordException.cpp
	echo "Creation de PasswordException.o"
	$(CO) $(CLASSESE)PasswordException.cpp -c -o $(CLASSESE)PasswordException.o		
	

clean:
	rm $(CLASSESM)*.o $(CLASSESV)*.o $(CLASSESO)*.o $(CLASSESP)*.o $(CLASSESE)*.o