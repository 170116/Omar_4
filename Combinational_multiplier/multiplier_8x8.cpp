#include "multiplier_8x8.h"

void Multiplier8x8::multiply_process() {
    // Generar productos parciales
    for(int i = 0; i < 8; i++) {
        pp[i] = a.read() & (b.read()[i] ? 0xFF : 0x00);
    }

    // Sumar productos parciales en árbol
    sum[0] = pp[0] + (pp[1] << 1);
    sum[1] = pp[2] + (pp[3] << 3);
    sum[2] = pp[4] + (pp[5] << 5);
    sum[3] = pp[6] + (pp[7] << 7);
    
    sum[4] = sum[0] + sum[1];
    sum[5] = sum[2] + sum[3];
    
    product.write(sum[4] + sum[5]);
}