#ifndef AERONAVE_H
#define AERONAVE_H
#include <iostream>
#include "base.h"
using namespace std;

class Aeronave : public Base{
    float horasDeAutonomia;
    float velocidadeMedia;
    int capacidade;
    string codigo;
    string modelo;
public:
    Aeronave(string codigo, string modelo, int capacidade, float velocidadeMedia, float distAutonomia);
};
    
#endif;