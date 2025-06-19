#include "piloto.h"
using namespace std;

Piloto::Piloto(string nm, string brv, string mat, string hdv) :
    Pessoa(nm), breve(brv), matricula(mat), horasDeVoo(hdv){};

string Piloto::serializar(){
    return "";
}
void Piloto::exibirDados(){
    cout << "\nNome: " << nome << "\nMatricula: " << matricula << "\nHorasDeVoo: " << horasDeVoo << endl;
}