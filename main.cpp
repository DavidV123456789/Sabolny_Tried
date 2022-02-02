#include <iostream>

//pri sablone sa jeho defnicia neda oddelit od sablony funkcie
#include "sablonyTried.h"
int main() {
    //std::cout << "Hello, World!" << std::endl;
    /*
    Obdlznik<int,int,15> ABCD(3,5);
    Obdlznik<float,float> EFGH(3.6);//vyuzije implicitnu hodnotu pre treti paramter
    Obdlznik<double> WXYZ(5.647885);//vyuzije implicitnu hodnotu pre jeden typ aj treti parameter

    std::cout<<ABCD.getObvod()<<std::endl;
    std::cout<<EFGH.getObsah()<<std::endl;
    std::cout<<WXYZ.getObvod()<<std::endl;
    */
    Pole<int,3> moje;
    moje.push(1);
    moje.push(3);
    moje.push(5);
    moje.push(8);
    moje.push(10);
    moje.printfPole();
    return 0;
}
