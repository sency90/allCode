# Makefile — make foo.cpp / make debug foo.cpp
MAKEFLAGS += -rR                 # 내장 규칙/변수 끔

CXX      := g++
STD      := -std=c++11
BIN_DIR  := bin

# 'debug'가 목표에 있으면 디버그 플래그, 아니면 릴리즈 플래그
ifneq (,$(filter debug,$(MAKECMDGOALS)))
  CXXFLAGS := -g $(STD)
else
  CXXFLAGS := -O2 $(STD)
endif

.PHONY: debug clean FORCE
# debug: 빈 레시피(quiet) → "Nothing to be done" 안 뜸
debug: ; @:

FORCE:

# *.cpp는 항상 재컴파일 → bin/<이름> 생성
%.cpp: FORCE | $(BIN_DIR)
	$(CXX) -o $(BIN_DIR)/$(basename $@) $@ $(CXXFLAGS)

$(BIN_DIR):
	mkdir -p $@

clean:
	rm -rf $(BIN_DIR)
