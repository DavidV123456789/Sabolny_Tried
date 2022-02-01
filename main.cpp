#include <iostream>

//pri sablone sa jeho defnicia neda oddelit od sablony funkcie
#include "sablonyTried.h"
int main() {
    //std::cout << "Hello, World!" << std::endl;
    Obdlznik<int> ABCD(3,5);
    Obdlznik<float> EFGH(3.6);
    Obdlznik<double> WXYZ(5.647885);

    std::cout<<ABCD.getObvod()<<std::endl;
    std::cout<<EFGH.getObsah()<<std::endl;
    std::cout<<WXYZ.getObvod()<<std::endl;

    return 0;
}
