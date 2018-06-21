CXX=g++

BOOST_LOCATION=/usr/include/boost

BUILD_DIR=.

CXXFLAGS+=-O3

CXXFLAGS+=-std=c++0x
CXXFLAGS+=-mfpmath=sse
CXXFLAGS+=-mmmx
CXXFLAGS+=-lm
CXXFLAGS+=-fomit-frame-pointer
CXXFLAGS+=-fno-schedule-insns2
CXXFLAGS+=-fexceptions
CXXFLAGS+=-funroll-loops
CXXFLAGS+=-march=native
CXXFLAGS+=-m64
CXXFLAGS+=-I$(BOOST_LOCATION)


SRCS=$(shell ls *.cpp)
OBJS=$(SRCS:.cpp=.o)


PROGRAM=filter_enju

all : $(BUILD_DIR) $(patsubst %,$(BUILD_DIR)/%,$(PROGRAM))

$(BUILD_DIR)/%.o : %.cpp
	$(CXX) -c $(CXXFLAGS) -o $@ $<

$(BUILD_DIR)/$(PROGRAM) : $(patsubst %,$(BUILD_DIR)/%,$(OBJS))
	$(CXX) $(CXXFLAGS) $(CXXLIBS) -o $@ $^

clean:
	rm -f $(BUILD_DIR)/*.o $(PROGRAM) ?*~
