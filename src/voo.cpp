#include "voo.h"
#include <sstream> 
using namespace std;

// Construtor da classe Voo inicializa todos os membros com os valores recebidos
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

// Adiciona um passageiro se ainda houver vaga na aeronave
void Voo :: adicionarPassageiros(Passageiro *p){
    if(passageiros.size() < (unsigned)aeronave->getCapacidade()){  // verifica lotação
        passageiros.push_back(p);
        cout << "Adicionou: "<< p->getnome() << endl;
    }
    else
        cout<<"O voo de " << origem << " para " << destino << " está cheio."<<endl;
}

// Remove um passageiro do vetor e libera a memória
void Voo :: removerPassageiro(Passageiro *p){
    for(unsigned int i = 0; i < passageiros.size(); i++){
        if(passageiros[i]==p){
            delete passageiros[i];  // desaloca o passageiro
            passageiros.erase(passageiros.begin() + i);  // remove do vetor
            break;
        }
    }
}

// Calcula número de escalas com base na autonomia da aeronave
int Voo::calcularNescalas() {
    float distanciaKm = stof(distancia);
    float autonomiaKm = aeronave->getVelocidade() * aeronave->getHorasDeAutonomia();  // distância máxima sem reabastecer

    if (autonomiaKm <= 0) return 0;

    int escalas = static_cast<int>(distanciaKm / autonomiaKm);  // número de trechos possíveis

    if (distanciaKm > autonomiaKm * escalas)
        escalas++; // mais uma escala se a distância restante for maior que autonomia

    if (escalas > 0) escalas--; // o último trecho é a chegada, não conta como escala

    return escalas;
}

// Calcula a duração total do voo (tempo de voo + 1h por escala)
float Voo::calcularDuracao() {
    nEscalas = calcularNescalas();
    float distanciaKm = stof(distancia);
    float velocidadeKmH = aeronave->getVelocidade();

    if (velocidadeKmH <= 0) return 0;

    float duracaoBase = distanciaKm / velocidadeKmH;
    return duracaoBase + nEscalas; // adiciona 1h por escala
}

// Calcula a data/hora estimada de chegada com base na saída + duração
string Voo::calcularDataChegada() {
    std::tm tm = {};
    std::istringstream ss(dataHoraSaida);
    ss >> std::get_time(&tm, "%d/%m/%Y %H:%M");  // converte string → struct tm

    if (ss.fail()) {
        cerr << "Erro ao converter dataHoraSaida: " << dataHoraSaida << endl;
        return "Data inválida";
    }

    time_t tempoSaida = mktime(&tm);  // struct tm → time_t
    float duracaoHoras = calcularDuracao();
    tempoSaida += static_cast<int>(duracaoHoras * 3600);  // soma duração em segundos

    std::tm* chegadaTm = localtime(&tempoSaida);  // time_t → struct tm

    std::ostringstream saida;
    saida << std::put_time(chegadaTm, "%d/%m/%Y %H:%M");  // formata string

    return saida.str();
}

// Exibe os dados dos passageiros desse voo
void Voo::listarPassageirosVoo(){
    for(const auto &p : passageiros){
        p->exibirDados();
    }
}

// Serializa os dados do voo em uma linha CSV
string Voo::serializar(){
    ostringstream oss;
    oss << codigo << ","
        << origem << ","
        << destino << ","
        << dataHoraChegada << ","
        << dataHoraSaida << ","
        << distancia << ","
        << nEscalas << ","
        << aeronave->getcodigo() << ","        // Código da aeronave
        << piloto->getBreve() << ","           // Brevê do piloto
        << copiloto->getBreve() << ",";        // Brevê do copiloto
        
        // Serializa os CPFs dos passageiros separados por '|'
        for (size_t i = 0; i < passageiros.size(); ++i) {
            oss << passageiros[i]->getCpf();
            if (i < passageiros.size() - 1)
                oss << "|";
            };
    return oss.str();
}

// Desserializa uma linha CSV e cria um objeto Voo, buscando os ponteiros no Gerenciador
Voo* Voo::desserializar(const string& linha, Gerenciador& g) {
    istringstream ss(linha);
    string cod, origem, destino, dataHoraChegada, dataHoraSaida, distancia, nEscalasStr;
    string codAero, codPiloto, codCopiloto, cpfsStr;

    // Extrai os dados básicos do voo
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
    getline(ss, cpfsStr);  // lista de passageiros

    // Busca os ponteiros a partir do código
    Aeronave* a = g.procurarAeronave(codAero);
    Piloto* p1 = g.procurarPiloto(codPiloto);
    Piloto* p2 = g.procurarPiloto(codCopiloto);

    if (!a || !p1 || !p2) return nullptr;  // falha se algum ponteiro não for encontrado

    int nEscalas = stoi(nEscalasStr);  // converte para int
    Voo* v = new Voo(cod, origem, destino, dataHoraChegada, dataHoraSaida, distancia, nEscalas, a, p1, p2);

    // Adiciona os passageiros ao voo
    istringstream sp(cpfsStr);
    string cpf;
    while (getline(sp, cpf, '|')) {
        Passageiro* p = g.procurarPassageiro(cpf);
        if (p) v->adicionarPassageiros(p);
    }

    return v;
}

// Exibe os dados gerais do voo e da aeronave associada
void Voo::exibirDados(){
    cout << "\nOrigem: " << origem
         << "\nDestino: " << destino
         << "\nCódigo do Voo: " << codigo
         << "\nDataHora saída: " << dataHoraSaida
         << "\nDataHora chegada: " << dataHoraChegada <<endl;
    aeronave->exibirDados();  // Chama método de exibição da aeronave
    cout <<"\n\n";
}
