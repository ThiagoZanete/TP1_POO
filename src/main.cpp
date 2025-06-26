#include<iostream>
#include "voo.h"
#include "gerenciador.h"   
#include <fstream>
#include <string>
void relatoriosEstatisticos(const Gerenciador& gerenciador);
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
        cout << "\n===================================\n1- Cadastrar aereonave\n2- Cadastrar Piloto\n3- Cadastrar Passageiro\n4- Criar Voo\n5- Cadastrar passageiro em voo\n6- Listar Voos\n7- Listar passageiros de um voo\n8- Carregar os dados anteriores\n9- Salvar dados e sair\n10- Gerar Relatórios estatísticos\n===================================\n\nEscolha uma opção seu gay: "<< endl;
        cin >> opc;
        switch (opc){
        case 1:{    //cadastrar aeronave
            cout << "Digite o código da aeronave: "; 
            cin.ignore();
            getline(cin,auxCod);
            cout << "Digite o modelo da aeronave: ";
            getline(cin,auxNome); 
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
            cin.ignore();
            getline(cin,auxNome);
            cout << "Digite o brevê do piloto: ";
            getline(cin,auxBreve);
            cout << "Digite a matrícula do piloto: ";
            getline(cin,auxMatricula);
            cout << "Digite as horas de voo do piloto: ";
            cin >> auxHorasdeVoo;
            Piloto *novoPiloto = new Piloto(auxNome, auxBreve, auxMatricula, auxHorasdeVoo);
            gerenciador.cadastrarPiloto(novoPiloto);
            break;
        }
        case 3:{    //cadastrar passageiro
            cout << "Digite o Nome do passageiro: ";
            cin.ignore();
            getline(cin,auxNome);
            cout << "Digite o bilhete do passageiro: ";
            getline(cin,auxBilhete);
            cout << "Digite o cpf do passageiro: ";
            getline(cin,auxCpf);
            Passageiro *novoPassageiro = new Passageiro(auxNome, auxBilhete, auxCpf);
            gerenciador.cadastrarPassageiro(novoPassageiro);
            break;
        }
        case 4:{    //criar Voo
            cout << "Digite o brevê do piloto: ";
            cin.ignore();
            getline(cin,auxBreve);
            cout << "Digite o brevê do copiloto: ";         //Tem que mudar para o brevê
            getline(cin,auxBreve2);
            auxPiloto = gerenciador.procurarPiloto(auxBreve);
            auxPiloto2 = gerenciador.procurarPiloto(auxBreve2);
            if(!auxPiloto || !auxPiloto2)
                break;
            cout << "Digite o código da aeronave: ";                      //Tem que mudar para o código
            getline(cin,auxCod);
            auxAeronave = gerenciador.procurarAeronave(auxCod);
            if(!auxAeronave)
                break;
            // Agora cria o voo (ponteiros válidos)
            cout << "Digite o código do voo: ";
            getline(cin,auxCod);
            cout << "Digite a origem do voo: ";
            getline(cin,auxOrigem);
            cout << "Digite o destino do voo: ";
            getline(cin,auxDestino);
            cout << "Digite a data e hora de saída do voo no formato dd/mm/aaaa HH:MM ";
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
            cin.ignore();      
            getline(cin,auxCod); 
            Voo *voo = gerenciador.procurarVoo(auxCod);
            if(!voo)//não achou
                break;
            cout << "Digite o cpf do passageiro que deseja incluir nesse voo: ";       //Tem que mudar para cpf
            getline(cin,auxCpf);
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
            cin.ignore();
            getline(cin,auxCod);
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
        case 10:{//gerar relatórios e estatísticas
            relatoriosEstatisticos(gerenciador);
            break;
        }
        default:
            cout << "Caso Default"<<endl;
            break;
        }
    }
    return 0;
}


void relatoriosEstatisticos(const Gerenciador& gerenciador) {
    int opc = 0;
    do {
        cout << "\n==== Menu de Relatórios Estatísticos ====\n";
        cout << "1 - Número total de voos cadastrados\n";
        cout << "2 - Média de passageiros por voo\n";
        cout << "3 - Aeronaves mais utilizadas\n";
        cout << "4 - Passageiros mais frequentes\n";
        cout << "5 - Voos com alta lotação (>=90% capacidade)\n";
        cout << "6 - Distância percorrida por cada aeronave\n";
        cout << "7 - Voltar ao menu principal\n";
        cout << "Escolha uma opção: ";
        cin >> opc;
        cin.ignore();  // limpa o '\n' do buffer

        switch(opc) {
            case 1: {
                cout << "Número total de voos cadastrados: " << gerenciador.contarVoos() << "\n\n";
                break;
            }
            case 2: {
                cout << "Média de passageiros por voo: " << gerenciador.mediaPassageirosVoo() << "\n\n";
                break;
            }
            case 3: {
                cout << "Aeronaves mais utilizadas:\n";
                auto aeronaves = gerenciador.aeronavesMaisUsadas();
                for (const auto& par : aeronaves){
                    cout << "Aeronave: " << par.first << " - Vezes usada: " << par.second << endl;
                }
                cout << endl;
                break;
            }
            case 4: {
                cout << "Passageiros mais frequentes:\n";
                auto passageirosFrequentes = gerenciador.passageirosFrequentes();
                for (const auto& par : passageirosFrequentes) {
                    Passageiro* p = par.first;  // ponteiro para passageiro
                    int frequencia = par.second; // número de voos
                    cout << "Passageiro: " << p->getnome() << " (CPF: " << p->getCpf() << ") - Voos: " << frequencia << "\n";
                }
                cout << endl;
                break;
            }
            case 5: {
                cout << "Voos com alta lotação (>=90% capacidade):\n";
                auto voosLotados = gerenciador.voosAltaLotacao();
                for (auto* v : voosLotados){
                    v->exibirDados();
                    cout << "--------------------------\n";
                }
                cout << endl;
                break;
            }
            case 6: {
                cout << "Distância percorrida por cada aeronave:\n";
                auto distAero = gerenciador.distanciaTotalPorAeronave();
                for (const auto& par : distAero){
                    cout << "Aeronave: " << par.first << " - Distância percorrida: " << par.second << " km\n";
                }
                cout << endl;
                break;
            }
            case 7: {
                cout << "Voltando ao menu principal...\n";
                break;
            }
            default: {
                cout << "Opção inválida! Tente novamente.\n";
            }
        }
        
        // Perguntar se quer salvar em arquivo (exceto opção 7)
        if (opc >=1 && opc <=6) {
            cout << "Deseja salvar esse relatório em arquivo? (s/n): ";
            char salvar;
            cin >> salvar;
            cin.ignore();
            if (salvar == 's' || salvar == 'S') {
                string nomeArquivo;
                switch(opc) {
                    case 1: nomeArquivo = "relatorio_total_voos.txt"; break;
                    case 2: nomeArquivo = "relatorio_media_passageiros.txt"; break;
                    case 3: nomeArquivo = "relatorio_aeronaves_mais_usadas.txt"; break;
                    case 4: nomeArquivo = "relatorio_passageiros_frequentes.txt"; break;
                    case 5: nomeArquivo = "relatorio_voos_alta_lotacao.txt"; break;
                    case 6: nomeArquivo = "relatorio_distancia_aeronaves.txt"; break;
                }

                ofstream arquivo(nomeArquivo);
                if (!arquivo.is_open()) {
                    cout << "Erro ao abrir arquivo para salvar!\n";
                    break;
                }

                switch(opc) {
                    case 1:
                        arquivo << "Número total de voos cadastrados: " << gerenciador.contarVoos() << "\n";
                        break;
                    case 2:
                        arquivo << "Média de passageiros por voo: " << gerenciador.mediaPassageirosVoo() << "\n";
                        break;
                    case 3: {
                        auto aeronaves = gerenciador.aeronavesMaisUsadas();
                        arquivo << "Aeronaves mais utilizadas:\n";
                        for (const auto& par : aeronaves){
                            arquivo << "Aeronave: " << par.first << " - Vezes usada: " << par.second << "\n";
                        }
                        break;
                    }
                    case 4: {
                        auto passageirosFrequentes = gerenciador.passageirosFrequentes();
                        arquivo << "Passageiros mais frequentes:\n";
                        for (const auto& par : passageirosFrequentes) {
                            Passageiro* p = par.first;  // ponteiro para passageiro
                            int frequencia = par.second; // número de voos

                            cout << "Passageiro: " << p->getnome() << " (CPF: " << p->getCpf() << ") - Voos: " << frequencia << "\n";
                        }
                        break;
                    }
                    case 5: {
                        auto voosLotados = gerenciador.voosAltaLotacao();
                        arquivo << "Voos com alta lotação (>=90% capacidade):\n";
                        for (auto* v : voosLotados){
                            // Você pode criar uma função para serializar dados do voo como texto
                            arquivo << "Voo: " << v->getcodigo() << " - Origem: " << v->getOrigem() << " - Destino: " << v->getDestino() << "\n";
                        }
                        break;
                    }
                    case 6: {
                        auto distAero = gerenciador.distanciaTotalPorAeronave();
                        arquivo << "Distância percorrida por cada aeronave:\n";
                        for (const auto& par : distAero){
                            arquivo << "Aeronave: " << par.first << " - Distância percorrida: " << par.second << " km\n";
                        }
                        break;
                    }
                }

                arquivo.close();
                cout << "Relatório salvo em " << nomeArquivo << "\n\n";
            }
        }

    } while(opc != 7);
}

