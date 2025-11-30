#ifndef RIPPLE_ADDER_8BIT_H
#define RIPPLE_ADDER_8BIT_H

#include <systemc.h>
#include "full_adder.h"

SC_MODULE(RippleAdder8Bit) {
    sc_in<sc_uint<8>> a, b;
    sc_in<bool> carry_in;
    sc_out<sc_uint<8>> sum;
    sc_out<bool> carry_out;

    FullAdder* fa[8];
    sc_signal<bool> carry_chain[9];

    SC_CTOR(RippleAdder8Bit) {
        carry_chain[0].write(carry_in.read());
        
        for(int i = 0; i < 8; i++) {
            fa[i] = new FullAdder(("fa" + std::to_string(i)).c_str());
            fa[i]->a(a.read().bit(i));
            fa[i]->b(b.read().bit(i));
            fa[i]->carry_in(carry_chain[i]);
            fa[i]->sum(sum.write().bit(i));
            fa[i]->carry_out(carry_chain[i+1]);
        }
        carry_out.write(carry_chain[8]);
    }
};

#endif