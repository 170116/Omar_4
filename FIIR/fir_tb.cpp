#include "fir_tb.h"
#include <cmath>

void FIR_TB::clk_gen() {
    while(true) {
        clk.write(0);
        wait(5, SC_NS);
        clk.write(1);
        wait(5, SC_NS);
    }
}

void FIR_TB::reset_process() {
    reset.write(1);
    wait(20, SC_NS);
    reset.write(0);
}

void FIR_TB::test_process() {
    wait(25, SC_NS); // Esperar fin del reset
    
    cout << "=== PRUEBA CON ESCALÓN ===" << endl;
    
    // Prueba con escalón (como en las especificaciones)
    data_in.write(50);
    for(int i = 0; i < 10; i++) {
        wait(10, SC_NS);
        cout << "t=" << sc_time_stamp() << " | Entrada: " << data_in.read() 
             << " | Salida: " << data_out.read() << endl;
    }

    cout << "\n=== PRUEBA CON SEÑAL SENOIDAL ===" << endl;
    
    // Prueba con señal senoidal (valores del ejemplo)
    sc_int<16> sine_values[] = {59, 95, 100, 59, 0, -59, -95, -100, -59, 0};
    
    for(int i = 0; i < 10; i++) {
        data_in.write(sine_values[i]);
        wait(10, SC_NS);
        cout << "t=" << sc_time_stamp() << " | Entrada: " << data_in.read() 
             << " | Salida: " << data_out.read() << endl;
    }

    sc_stop();
}