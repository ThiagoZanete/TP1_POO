#include "aeronave.h"
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

Aeronave::Aeronave(string codigo, string modelo, int capacidade, float velocidadeMedia, float horasDeAutonomia) : Base(){
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
    cout << "Codigo: " << codigo << "\nModelo: " << modelo << "\nCapacidade: " << capacidade << "\nVelocidade Media: " << velocidadeMedia << "\nHoras de Autonomia: " << horasDeAutonomia <<endl;
}


/*
Aeronave* Aeronave::registerAircraft(string cod, string model, int cap, float velMed, float hAut){
     return new Aeronave(cod, model, cap, velMed, hAut);//cria um aeronave e retorna um ponteiro pra ela
}*/