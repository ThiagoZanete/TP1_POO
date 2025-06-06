#include "voo.h"

Voo :: Voo(string codigo, string origem, string destino, Aeronave *aeronave, Piloto *piloto, Piloto *copiloto):
    codigo(codigo),origem(origem), destino(destino), aeronave(aeronave), piloto(piloto), copiloto(piloto){}

void Voo :: adicionarPassageiros(Passageiro *p){
    cout<<"Aqui";
    if(passageiros.size() < (unsigned)aeronave->getCapacidade()){
        passageiros.push_back(p);
        cout<<"Adicionou";
    }
    else
        cout<<"Voo está cheio";
}

void Voo :: removerPassageiro(Passageiro *p){
    for(unsigned int i = 0; i < passageiros.size(); i++){
        if(passageiros[i]==p){
            delete passageiros[i];
            passageiros.erase(passageiros.begin() + i);
        }
    }
}