# Makefile
CXX      = g++
CXXFLAGS = -std=c++14 -Wall -Wextra -O2

DLL_NAME    = libPile.dll
CLIENT_NAME = client.exe

DLL_SRC = $(wildcard Pile*.cpp)
DLL_OBJ = $(DLL_SRC:.cpp=.o)

ifeq ($(OS),Windows_NT)
    ifeq ($(findstring sh.exe,$(SHELL)),)
        RM = del /Q /F
    else
        RM = rm -f
    endif
else
    RM = rm -f
endif

.PHONY: all dll client clean

all: dll client

dll: $(DLL_NAME)

$(DLL_NAME): $(DLL_OBJ)
	$(CXX) -shared -o $@ $^

Pile%.o: Pile%.cpp Pile%.h IPile.h
	$(CXX) $(CXXFLAGS) -DBUILDING_DLL -c $< -o $@

client: $(CLIENT_NAME)

$(CLIENT_NAME): main.o $(DLL_NAME)
	$(CXX) main.o -o $@ -L. -lPile

main.o: main.cpp IPile.h PileTableau.h PileListe.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	-$(RM) *.o *.dll *.exe
