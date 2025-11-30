#ifndef MULTIPLIER_TB_H
#define MULTIPLIER_TB_H

#include <systemc.h>
#include "multiplier_8x8.h"

SC_MODULE(Multiplier_TB) {
    sc_signal<sc_uint<8>> a, b;
    sc_signal<sc_uint<16>> product;
    Multiplier8x8* multiplier;

    void test_process();

    SC_CTOR(Multiplier_TB) {
        multiplier = new Multiplier8x8("multiplier");
        multiplier->a(a);
        multiplier->b(b);
        multiplier->product(product);

        SC_THREAD(test_process);
        tracedump();
    }

    void tracedump() {
        sc_trace_file* tf = sc_create_vcd_trace_file("multiplier_trace");
        tf->set_time_unit(1, SC_NS);
        sc_trace(tf, a, "a");
        sc_trace(tf, b, "b");
        sc_trace(tf, product, "product");
    }
};

#endif