#include "full_adder.h"

void FullAdder::add_process() {
    sum.write(a.read() ^ b.read() ^ carry_in.read());
    carry_out.write((a.read() & b.read()) | 
                   (a.read() & carry_in.read()) | 
                   (b.read() & carry_in.read()));
}