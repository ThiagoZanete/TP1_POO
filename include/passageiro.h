#ifndef PASSAGEIRO_H
#define PASSAGEIRO_H
#include <iostream>
#include "pessoa.h"
using namespace std;

class Passageiro : public Pessoa{
    string bilhete;
    string cpf;
public:
    Passageiro(string nome, string bilhete, string cpf);
    virtual ~Passageiro() {};
    string serializar() override;
    void exibirDados() override;

    //getters
    //string getNome() const { return nome; } essa parte foi herdada de Pessoa
    string getBilhete() const {return bilhete; }
    string getCpf() const {return cpf; }

    //setters
    //void setNome(string nome) { nome = nome; }essa parte foi herdad de pessoa
    void setBilhete(string bilheteNovo) { bilhete = bilheteNovo; }
    void setCpf(string cpfNovo) { cpf = cpfNovo; } 

};
#endif 