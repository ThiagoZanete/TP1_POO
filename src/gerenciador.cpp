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

Piloto* Gerenciador::procurarPiloto(string pilotoProcurado) {
    for (const auto& obj : objetosCadastrados) {
        // Tenta converter para Piloto*
        Piloto* piloto = dynamic_cast<Piloto*>(obj);
        if (piloto != nullptr) {
            if (piloto->getnome() == pilotoProcurado) {
                return piloto;  // retorna o ponteiro encontrado
            }
        }
    }
    return nullptr;  // não encontrou
}


Aeronave* Gerenciador::procurarAeronave(string aeronaveProcurada) {
    for (const auto& obj : objetosCadastrados) {
        // Tenta converter para Aeronave*
        Aeronave* aeronave = dynamic_cast<Aeronave*>(obj);
        if (aeronave != nullptr) {
            if (aeronave->getCodigo() == aeronaveProcurada) {
                cout << aeronave->getnome();
                return aeronave;  // retorna o ponteiro encontrado
            }
        }
    }
    return nullptr;  // não encontrou
}


void Gerenciador::listarObjetos() const{
    for(const auto& obj : objetosCadastrados){
        obj->exibirDados();
        cout << "====================================="<<endl;
    }
}        

void Gerenciador::cadastrarVoo(Voo* voo){
    if(voo) voosCadastrados.push_back(voo);
}

