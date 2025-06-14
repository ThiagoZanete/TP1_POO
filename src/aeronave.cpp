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

void Aeronave::exibirDados(){
    cout << "Codigo: " << codigo << "\nModelo: " << modelo << "\nCapacidade: " << capacidade << "\nVelocidade Media: " << velocidadeMedia << "\nHoras de Autonomia: " << horasDeAutonomia <<endl;
}


/*
Aeronave* Aeronave::registerAircraft(string cod, string model, int cap, float velMed, float hAut){
     return new Aeronave(cod, model, cap, velMed, hAut);//cria um aeronave e retorna um ponteiro pra ela
}*/