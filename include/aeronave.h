#ifndef AERONAVE_H
#define AERONAVE_H
#include <iostream>
using namespace std;

class Aeronave{
    string codigo;           // Código identificador da aeronave
    string modelo;           // Modelo da aeronave
    int capacidade;          // Capacidade máxima de passageiros da aeronave
    float velocidadeMedia;   // Velocidade média da aeronave
    float horasDeAutonomia;  // Horas de autonomia da aeronave

public:
    Aeronave(string codigo ="", string modelo="", int capacidade=0, float velocidadeMedia=0.0, float horasDeAutonomia=0.0);     // Construtor com valores padrão para todos os atributos
    string serializar();     // Método para serializar os dados da aeronave em uma string
    static Aeronave* desserializar(const string& linha);     // Método estático para criar um objeto Aeronave a partir de uma string (desserialização)
    void exibirDados();     // Método para exibir os dados da aeronave no console


    //getters
    string getcodigo() const { return codigo; }
    string getnome() const { return modelo; }
    int getCapacidade() const { return capacidade; }
    float getVelocidade() const { return velocidadeMedia; }
    float getHorasDeAutonomia() const { return horasDeAutonomia; }
    //setters
    void setModelo(string model) { modelo = model; }
    void setCodigo(string cod) { codigo = cod; }
    void setCapacidade(int cap) { capacidade = cap; }
    void setVelocidade(float velMed) { velocidadeMedia = velMed; }
    void setHoras(float hAuto) { horasDeAutonomia = hAuto; }

};   
#endif
