#include "piloto.h"
#include <sstream>
using namespace std;

Piloto::Piloto(string nm, string brv, string mat, string hdv) :
    Pessoa(nm), breve(brv), matricula(mat), horasDeVoo(hdv){};

string Piloto::serializar(){
    ostringstream oss;
    oss << nome << ","
        << breve << ","
        << matricula << ","
        << horasDeVoo;
    return oss.str();
}
void Piloto::exibirDados(){
    cout << "\nNome: " << nome << "\nMatricula: " << matricula << "\nHorasDeVoo: " << horasDeVoo << endl;
}