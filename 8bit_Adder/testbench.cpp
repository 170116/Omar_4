#include "testbench.h"

void Testbench::test_process() {
    // Casos de prueba especificados
    a.write(10); b.write(20); carry_in.write(0);
    wait(10, SC_NS);
    cout << "[" << sc_time_stamp() << "] " << a.read() << " + " << b.read() 
         << " = " << sum.read() << " (Cout=" << carry_out.read() << ")" << endl;

    a.write(5); b.write(10); carry_in.write(1);
    wait(10, SC_NS);
    cout << "[" << sc_time_stamp() << "] " << a.read() << " + " << b.read() 
         << " + " << carry_in.read() << " = " << sum.read() 
         << " (Cout=" << carry_out.read() << ")" << endl;

    a.write(255); b.write(1); carry_in.write(0);
    wait(10, SC_NS);
    cout << "[" << sc_time_stamp() << "] " << a.read() << " + " << b.read() 
         << " = " << sum.read() << " (Cout=" << carry_out.read() << " - OVERFLOW)" << endl;

    a.write(255); b.write(255); carry_in.write(1);
    wait(10, SC_NS);
    cout << "[" << sc_time_stamp() << "] " << a.read() << " + " << b.read() 
         << " + " << carry_in.read() << " = " << sum.read() 
         << " (Cout=" << carry_out.read() << " - OVERFLOW)" << endl;

    a.write(0xAA); b.write(0x55); carry_in.write(0);
    wait(10, SC_NS);
    cout << "[" << sc_time_stamp() << "] 0x" << hex << a.read() << " + 0x" << b.read() 
         << " = 0x" << sum.read() << " (Cout=" << carry_out.read() << ")" << endl;

    a.write(0); b.write(0); carry_in.write(0);
    wait(10, SC_NS);
    cout << "[" << sc_time_stamp() << "] " << a.read() << " + " << b.read() 
         << " = " << sum.read() << " (Cout=" << carry_out.read() << ")" << endl;

    sc_stop();
}