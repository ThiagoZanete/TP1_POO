#ifndef BASE_H
#define BASE_H
#include <iostream>
using namespace std;

class Base{
public:
    virtual void exibirDados();
    virtual string serializar();
};
#endif