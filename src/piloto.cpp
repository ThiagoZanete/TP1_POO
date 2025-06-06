#include "piloto.h"
using namespace std;

Piloto::Piloto(string nome, string breve, string matricula, string horasDeVoo) :
    Pessoa(nome), breve(breve), matricula(matricula), horasDeVoo(horasDeVoo){};

string Piloto::serializar(){

}
void Piloto::exibirDados(){
    cout << "\nNome: " << nome << "\nMatricula: " << matricula << "\nHorasDeVoo: " << horasDeVoo << endl;
}