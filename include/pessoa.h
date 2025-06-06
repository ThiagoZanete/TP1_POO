#ifndef PESSOA_H
#define PESSOA_H
#include <iostream>
#include "base.h"
using namespace std;
class Pessoa : public Base{
protected:
    string nome;
public:
    Pessoa(string nome) : nome(nome) {}
    
    string getNome() const { return nome; };
    void setNome(string nome) {nome = nome; }; 
};

#endif