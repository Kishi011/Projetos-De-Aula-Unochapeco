#include <iostream>

using std::string;

class Carro {
    private:
        string cor;
        int ano;
        double velocidade;
        string combustivel;

    public: Carro(){};

    public:
        string getCor() {
            return this->cor;
        }

        void setCor(string cor) {
            this->cor = cor;
            return;
        }

        int getAno() {
            return this->ano;
        }

        void setAno(int ano) {
            this->ano = ano;
            return;
        }

        double getVelocidade() {
            return this->velocidade;
        }

        void setVelocidade(double velocidade) {
            this->velocidade = velocidade;
            return;
        }

        string getCombustivel() {
            return this->combustivel;
        }

        void setCombustivel(string combustivel) {
            this->combustivel = combustivel;
            return;
        }

};