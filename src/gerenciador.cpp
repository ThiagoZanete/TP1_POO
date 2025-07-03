#include <fstream>
#include <sstream>
#include <algorithm> // para sort
#include "gerenciador.h"
using namespace std;

// Destrutor da classe Gerenciador
// Libera a memória de todos os objetos criados 
Gerenciador::~Gerenciador() {
    for (auto* p : pilotosCadastrados) delete p;
    for (auto* ps : passageirosCadastrados) delete ps;
    for (auto* a : aeronavesCadastradas) delete a;
    for (auto* v : voosCadastrados) delete v;
}

// Cadastra um piloto, adicionando ao vetor e ao map pra busca rápida pelo brevê
bool Gerenciador::cadastrarPiloto(Piloto *p){
    if(p != nullptr){
        pilotosCadastrados.push_back(p);
        mapaPilotos[p->getBreve()] = p; // Map que facilita procura pelo brevê
        return true;
    }
    return false;
}

// Cadastra uma aeronave, adicionando ao vetor e ao map para busca rápida pelo código
bool Gerenciador::cadastrarAeronave(Aeronave *a){
    if(a != nullptr){
        aeronavesCadastradas.push_back(a);
        mapaAeronaves[a->getcodigo()] = a; // Map que procura pelo código
        return true;
    }
    return false;
}

// Cadastra um passageiro, adicionando ao vetor e ao map para busca pelo CPF
bool Gerenciador::cadastrarPassageiro(Passageiro *ps){
    if(ps != nullptr){
        passageirosCadastrados.push_back(ps);
        mapaPassageiros[ps->getCpf()] = ps; // Map facilita procura pelo CPF
        return true;
    }
    return false;
}

// Cadastra um voo adicionando ao vetor
bool Gerenciador::cadastrarVoo(Voo* voo){
    if(voo != nullptr) {
        voosCadastrados.push_back(voo);
        return true;
    }
    return false;
}

// Adiciona um passageiro a um voo específico, e verifica se ambos são válidos
bool Gerenciador::cadastrarPassageiroVoo(Passageiro *p, Voo *v){
    if(p != nullptr && v != nullptr){
        v->adicionarPassageiros(p);
        return true;
    }
    return false;
}

// Busca um piloto no map pelo brevê 
Piloto* Gerenciador::procurarPiloto(string breve){
    auto it = mapaPilotos.find(breve);
    if (it != mapaPilotos.end())
        return it->second;  // Retorna o ponteiro do piloto
    return nullptr; // Caso não encontra
}

// Busca uma aeronave no map pelo código
Aeronave* Gerenciador::procurarAeronave(string cod){
    auto it = mapaAeronaves.find(cod);
    if (it != mapaAeronaves.end())
        return it->second; // Retorna ponteiro da aeronave
    return nullptr;
}

// Busca um voo percorrendo o vetor e comparando código
Voo* Gerenciador::procurarVoo(string codigo){
    for(const auto& v : voosCadastrados){
        if(v->getcodigo() == codigo)
            return v;
    }
    return nullptr;
}

// Busca um passageiro no map pelo CPF (chave)
Passageiro* Gerenciador::procurarPassageiro(string cpf) const{
    auto it = mapaPassageiros.find(cpf);
    if (it != mapaPassageiros.end())
        return it->second;
    return nullptr;
}

// Lista os dados de todos os voos cadastrados, chamando método da classe Voo
void Gerenciador::listarVoos() const{
    for(const auto& voo : voosCadastrados){
        voo->exibirDados();
        cout << "====================================="<<endl;
    }
}    

// Lista os dados de todas as aeronaves cadastradas
void Gerenciador::listarAeronaves() const{
    for(const auto& a : aeronavesCadastradas){
        a->exibirDados();
        cout << "====================================="<<endl;
    }
} 

// Lista os dados de todos os passageiros cadastrados
void Gerenciador::listarPassageiros() const{
    for(const auto& p : passageirosCadastrados){
        p->exibirDados();
        cout << "====================================="<<endl;
    }
} 

// Lista os passageiros de um voo específico
void Gerenciador::listarPassageirosDeUmVoo(Voo *v) const{
    v->listarPassageirosVoo();
    cout << "====================================="<<endl;
}

// Retorna a quantidade total de voos cadastrados
int Gerenciador::contarVoos() const{
    return voosCadastrados.size();
}

// Calcula a média de passageiros por voo somando passageiros de todos os voos
int Gerenciador::mediaPassageirosVoo() const{
    int totalGeralPas = 0;
    for(const auto & p : voosCadastrados){
        totalGeralPas += p->getPassageiros().size(); // soma passageiros de cada voo
    }
    if(contarVoos()<=0) return 0;  // evita divisão por zero
    return totalGeralPas / contarVoos();  // calcula média
}

// Retorna um vetor ordenado com as aeronaves mais usadas e o número de vezes que foram usadas
vector<pair<string, int>> Gerenciador::aeronavesMaisUsadas() const {
    map<string, int> contagem;

    // Conta quantas vezes cada aeronave aparece nos voos
    for (const auto& v : voosCadastrados) {
        string cod = v->getAeronave()->getcodigo();
        contagem[cod]++;
    }

    // Converte o map em vetor para permitir ordenação
    vector<pair<string, int>> vetorContagem(contagem.begin(), contagem.end());

    // Ordena decrescente pelo número de vezes usada
    sort(vetorContagem.begin(), vetorContagem.end(), [](auto& a, auto& b) { return a.second > b.second; });

    return vetorContagem;
}

// Retorna map de passageiros frequentes, ou seja, que participaram de mais de um voo
map<Passageiro*, int> Gerenciador::passageirosFrequentes() const {
    map<string, int> contagem;  // Mapa CPF → número de voos

    // Conta o número de voos para cada passageiro pelos voos cadastrados
    for (const auto& v : voosCadastrados) {
        for (Passageiro* p : v->getPassageiros()) {
            contagem[p->getCpf()]++;
        }
    }

    map<Passageiro*, int> resultados;
    // Seleciona apenas passageiros com mais de um voo
    for (auto& par : contagem) {
        if (par.second > 1) {
            Passageiro* p = procurarPassageiro(par.first);
            if (p) resultados[p] = par.second;
        }
    }

    return resultados;
}

// Retorna vetor com voos que possuem ocupação igual ou maior que 90% da capacidade da aeronave
vector<Voo*> Gerenciador::voosAltaLotacao() const {
    std::vector<Voo*> resultado;

    for (auto& v : voosCadastrados) {
        int capacidade = v->getAeronave()->getCapacidade();
        int ocupacao = v->getPassageiros().size();
        // Considera apenas voos com capacidade válida e ocupação >= 90%
        if (capacidade > 0 && ocupacao >= capacidade * 0.9) {
            resultado.push_back(v);
        }
    }
    return resultado;
}

// Retorna um mapa com a soma da distância total percorrida por cada aeronave
map<string, float> Gerenciador::distanciaTotalPorAeronave() const {
    std::map<std::string, float> distancias;

    for (auto& v : voosCadastrados) {
        std::string cod = v->getAeronave()->getcodigo();
        float dist = std::stof(v->getDistancia());  // Converte distância (string) para float
        distancias[cod] += dist;  // Acumula distância por aeronave
    }
    return distancias;
}

// Carrega os dados de arquivos CSV para memória, em ordem: pessoas, aeronaves, voos
void Gerenciador::carregarDados() {
    // Carrega pilotos e passageiros de pessoas.csv
    ifstream fp("csv/pessoas.csv");
    if (fp.is_open()) {
        string linha;
        while (getline(fp, linha)) {
            istringstream ss(linha);
            string tipo;
            getline(ss, tipo, ',');

            if (tipo == "PILOTO") {
                Piloto* p = Piloto::desserializar(linha);
                if (p) cadastrarPiloto(p);
            } else if (tipo == "PASSAGEIRO") {
                Passageiro* ps = Passageiro::desserializar(linha);
                if (ps) cadastrarPassageiro(ps);
            }
        }
        fp.close();
    }
    // Carrega aeronaves de aeronaves.csv
    ifstream fa("csv/aeronaves.csv");
    if (fa.is_open()) {
        string linha;
        while (getline(fa, linha)) {
            Aeronave* a = Aeronave::desserializar(linha);
            if (a) cadastrarAeronave(a);
        }
        fa.close();
    }
    // Carrega voos de voos.csv, passando referência para buscar pilotos e aeronaves
    ifstream fv("csv/voos.csv");
    if (fv.is_open()) {
        string linha;
        while (getline(fv, linha)) {
            Voo* v = Voo::desserializar(linha, *this); // precisa acessar mapas para associar dados
            if (v) cadastrarVoo(v);
            //exit(0);
        }
        fv.close();
    }
}

// Salva os dados da memória para arquivos CSV em ordem: aeronaves, pessoas, voos
void Gerenciador::salvarDados() {
    // Salva aeronaves
    ofstream fa("csv/aeronaves.csv");
    if (!fa.is_open()) {
        cerr << "Erro ao abrir aeronaves.csv\n";
        return;
    }
    for (const auto& a : aeronavesCadastradas) {
        fa << a->serializar() << '\n';  // Grava cada aeronave em linha CSV
    }

    // Salva pessoas (pilotos e passageiros)
    ofstream fp("csv/pessoas.csv");
    if (!fp.is_open()) {
        cerr << "Erro ao abrir pessoas.csv\n";
        return;
    }
    for (const auto& p : pilotosCadastrados) {
        fp << p->serializar() << '\n';  // Grava pilotos
    }
    for (const auto& p : passageirosCadastrados) {
        fp << p->serializar() << '\n';  // Grava passageiros
    }

    // Salva voos
    ofstream fv("csv/voos.csv");
    if (!fv.is_open()) {
        cerr << "Erro ao abrir voos.csv\n";
        return;
    }
    for (const auto& v : voosCadastrados) {
        fv << v->serializar() << '\n';  // Grava cada voo
    }
}
