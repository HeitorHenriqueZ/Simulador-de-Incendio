#include "Funcoes.hpp"
#include "Floresta.hpp"

void Funcoes::lerArquivo()
{
    ifstream arquivo("data/input.dat");

        if(!arquivo.is_open())
        {
          cerr<<"Erro ao abrir o arquivo 'input.dat'"<<endl;
          return;
        }

        int m,n,fogoInicialL,fogoInicialC;
        arquivo>>m>>n>>fogoInicialL>>fogoInicialC;

        cout << "m: " << m << ", n: " << n << ", L: " << fogoInicialL << ", C: " << fogoInicialC << endl;

        vector<vector<int>> matriz(m, vector<int>(n));

        for(int i =0;i<m;i++)
        {
          for(int j=0;j<n;j++)
          {
            arquivo>>matriz[i][j];
          }
        }

        this->posicaoInicialFX=fogoInicialL;
        this->posicaoInicialFY=fogoInicialC;
        this->linhas=m;
        this->colunas=n;
        this->matriz=matriz;

        for(int i =0;i<m;i++)
        {
          for(int j=0;j<n;j++)
          {
            cout<<matriz[i][j]<<" ";
          }
          cout<<endl;
        }
        vector<vector<bool>> aux(m, vector<bool>(n));
        this->setVisitados(aux);
}
 
int Funcoes::getPX()
{
  return posicaoInicialFX;
}

void Funcoes::setPX(int i)
{
  this->posicaoInicialFX=i;
}

int Funcoes::getPY()
{
  return posicaoInicialFY;
}

void Funcoes::setPY(int j)
{
  this->posicaoInicialFY=j;
}
vector<std::vector<int>> Funcoes::getMatriz()
{
  return matriz;
}
void Funcoes::setMatriz(vector<vector<int>>& novaMatriz)
{
  this->matriz=novaMatriz;
}
void Funcoes::setVisitados(vector<std::vector<bool>> visitados)
{
  this->visitados=visitados;
}
vector<std::vector<bool>>& Funcoes::getVisitados()
{
  return visitados;
}
void Funcoes::printArquivoComAnimal(vector<vector<int>> matriz, int animalX, int animalY, ofstream& arquivoSaida) 
{
    // Garante que o buffer seja liberado
    arquivoSaida << std::flush;
    
    for (int i = 0; i < linhas; i++) 
    {
        for (int j = 0; j < colunas; j++) 
        {
            if (i == animalX && j == animalY) 
            {
                arquivoSaida << "A ";
            } 
            else 
            {
                arquivoSaida << matriz[i][j] << " ";
            }
        }
        arquivoSaida << endl;
    }
    arquivoSaida << endl << std::flush;  // Força a escrita no arquivo
}
int Funcoes::getLinhas()
{
  return linhas;
}
int Funcoes::getColunas()
{
  return colunas;
}
void Funcoes::printFinal(int iteracao, int passos, int vivo)
{
  cout<<"Passos:"<<passos<<endl;
  cout<<"Interacoes:"<<iteracao<<endl;
  if(vivo==1)
  {
    cout<<"Estado do animal: Vivo"<<endl;
  }
  else
  {
    cout<<"Estado do animal: Morto"<<endl;
  }
}



