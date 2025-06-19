#include "passageiro.h"
using namespace std;
Passageiro::Passageiro(string nome, string bilhete, string cpf) :
    Pessoa(nome), bilhete(bilhete), cpf(cpf){}


string Passageiro::serializar(){
    return "";
}
void Passageiro::exibirDados(){
    cout << "\nNome: " << nome << "\nBilhete: " << bilhete << "\nCPF: " << cpf << endl;
}