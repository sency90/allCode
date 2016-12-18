.SUFFIXES:

CXX=g++
CPPFLAGS= -Wall -O2

BIN=$(wordlist 2,$(words $(MAKECMDGOALS)),$(MAKECMDGOALS))

cc:
	$(CXX) $(BIN).cpp -o ./$(BIN) $(CPPFLAGS)

c11:
	$(CXX) $(BIN).cc -o ./$(BIN) $(CPPFLAGS) -std=c++11

c14:
	$(CXX) $(BIN).cxx -o ./$(BIN) $(CPPFLAGS) -std=c++14
