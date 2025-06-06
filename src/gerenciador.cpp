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
