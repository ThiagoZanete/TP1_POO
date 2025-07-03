#include "passageiro.h"
#include <sstream> 
using namespace std;

// Construtor da classe Passageiro, inicializa atributos herdando o nome da classe Pessoa
Passageiro::Passageiro(string nome, string bilhete, string cpf) :
    Pessoa(nome), bilhete(bilhete), cpf(cpf){}  // Inicialização da base e dos membros

// Converte os dados do passageiro para uma string no formato CSV
string Passageiro::serializar(){
    ostringstream oss;
        oss << "PASSAGEIRO" << ","  
            << nome << ","          
            << bilhete << ","       
            << cpf;                 
    return oss.str();               // Retorna a string formatada
}

// Constrói um objeto Passageiro a partir de uma linha de texto CSV
Passageiro* Passageiro::desserializar(const string& linha) {
    istringstream ss(linha);              // Cria um fluxo de entrada com a linha
    string tipo, nome, cpf, bilhete;
    getline(ss, tipo, ',');              
    getline(ss, nome, ',');              
    getline(ss, bilhete, ',');           
    getline(ss, cpf, ',');               
    return new Passageiro(nome, bilhete, cpf);  // Cria e retorna um novo objeto Passageiro
}

// Exibe as informações do passageiro no console
void Passageiro::exibirDados(){
    cout << "\nNome: " << nome            // Nome herdado de Pessoa
         << "\nBilhete: " << bilhete
         << "\nCPF: " << cpf << endl;
}
