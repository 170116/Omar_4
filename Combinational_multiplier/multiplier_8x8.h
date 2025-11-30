#ifndef MULTIPLIER_8X8_H
#define MULTIPLIER_8X8_H

#include <systemc.h>
#include "ripple_adder_8bit.h"

SC_MODULE(Multiplier8x8) {
    sc_in<sc_uint<8>> a, b;
    sc_out<sc_uint<16>> product;

    sc_signal<sc_uint<8>> pp[8];  // Productos parciales
    sc_signal<sc_uint<16>> sum[7]; // Señales intermedias

    void multiply_process();

    SC_CTOR(Multiplier8x8) {
        SC_METHOD(multiply_process);
        sensitive << a << b;
    }
};

#endif