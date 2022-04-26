#include <iostream>
#include <stdlib.h> // Biblioteca rand, srand
#include <iomanip>
#include <ctime>
#define facil 8
#define medio 12
#define dificil 20

using namespace std;

/* OBJETIVOS: Gerar uma matriz de acordo com a preferencia do jogados
->Função para sortear bombas
->Função que verifica a quantidade de bombas vizinhas
*/

struct Campo { //Nessa struct está contido as variáveis que iremos usar para fazer a verificação de uma coordenada 

  int Vbomb;
  int Vadj;  

};

int linha, coluna;
Campo Matriz[facil][facil];

void Start(){

  for (int i = 0; i < linha ; i++){
    for (int j = 0; i < coluna; j++){
      Matriz[i][j].Vbomb = 0; // zera a quantidade de bombas na Matriz
    } 
  }
}

void Bombas(int Qb){ // Função que gera as bombas

  int bombas;

    srand(time(NULL));//Sorteia um numero diferente cada vez que o codigo é executado

    for (int b = 0; b == Qb; b++) 
    {
        linha = rand() % linha;
        coluna = rand() % coluna;

        if(Matriz[linha][coluna].Vbomb == 0){ //Caso não tenha uma bomba nessa coordenada 
            Matriz[linha][coluna].Vbomb = 1; //Coloca uma bombaSS
            bombas++;
        }
        else
            b--;
    }
}

int Verifica(int linha, int coluna){ // Verifica se uma coordenada é válida 
  if (linha >= 0  && coluna >= 0){
    return 1;
  }
  else
  cout << "Coordenada invalida" << endl;
  return 0;
  }

int Vizinhas(int linha, int coluna){

  int Quantidade = 0;

  if (Verifica(linha - 1, coluna) && Matriz[linha - 1][coluna].Vbomb) //verifica a linha da esquerda
    Quantidade++;
  if (Verifica(linha + 1, coluna) && Matriz[linha + 1][coluna].Vbomb) //verifica a linha da direita
    Quantidade++;  
  if (Verifica(coluna - 1, linha) && Matriz[linha][coluna - 1].Vbomb) //verifica a coluna da esquerda
    Quantidade++; 
  if (Verifica(coluna + 1, linha) && Matriz[linha][coluna + 1].Vbomb) //verifica a coluna da direita
    Quantidade++;
  if (Verifica(linha - 1, coluna + 1) && Matriz[linha - 1][coluna + 1].Vbomb) //verifica a diagonal superior direita
    Quantidade++; 
  if (Verifica(linha + 1, coluna + 1) && Matriz[linha + 1][coluna + 1].Vbomb) //verifica a diagonal inferior direita
    Quantidade++;
  if (Verifica(linha - 1, coluna - 1) && Matriz[linha - 1][coluna - 1].Vbomb) //verifica a diagonal superior esquerda
    Quantidade++;    
  if (Verifica(linha + 1, coluna - 1) && Matriz[linha + 1][coluna - 1].Vbomb) //verifica a diagonal inferior esquerda
    Quantidade++;

  return Quantidade;
}

void ContarBombas(){

  for (int i = 0; i < linha ; i++){
    for (int j = 0; i < coluna; j++){
      Matriz[linha][coluna].Vadj = Vizinhas(linha, coluna);
    } 
  }

}

int main()
{

  int Matriz[linha][coluna];

  int i, j; //Contadores
  int Qb; //Variável que vai definir a quantidade de bombas

  Start();
  	
  cout << "______Campo Minado______" << endl;

  cout << "Escolha a dificuldade: " << endl;      

  cout << "Escolha a quantidade de bombas: ";
  cin >> Qb; //Leitura da qunatidade de bombas

  Bombas(Qb); //Chama a função bombas, colocando as bombas no Campo 
  ContarBombas();

  for (i = 0; i < facil; i++) {  // Imprimindo a Matriz
  	cout << "|";
    for (j = 0; j < facil; j++){
      cout << " * ";
    }
    cout << "|" << endl;
  } 

  return 0;
}

/* 

'*' -> Não descoberto
 'X' -> Bomba
 '0' -> Vazio ao redor
 '1' - '8' -> Bombas ao redor

 */