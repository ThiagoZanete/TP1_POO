#include "voo.h"
#include <sstream>
using namespace std;
Voo::Voo(string codigo, string origem, string destino,string datachegada, string datasaida, string distancia, int nEscalas, Aeronave *aeronave, Piloto *piloto, Piloto *copiloto):
    codigo(codigo),
    origem(origem),
    destino(destino),
    dataHoraChegada(datachegada),
    dataHoraSaida(datasaida),
    distancia(distancia),
    nEscalas(nEscalas),
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
            break;
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

Voo* Voo::desserializar(const string& linha, Gerenciador& g) {
    istringstream ss(linha);
    string cod, origem, destino, dataHoraChegada, dataHoraSaida, distancia, nEscalas, codAero, codPiloto, codCopiloto;

    getline(ss, cod, ',');
    getline(ss, origem, ',');
    getline(ss, destino, ',');
    getline(ss, dataHoraChegada, ',');
    getline(ss, dataHoraSaida, ',');
    getline(ss, distancia, ',');
    getline(ss, nEscalas, ',');
    getline(ss, codAero, ',');
    getline(ss, codPiloto, ',');
    getline(ss, codCopiloto, ',');
    int numEscalas = stoi(nEscalas); // Convertido para int
    Aeronave* a = g.procurarAeronave(codAero);
    Piloto *p = g.procurarPiloto(codPiloto);
    Piloto *ps = g.procurarPiloto(codCopiloto);

    Voo* voo = new Voo(
        cod, origem, destino, 
        dataHoraChegada, dataHoraSaida, 
        distancia, // String
        numEscalas, // Int
        a, p, ps
    );

    // Ler passageiros
    string listaCPFs;
    if (getline(ss, listaCPFs)) {
        istringstream cpfStream(listaCPFs);
        string cpf;
        while (getline(cpfStream, cpf, '|')) {
            Passageiro* passageiro = g.procurarPassageiro(cpf);
            if (passageiro) voo->adicionarPassageiros(passageiro);
        }
    }
    return voo;
}

void Voo::exibirDados(){
    cout << "\nOrigem: " << origem << "\nDestino: " << destino << "\nCódigo:" << codigo <<endl;
    aeronave->exibirDados();  
    cout <<"\n\n";
}