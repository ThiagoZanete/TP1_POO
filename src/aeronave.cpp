#include "aeronave.h"
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

Aeronave::Aeronave(string codigo, string modelo, int capacidade, float velocidadeMedia, float horasDeAutonomia){
    this->codigo = codigo;
    this->modelo = modelo;
    this->capacidade = capacidade;
    this->velocidadeMedia = velocidadeMedia;
    this->horasDeAutonomia = horasDeAutonomia;
}
string Aeronave::serializar(){
    ostringstream oss;
        oss << codigo << ","
            << modelo << ","
            << capacidade << ","
            << velocidadeMedia << ","
            << horasDeAutonomia;
    return oss.str();
}

Aeronave* Aeronave::desserializar(const string& linha) {
    istringstream ss(linha);
    string cod, mod, capStr, veloStr, autonomiaStr;

    getline(ss, cod, ',');
    getline(ss, mod, ',');
    getline(ss, capStr, ',');
    getline(ss, veloStr, ',');
    getline(ss, autonomiaStr, ',');

    int cap = stoi(capStr);
    float velo = stof(veloStr);
    float autonomia = stof(autonomiaStr);

    return new Aeronave(cod, mod, cap, velo, autonomia);
}

void Aeronave::exibirDados(){
    cout << "Código da aeronave: " << codigo << "\nModelo: " << modelo << "\nCapacidade: " << capacidade << "\nVelocidade Media: " << velocidadeMedia << "\nHoras de Autonomia: " << horasDeAutonomia <<endl;
}
