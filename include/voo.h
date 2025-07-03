#ifndef VOO_H
#define VOO_H

#include "passageiro.h"    
#include "piloto.h"        
#include "aeronave.h"       
#include "gerenciador.h"   

#include <vector>          
#include <iostream>         
#include <ctime>            
#include <iomanip>          

using namespace std;        

class Gerenciador; // Declaração antecipada da classe Gerenciador (para uso em ponteiros)

class Voo { // Declaração da classe Voo
    // Atributos privados do voo
    string codigo, origem, destino, dataHoraChegada, dataHoraSaida, distancia; // Informações básicas do voo
    int nEscalas;                        // Número de escalas
    float duracaoEstimada;              // Duração estimada do voo
    Aeronave *aeronave;                 // Ponteiro para a aeronave usada
    Piloto *piloto, *copiloto;          // Ponteiros para piloto e copiloto
    vector<Passageiro *> passageiros;   // Lista de passageiros do voo

public:
    // Construtor da classe
    Voo(string codigo, string origem, string destino, string datasaida, string datachegada, string distancia, int nEscalas, Aeronave *aeronave, Piloto *piloto, Piloto *copiloto);

    // Métodos principais
    float calcularDuracao();                            // Calcula a duração do voo com base nos horários
    int calcularNescalas();                             // Calcula o número de escalas (caso precise)
    string calcularDataChegada();                       // Estima a data de chegada com base na saída e duração
    void adicionarPassageiros(Passageiro *passageiro);  // Adiciona um passageiro ao vetor de passageiros
    void removerPassageiro(Passageiro *Passageiro);     // Remove um passageiro do vetor
    void listarPassageirosVoo();                        // Lista todos os passageiros do voo
    string serializar();                                // Converte os dados do voo para uma string (ex: para salvar em arquivo)
    static Voo* desserializar(const string& linha, Gerenciador& g); // Constrói um voo a partir de uma linha lida do arquivo CSV
    void exibirDados();                                 // Exibe os dados principais do voo no console

    // Getters 
    Aeronave* getAeronave() const { return aeronave; }
    Piloto* getPiloto() const { return piloto; }
    Piloto* getCopiloto() const { return copiloto; }
    float getDuracaoEstimada() const { return duracaoEstimada; }
    int getNEscalas() const { return nEscalas; }
    string getcodigo() const { return codigo; }
    string getDataHoraChegada() const { return dataHoraChegada; }
    string getDataHoraSaida() const { return dataHoraSaida; }
    string getDestino() const { return destino; }
    string getDistancia() const { return distancia; }
    string getOrigem() const { return origem; }
    vector<Passageiro*> getPassageiros() const { return passageiros; }

    // Setters 
    void setAeronave(Aeronave* a) { aeronave = a; }
    void setPiloto(Piloto* p) { piloto = p; }
    void setCopiloto(Piloto* cp) { copiloto = cp; }
    void setDuracaoEstimada(float duracao) { duracaoEstimada = duracao; }
    void setNEscalas(int escalas) { nEscalas = escalas; }
    void setCodigo(string c) { codigo = c; }
    void setDataHoraChegada(string dh) { dataHoraChegada = dh; }
    void setDataHoraSaida(string dh) { dataHoraSaida = dh; }
    void setDestino(string d) { destino = d; }
    void setDistancia(string dist) { distancia = dist; }
    void setOrigem(string o) { origem = o; }
    void setPassageiros(vector<Passageiro*> p) { passageiros = p; }

};

#endif 
