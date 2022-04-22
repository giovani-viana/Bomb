#include <iostream>
#include <stdlib.h> // Biblioteca rand, srand
#include <iomanip>
#include <ctime>

using namespace std;

/* OBJETIVOS: Gerar uma matriz de acordo com a preferencia do jogados
->Função para sortear bombas
->Função que verifica a quantidade de bombas vizinhas
*/

struct Campo { //Informações essenciais para o jogo 

  int Vadj; //Verifica se a coordenada tem bombas adjacentes/vizinhas
  int Vbomb; //Verifica se a coordenada tem bombas
  int Vopen; //Verifica se a coordenada já foi aberta
  int Vcord; //Verifica se as coordenadas inseridas são válidas
  
};

struct coordenadas {

int linha, coluna;
int Qb;
struct Campo Matriz[0][0];

};



int Bombas(coordenadas p2){ // Função que gera as bombas

  int bombas;

    srand(time(NULL));//Sorteia um nuemro diferente cada vez que o codigo é executado

    for (int b = 0; b == p2.Qb; b++) //Gerando número aleátorio 
    {
        p2.linha = rand() % p2.linha;
        p2.coluna = rand() % p2.coluna;

        if(p2.Matriz[p2.linha][p2.coluna].Vbomb == 0){
            p2.Matriz[p2.linha][p2.coluna].Vbomb = 1;
            bombas++;
        }
        else
            b--;
    }

        return 0;
}

int main()
{

  int i, j; //Contadores
  coordenadas p1; //Variáveis das linhas e das colunas
  int Qb; //Variável que vai definir a quantidade de bombas
  	
  cout << "______Campo Minado______" << endl;

  cout << "Escolha o numero de linhas e colunas: " << endl;
  cin >> p1.linha >> p1.coluna; //leitura da variável do número de linhas e colunas	       

  cout << "Escolha a quantidade de bombas: ";
  cin >> p1.Qb; //Leitura da qunatidade de bombas

  Bombas(p1); //Chama a função

  for (i = 0; i < p1.linha; i++) {  // Imprimindo a Matriz
  	cout << "|";
    for (j = 0; j < p1.coluna; j++){
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