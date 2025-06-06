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
    Aeronave(string codigo, string modelo, int capacidade, float velocidadeMedia, float horasDeAutonomia);
    string serializar() override;//indica que esta sobrescerevndo um método da classe base
    void exibirDados() override;
    //Aeronave* registerAircraft(string cod, string model, int cap, float velMed, float hAut);
    //getters
    string getModelo() const { return modelo; }
    string getCodigo() const { return codigo; }
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
