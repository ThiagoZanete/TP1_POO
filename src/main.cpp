#include<iostream>
#include "voo.h"
#include "gerenciador.h"
int main(){
    int opc;
    Gerenciador gerenciador;
    cout << "1 - Cadastrar aereonave"<< endl;
    cin >> opc;
    Aeronave *a = new Aeronave("459", "Hurricane", 2, 270, 17);
    Aeronave *b = new Aeronave("451", "Spitfire", 1, 23, 17);
    Aeronave *c = new Aeronave("123", "Boeing", 200, 270, 17);

    gerenciador.cadastrarObjeto(a);
    gerenciador.cadastrarObjeto(b);
    gerenciador.cadastrarObjeto(c);
    gerenciador.listarObjetos();
    return 0;
}