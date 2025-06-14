#ifndef AERONAVE_H
#define AERONAVE_H
#include <iostream>
#include "base.h"
using namespace std;

class Aeronave : public Base{
    string codigo;
    string modelo;
    int capacidade;
    float velocidadeMedia;
    float horasDeAutonomia;

public:
    Aeronave(string codigo ="", string modelo="", int capacidade=0, float velocidadeMedia=0.0, float horasDeAutonomia=0.0);
    string serializar() override;//indica que esta sobrescerevndo um método da classe base
    void exibirDados() override;
    //Aeronave* registerAircraft(string cod, string model, int cap, float velMed, float hAut);
    //getters
    string getcodigo() const override { return codigo; }
    string getnome() const override { return modelo; } 
    int getCapacidade() const { return capacidade; }
    float getVelocidade() const { return velocidadeMedia; }
    float getHorasDeAutonomia() const { return horasDeAutonomia; }
    //setters
    void setModelo(string model) { modelo = model; }
    void setCodigo(string cod) { codigo = cod; }
    void setCapacidade(int cap) { capacidade = cap; }
    void setVelocidade(float velMed) { velocidadeMedia = velMed; }
    void setHoras(float hAuto) { horasDeAutonomia = hAuto; }

};   
#endif
