#include<iostream>
#include "voo.h"
#include "gerenciador.h"

int main(){
    int opc;
    Piloto *auxPiloto, *auxPiloto2;
    Aeronave *auxAeronave;
    Gerenciador gerenciador;
    string auxCod, auxNome, auxNome2, auxBreve, auxMatricula, auxHorasdeVoo, auxBilhete, auxCpf, auxOrigem, auxDestino;
    int auxCap;
    float auxVel, auxHorasAutonomia;
    
    while(opc != 9){
        cout << "\n===================================\n1- Cadastrar aereonave\n2- Cadastrar Piloto\n3- Cadastrar Passageiro\n4- Criar Voo\n5- Cadastrar passageiro em voo\n6- Listar Voos\n7- Listar passageiros de um voo\n8- Gerar relatórios e estatísticas\n9- Salvar dados e sair\n===================================\n\nEscolha uma opção seu gay: "<< endl;
        cin >> opc;
        switch (opc){
        case 1:{//cadastrar aeronave
            cout << "Digite o código da aeronave, auxNome, auxCapacidade, auxVelocidadeMedia e autonomia: ";
            cin >> auxCod >> auxNome >> auxCap >> auxVel >> auxHorasAutonomia;
            Aeronave *novaAeronave = new Aeronave(auxCod, auxNome, auxCap, auxVel, auxHorasAutonomia);
            gerenciador.cadastrarObjeto(novaAeronave);
            break;
        }
        case 2:{//cadastrar piloto
            cout << "Digite o auxNome do piloto, brevê, matrícula e as horas de voo: ";
            cin >> auxNome >> auxBreve >> auxMatricula >> auxHorasdeVoo;
            Piloto *novoPiloto = new Piloto(auxNome, auxBreve, auxMatricula, auxHorasdeVoo);
            gerenciador.cadastrarObjeto(novoPiloto);
            break;
        }
        case 3:{//cadastrar passageiro
            cout << "Digite o auxNome do passageiro, o auxBilhete e o auxCpf: ";
            cin >> auxNome >> auxBilhete >> auxCpf;
            Passageiro *novoPassageiro = new Passageiro(auxNome, auxBilhete, auxCpf);
            gerenciador.cadastrarObjeto(novoPassageiro);
            break;
        }
        case 4:{//criar Voo
            cout << "Digite o nome do piloto e do copiloto: ";
            cin >> auxNome >> auxNome2;
            auxPiloto = gerenciador.procurarPiloto(auxNome);
            auxPiloto2 = gerenciador.procurarPiloto(auxNome2);
            if(auxPiloto && auxPiloto2){
                cout << "Ambos Pilotos encontrados" << endl;
            }
            cout << "Digite o nome da aeronave: ";
            cin >> auxNome;
            auxAeronave = gerenciador.procurarAeronave(auxNome);
            if(auxAeronave){
                cout << "Aeronave encontrada" << endl;
            }
            // Agora cria o voo (ponteiros válidos)
            cout << "Digite o código, origem e destino do voo: ";
            cin >> auxCod >> auxOrigem >> auxDestino;
            Voo* novoVoo = new Voo(auxCod, auxOrigem, auxDestino, auxAeronave, auxPiloto, auxPiloto2);
            gerenciador.cadastrarVoo(novoVoo);
            gerenciador.listarObjetos();
            break;
        }
        default:
            cout << "Caso Default"<<endl;
            break;
        }
        //break;
    }
   
    gerenciador.listarObjetos();
    return 0;
}