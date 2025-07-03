#include<iostream>
#include "voo.h"
#include "gerenciador.h"   
#include <fstream>
#include <string>
#include <limits>
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

    gerenciador.carregarDados();//carrega os dados salvos 
    while(opc != 8){
        cout << "\n===================================\n"
             << "1- Cadastrar aeronave\n2- Cadastrar piloto\n3- Cadastrar passageiro\n"
             << "4- Criar voo\n5- Cadastrar passageiro em voo\n6- Listar voos\n"
             << "7- Listar passageiros de um voo\n"
             << "8- Gerar relatórios estatísticos\n9- Salvar dados e sair\n"
             << "===================================\n\nEscolha uma opção: ";        
        
        cin >> opc;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada inválida. Tente novamente.\n";
            continue;
        }

        switch (opc){
        case 1:{    //cadastrar aeronave
            cout << "Digite o código da aeronave: "; 
            cin.ignore();
            getline(cin,auxCod);
            if(auxCod.empty()) { cout << "Código não pode ser vazio"; break;}

            if (gerenciador.procurarAeronave(auxCod)) {
                cout << "Aeronave já cadastrada com esse código.\n"; break;
            }

            cout << "Digite o modelo da aeronave: ";
            getline(cin,auxNome);
            if (auxNome.empty()) { cout << "Modelo não pode ser vazio.\n"; break; }

            cout << "Digite a capacidade da aeronave: ";
            cin >> auxCap;
            if (cin.fail() || auxCap <= 0) {
                cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Capacidade inválida.\n"; break;
            }

            cout << "Digite a velocidade média da aeronave: ";
            cin >> auxVel;
            if (cin.fail() || auxVel <= 0) {
                cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Velocidade inválida.\n"; break;
            }

            cout << "Digite a autonomia da aeronave: ";
            cin >> auxHorasAutonomia;
            if (cin.fail() || auxHorasAutonomia <= 0) {
                cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Autonomia inválida.\n"; break;
            }

            Aeronave *novaAeronave = new Aeronave(auxCod, auxNome, auxCap, auxVel, auxHorasAutonomia);
            gerenciador.cadastrarAeronave(novaAeronave);
            cout << "\nAeronave cadastrada com sucesso!\n\n";
            gerenciador.listarAeronaves();
            break;
        }

        case 2:{    //cadastrar piloto
            cout << "Digite o Nome do piloto: ";
            cin.ignore();
            getline(cin,auxNome);
            if (auxNome.empty()) { cout << "O nome não pode ser vazio.\n"; break; }


            cout << "Digite o brevê do piloto: ";
            getline(cin,auxBreve);
            if (auxBreve.empty()) { cout << "O brevê não pode ser vazio.\n"; break; }

            if (gerenciador.procurarPiloto(auxBreve)) {
                cout << "Piloto já cadastrado com esse brevê.\n"; break;
            }

            cout << "Digite a matrícula do piloto: ";
            getline(cin,auxMatricula);
            if (auxMatricula.empty()) { cout << "A matrícula não pode ser vazia.\n"; break; }

            cout << "Digite as horas de voo do piloto: ";
            cin >> auxHorasdeVoo;
            if (auxHorasdeVoo.empty()) { cout << "As horas de voo não podem ser vazias.\n"; break; }

            Piloto *novoPiloto = new Piloto(auxNome, auxBreve, auxMatricula, auxHorasdeVoo);
            gerenciador.cadastrarPiloto(novoPiloto);
            cout << "Piloto cadastrado com sucesso!\n";
            break;
        }

        case 3:{    //cadastrar passageiro
            cout << "Digite o Nome do passageiro: ";
            cin.ignore();
            getline(cin,auxNome);
            if (auxNome.empty()) { cout << "O nome não pode ser vazio.\n"; break; }

            cout << "Digite o bilhete do passageiro: ";
            getline(cin,auxBilhete);
            if (auxBilhete.empty()) { cout << "O bilhete não pode ser vazio.\n"; break; }

            cout << "Digite o cpf do passageiro: ";
            getline(cin,auxCpf);
            if (auxCpf.empty()) { cout << "O CPF não pode ser vazio.\n"; break; }

            Passageiro *novoPassageiro = new Passageiro(auxNome, auxBilhete, auxCpf);
            gerenciador.cadastrarPassageiro(novoPassageiro);
            cout << "Passageiro cadastrado com sucesso!\n";
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
            if (!auxPiloto || !auxPiloto2) {
                cout << "Erro: piloto ou copiloto não encontrado.\n"; break;
            }
            if(auxBreve == auxBreve2){
                cout << "Erro: O brevê do piloto não pode ser igual ao do copiloto.\n"; break;
            }

            cout << "Digite o código da aeronave: ";
            getline(cin, auxCod);
            auxAeronave = gerenciador.procurarAeronave(auxCod);
            if (!auxAeronave) {
                cout << "Aeronave não encontrada.\n"; break;
            }

            // Agora cria o voo (ponteiros válidos)
            cout << "Digite o código do voo: ";
            getline(cin,auxCod);
            if (gerenciador.procurarVoo(auxCod)) {
                cout << "Voo já cadastrado com esse código.\n"; break;
            }

            cout << "Digite a origem do voo: ";
            getline(cin,auxOrigem);
            if (auxOrigem.empty()) { cout << "A origem do voo não pode ser vazia.\n"; break; }

            cout << "Digite o destino do voo: ";
            getline(cin,auxDestino);
            if (auxOrigem.empty()) { cout << "O destino do voo não pode ser vazio.\n"; break; }

            cout << "Digite a data e hora de saída do voo no formato dd/mm/aaaa HH:MM ";
            getline(cin, auxDataSaida);
            if (auxOrigem.empty()) { cout << "A hora/data do voo não pode ser vazia.\n"; break; }

            cout << "Digite a distância do voo: ";
            cin >> auxDistancia;
            if (cin.fail()) {
                cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Distância inválida.\n"; break;
            }

            Voo* novoVoo = new Voo(auxCod, auxOrigem, auxDestino, "", auxDataSaida, auxDistancia, 0,  auxAeronave, auxPiloto, auxPiloto2);
            int escalas = novoVoo->calcularNescalas();
            novoVoo->setNEscalas(escalas);
            string dataChegada = novoVoo->calcularDataChegada();
            if(dataChegada == "Data inválida"){
                delete(novoVoo);
                break;
            }
            novoVoo->setDataHoraChegada(dataChegada);
            gerenciador.cadastrarVoo(novoVoo);
            cout << "Voo criado com sucesso!\n";
            //gerenciador.listarObjetos();
            break;
        }

        case 5:{//cadastrar passageiro em voo
            cout << "Digite o codigo do voo em que deseja cadastrar um passageiro: "; 
            cin.ignore();      
            getline(cin,auxCod); 
            Voo *voo = gerenciador.procurarVoo(auxCod);
            if (!voo) { cout << "Voo não encontrado.\n"; break; }

            cout << "Digite o cpf do passageiro que deseja incluir nesse voo: ";       //Tem que mudar para cpf
            getline(cin,auxCpf);
            Passageiro *passageiro= gerenciador.procurarPassageiro(auxCpf);
            if (!passageiro) { cout << "Passageiro não encontrado.\n"; break; }

            if (!gerenciador.cadastrarPassageiroVoo(passageiro, voo)) {
                cout << "Passageiro já está no voo ou voo cheio.\n";
            } else {
                cout << "Passageiro adicionado ao voo.\n";
            }
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
            if (!voo) { cout << "Voo não encontrado.\n"; break; }
            //gerenciador.listarPassageiros();
            gerenciador.listarPassageirosDeUmVoo(voo);
            break;
        }
        case 8:{
            relatoriosEstatisticos(gerenciador);
            opc = 0;
            break;
        }
        case 9:{
            gerenciador.salvarDados();
            cout << "Salvou os dados e saiu!\n";
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
        cout << "7 - Voltar ao menu principal\n\n";
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

