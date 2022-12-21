


CLASSESM=Classes/Modele/
CLASSESV=Classes/Voiture/
CLASSESO=Classes/Option/
CLASSESP=Classes/Personne/
CLASSESE=Classes/Exception/
CLASSESVE=Classes/Vecteur/
CLASSESIT= Classes/Iterateur/
CLASSESVET=Classes/VecteurTrie/
CLASSESG = Classes/Garage/

OBJSM=Classes/Modele/Modele.o
OBJSV=Classes/Voiture/Voiture.o
OBJSO=Classes/Option/Option.o

OBJSP=Classes/Personne/Personne.o
OBJSI=Classes/Personne/Intervenant.o
OBJSE=Classes/Personne/Employe.o
OBJSC=Classes/Personne/Client.o
PERS = $(OBJSP) $(OBJSI) $(OBJSE) $(OBJSC)

OBJSEX=Classes/Exception/Exception.o
OBJSEOE=Classes/Exception/OptionException.o
OBJSEPE=Classes/Exception/PasswordException.o
EXEC= $(OBJSEX) $(OBJSEOE) $(OBJSEPE)

OBJSVE= Classes/Vecteur/Vecteur.o
OBJSIT= Classes/Iterateur/Iterateur.o
OBJSVET= Classes/VecteurTrie/VecteurTrie.o
VEC= $(OBJSVE) $(OBJSIT) 
OBJSG = Classes/Garage/Garage.o




CO=g++ -I $(CLASSESM) -I $(CLASSESV) -I $(CLASSESO) -I $(CLASSESP) -I $(CLASSESE) -I$(CLASSESVE) -I$(CLASSESIT) -I$(CLASSESVET) -I$(CLASSESG)  #quettier dit qu'on ne peut pas mettre le -d-D DEBUG à la fin


Test8a:		Test8a.cpp $(OBJSM) $(OBJSV) $(OBJSO) $(PERS) $(EXEC) $(VEC) $(OBJSG)
	# g++ Test1.cpp $(CLASSE)Modele.o -I Classes/ -o Test1
	echo "Creation de Test8a"
	$(CO) $(OBJSM) $(OBJSV) $(OBJSO) $(PERS) $(EXEC) $(VEC) $(OBJSG) Test8a.cpp -o Test8a
	

$(OBJSM):	$(CLASSESM)Modele.cpp
	echo "Creation de Modele.o"
	$(CO) $(CLASSESM)Modele.cpp -c -o $(OBJSM)

$(OBJSV):	$(CLASSESV)Voiture.cpp
	echo "Creation de Voiture.o"
	$(CO) $(CLASSESV)Voiture.cpp -c -o $(OBJSV)

$(OBJSO):	$(CLASSESO)Option.cpp
	echo "Creation de Option.o"
	$(CO) $(CLASSESO)Option.cpp -c -o $(OBJSO)

$(OBJSP):	$(CLASSESP)Personne.cpp
	echo "Creation de Personne.o"
	$(CO) $(CLASSESP)Personne.cpp -c -o $(OBJSP)

$(OBJSI):	$(CLASSESP)Intervenant.cpp
	echo "Creation de Intervenant.o"
	$(CO) $(CLASSESP)Intervenant.cpp -c -o $(OBJSI)

$(OBJSE):	$(CLASSESP)Employe.cpp
	echo "Creation de Employe.o"
	$(CO) $(CLASSESP)Employe.cpp -c -o $(OBJSE)

$(OBJSC):	$(CLASSESP)Client.cpp
	echo "Creation de Client.o"
	$(CO) $(CLASSESP)Client.cpp -c -o $(OBJSC)

$(OBJSEX):		$(CLASSESE)Exception.cpp
	echo "Creation de Exception.o"
	$(CO) $(CLASSESE)Exception.cpp -c -o $(OBJSEX)

$(OBJSOE):		$(CLASSESE)OptionException.cpp
	echo "Creation de OptionException.o"
	$(CO) $(CLASSESE)OptionException.cpp -c -o $(OBJSOE)

$(OBJSPE):		$(CLASSESE)PasswordException.cpp
	echo "Creation de PasswordException.o"
	$(CO) $(CLASSESE)PasswordException.cpp -c -o $(OBJSPE)	
	
$(OBJSVE):	$(CLASSESVE)Vecteur.cpp
	echo "Creation de vecteur.o"
	$(CO) $(CLASSESVE)Vecteur.cpp -c -o $(OBJSVE)

$(OBJSIT):	$(CLASSESIT)Iterateur.cpp
	echo "Creation d'iterateur.o"
	$(CO) $(CLASSESIT)Iterateur.cpp -c -o $(OBJSIT)

$(OBJSVET):	$(CLASSESVET)VecteurTrie.cpp
	echo "Creation de vecteurTrie.o"
	$(CO) $(CLASSESVET)VecteurTrie.cpp -c -o $(OBJSVET)

$(OBJSG):	$(CLASSESG)Garage.cpp
	echo "Creation de Garage.o"
	$(CO) $(CLASSESG)Garage.cpp -c -o $(OBJSG)
	

clean:
	rm $(CLASSESM)*.o $(CLASSESV)*.o $(CLASSESO)*.o $(CLASSESP)*.o $(CLASSESE)*.o $(CLASSESVE)*.o $(CLASSESIT)*.o $(CLASSESVET)*.o $(CLASSESG)*.o