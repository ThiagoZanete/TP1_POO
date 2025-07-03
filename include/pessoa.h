#ifndef PESSOA_H
#define PESSOA_H
#include <iostream>
using namespace std;                         

class Pessoa{                                  // Declaração da classe base Pessoa
protected:
    string nome;                               // Atributo protegido que armazena o nome da pessoa
public:
    Pessoa(string nome) : nome(nome) {}        // Construtor que inicializa o nome com o valor passado como argumento
    
    string getnome() const { return nome; };   // Getter que retorna o nome da pessoa (const para não alterar o objeto)
    void setNome(string nome) {nome = nome; }; // Setter que altera o nome da pessoa
};


#endif