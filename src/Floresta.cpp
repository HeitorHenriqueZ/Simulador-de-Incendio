#include "Floresta.hpp"

Floresta::Floresta(int linhas, int colunas, int posicaoInicialFX,int posicaoInicialFY, vector<std::vector<int>> matriz, vector<std::vector<bool>>& visitados)
{
    this->linhas=linhas;
    this->colunas=colunas;
    this->posicaoInicialFX=posicaoInicialFX;
    this->posicaoInicialFY=posicaoInicialFY;
    this->matriz=matriz;
    acharPosicaoInicial();
    visitados[animalX][animalY]=true;
    this->visitados=visitados;
}
int Floresta::getPX()
{
  return posicaoInicialFX;
}

void Floresta::setPX(int i)
{
  this->posicaoInicialFX=i;
}

int Floresta::getPY()
{
  return posicaoInicialFY;
}

void Floresta::setPY(int j)
{
  this->posicaoInicialFY=j;
}
vector<std::vector<int>> Floresta::getMatriz()
{
  return matriz;
}
void Floresta::setVisitados(vector<std::vector<bool>> visitados)
{
  this->visitados=visitados;
}
vector<std::vector<bool>> Floresta::getVisitados()
{
  return visitados;
}

void Floresta::espalharFogo(char cima, char baixo, char esquerda, char direita)
{
    vector<vector<int>> novaMatriz = matriz; // cópia temporária para evitar propagação incorreta

    for (int i = 0; i < linhas; i++) 
    {
        for (int j = 0; j < colunas; j++) 
        {
            if (matriz[i][j] == 2) 
            {
                // Sem vento
                if (cima == '0' && baixo == '0' && esquerda == '0' && direita == '0') 
                {
                    if (i + 1 < linhas && matriz[i + 1][j] == 1) 
                    {
                        novaMatriz[i + 1][j] = 2;
                        cout << "(" << i + 1 << "," << j << ") vira 2 (abaixo)" << endl;
                    }
                    if (i - 1 >= 0 && matriz[i - 1][j] == 1) 
                    {
                        novaMatriz[i - 1][j] = 2;
                        cout << "(" << i - 1 << "," << j << ") vira 2 (acima)" << endl;
                    }
                    if (j + 1 < colunas && matriz[i][j + 1] == 1) 
                    {
                        novaMatriz[i][j + 1] = 2;
                        cout << "(" << i << "," << j + 1 << ") vira 2 (direita)" << endl;
                    }
                    if (j - 1 >= 0 && matriz[i][j - 1] == 1) 
                    {
                        novaMatriz[i][j - 1] = 2;
                        cout << "(" << i << "," << j - 1 << ") vira 2 (esquerda)" << endl;
                    }
                }
                else
                {   
                    // Vento para direita
                    if(direita == '1')
                    {
                        if (j + 1 < colunas && matriz[i][j + 1] == 1) 
                        {
                            novaMatriz[i][j + 1] = 2;
                            cout << "(" << i << "," << j + 1 << ") vira 2 (direita)" << endl;
                        }
                    }
                    if(esquerda == '1')
                    {
                        if (j - 1 >= 0 && matriz[i][j - 1] == 1) 
                        {
                            novaMatriz[i][j - 1] = 2;
                            cout << "(" << i << "," << j - 1 << ") vira 2 (esquerda)" << endl;
                        }
                    }
                    if(cima == '1')
                    {
                        if (i - 1 >= 0 && matriz[i - 1][j] == 1) 
                        {
                            novaMatriz[i - 1][j] = 2;
                            cout << "(" << i - 1 << "," << j << ") vira 2 (acima)" << endl;
                        }
                    }
                    if(baixo == '1')
                    {
                        if (i + 1 < linhas && matriz[i + 1][j] == 1) 
                        {
                            novaMatriz[i + 1][j] = 2;
                            cout << "(" << i + 1 << "," << j << ") vira 2 (abaixo)" << endl;
                        }
                    }
                }
             
                novaMatriz[i][j] = 3;
            }
        }
    }

    // Atualiza a matriz real
    matriz = novaMatriz;
}

bool Floresta::temFogo() 
{
    for (int i = 0; i < linhas; i++) 
    {
        for (int j = 0; j < colunas; j++) 
        {
            if (matriz[i][j] == 2) 
            {
                return true;
            }
        }
    }
    return false;
}
void Floresta::acharPosicaoInicial()  //Acha a posicao inicial do animal
{
    for (int i = 0; i < linhas; i++) 
    {
        for (int j = 0; j < colunas; j++) 
        {
            if (matriz[i][j] == 0) 
            {
                animalX = i;
                animalY = j;
                return;
            }
        }
    }
    vivo=false;
}


void Floresta::andarAnimal() 
{
    if (!vivo) return;

    vector<pair<int, int>> direcoes = {{-1,0}, {1,0}, {0,-1}, {0,1}};

    auto buscarOpcoes = [&](int valorAlvo) 
    {
        vector<pair<int, int>> naoVisitadas, visitadas;
        for (auto& dir : direcoes) 
        {
            int x = animalX + dir.first;
            int y = animalY + dir.second;
            if (x >= 0 && x < linhas && y >= 0 && y < colunas && matriz[x][y] == valorAlvo) 
            {
                if (!visitados[x][y]) naoVisitadas.push_back({x, y});
                else visitadas.push_back({x, y});
            }
        }
        return !naoVisitadas.empty() ? naoVisitadas : visitadas;
    };

    vector<pair<int, int>> opcoes;

    
    opcoes = buscarOpcoes(4);
    if (opcoes.empty()) 
    {
        
        opcoes = buscarOpcoes(0);
    }
    if (opcoes.empty()) 
    {
        
        opcoes = buscarOpcoes(1);
    }
    if (opcoes.empty()) 
    {
        opcoes = buscarOpcoes(3);
    }

    if (!opcoes.empty()) 
    {
        // Move para a primeira opção válida 
        animalX = opcoes[0].first;
        animalY = opcoes[0].second;
        visitados[animalX][animalY] = true; // Marca nova posição como visitada
        passos++;

        // Lógica de água 
        if (matriz[animalX][animalY] == 4) 
        {
            encontrouAgua++;
            matriz[animalX][animalY] = 0;
            // Atualiza adjacentes
            if (animalX - 1 >= 0) matriz[animalX - 1][animalY] = 1;
            if (animalX + 1 < linhas) matriz[animalX + 1][animalY] = 1;
            if (animalY - 1 >= 0) matriz[animalX][animalY - 1] = 1;
            if (animalY + 1 < colunas) matriz[animalX][animalY + 1] = 1;
        }
    } 
    else 
    {
        vivo = false;
        iteracaoPreso = passos;
    }
}
int Floresta::getPassos()
{
  return passos;
}
int Floresta::getEncontrouAgua()
{
  return encontrouAgua;
}
int Floresta::getIteracaoPreso()
{
  return iteracaoPreso;
}
bool Floresta::getVivo()
{
  return vivo;
}
int Floresta::getAnimalX()
{
  return animalX;
}
int Floresta::getAnimalY()
{
  return animalY;
}
void Floresta::setVivo(bool vivo)
{
  this->vivo=vivo;
}

bool Floresta::segundaChance() 
{
    int xAnimal = getAnimalX();
    int yAnimal = getAnimalY();
    int estadoCelula = matriz[xAnimal][yAnimal];

    if (estadoCelula == 2 ) 
    {
        andarAnimal(); // Segunda tentativa
        xAnimal = getAnimalX();
        yAnimal = getAnimalY();
        estadoCelula = matriz[xAnimal][yAnimal];

        if (estadoCelula == 2) 
        {
            vivo = false;
            return false; // Indica que o animal está preso
        }
    }
    return true; // Continua a simulação
}


