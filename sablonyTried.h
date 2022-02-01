//
// Created by map on 1. 2. 2022.
//

#ifndef SABOLNY_TRIED_SABLONYTRIED_H
#define SABOLNY_TRIED_SABLONYTRIED_H

template<typename Any, typename Other=int>//dávame najavo že budeme vytvárať generickú triedu
class Obdlznik{
private:
    Any a;
    Any b;
public:
    Obdlznik():a(1),b(1){};
    Obdlznik(Any x):a(x),b(x){};
    Obdlznik(Any x, Any y):a(x),b(y){};
    Any getObvod() const;
    Any getObsah() const;
    auto getObvod1()-> decltype(a,b) const;//prakticky alternativny zapis ku: Any getObvod() const;
};

template<typename Any, typename Other>
Any Obdlznik<Any,Other>::getObvod() const {
    return 2*a+2*b;
}

template<typename Any, typename Other>
Any Obdlznik<Any,Other>::getObsah() const {
    return a*b;
}

template<typename Any, typename Other>
auto Obdlznik<Any, Other>::getObvod1() -> decltype(a, b) const {
    return 2*a+2*b;
}

#endif //SABOLNY_TRIED_SABLONYTRIED_H
