#include "voo.h"
#include <vector>
#include "aeronave.h"
#include "gerenciador.h"

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

Piloto* Gerenciador::procurarPiloto(string nome){
    for(const auto& p : pilotosCadastrados){
        if(p->getnome() == nome)
            return p;
    }
    cout << "Piloto não cadastrado ainda"<<endl;
    return nullptr;
}

Aeronave* Gerenciador::procurarAeronave(string nome){
    for(const auto& a : aeronavesCadastradas){
        if(a->getnome() == nome)
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

Passageiro* Gerenciador::procurarPassageiro(string passageiroProcurado){
    for(const auto& p : passageirosCadastrados){
        if(p->getnome() == passageiroProcurado)
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




