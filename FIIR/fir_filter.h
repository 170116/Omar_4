#ifndef FIR_FILTER_H
#define FIR_FILTER_H

#include <systemc.h>

SC_MODULE(FIRFilter) {
    sc_in<bool> clk;
    sc_in<bool> reset;
    sc_in<sc_int<16>> data_in;
    sc_out<sc_int<16>> data_out;

    // Coeficientes del filtro [1, 2, 3, 2, 1]
    const sc_int<16> coeff[5] = {1, 2, 3, 2, 1};
    
    // Registros de desplazamiento
    sc_signal<sc_int<16>> shift_reg[5];
    
    // Señales para pipeline
    sc_signal<sc_int<16>> mult_stage[5];
    sc_signal<sc_int<16>> sum_stage[3];

    void shift_reg_process();
    void multiplication_stage();
    void addition_stage();
    void output_stage();

    SC_CTOR(FIRFilter) {
        SC_METHOD(shift_reg_process);
        sensitive << clk.pos();
        
        SC_METHOD(multiplication_stage);
        sensitive << shift_reg[0] << shift_reg[1] << shift_reg[2] 
                  << shift_reg[3] << shift_reg[4];
        
        SC_METHOD(addition_stage);
        sensitive << mult_stage[0] << mult_stage[1] << mult_stage[2] 
                  << mult_stage[3] << mult_stage[4];
        
        SC_METHOD(output_stage);
        sensitive << sum_stage[2];
    }
};

#endif