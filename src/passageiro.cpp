#include "passageiro.h"
#include <sstream>
using namespace std;
Passageiro::Passageiro(string nome, string bilhete, string cpf) :
    Pessoa(nome), bilhete(bilhete), cpf(cpf){}


string Passageiro::serializar(){
    ostringstream oss;
        oss << "PASSAGEIRO" << ","
            << nome << ","
            << bilhete << ","
            << cpf;
    return oss.str();
}

Passageiro* Passageiro::desserializar(const string& linha) {
    istringstream ss(linha);
    string tipo, nome, cpf, bilhete;
    getline(ss, tipo, ',');
    getline(ss, nome, ',');
    getline(ss, bilhete, ',');
    getline(ss, cpf, ',');
    return new Passageiro(nome, bilhete, cpf);
}

void Passageiro::exibirDados(){
    cout << "\nNome: " << nome << "\nBilhete: " << bilhete << "\nCPF: " << cpf << endl;
}