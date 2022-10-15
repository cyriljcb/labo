.SILENT:


CLASSES=Classes/
OBJS=Classes/Modele.o
CO=g++ -D DEBUG -I $(CLASSES)         #quettier dit qu'on ne peut pas mettre le -d-D DEBUG à la fin

Test1:	Test1.cpp $(CLASSES)Modele.o
	# g++ Test1.cpp $(CLASSE)Modele.o -I Classes/ -o Test1
	$(CO) $(OBJS) Test1.cpp -o Test1
	echo "Creation de Test1"

$(CLASSES)Modele.o:	$(CLASSES)Modele.h $(CLASSES)Modele.cpp
	# g++ Classes/Modele.cpp -c -o Classes/Modele.o
	$(CO) $(CLASSES)Modele.cpp -c -o $(CLASSES)Modele.o
	echo "Creation de Modele.o"

clean:
	rm $(CLASSES)*.o