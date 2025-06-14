#include "piloto.h"
#include <sstream>
using namespace std;

Piloto::Piloto(string nm, string brv, string mat, string hdv) :
    Pessoa(nm), breve(brv), matricula(mat), horasDeVoo(hdv){};

string Piloto::serializar(){
    ostringstream oss;
    oss << "PILOTO" << "," 
        << nome << ","
        << breve << ","
        << matricula << ","
        << horasDeVoo;
    return oss.str();
}

Piloto* Piloto::desserializar(const string& linha) {
    istringstream ss(linha);
    string tipo, nome,horasDeVoo,matricula, breve;
    getline(ss, tipo, ',');
    getline(ss, nome, ',');
    getline(ss, breve, ',');
    getline(ss, matricula, ',');
    getline(ss, horasDeVoo, ',');
    return new Piloto(nome, breve, matricula, horasDeVoo);
}

void Piloto::exibirDados(){
    cout << "\nNome: " << nome << "\nMatricula: " << matricula << "\nHorasDeVoo: " << horasDeVoo << endl;
}