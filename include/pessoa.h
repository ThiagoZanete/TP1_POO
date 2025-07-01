#ifndef PESSOA_H
#define PESSOA_H
#include <iostream>
using namespace std;
class Pessoa{
protected:
    string nome;
public:
    Pessoa(string nome) : nome(nome) {}
    
    string getnome() const { return nome; };
    void setNome(string nome) {nome = nome; }; 
};

#endif