.SUFFIXES:

CXX=g++
CPPFLAGS= -Wall -O2

SRC=$(BIN).cpp
BIN=$(wordlist 2,$(words $(MAKECMDGOALS)),$(MAKECMDGOALS))

cc:
	$(CXX) $(SRC) -o ./bin/$(BIN) $(CPPFLAGS)

ccd:
	$(CXX) $(SRC) -o ./bin/$(BIN) $(CPPFLAGS) -DPLZRUN

c11:
	$(CXX) $(BIN).cc -o ./bin/$(BIN) $(CPPFLAGS) -std=c++11

c11d:
	$(CXX) $(BIN).cc -o ./bin/$(BIN) $(CPPFLAGS) -std=c++11 -DPLZRUN

c14:
	$(CXX) $(BIN).cxx -o ./bin/$(BIN) $(CPPFLAGS) -std=c++14

c14d:
	$(CXX) $(BIN).cxx -o ./bin/$(BIN) $(CPPFLAGS) -std=c++14 -DPLZRUN
