#include <iostream>
#include "Funcoes.hpp"
#include "Floresta.hpp"
#include "Config.hpp"


int main()
{
    Funcoes funcoes;
    Config config;
    funcoes.lerArquivo();
    Floresta* floresta = new Floresta(funcoes.getLinhas(), funcoes.getColunas(), funcoes.getPX(), funcoes.getPY(), funcoes.getMatriz(),funcoes.getVisitados());
    string nomeArquivo="output.dat";

    ofstream arquivoSaida(nomeArquivo);

    if (!arquivoSaida.is_open()) 
    {
        cerr << "Erro ao abrir o arquivo de saída!" << endl;
        return 1;
    }

    streambuf* coutBuffer = cout.rdbuf();
    cout.rdbuf(arquivoSaida.rdbuf());

    floresta->acharPosicaoInicial();
    int iteracao = 0;
    while (floresta->temFogo() && iteracao < config.getInteracoes()) 
    {
        arquivoSaida << "=== Iteração " << iteracao << " ===" << endl;

        
        floresta->andarAnimal();
        arquivoSaida << "\nPosição do animal: (" << floresta->getAnimalX() << "," << floresta->getAnimalY() << ")\n";
        funcoes.printArquivoComAnimal(floresta->getMatriz(), floresta->getAnimalX(), floresta->getAnimalY(), arquivoSaida);
        if(floresta->getMatriz()[floresta->getAnimalX()][floresta->getAnimalY()] == 0)
        {
            for(int i=0;i<3;i++)
            {    
                if(iteracao == config.getInteracoes())
                {
                    break;
                }            
                cout<<"Animal descansando"<<endl;
                floresta->espalharFogo(config.getCima(), config.getBaixo(), config.getEsquerda(), config.getDireita());
                funcoes.printArquivoComAnimal(floresta->getMatriz(), floresta->getAnimalX(), floresta->getAnimalY(), arquivoSaida);
                iteracao++;
            }
        }
        else
        {
            streambuf* originalCoutBuffer = cout.rdbuf(); 
            cout.rdbuf(arquivoSaida.rdbuf());
            floresta->espalharFogo(config.getCima(), config.getBaixo(), config.getEsquerda(), config.getDireita());
            cout.rdbuf(originalCoutBuffer);
            iteracao++;
        }
        
        if (!floresta->segundaChance()) 
        {
            arquivoSaida << "[FIM] Animal preso na iteração " << iteracao << endl;
            break;
        }
                
        funcoes.printArquivoComAnimal(floresta->getMatriz(), floresta->getAnimalX(), floresta->getAnimalY(), arquivoSaida);

    }
    funcoes.printFinal(iteracao,floresta->getPassos(), floresta->getVivo());
    cout.rdbuf(coutBuffer);
    arquivoSaida.close();
    delete floresta;
    return 0;
}