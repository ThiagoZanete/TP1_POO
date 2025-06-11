#include "voo.h"

Voo::Voo(string codigo, string origem, string destino, Aeronave *aeronave, Piloto *piloto, Piloto *copiloto)
    : aeronave(aeronave), piloto(piloto), copiloto(copiloto),
      duracaoEstimada(0), nEscalas(0),
      codigo(codigo), dataHoraChegada(""), dataHoraSaida(""),
      destino(destino), distancia(""), origem(origem) {}


void Voo :: adicionarPassageiros(Passageiro *p){
    if(passageiros.size() < (unsigned)aeronave->getCapacidade()){
        passageiros.push_back(p);
        cout<<"Adicionou: "<< p->getNome() << endl;
    }
    else
        cout<<"O voo de " << origem << " para " << destino << " está cheio."<<endl;
}

void Voo :: removerPassageiro(Passageiro *p){
    for(unsigned int i = 0; i < passageiros.size(); i++){
        if(passageiros[i]==p){
            delete passageiros[i];
            passageiros.erase(passageiros.begin() + i);
        }
    }
}
string Voo::serializar(){
    return "";
}
void Voo::exibirDados(){
    cout << "\nOrigem: " << origem << "\nDestino: " << destino << endl;
}