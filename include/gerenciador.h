#ifndef GERENCIADOR_H
#define GERENCIADOR_H
#include "aeronave.h"
#include "base.h"
#include <vector>
using namespace std;

class Gerenciador{
    vector <Base*> objetosCadastrados;
    vector<Voo*> voosCadastrados;
public:
    bool cadastrarObjeto(Base *obj);
    Piloto* procurarPiloto(string pilotoProcurado);
    Aeronave* procurarAeronave(string aeronaveProcurada); 
    void listarObjetos() const;
    void cadastrarVoo(Voo* voo);
};

#endif