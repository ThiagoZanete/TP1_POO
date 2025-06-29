#include <fstream>
#include <sstream>
#include <algorithm> // para sort
#include "gerenciador.h"
using namespace std;

Gerenciador::~Gerenciador() {
    for (auto* p : pilotosCadastrados) delete p;
    for (auto* ps : passageirosCadastrados) delete ps;
    for (auto* a : aeronavesCadastradas) delete a;
    for (auto* v : voosCadastrados) delete v;
}

bool Gerenciador::cadastrarPiloto(Piloto *p){
    if(p != nullptr){
        pilotosCadastrados.push_back(p);
        mapaPilotos[p->getBreve()] = p;
        return true;
    }
    return false;
}


bool Gerenciador::cadastrarAeronave(Aeronave *a){
    if(a != nullptr){
        aeronavesCadastradas.push_back(a);
        mapaAeronaves[a->getcodigo()] = a;
        return true;
    }
    return false;
}

bool Gerenciador::cadastrarPassageiro(Passageiro *ps){
    if(ps != nullptr){
        passageirosCadastrados.push_back(ps);
        mapaPassageiros[ps->getCpf()] = ps;
        return true;
    }
    return false;
}

bool Gerenciador::cadastrarVoo(Voo* voo){
    if(voo != nullptr) {
        voosCadastrados.push_back(voo);
        return true;
    }
    return false;
}

bool Gerenciador::cadastrarPassageiroVoo(Passageiro *p, Voo *v){
    if(p != nullptr && v != nullptr){
        v->adicionarPassageiros(p);
        return true;
    }
    return false;
}

Piloto* Gerenciador::procurarPiloto(string breve){
    auto it = mapaPilotos.find(breve);
    if (it != mapaPilotos.end())
        return it->second;

    //cout << "Piloto não cadastrado ainda" << endl;
    return nullptr;
}

Aeronave* Gerenciador::procurarAeronave(string cod){
    auto it = mapaAeronaves.find(cod);
    if (it != mapaAeronaves.end())
        return it->second;

    //cout << "Aeronave não cadastrada ainda" << endl;
    return nullptr;
}

Voo* Gerenciador::procurarVoo(string codigo){
    for(const auto& v : voosCadastrados){
        if(v->getcodigo() == codigo)
            return v;
    }
    //cout << "Voo não cadastrado ainda"<<endl;
    return nullptr;
}

Passageiro* Gerenciador::procurarPassageiro(string cpf) const{
    auto it = mapaPassageiros.find(cpf);
    if (it != mapaPassageiros.end())
        return it->second;

    //cout << "Passageiro não cadastrado ainda" << endl;
    return nullptr;
}


void Gerenciador::listarVoos() const{
    for(const auto& voo : voosCadastrados){
        voo->exibirDados();
        cout << "====================================="<<endl;
    }
}    

void Gerenciador::listarAeronaves() const{
    for(const auto& a : aeronavesCadastradas){
        a->exibirDados();
        cout << "====================================="<<endl;
    }
} 

void Gerenciador::listarPassageiros() const{
    for(const auto& p : passageirosCadastrados){
        p->exibirDados();
        cout << "====================================="<<endl;
    }
} 

void Gerenciador::listarPassageirosDeUmVoo(Voo *v) const{
    v->listarPassageirosVoo();
    cout << "====================================="<<endl;
}

int Gerenciador::contarVoos() const{
    return voosCadastrados.size();
}

int Gerenciador::mediaPassageirosVoo() const{
    int totalGeralPas = 0;
    for(const auto & p : voosCadastrados){
        totalGeralPas += p->getPassageiros().size();//conta os passageiros de cada voo
    }
    if(contarVoos()<=0) return 0;
    return totalGeralPas / contarVoos();
}


vector<pair<string, int>> Gerenciador::aeronavesMaisUsadas() const {//retorna um vector de pares de aeronave (código, quant uso)
    map<string, int> contagem;

    for (const auto& v : voosCadastrados) {
        string cod = v->getAeronave()->getcodigo();
        contagem[cod]++;
    }

    // Transforma o map em vector para ordenar
    vector<pair<string, int>> vetorContagem(contagem.begin(), contagem.end());

    // Ordena decrescente pela quantidade
    sort(vetorContagem.begin(), vetorContagem.end(),
              [](auto& a, auto& b) { return a.second > b.second; });

    return vetorContagem;
}

map<Passageiro*, int> Gerenciador::passageirosFrequentes() const {
    map<string, int> contagem;  // CPF → qtd voos

    for (const auto& v : voosCadastrados) {
        for (Passageiro* p : v->getPassageiros()) {
            contagem[p->getCpf()]++;//passa para o map o cpf e o ++ é a contagem de vezes que esse passageiro aparece
        }
    }

    map<Passageiro*, int> resultados;
    for (auto& par : contagem) {
        if (par.second > 1) {
            Passageiro* p = procurarPassageiro(par.first);
            if (p) resultados[p] = par.second;
        }
    }

    return resultados;
}

vector<Voo*> Gerenciador::voosAltaLotacao() const {
    std::vector<Voo*> resultado;

    for (auto& v : voosCadastrados) {
        int capacidade = v->getAeronave()->getCapacidade();
        int ocupacao = v->getPassageiros().size();
        if (capacidade > 0 && ocupacao >= capacidade * 0.9) {
            resultado.push_back(v);
        }
    }
    return resultado;
}

map<string, float> Gerenciador::distanciaTotalPorAeronave() const {
    std::map<std::string, float> distancias;

    for (auto& v : voosCadastrados) {
        std::string cod = v->getAeronave()->getcodigo();
        float dist = std::stof(v->getDistancia());  // sua distância é string, converta
        distancias[cod] += dist;
    }
    return distancias;
}























void Gerenciador::carregarDados() {
    // 1. Carregar pessoas PRIMEIRO (pilotos e passageiros)
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

    // 2. Carregar aeronaves DEPOIS das pessoas
    ifstream fa("csv/aeronaves.csv");
    if (fa.is_open()) {
        string linha;
        while (getline(fa, linha)) {
            Aeronave* a = Aeronave::desserializar(linha);
            if (a) cadastrarAeronave(a);
        }
        fa.close();
    }

    // 3. Carregar voos POR ÚLTIMO (dependem de pilotos e aeronaves)
    ifstream fv("csv/voos.csv");
    if (fv.is_open()) {
        string linha;
        while (getline(fv, linha)) {
            Voo* v = Voo::desserializar(linha, *this);
            if (v) cadastrarVoo(v);
        }
        fv.close();
    }
}

void Gerenciador::salvarDados() {
    // 1. Salva aeronaves
    ofstream fa("csv/aeronaves.csv");
    if (!fa.is_open()) {
        cerr << "Erro ao abrir aeronaves.csv\n";
        return;
    }
    for (const auto& a : aeronavesCadastradas) {
        fa << a->serializar() << '\n';
    }

    // 2. Salva pessoas (pilotos + passageiros)
    ofstream fp("csv/pessoas.csv");
    if (!fp.is_open()) {
        cerr << "Erro ao abrir pessoas.csv\n";
        return;
    }
    for (const auto& p : pilotosCadastrados) {
        fp << p->serializar() << '\n';
    }
    for (const auto& p : passageirosCadastrados) {
        fp << p->serializar() << '\n';
    }

    // 3. Salva voos
    ofstream fv("csv/voos.csv");
    if (!fv.is_open()) {
        cerr << "Erro ao abrir voos.csv\n";
        return;
    }
    for (const auto& v : voosCadastrados) {
        fv << v->serializar() << '\n';
    }
}

