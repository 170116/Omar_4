#include "multiplier_tb.h"

void Multiplier_TB::test_process() {
    // Casos de prueba exhaustivos
    struct TestCase {
        sc_uint<8> a, b;
    } test_cases[] = {
        {0, 0}, {1, 1}, {2, 2}, {10, 20}, {255, 1}, 
        {255, 255}, {0xAA, 0x55}, {127, 127}
    };

    for(int i = 0; i < 8; i++) {
        a.write(test_cases[i].a);
        b.write(test_cases[i].b);
        wait(10, SC_NS);
        cout << "[" << sc_time_stamp() << "] " << a.read() << " * " << b.read() 
             << " = " << product.read() << endl;
    }

    sc_stop();
}