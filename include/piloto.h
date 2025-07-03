#ifndef PILOTO_H
#define PILOTO_H
#include <iostream>
#include "pessoa.h"
using namespace std;
class Piloto : public Pessoa{ // Declaração da classe Piloto que herda de Pessoa
    string breve;             // Atributo para armazenar o brevê do piloto
    string matricula;         // Atributo para armazenar a matrícula do piloto
    string horasDeVoo;        // Atributo para armazenar as horas de voo do piloto
public:
    Piloto(string nome, string breve, string matricula, string horasDeVoo);  // Construtor da classe Piloto
    string serializar();       // Método para serializar os dados do piloto em uma string
    void exibirDados();        // Método para exibir os dados do piloto na tela
    static Piloto* desserializar(const string& linha);  // Método estático para desserializar um piloto a partir de uma string

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