#include<iostream>
#include "voo.h"
#include "gerenciador.h"

int main(){
    int opc = 0;
    Piloto *auxPiloto, *auxPiloto2;
    Aeronave *auxAeronave;
    Gerenciador gerenciador;
    string auxCod, auxNome, auxNome2, auxBreve, auxBreve2, auxMatricula, auxHorasdeVoo, auxBilhete,
            auxCpf, auxOrigem, auxDestino, auxDistancia, auxDataSaida;
    int auxCap;
    float auxVel, auxHorasAutonomia;

    while(opc != 9){
        cout << "\n===================================\n1- Cadastrar aereonave\n2- Cadastrar Piloto\n3- Cadastrar Passageiro\n4- Criar Voo\n5- Cadastrar passageiro em voo\n6- Listar Voos\n7- Listar passageiros de um voo\n8- Carregar os dados anteriores\n9- Salvar dados e sair\n===================================\n\nEscolha uma opção seu gay: "<< endl;
        cin >> opc;
        switch (opc){
        case 1:{    //cadastrar aeronave
            cout << "Digite o código da aeronave: "; 
            cin >> auxCod;
            cout << "Digite o modelo da aeronave: ";
            cin >> auxNome; 
            cout << "Digite a capacidade da aeronave: ";
            cin >> auxCap;
            cout << "Digite a velocidade média da aeronave: ";
            cin >> auxVel; 
            cout << "Digite a autonomia da aeronave: ";
            cin >> auxHorasAutonomia;
            Aeronave *novaAeronave = new Aeronave(auxCod, auxNome, auxCap, auxVel, auxHorasAutonomia);
            gerenciador.cadastrarAeronave(novaAeronave);
            gerenciador.listarAeronaves();
            break;
        }
        case 2:{    //cadastrar piloto
            cout << "Digite o Nome do piloto: ";
            cin >> auxNome;
            cout << "Digite o brevê do piloto: ";
            cin >> auxBreve;
            cout << "Digite a matrícula do piloto: ";
            cin >> auxMatricula;
            cout << "Digite as horas de voo do piloto: ";
            cin >> auxHorasdeVoo;
            Piloto *novoPiloto = new Piloto(auxNome, auxBreve, auxMatricula, auxHorasdeVoo);
            gerenciador.cadastrarPiloto(novoPiloto);
            break;
        }
        case 3:{    //cadastrar passageiro
            cout << "Digite o Nome do passageiro: ";
            cin >> auxNome;
            cout << "Digite o bilhete do passageiro: ";
            cin >> auxBilhete;
            cout << "Digite o cpf do passageiro: ";
            cin >> auxCpf;
            Passageiro *novoPassageiro = new Passageiro(auxNome, auxBilhete, auxCpf);
            gerenciador.cadastrarPassageiro(novoPassageiro);
            break;
        }
        case 4:{    //criar Voo
            cout << "Digite o brevê do piloto: ";
            cin >> auxBreve;
            cout << "Digite o brevê do copiloto: ";          //Tem que mudar para o brevê
            cin >> auxBreve2;
            auxPiloto = gerenciador.procurarPiloto(auxBreve);
            auxPiloto2 = gerenciador.procurarPiloto(auxBreve2);
            if(!auxPiloto || !auxPiloto2)
                break;
            cout << "Digite o código da aeronave: ";                      //Tem que mudar para o código
            cin >> auxCod;
            auxAeronave = gerenciador.procurarAeronave(auxCod);
            if(!auxAeronave)
                break;
            // Agora cria o voo (ponteiros válidos)
            cout << "Digite o código do voo: ";
            cin >> auxCod;
            cout << "Digite a origem do voo: ";
            cin >> auxOrigem;
            cout << "Digite o destino do voo: ";
            cin >> auxDestino;
            cout << "Digite a data e hora de saída do voo no formato dd/mm/aaaa HH:MM ";
            cin.ignore();
            getline(cin, auxDataSaida);
            cout << "Digite a distância do voo: ";
            cin >> auxDistancia;
            Voo* novoVoo = new Voo(auxCod, auxOrigem, auxDestino, "", auxDataSaida, auxDistancia, 0,  auxAeronave, auxPiloto, auxPiloto2);
            int escalas = novoVoo->calcularNescalas();
            novoVoo->setNEscalas(escalas);
            string dataChegada = novoVoo->calcularDataChegada();
            novoVoo->setDataHoraChegada(dataChegada);
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
            cout << "Digite o cpf do passageiro que deseja incluir nesse voo: ";       //Tem que mudar para cpf
            cin >> auxCpf;
            Passageiro *passageiro= gerenciador.procurarPassageiro(auxCpf);
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
            //gerenciador.listarPassageiros();
            gerenciador.listarPassageirosDeUmVoo(voo);
            break;
        }
        case 8:{
            gerenciador.carregarDados();
            cout << "Dados carregados!";
            break;
        }
        case 9:{
            gerenciador.salvarDados();
            cout << "Salvou os dados e saiu!";
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