#include "voo.h"
#include <sstream>
using namespace std;
Voo::Voo(string codigo, string origem, string destino,string datachegada, string datasaida, string distancia, int nEscalas, Aeronave *aeronave, Piloto *piloto, Piloto *copiloto):
    codigo(codigo),
    origem(origem),
    destino(destino),
    dataHoraChegada(datachegada),
    dataHoraSaida(datasaida),
    distancia(distancia),
    nEscalas(nEscalas),
    aeronave(aeronave),
    piloto(piloto),
    copiloto(copiloto){}


void Voo :: adicionarPassageiros(Passageiro *p){
    if(passageiros.size() < (unsigned)aeronave->getCapacidade()){
        passageiros.push_back(p);
        cout << "Adicionou: "<< p->getnome() << endl;
    }
    else
        cout<<"O voo de " << origem << " para " << destino << " está cheio."<<endl;
}

void Voo :: removerPassageiro(Passageiro *p){
    for(unsigned int i = 0; i < passageiros.size(); i++){
        if(passageiros[i]==p){
            delete passageiros[i];
            passageiros.erase(passageiros.begin() + i);
            break;
        }
    }
}

int Voo::calcularNescalas() {
    float distanciaKm = stof(distancia);
    float autonomiaKm = aeronave->getHorasDeAutonomia();

    if (autonomiaKm <= 0) return 0;

    int escalas = distanciaKm / autonomiaKm;
    if (distanciaKm > autonomiaKm && distanciaKm > escalas * autonomiaKm)
        escalas++; // uma escala extra se houver sobra
    return escalas;
}

float Voo::calcularDuracao() {
    nEscalas = calcularNescalas();
    float distanciaKm = stof(distancia);
    float velocidadeKmH = aeronave->getVelocidade();

    if (velocidadeKmH <= 0) return 0;

    float duracaoBase = distanciaKm / velocidadeKmH;
    return duracaoBase + nEscalas; // 1h por escala
}

string Voo::calcularDataChegada() {
    std::tm tm = {};
    std::istringstream ss(dataHoraSaida);
    //cerr << "DEBUG: dataHoraSaida recebida -> [" << dataHoraSaida << "]" << endl;
    ss >> std::get_time(&tm, "%d/%m/%Y %H:%M");

    if (ss.fail()) {
        cerr << "Erro ao converter dataHoraSaida: " << dataHoraSaida << endl;
        return "Data inválida";
    }

    // Transforma para time_t e adiciona a duração
    time_t tempoSaida = mktime(&tm);
    float duracaoHoras = calcularDuracao();
    tempoSaida += static_cast<int>(duracaoHoras * 3600);

    // Converte de volta para struct tm
    std::tm* chegadaTm = localtime(&tempoSaida);

    // Formata como string no mesmo estilo
    std::ostringstream saida;
    saida << std::put_time(chegadaTm, "%d/%m/%Y %H:%M");

    return saida.str();
}



void Voo::listarPassageirosVoo(){
    for(const auto &p : passageiros){
        p->exibirDados();
    }
}


string Voo::serializar(){
    ostringstream oss;
    oss << codigo << ","
        << origem << ","
        << destino << ","
        << dataHoraChegada << ","
        << dataHoraSaida << ","
        << distancia << ","
        << nEscalas << ","
        << aeronave->getcodigo() << ","
        << piloto->getBreve() << ","
        << copiloto->getBreve() << ",";
        
        // Lista de CPFs dos passageiros separados por '|'
        for (size_t i = 0; i < passageiros.size(); ++i) {
            oss << passageiros[i]->getCpf();
            if (i < passageiros.size() - 1)
                oss << "|";
            };
    return oss.str();
}

Voo* Voo::desserializar(const string& linha, Gerenciador& g) {
    istringstream ss(linha);
    string cod, origem, destino, dataHoraChegada, dataHoraSaida, distancia, nEscalasStr;
    string codAero, codPiloto, codCopiloto, cpfsStr;

    getline(ss, cod, ',');
    getline(ss, origem, ',');
    getline(ss, destino, ',');
    getline(ss, dataHoraChegada, ',');
    getline(ss, dataHoraSaida, ',');
    getline(ss, distancia, ',');
    getline(ss, nEscalasStr, ',');
    getline(ss, codAero, ',');
    getline(ss, codPiloto, ',');
    getline(ss, codCopiloto, ',');
    getline(ss, cpfsStr);  // resto da linha

    Aeronave* a = g.procurarAeronave(codAero);
    Piloto* p1 = g.procurarPiloto(codPiloto);
    Piloto* p2 = g.procurarPiloto(codCopiloto);

    if (!a || !p1 || !p2) return nullptr;

    int nEscalas = stoi(nEscalasStr);
    Voo* v = new Voo(cod, origem, destino, dataHoraChegada, dataHoraSaida, distancia, nEscalas, a, p1, p2);

    // Processar passageiros
    istringstream sp(cpfsStr);
    string cpf;
    while (getline(sp, cpf, '|')) {
        Passageiro* p = g.procurarPassageiro(cpf);
        if (p) v->adicionarPassageiros(p);
    }

    return v;
}

void Voo::exibirDados(){
    cout << "\nOrigem: " << origem << "\nDestino: " << destino << "\nCódigo do Voo: " << codigo << "\nDataHora saída: " << dataHoraSaida << "\nDataHora chegada: " << dataHoraChegada <<endl;
    aeronave->exibirDados();  
    cout <<"\n\n";
}