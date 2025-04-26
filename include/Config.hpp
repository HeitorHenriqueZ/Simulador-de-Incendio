#ifndef CONFIG_HPP
#define CONFIG_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Config
{
    private:

    int interacoes=1000;
    char direita='0';
    char esquerda='0';
    char baixo='0';
    char cima='0';

    public:

    int getInteracoes();
    void setInteracoes(int interacoes);
    char getEsquerda();
    void setEsquerda(char esquerda);
    char getDireita();
    void setDireita(char direita);
    char getCima();
    void setCima(char cima);
    char getBaixo();
    void setBaixo(char baixo);
};
#endif