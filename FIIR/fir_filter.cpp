#include "fir_filter.h"

void FIRFilter::shift_reg_process() {
    if (reset.read()) {
        for (int i = 0; i < 5; i++) {
            shift_reg[i].write(0);
        }
    } else {
        // Desplazar registros
        for (int i = 4; i > 0; i--) {
            shift_reg[i].write(shift_reg[i-1].read());
        }
        shift_reg[0].write(data_in.read());
    }
}

void FIRFilter::multiplication_stage() {
    // Etapa de multiplicación
    for (int i = 0; i < 5; i++) {
        mult_stage[i].write(shift_reg[i].read() * coeff[i]);
    }
}

void FIRFilter::addition_stage() {
    // Etapa de suma en árbol (pipeline)
    sum_stage[0].write(mult_stage[0].read() + mult_stage[1].read());
    sum_stage[1].write(mult_stage[2].read() + mult_stage[3].read());
    sum_stage[2].write(sum_stage[0].read() + sum_stage[1].read() + mult_stage[4].read());
}

void FIRFilter::output_stage() {
    data_out.write(sum_stage[2].read());
}