CXX=g++
CXXFLAGS= -Wall -O2

STEM=$(basename $(s))
BIN=./bin/$(STEM)
LGREEN=\033[0;92m
NC=\033[0m

default:
	@echo "$(LGREEN)$(CXX) $(s) -o $(BIN) $(CXXFLAGS) -std=c++14"
	@$(CXX) $(s) -o $(BIN) $(CXXFLAGS) -std=c++14
	@echo "$(shell pwd)/bin/$(STEM)$(NC)"
	@$(BIN)

cc:
	@echo "$(LGREEN)$(CXX) $(s) -o $(BIN) $(CXXFLAGS)$(NC)"
	@$(CXX) $(s) -o $(BIN) $(CXXFLAGS)

c11:
	@echo "$(LGREEN)$(CXX) $(s) -o $(BIN) $(CXXFLAGS) -std=c++11$(NC)"
	@$(CXX) $(s) -o $(BIN) $(CXXFLAGS) -std=c++11

c14:
	@echo "$(LGREEN)$(CXX) $(s) -o $(BIN) $(CXXFLAGS) -std=c++14$(NC)"
	@$(CXX) $(s) -o $(BIN) $(CXXFLAGS) -std=c++14

java:
	@echo "$(LGREEN)javac $(s)"
	@javac $(s)
	@echo "java $(STEM)$(NC)"
	@java $(STEM)
	@echo "$(LGREEN)rm -rf $(STEM).class$(NC)"
	@rm -rf "$(STEM).class"
