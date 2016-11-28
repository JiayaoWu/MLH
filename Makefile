C++ = g++
CFLAGS = -c -g

all: MLH Center

MLH: 		finalProject.o ML_hash.o MLH.h random_op.o
		$(C++) -o PartI finalProject.o ML_hash.o MLH.h random_op.o

Center:		ServiceCenterDriver.o Vehicle.o List.o Task.o Motorcycle.o Hybrid.o Bus.o Car.o MLH.h ML_hash.o
		$(C++) -o PartII ServiceCenterDriver.o Vehicle.o List.o Task.o Motorcycle.o Hybrid.o Bus.o Car.o MLH.h ML_hash.o

clean:
		rm -f *.o *.exe 

%.o:	%.cpp
		$(C++) $(CFLAGS) $*.cpp

