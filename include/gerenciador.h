#ifndef GERENCIADOR_H
#define GERENCIADOR_H
#include "aeronave.h"
#include "voo.h"
#include "piloto.h"
#include "passageiro.h"
#include "base.h"
#include <vector>
#include <map>
using namespace std;

class Voo;

class Gerenciador{
    vector<Piloto*> pilotosCadastrados;
    vector<Passageiro*> passageirosCadastrados;
    vector<Aeronave*> aeronavesCadastradas;
    vector<Voo*> voosCadastrados;
    map<string, Passageiro*> mapaPassageiros;
    map<string, Aeronave*> mapaAeronaves;
    map<string, Piloto*> mapaPilotos;
public:
    ~Gerenciador();

    bool cadastrarPiloto(Piloto *p);
    bool cadastrarAeronave(Aeronave *a);
    bool cadastrarPassageiro(Passageiro *ps);
    bool cadastrarVoo(Voo* voo);
    bool cadastrarPassageiroVoo(Passageiro *p, Voo *v);

    Piloto* procurarPiloto(string pilotoProcurado);
    Aeronave* procurarAeronave(string aeronaveProcurada); 
    Voo* procurarVoo(string codigoProcurado);
    Passageiro* procurarPassageiro(string passageiroProcurado)const;
    //void listarObjetos() const;

    void listarVoos() const;
    void listarAeronaves() const;
    void listarPassageiros() const;
    void listarPilotos() const;
    void listarPassageirosDeUmVoo(Voo *v) const;

    int contarVoos() const;
    int mediaPassageirosVoo() const;
    vector<pair<string, int>> aeronavesMaisUsadas() const;
    map<Passageiro*, int> passageirosFrequentes() const;
    vector<Voo*> voosAltaLotacao() const;
    map<string, float> distanciaTotalPorAeronave() const;

    void salvarDados();
    void carregarDados();
};

#endif