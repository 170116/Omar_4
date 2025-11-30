CXX = g++
SYSTEMC = /usr/local/systemc-2.3.3
TARGET_ARCH = linux64

CFLAGS = -I$(SYSTEMC)/include -L$(SYSTEMC)/lib-$(TARGET_ARCH) -lsystemc -lm

SOURCES_ADDER = main.cpp full_adder.cpp ripple_adder_8bit.cpp testbench.cpp
SOURCES_MULT = main.cpp multiplier_8x8.cpp multiplier_tb.cpp
SOURCES_FIR = main.cpp fir_filter.cpp fir_tb.cpp

all: adder multiplier fir

adder: $(SOURCES_ADDER)
	$(CXX) -o $@ $^ $(CFLAGS) -DACTIVITY=1

multiplier: $(SOURCES_MULT)
	$(CXX) -o $@ $^ $(CFLAGS) -DACTIVITY=2

fir: $(SOURCES_FIR)
	$(CXX) -o $@ $^ $(CFLAGS) -DACTIVITY=3

clean:
	rm -f adder multiplier fir *.vcd

.PHONY: all clean