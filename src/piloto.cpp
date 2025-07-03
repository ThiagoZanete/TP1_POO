#include "piloto.h"        
#include <sstream>          
using namespace std;

Piloto::Piloto(string nm, string brv, string mat, string hdv) :  // Construtor que inicializa a classe base Pessoa e atributos próprios
    Pessoa(nm), breve(brv), matricula(mat), horasDeVoo(hdv){};

string Piloto::serializar(){   // Transforma os dados do Piloto em uma string formatada CSV
    ostringstream oss;        // Usa stream de saída para construir a string
    oss << "PILOTO" << ","    // Prefixo para identificar o tipo na serialização
        << nome << ","        
        << breve << ","       
        << matricula << ","   
        << horasDeVoo;       
    return oss.str();         
}

Piloto* Piloto::desserializar(const string& linha) {   // Cria um objeto Piloto a partir de uma linha CSV recebida
    istringstream ss(linha);       // Usa stream de entrada para ler campos da string
    string tipo, nome, horasDeVoo, matricula, breve;
    getline(ss, tipo, ',');        
    getline(ss, nome, ',');        
    getline(ss, breve, ',');       
    getline(ss, matricula, ',');   
    getline(ss, horasDeVoo, ','); 
    return new Piloto(nome, breve, matricula, horasDeVoo);  // Cria e retorna um novo objeto Piloto com os dados lidos
}

void Piloto::exibirDados(){       // Imprime os dados do piloto no console de forma legível
    cout << "\nNome: " << nome << "\nMatricula: " << matricula << "\nHorasDeVoo: " << horasDeVoo << endl;
}
