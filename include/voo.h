#ifndef VOO_H
#define VOO_H
#include "passageiro.h"
#include "piloto.h"
#include "aeronave.h"
#include <vector>
#include <iostream>
using namespace std;

class Voo : public Base{
    Aeronave *aeronave;
    Piloto *piloto, *copiloto;
    float duracaoEstimada;
    int nEscalas;
    string codigo, dataHoraChegada, dataHoraSaida, destino, distancia, origem;
    vector<Passageiro *> passageiros;

public:
    Voo(string codigo, string origem, string destino, Aeronave *aeronave, Piloto *piloto, Piloto *copiloto);
    float calcularDuracao();
    int calcularNescalas();
    void adicionarPassageiros(Passageiro *passageiro);
    void removerPasasgeiro(Passageiro *Pasasgeiro);
    
   // Getters
    Aeronave* getAeronave() const { return aeronave; }
    Piloto* getPiloto() const { return piloto; }
    Piloto* getCopiloto() const { return copiloto; }
    float getDuracaoEstimada() const { return duracaoEstimada; }
    int getNEscalas() const { return nEscalas; }
    string getCodigo() const { return codigo; }
    string getDataHoraChegada() const { return dataHoraChegada; }
    string getDataHoraSaida() const { return dataHoraSaida; }
    string getDestino() const { return destino; }
    string getDistancia() const { return distancia; }
    string getOrigem() const { return origem; }
    vector<Passageiro*> getPassageiros() const { return passageiros; }

    // Setters
    void setAeronave(Aeronave* a) { aeronave = a; }
    void setPiloto(Piloto* p) { piloto = p; }
    void setCopiloto(Piloto* cp) { copiloto = cp; }
    void setDuracaoEstimada(float duracao) { duracaoEstimada = duracao; }
    void setNEscalas(int escalas) { nEscalas = escalas; }
    void setCodigo(string c) { codigo = c; }
    void setDataHoraChegada(string dh) { dataHoraChegada = dh; }
    void setDataHoraSaida(string dh) { dataHoraSaida = dh; }
    void setDestino(string d) { destino = d; }
    void setDistancia(string dist) { distancia = dist; }
    void setOrigem(string o) { origem = o; }
    void setPassageiros(vector<Passageiro*> p) { passageiros = p; }

};

#endif