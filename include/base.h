#ifndef BASE_H
#define BASE_H
#include <iostream>
using namespace std;

class Base {
public:
    virtual void exibirDados() = 0;
    virtual string serializar() = 0;

    virtual string getcodigo() const;
    virtual string getnome() const;

    virtual ~Base() = default;
};


#endif