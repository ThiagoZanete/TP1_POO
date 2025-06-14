#include "voo.h"
#include <sstream>
using namespace std;
Voo::Voo(string codigo, string origem, string destino, string datasaida, string distancia, Aeronave *aeronave, Piloto *piloto, Piloto *copiloto):
    codigo(codigo),
    origem(origem),
    destino(destino),
    dataHoraChegada(""),
    dataHoraSaida(datasaida),
    distancia(distancia),
    nEscalas(0),
    aeronave(aeronave),
    piloto(piloto),
    copiloto(copiloto){}


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
    nEscalas = calcularNescalas();
    float distanciaKm = stof(distancia);
    float velocidadeKmH = aeronave->getVelocidade();

    if (velocidadeKmH <= 0) return 0;

    float duracaoBase = distanciaKm / velocidadeKmH;
    return duracaoBase + nEscalas; // 1h por escala
}


void Voo::listarPassageirosVoo(){
    for(const auto &p : passageiros){
        p->exibirDados();
    }
}


string Voo::serializar(){
    ostringstream oss;
    oss << codigo << ","
        << origem << ","
        << destino << ","
        << dataHoraChegada << ","
        << dataHoraSaida << ","
        << distancia << ","
        << nEscalas << ","
        << aeronave->getcodigo() << ","
        << piloto->getBreve() << ","
        << copiloto->getBreve() << ",";
        
        // Lista de CPFs dos passageiros separados por '|'
        for (size_t i = 0; i < passageiros.size(); ++i) {
            oss << passageiros[i]->getCpf();
            if (i < passageiros.size() - 1)
                oss << "|";
            };
    return oss.str();
}

void Voo::exibirDados(){
    cout << "\nOrigem: " << origem << "\nDestino: " << destino << "\nCódigo:" << codigo <<endl;
    aeronave->exibirDados();  
    cout <<"\n\n";
}