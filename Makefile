CC = g++
CXXFLAGS = -g -pipe
PARENT = Component.cpp Component.h
dependencies = Rotor.cpp Rotor.h Reflector.h Reflector.cpp Component.cpp Component.h Plugboard.cpp Plugboard.h
full = ${dependencies} Enigma.cpp Enigma.h
all: enigma

#enigma:  ${full}  maintest.cpp
#	${CC} ${CCFLAGS} ${full}  maintest.cpp -o enigma

enigma:  enigma.o Rotor.o Plugboard.o Reflector.o Component.o Enigma.o 

enigma.o: enigma.cpp

profiling: ${full} enigma.cpp
	${CC} ${CCFLAGS} ${full}  enigma.cpp -o enigma -fprofile-arcs

#Enigma.o: Enigma.cpp Enigma.h ${dependencies}
Enigma.o: Enigma.cpp
#	${CC} Enigma.cpp Enigma.h ${dependencies}

#Rotor.o: Rotor.cpp Rotor.h ${PARENT}
Rotor.o: Rotor.cpp
#	${CC} Rotor.cpp Rotor.h ${PARENT}

#Plugboard.o: Plugboard.cpp Plugboard.h ${PARENT}
Plugboard.o: Plugboard.cpp
#	${CC} Plugboard.cpp Plugboard.h ${PARENT}

#Reflector.o: Reflector.h Reflector.cpp
Reflector.o: Reflector.cpp
#	${CC} Reflector.h Reflector.cpp

#Component.o: Component.cpp Component.h
Component.o: Component.cpp
#	${CC} Component.h Component.cpp

clean: 
	rm  *.o enigma
