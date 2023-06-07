#include <iostream>
#include <Carro.class.h>

using std::string, std::cout, std::cin;

int main() {
    Carro *c  = NULL;
    string cor;
    int ano;
    double velocidade;
    string combustivel;
    for(int i = 0; i < 2; i++) {
        c = new Carro();
        cout<<"Digite a cor: ";
        cin>>cor;
        c->setCor(cor);

        cout<<"Digite o ano: ";
        cin>>ano;
        c->setAno(ano);

        cout<<"Digite a velocidade: ";
        cin>>velocidade;
        c->setVelocidade(velocidade);

        cout<<"Digite o tipo de combustivel: ";
        cin>>combustivel;
        c->setCombustivel(combustivel);

        cout<<"Carro "<<i+1<<":\n";
        cout<<"Cor: "<<c->getCor()<<":\n";
        cout<<"Ano: "<<c->getAno()<<":\n";
        cout<<"Velocidade: "<<c->getVelocidade()<<":\n";
        cout<<"Tipo de Combustivel: "<<c->getCombustivel()<<":\n";
    }
    return 0;
}
