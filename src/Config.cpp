#include "Config.hpp"

int Config::getInteracoes()
{
    return interacoes;
}

void Config::setInteracoes(int interacoes)
{
    this->interacoes=interacoes;
}

char Config::getEsquerda()
{
    return esquerda;
}

void Config::setEsquerda(char esquerda)
{
    this->esquerda=esquerda;
}

char Config::getDireita()
{
    return direita;
}

void Config::setDireita(char direita)    
{
    this->direita=direita;
}

char Config::getCima()
{
    return cima;
}

void Config::setCima(char cima)
{
    this->cima=cima;
}

char Config::getBaixo()
{
    return baixo;
}    

void Config::setBaixo(char baixo)
{
    this->baixo=baixo;
}