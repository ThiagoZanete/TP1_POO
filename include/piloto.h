#ifndef PILOTO_H
#define PILOTO_H
#include <iostream>
#include "pessoa.h"
using namespace std;

class Piloto : public Pessoa{
    string breve;//brevê
    string matricula;
    string horasDeVoo;
public:
    Piloto(string nome, string breve, string matricula, string horasDeVoo);
    string serializar() override;
    void exibirDados() override;

    //getters
    //string getNome() const { return nome; } essa parte foi herdada de Pessoa
    string getBreve() const {return breve; }
    string getHorasDeVoo() const {return horasDeVoo; }
    string getMatricula() const {return matricula; }

    //setters
    //void setNome(string nome) { nome = nome; }essa parte foi herdad de pessoa
    void setBreve(string breve) { breve = breve; }
    void setHorasDeVoo(string horasDeVoo) { horasDeVoo = horasDeVoo; }
    void setMatricula(string matricula) {matricula = matricula; }
};

#endif