#Este makefile sirve para compilar un menu dinamico
#variables

OBJS := $(shell dir /b/s *.cpp)
BINARY = Calculadora.exe
CXX = clang

#objetivos
all: Ejecutable

Ejecutable: $(OBJS)
	$(CXX) -o $(BINARY) $?


%.o: %.c 
	$(CXX) -c $< -o $? 
