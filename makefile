final: UtPodDriver.o UTPod.o Song.o
	g++ -otest  UtPodDriver.o UTPod.o Song.o
driver: UtPodDriver.cpp UTPod.h Song.h
	g++ -c UtPodDriver.cpp
UTPod.o: UTPod.cpp UTPod.h Song.h
	g++ -c UTPod.cpp
Song.o: Song.cpp Song.h
	g++ -c Song.cpp
