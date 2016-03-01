.SUFFIXES:

CXX=g++
CPPFLAGS= -Wall -O2

BIN=$(wordlist 2,$(words $(MAKECMDGOALS)),$(MAKECMDGOALS))
SRC=$(BIN).cpp

cc:
	$(CXX) $(SRC) -o ./bin/$(BIN) $(CPPFLAGS)

c11:
	$(CXX) $(SRC) -o ./bin/$(BIN) $(CPPFLAGS) -std=c++11
