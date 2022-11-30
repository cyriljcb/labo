


CLASSESM=Classes/Modele/
CLASSESV=Classes/Voiture/
CLASSESO=Classes/Option/
CLASSESP=Classes/Personne/
CLASSESE=Classes/Exception/
CLASSESVE=Classes/Vecteur/
CLASSESIT= Classes/Iterateur/
CLASSESVET=Classes/VecteurTrie/

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
OBJSVE= Classes/Vecteur/Vecteur.o
OBJSIT= Classes/Iterateur/Iterateur.o
OBJSVET= Classes/VecteurTrie/VecteurTrie.o

EXEC= $(OBJSEX) $(OBJSEOE) $(OBJSEPE)
VEC= $(OBJSVE) $(OBJSIT) $(OBJSVET)

CO=g++ -I $(CLASSESM) -I $(CLASSESV) -I $(CLASSESO) -I $(CLASSESP) -I $(CLASSESE) -I$(CLASSESVE) -I$(CLASSESIT) -I$(CLASSESVET)  #quettier dit qu'on ne peut pas mettre le -d-D DEBUG à la fin


Test6:		Test6.cpp $(CLASSESM)Modele.o $(CLASSESV)Voiture.o $(CLASSESO)Option.o $(CLASSESP)Personne.o $(CLASSESP)Intervenant.o $(CLASSESP)Client.o $(CLASSESP)Employe.o $(EXEC) $(VEC)
	# g++ Test1.cpp $(CLASSE)Modele.o -I Classes/ -o Test1
	echo "Creation de Test6"
	$(CO) $(OBJSM) $(OBJSV) $(OBJSO) $(OBJSP) $(OBJSI) $(OBJSC) $(OBJSE) $(EXEC) $(VEC) Test6.cpp -o Test6
	

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
	
$(CLASSESVE)Vecteur.o:	$(CLASSESVE)Vecteur.cpp
	echo "Creation de vecteur.o"
	$(CO) $(CLASSESVE)Vecteur.cpp -c -o $(CLASSESVE)Vecteur.o

$(OBJSIT):	$(CLASSESIT)Iterateur.cpp
	echo "Creation d'iterateur.o"
	$(CO) $(CLASSESIT)Iterateur.cpp -c -o $(OBJSIT)

$(OBJSVET):	$(CLASSESVET)VecteurTrie.cpp
	echo "Creation de vecteurTrie.o"
	$(CO) $(CLASSESVET)VecteurTrie.cpp -c -o $(OBJSVET)
	

clean:
	rm $(CLASSESM)*.o $(CLASSESV)*.o $(CLASSESO)*.o $(CLASSESP)*.o $(CLASSESE)*.o $(CLASSESVE)*.o $(CLASSESIT)*.o $(CLASSESVET)*.o