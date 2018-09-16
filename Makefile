OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

program.exe: program.o Almacen.o Sala.o Catalogo.o
	g++ -o program.exe *.o 

Almacen.o: Almacen.cc Almacen.hh BinTree.hh
	g++ -c Almacen.cc $(OPCIONS) 

Sala.o: Sala.cc Sala.hh
	g++ -c Sala.cc $(OPCIONS) 

Catalogo.o: Catalogo.cc Catalogo.hh
	g++ -c Catalogo.cc $(OPCIONS) 

program.o: program.cc Sala.hh Catalogo.hh Almacen.hh
	g++ -c program.cc $(OPCIONS)

practica.tar: Makefile program.cc Almacen.cc Almacen.hh Sala.cc Sala.hh Catalogo.cc Catalogo.hh html.zip jp_gerard.palomares.zip
	tar cvf practica.tar Makefile program.cc Almacen.cc Almacen.hh Sala.cc Sala.hh Catalogo.cc Catalogo.hh html.zip jp_gerard.palomares.zip

clean:
	rm *.o
	rm *.exe
