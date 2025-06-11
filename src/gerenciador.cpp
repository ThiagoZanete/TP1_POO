#include "voo.h"
#include <vector>
#include "aeronave.h"
#include "gerenciador.h"


bool Gerenciador::cadastrarObjeto(Base *objeto){
    if(objeto != nullptr){
        objetosCadastrados.push_back(objeto);
        return true;
    }
    return false;
}

void Gerenciador::listarObjetos() const{
    for(const auto& obj : objetosCadastrados){
        obj->exibirDados();
        cout << "====================================="<<endl;
    }
}    

Piloto* Gerenciador::procurarPiloto(string nome){
    for(size_t i = 0; i < objetosCadastrados.size(); i++){
        if(Piloto *p = dynamic_cast<Piloto*>(objetosCadastrados[i])){
            cout << "É um piloto"<<endl;
            if(p->getnome() == nome)
                return p;
        }
    }
    cout << "Piloto não encontrado"<< endl;
    return nullptr;
}

Aeronave* Gerenciador::procurarAeronave(string nome){
    for(size_t i = 0; i < objetosCadastrados.size(); i++){
        if(Aeronave *a = dynamic_cast<Aeronave*>(objetosCadastrados[i])){
            cout << "É uma aeronave"<<endl;
            if(a->getnome() == nome)
                return a;
        }
    }
    cout << "Aeronave não encontrada"<< endl;
    return nullptr;
}

void Gerenciador::cadastrarVoo(Voo* voo){
    if(voo) voosCadastrados.push_back(voo);
}

