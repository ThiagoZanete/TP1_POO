#include<iostream>
#include "voo.h"
#include "gerenciador.h"
int main(){
    int opc;
    Gerenciador gerenciador;
    cout << "1 - Cadastrar aereonave"<< endl;
    cin >> opc;
    Aeronave *a = new Aeronave("459", "Hurricane", 2, 270, 17);
    Passageiro *b = new Passageiro("João Voador", "voo12345", "123.456.789-10");
    Piloto *c = new Piloto("Ze do aviao", "123Ze", "4321", "60");

    gerenciador.cadastrarObjeto(a);
    gerenciador.cadastrarObjeto(b);
    gerenciador.cadastrarObjeto(c);
    gerenciador.listarObjetos();
    return 0;
}