#ifndef PASSAGEIRO_H
#define PASSAGEIRO_H
#include <iostream>
#include "pessoa.h"
using namespace std;

class Passageiro : public Pessoa{
    string nome;
    string bilhete;
    string cpf;
public:
    Passageiro(string nome, string bilhete, string cpf);
  
    

};
#endif