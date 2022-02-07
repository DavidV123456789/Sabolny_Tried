//
// Created by map on 1. 2. 2022.
//
#include<iostream>
#include<cstdlib>


#ifndef SABOLNY_TRIED_SABLONYTRIED_H
#define SABOLNY_TRIED_SABLONYTRIED_H

template<typename Any, typename Other=int, int pocet=10>//dávame najavo že budeme vytvárať generickú triedu
class Obdlznik{
private:
    Any a;
    Any b;
public:
    Obdlznik():a(1),b(1){};
    explicit Obdlznik(Any x):a(x),b(x){};
    Obdlznik(Any x, Any y):a(x),b(y){};
    Any getObvod() const;
    Any getObsah() const;
    auto getObvod1()-> decltype(a+b) const;//prakticky alternativny zapis ku: Any getObvod() const;//
};

template<typename Any, typename Other, int pocet>
Any Obdlznik<Any,Other,pocet>::getObvod() const {
    return 2*a+2*b;
}

template<typename Any, typename Other, int pocet>
Any Obdlznik<Any,Other,pocet>::getObsah() const {
    return a*b;
}

template<typename Any, typename Other, int pocet>
auto Obdlznik<Any,Other,pocet>::getObvod1() -> decltype(a+b) const {
    return (2*a+2*b);
}

template<typename  Any=int, unsigned  pocet=10>
class Pole;

template<typename T>
int comp(const void * a, const void  *b);
/*
template<typename Any,unsigned  int pocet>
std::ostream & operator;*/

template<typename Any, unsigned pocet>
class Pole
{
private:
    Any *array;
    unsigned  maxIndex;
    unsigned  curIndex;
    unsigned  numRealoc;

public:
    Pole();
    ~Pole();//destruktor, uprace po sebe. Uvolni pointer a ho aj zakotvi teda priradí nulovy pointer
    Pole(unsigned  kolko);
    bool push(Any hodnota);
    void printfPole() const;
    Any operator[](unsigned  int index);
    //Any &operator[](unsigned  int index);
    Any max() const;
    Any min() const;

};

template<typename Any, unsigned int pocet>
Pole<Any, pocet>::Pole() {
    array= (Any *)std::malloc(pocet* sizeof(Any));
    curIndex=0;
    maxIndex=pocet-1;
    numRealoc=1;

}

template<typename Any, unsigned int pocet>
Pole<Any, pocet>::~Pole() {
    free(array);
    array= nullptr;

}

template<typename Any, unsigned int pocet>//urcim pocet prvkov aby sa dalo priamo
Pole<Any, pocet>::Pole(unsigned int kolko) {
    array= (Any *)std::malloc(kolko* sizeof(Any));
    curIndex=0;
    maxIndex=kolko-1;
    numRealoc=1;
}


template<typename Any, unsigned int pocet>
bool Pole<Any, pocet>::push(Any hodnota) {
    if(curIndex<maxIndex)
    {
        array[curIndex]=hodnota;
        curIndex++;
        return  true;
    }
    numRealoc++;
    Any * tmp=(Any *) realloc(array,numRealoc * maxIndex * sizeof (Any));
    if(tmp==NULL)
    {
        return false;
    }
    array=tmp;
    array[curIndex]=hodnota;
    curIndex++;
    maxIndex*=numRealoc;
    return true;
}

template<typename Any, unsigned int pocet>
void Pole<Any, pocet>::printfPole() const {
    //nova syntax nefunguje s dynamickymi poliami
    for(unsigned  i=0;i<curIndex;i++)
    {
        std::cout<<array[i]<<" ";
    }
}

template<typename Any, unsigned int pocet>
Any Pole<Any, pocet>::operator[](unsigned int index) {
    return array[index];
}

#endif //SABOLNY_TRIED_SABLONYTRIED_H
/*
                      / \                               //
                     // \\                              //
                    //   \\                             //
                   // / \ \\                            //
                  // // \\ \\                           //
                 // //   \\ \\                          //
                // // / \ \\ \\                         //
               // // // \\ \\ \\                        //
              // // //   \\ \\ \\                       //
             // // // / \ \\ \\ \\                      //
            // // // // \\ \\ \\ \\                     //
           // // // //   \\ \\ \\ \\                    //
          // // // // / \ \\ \\ \\ \\                   //
         // // // // // \\ \\ \\ \\ \\                  //
        // // // // //   \\ \\ \\ \\ \\                 //
       // // // // // / \ \\ \\ \\ \\ \\                //
      // // // // // // \\ \\ \\ \\ \\ \\               //
     // // // // // //   \\ \\ \\ \\ \\ \\              //
    // // // // // // / \ \\ \\ \\ \\ \\ \\             //
   // // // // // // // \\ \\ \\ \\ \\ \\ \\            //
  // // // // // // //   \\ \\ \\ \\ \\ \\ \\           //
 // // // // // // // / \ \\ \\ \\ \\ \\ \\ \\          //
// // // // // // // // \\ \\ \\ \\ \\ \\ \\ \\         //
 */