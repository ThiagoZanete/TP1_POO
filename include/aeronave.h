#ifndef AERONAVE_H
#define AERONAVE_H
#include <iostream>
using namespace std;

class Aeronave{
    string codigo;
    string modelo;
    int capacidade;
    float velocidadeMedia;
    float horasDeAutonomia;

public:
    Aeronave(string codigo ="", string modelo="", int capacidade=0, float velocidadeMedia=0.0, float horasDeAutonomia=0.0);
    string serializar();//indica que esta sobrescerevndo um método da classe base
    static Aeronave* desserializar(const string& linha);
    void exibirDados();
    //getters
    string getcodigo() const { return codigo; }
    string getnome() const { return modelo; }
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
