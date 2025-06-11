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
            cout << "Digite o código da aeronave, Nome, Capacidade, VelocidadeMedia e autonomia: ";
            cin >> auxCod >> auxNome >> auxCap >> auxVel >> auxHorasAutonomia;
            Aeronave *novaAeronave = new Aeronave(auxCod, auxNome, auxCap, auxVel, auxHorasAutonomia);
            gerenciador.cadastrarAeronave(novaAeronave);
            gerenciador.listarAeronaves();
            break;
        }
        case 2:{//cadastrar piloto
            cout << "Digite o Nome do piloto, brevê, matrícula e as horas de voo: ";
            cin >> auxNome >> auxBreve >> auxMatricula >> auxHorasdeVoo;
            Piloto *novoPiloto = new Piloto(auxNome, auxBreve, auxMatricula, auxHorasdeVoo);
            gerenciador.cadastrarPiloto(novoPiloto);
            break;
        }
        case 3:{//cadastrar passageiro
            cout << "Digite o Nome do passageiro, o auxBilhete e o auxCpf: ";
            cin >> auxNome >> auxBilhete >> auxCpf;
            Passageiro *novoPassageiro = new Passageiro(auxNome, auxBilhete, auxCpf);
            gerenciador.cadastrarPassageiro(novoPassageiro);
            break;
        }
        case 4:{//criar Voo
            cout << "Digite o nome do piloto e do copiloto: ";
            cin >> auxNome >> auxNome2;
            auxPiloto = gerenciador.procurarPiloto(auxNome);
            auxPiloto2 = gerenciador.procurarPiloto(auxNome2);
            if(!auxPiloto || !auxPiloto2)
                break;
            cout << "Digite o nome da aeronave: ";
            cin >> auxNome;
            auxAeronave = gerenciador.procurarAeronave(auxNome);
            if(!auxAeronave)
                break;
            // Agora cria o voo (ponteiros válidos)
            cout << "Digite o código, origem e destino do voo: ";
            cin >> auxCod >> auxOrigem >> auxDestino;
            Voo* novoVoo = new Voo(auxCod, auxOrigem, auxDestino, auxAeronave, auxPiloto, auxPiloto2);
            gerenciador.cadastrarVoo(novoVoo);
            //gerenciador.listarObjetos();
            break;
        }
        case 5:{//cadastrar passageiro em voo
            cout << "Digite o codigo do voo em que deseja cadastrar um passageiro: ";
            cin >> auxCod; 
            Voo *voo = gerenciador.procurarVoo(auxCod);
            if(!voo)//não achou
                break;
            cout << "Digite o nome do passageiro que deseja incluir nesse voo: ";
            cin >> auxNome;
            Passageiro *passageiro= gerenciador.procurarPassageiro(auxNome);
            if(!passageiro)//não achou
                break;
            gerenciador.cadastrarPassageiroVoo(passageiro, voo);
            break;
        }
        case 6:{//listar voos
            cout << "Voos cadastrados:"<<endl;
            gerenciador.listarVoos();
            break;
        }
        case 7:{//listar passageiros de voo
            cout << "Digite o código do voo que deseja listar os passageiros: ";
            cin >> auxCod;
            Voo *voo = gerenciador.procurarVoo(auxCod);
            if(!voo)//não achou
                break;
            gerenciador.listarPassageirosDeUmVoo(voo);
            break;
        }
        default:
            cout << "Caso Default"<<endl;
            break;
        }
    }
   
    gerenciador.listarVoos();
    return 0;
}