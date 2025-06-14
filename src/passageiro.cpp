#include "passageiro.h"
#include <sstream>
using namespace std;
Passageiro::Passageiro(string nome, string bilhete, string cpf) :
    Pessoa(nome), bilhete(bilhete), cpf(cpf){}


string Passageiro::serializar(){
    ostringstream oss;
        oss << nome << ","
            << bilhete << ","
            << cpf;
    return oss.str();
}
void Passageiro::exibirDados(){
    cout << "\nNome: " << nome << "\nBilhete: " << bilhete << "\nCPF: " << cpf << endl;
}