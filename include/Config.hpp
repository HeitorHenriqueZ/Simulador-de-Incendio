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
    char vento='0';

    public:

    int getInteracoes();
    void setInteracoes(int interacoes);
    char getVento();
    void setVento(char vento);
};
#endif