#include "voo.h"

Voo::Voo(string codigo, string origem, string destino, Aeronave *aeronave, Piloto *piloto, Piloto *copiloto)
    : aeronave(aeronave), piloto(piloto), copiloto(copiloto),
      duracaoEstimada(calcularDuracao()), nEscalas(calcularNescalas()),
      codigo(codigo), dataHoraChegada(""), dataHoraSaida(""),
      destino(destino), distancia("1350"), origem(origem) {}


void Voo :: adicionarPassageiros(Passageiro *p){
    if(passageiros.size() < (unsigned)aeronave->getCapacidade()){
        passageiros.push_back(p);
        cout << "Adicionou: "<< p->getnome() << endl;
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

int Voo::calcularNescalas() {
    float distanciaKm = stof(distancia);
    float autonomiaKm = aeronave->getHorasDeAutonomia();

    if (autonomiaKm <= 0) return 0;

    int escalas = distanciaKm / autonomiaKm;
    if (distanciaKm > autonomiaKm && distanciaKm > escalas * autonomiaKm)
        escalas++; // uma escala extra se houver sobra

    return escalas;
}

float Voo::calcularDuracao() {
    float distanciaKm = stof(distancia);
    float velocidadeKmH = aeronave->getVelocidade();

    if (velocidadeKmH <= 0) return 0;

    float duracaoBase = distanciaKm / velocidadeKmH;
    return duracaoBase + calcularNescalas(); // 1h por escala
}


void Voo::listarPassageirosVoo(){
    for(const auto &p : passageiros){
        p->exibirDados();
    }
}


string Voo::serializar(){
    return "";
}

void Voo::exibirDados(){
    cout << "\nOrigem: " << origem << "\nDestino: " << destino << "\nCódigo:" << codigo <<endl;
    aeronave->exibirDados();  
    cout <<"\n\n";
}