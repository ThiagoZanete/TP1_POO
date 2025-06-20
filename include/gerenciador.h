#ifndef GERENCIADOR_H
#define GERENCIADOR_H
#include "aeronave.h"
#include "base.h"
#include <vector>
using namespace std;

class Gerenciador{
    vector<Piloto*> pilotosCadastrados;
    vector<Passageiro*> passageirosCadastrados;
    vector<Aeronave*> aeronavesCadastradas;
    vector<Voo*> voosCadastrados;
public:
    bool cadastrarPiloto(Piloto *p);
    bool cadastrarAeronave(Aeronave *a);
    bool cadastrarPassageiro(Passageiro *ps);
    bool cadastrarVoo(Voo* voo);
    bool cadastrarPassageiroVoo(Passageiro *p, Voo *v);

    Piloto* procurarPiloto(string pilotoProcurado);
    Aeronave* procurarAeronave(string aeronaveProcurada); 
    Voo* procurarVoo(string codigoProcurado);
    Passageiro* procurarPassageiro(string passageiroProcurado);
    //void listarObjetos() const;

    void listarVoos() const;
    void listarAeronaves() const;
    void listarPassageiros() const;
    void listarPilotos() const;
    void listarPassageirosDeUmVoo(Voo *v) const;
};

#endif