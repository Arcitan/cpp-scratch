CXXFLAGS += -std=c++17 
CXXFLAGS += -O3
CXXFLAGS += -I include/ 
CXXFLAGS += -Wall
CXXFLAGS += -Werror
CXXFLAGS += -Wempty-body
CXXFLAGS += -Wno-builtin-macro-redefined
CXXFLAGS += -Wno-strict-aliasing
CXXFLAGS += -Wno-int-in-bool-context
CXXFLAGS += -Wno-enum-compare
CXXFLAGS += -Wno-unknown-pragmas
CXXFLAGS += -Wno-unused-parameter
CXXFLAGS += -Wno-ignored-qualifiers
CXXFLAGS += -Winit-self
CXXFLAGS += -Wvla
CXXFLAGS += -Wimplicit-fallthrough
CXXFLAGS += -fstack-protector
CXXFLAGS += -Wextra
CXXFLAGS += -Wshift-overflow
CXXFLAGS += -Wdouble-promotion

LDFLAGS += -lboost_system

.PHONY: all clean 

SOURCES = $(wildcard src/*.cpp)
TARGETS = $(patsubst src/%.cpp, bin/%, $(SOURCES))

all: $(TARGETS)

bin/% : src/%.cpp
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $< 

clean: 
	$(RM) bin/*

