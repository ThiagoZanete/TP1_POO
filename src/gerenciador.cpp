#include <vector>
#include <fstream>
#include <sstream>
#include "gerenciador.h"
using namespace std;

bool Gerenciador::cadastrarPiloto(Piloto *p){
    if(p != nullptr){
        pilotosCadastrados.push_back(p);
        return true;
    }
    return false;
}

bool Gerenciador::cadastrarAeronave(Aeronave *a){
    if(a != nullptr){
        aeronavesCadastradas.push_back(a);
        return true;
    }
    return false;
}

bool Gerenciador::cadastrarPassageiro(Passageiro *ps){
    if(ps != nullptr){
        passageirosCadastrados.push_back(ps);
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
    for(const auto& p : pilotosCadastrados){
        if(p->getBreve() == breve)
            return p;
    }
    cout << "Piloto não cadastrado ainda"<<endl;
    return nullptr;
}

Aeronave* Gerenciador::procurarAeronave(string cod){
    for(const auto& a : aeronavesCadastradas){
        if(a->getcodigo() == cod)
            return a;
    }
    cout << "Aeronave não cadastrada ainda"<<endl;
    return nullptr;
}

Voo* Gerenciador::procurarVoo(string codigo){
    for(const auto& v : voosCadastrados){
        if(v->getcodigo() == codigo)
            return v;
    }
    cout << "Voo não cadastrado ainda"<<endl;
    return nullptr;
}

Passageiro* Gerenciador::procurarPassageiro(string cpf){
    for(const auto& p : passageirosCadastrados){
        if(p->getCpf() == cpf)
            return p;
    }
    cout << "Passageiro não cadastrado ainda"<<endl;
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

void Gerenciador::listarPassageirosDeUmVoo(Voo *v) const{
    v->listarPassageirosVoo();
    cout << "====================================="<<endl;
}

void Gerenciador::carregarDados() {
    // 1. Carregar aeronaves
    ifstream fa("csv/aeronaves.csv");
    if (fa.is_open()) {
        string linha;
        while (getline(fa, linha)) {
            Aeronave* a = Aeronave::desserializar(linha);
            if (a != nullptr) {
                aeronavesCadastradas.push_back(a);
            }
        }
        fa.close();
    } else {
        cerr << "Erro ao abrir aeronaves.csv\n";
    }

    // 2. Carregar pessoas
    ifstream fp("csv/pessoas.csv");
    if (fp.is_open()) {
        string linha;
        while (getline(fp, linha)) {
            istringstream ss(linha);
            string tipo;
            getline(ss, tipo, ','); // PILOTO ou PASSAGEIRO

            if (tipo == "PILOTO") {
                Piloto* p = Piloto::desserializar(linha);
                if (p != nullptr) {
                    pilotosCadastrados.push_back(p);
                }
            } else if (tipo == "PASSAGEIRO") {
                Passageiro* ps = Passageiro::desserializar(linha);
                if (ps != nullptr) {
                    passageirosCadastrados.push_back(ps);
                }
            }
        }
        fp.close();
    } else {
        cerr << "Erro ao abrir pessoas.csv\n";
    }

    // 3. Carregar voos
    ifstream fv("csv/voos.csv");
    if (fv.is_open()) {
        string linha;
        while (getline(fv, linha)) {
            Voo* v = Voo::desserializar(linha, *this);
            if (v != nullptr) {
                voosCadastrados.push_back(v);
            }
        }
        fv.close();
    } else {
        cerr << "Erro ao abrir voos.csv\n";
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

