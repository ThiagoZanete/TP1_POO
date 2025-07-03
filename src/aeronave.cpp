#include "aeronave.h"
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

Aeronave::Aeronave(string codigo, string modelo, int capacidade, float velocidadeMedia, float horasDeAutonomia){
    // Inicializa os atributos da aeronave com os valores fornecidos
    this->codigo = codigo;
    this->modelo = modelo;
    this->capacidade = capacidade;
    this->velocidadeMedia = velocidadeMedia;
    this->horasDeAutonomia = horasDeAutonomia;
}

string Aeronave::serializar(){
    ostringstream oss;
    // Constrói uma string CSV com os dados da aeronave, separando por vírgula
    oss << codigo << ","
        << modelo << ","
        << capacidade << ","
        << velocidadeMedia << ","
        << horasDeAutonomia;
    return oss.str();  // Retorna a string formatada
}

Aeronave* Aeronave::desserializar(const string& linha) {
    istringstream ss(linha);  // Usa stream para extrair os campos da string CSV
    string cod, mod, capStr, veloStr, autonomiaStr;

    // Lê cada campo separado por vírgula
    getline(ss, cod, ',');
    getline(ss, mod, ',');
    getline(ss, capStr, ',');
    getline(ss, veloStr, ',');
    getline(ss, autonomiaStr, ',');

    // Converte os campos numéricos que foram lidos como strings para os tipos corretos
    int cap = stoi(capStr);
    float velo = stof(veloStr);
    float autonomia = stof(autonomiaStr);

    // Cria e retorna um novo objeto Aeronave com os dados desserializados
    return new Aeronave(cod, mod, cap, velo, autonomia);
}

void Aeronave::exibirDados(){
    // Imprime as informações da aeronave de forma formatada no console
    cout << "Código da aeronave: " << codigo << "\nModelo: " << modelo << "\nCapacidade: " << capacidade 
         << "\nVelocidade Media: " << velocidadeMedia << "\nHoras de Autonomia: " << horasDeAutonomia <<endl;
}
