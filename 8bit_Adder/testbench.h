#ifndef TESTBENCH_H
#define TESTBENCH_H

#include <systemc.h>
#include "ripple_adder_8bit.h"

SC_MODULE(Testbench) {
    sc_signal<sc_uint<8>> a, b, sum;
    sc_signal<bool> carry_in, carry_out;
    RippleAdder8Bit* adder;

    void test_process();

    SC_CTOR(Testbench) {
        adder = new RippleAdder8Bit("adder");
        adder->a(a);
        adder->b(b);
        adder->carry_in(carry_in);
        adder->sum(sum);
        adder->carry_out(carry_out);

        SC_THREAD(test_process);
        tracedump();
    }

    void tracedump() {
        sc_trace_file* tf = sc_create_vcd_trace_file("adder_trace");
        tf->set_time_unit(1, SC_NS);
        sc_trace(tf, a, "a");
        sc_trace(tf, b, "b");
        sc_trace(tf, carry_in, "carry_in");
        sc_trace(tf, sum, "sum");
        sc_trace(tf, carry_out, "carry_out");
    }
};

#endif