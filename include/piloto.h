#ifndef PILOTO_H
#define PILOTO_H
#include <iostream>
#include "pessoa.h"
using namespace std;

class Piloto : public Pessoa{
    string breve;//brevê
    string horasDeVoo;
    string matricula;
public:
    Piloto(string nome, string matricula, string breve, string horasDeVoo);
};

#endif;