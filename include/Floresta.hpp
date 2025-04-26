#ifndef FLORESTA_HPP
#define FLORESTA_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Floresta 
{
    private:

    int linhas;
    int colunas;
    int posicaoInicialFX;
    int posicaoInicialFY;
    int posicaoInicialAX;
    int posicaoInicialAY;
    vector<std::vector<int>> matriz;
    vector<std::vector<bool>> visitados;
    int animalX, animalY;
    int passos = 0;
    int encontrouAgua = 0;
    int iteracaoPreso = -1;
    bool vivo = true;

    public:

    Floresta(int linhas, int colunas, int posicaoInicialFX,int posicaoInicialFY, vector<std::vector<int>> matriz, vector<std::vector<bool>>& visitados);
    int getPX();
    void setPX(int i);
    int getPY();
    void setPY(int j);
    vector<std::vector<int>> getMatriz();
    void espalharFogo(char vento);
    bool temFogo();
    vector<std::vector<bool>> getVisitados();
    void setVisitados(vector<std::vector<bool>> visitados);
    void acharPosicaoInicial();
    void andarAnimal();
    int getPassos();
    int getEncontrouAgua();
    int getIteracaoPreso();
    int getAnimalX();
    int getAnimalY();
    bool getVivo();
    void setVivo(bool vivo);
    bool segundaChance();
};
#endif 