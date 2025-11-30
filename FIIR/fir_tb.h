#ifndef FIR_TB_H
#define FIR_TB_H

#include <systemc.h>
#include "fir_filter.h"

SC_MODULE(FIR_TB) {
    sc_signal<bool> clk, reset;
    sc_signal<sc_int<16>> data_in, data_out;
    FIRFilter* fir;

    void clk_gen();
    void test_process();
    void reset_process();

    SC_CTOR(FIR_TB) {
        fir = new FIRFilter("fir");
        fir->clk(clk);
        fir->reset(reset);
        fir->data_in(data_in);
        fir->data_out(data_out);

        SC_THREAD(clk_gen);
        SC_THREAD(reset_process);
        SC_THREAD(test_process);
        tracedump();
    }

    void tracedump() {
        sc_trace_file* tf = sc_create_vcd_trace_file("fir_trace");
        tf->set_time_unit(1, SC_NS);
        sc_trace(tf, clk, "clk");
        sc_trace(tf, reset, "reset");
        sc_trace(tf, data_in, "data_in");
        sc_trace(tf, data_out, "data_out");
        
        for(int i = 0; i < 5; i++) {
            sc_trace(tf, fir->shift_reg[i], 
                    ("shift_reg_" + std::to_string(i)).c_str());
        }
    }
};

#endif