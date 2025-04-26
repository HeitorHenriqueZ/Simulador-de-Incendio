#ifndef FUNCOES_HPP
#define FUNCOES_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Funcoes 
{
    private:

    int linhas;
    int colunas;
    int posicaoInicialFX;
    int posicaoInicialFY;
    vector<std::vector<int>> matriz;
    vector<std::vector<bool>> visitados;
    public:
    
    void lerArquivo();
    int getPX();
    void setPX(int i);
    int getPY();
    void setPY(int j);
    vector<std::vector<int>> getMatriz(); 
    void setMatriz(vector<vector<int>>& novaMatriz);
    int getLinhas();
    int getColunas();
    void setVisitados(vector<std::vector<bool>> visitados);
    vector<std::vector<bool>>& getVisitados();
    void printArquivo(vector<std::vector<int>> matriz);
    void printArquivoComAnimal(vector<vector<int>> matriz, int animalX, int animalY, ofstream& arquivoSaida);
    void printFinal(int iteracao, int passos, int vivo);
};
#endif 