#ifndef GERENCIADOR_H 
#define GERENCIADOR_H

#include "aeronave.h"     
#include "voo.h"          
#include "piloto.h"       
#include "passageiro.h"   
#include <vector>         
#include <map>            

using namespace std; 

class Voo; // Declaração antecipada da classe Voo (necessária para ponteiros em parâmetros)

class Gerenciador {
    vector<Piloto*> pilotosCadastrados;             // Vetor com os pilotos cadastrados
    vector<Passageiro*> passageirosCadastrados;     // Vetor com os passageiros cadastrados
    vector<Aeronave*> aeronavesCadastradas;         // Vetor com as aeronaves cadastradas
    vector<Voo*> voosCadastrados;                   // Vetor com os voos cadastrados

    map<string, Passageiro*> mapaPassageiros;       // Mapa para buscar passageiros por CPF
    map<string, Aeronave*> mapaAeronaves;           // Mapa para buscar aeronaves por código
    map<string, Piloto*> mapaPilotos;               // Mapa para buscar pilotos por brevê

public:
    ~Gerenciador(); // Destrutor: responsável por liberar memória

    bool cadastrarPiloto(Piloto *p);                        // Cadastra piloto
    bool cadastrarAeronave(Aeronave *a);                    // Cadastra aeronave
    bool cadastrarPassageiro(Passageiro *ps);               // Cadastra passageiro
    bool cadastrarVoo(Voo* voo);                            // Cadastra voo
    bool cadastrarPassageiroVoo(Passageiro *p, Voo *v);     // Adiciona passageiro a um voo

    Piloto* procurarPiloto(string pilotoProcurado);                     // Procura piloto pelo brevê
    Aeronave* procurarAeronave(string aeronaveProcurada);              // Procura aeronave pelo código
    Voo* procurarVoo(string codigoProcurado);                          // Procura voo pelo código
    Passageiro* procurarPassageiro(string passageiroProcurado) const; // Procura passageiro por CPF

    //void listarObjetos() const; // (Comentado) Poderia listar todos os objetos, se implementado

    void listarVoos() const;                             // Lista todos os voos cadastrados
    void listarAeronaves() const;                        // Lista todas as aeronaves cadastradas
    void listarPassageiros() const;                      // Lista todos os passageiros cadastrados
    void listarPilotos() const;                          // Lista todos os pilotos cadastrados
    void listarPassageirosDeUmVoo(Voo *v) const;         // Lista os passageiros de um voo específico

    int contarVoos() const;                              // Retorna o número total de voos
    int mediaPassageirosVoo() const;                     // Calcula a média de passageiros por voo
    vector<pair<string, int>> aeronavesMaisUsadas() const;       // Retorna vetor com aeronaves mais utilizadas
    map<Passageiro*, int> passageirosFrequentes() const;         // Retorna passageiros que voaram mais de uma vez
    vector<Voo*> voosAltaLotacao() const;                        // Retorna os voos com mais de 90% da lotação
    map<string, float> distanciaTotalPorAeronave() const;        // Retorna a distância total percorrida por cada aeronave

    void salvarDados();                                // Salva todos os dados em arquivos
    void carregarDados();                              // Carrega todos os dados a partir dos arquivos
};

#endif // Fim do guardião de inclusão
