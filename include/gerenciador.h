#ifndef GERENCIADOR_H
#define GERENCIADOR_H
#include "aeronave.h"
#include "base.h"
#include <vector>
using namespace std;
class Gerenciador{
    vector <Base*> objetosCadastrados;
public:
    bool cadastrarObjeto(Base *obj);
    void listarObjetos() const;
};

#endif