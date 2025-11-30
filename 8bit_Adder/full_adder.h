#ifndef FULL_ADDER_H
#define FULL_ADDER_H

#include <systemc.h>

SC_MODULE(FullAdder) {
    sc_in<bool> a, b, carry_in;
    sc_out<bool> sum, carry_out;

    void add_process();

    SC_CTOR(FullAdder) {
        SC_METHOD(add_process);
        sensitive << a << b << carry_in;
    }
};

#endif