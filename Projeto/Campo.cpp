#include <iostream>
#include <stdlib.h> // Biblioteca rand, srand
#include <iomanip>

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

int Bombas(int b){ // Função que gera as bombas
    int Qb;
    for (int b= 0; b == Qb; b++) //Gerando número aleátorio 
        cout << rand() % 10  << "; ";
        cout << endl;

        return 0;
}


int main()
{

  int i, j; //Contadores
  int l, c; //Variáveis das linhas e das colunas
  int Qb; //Variável que vai definir a quantidade de bombas
  	
  double Matriz[l][c];

  cout << "______Campo Minado______" << endl;

  cout << "Escolha o numero de linhas e colunas: " << endl;
  cin >> l >> c; //leitura da variável do número de linhas e colunas	       

  cout << "Escolha a quantidade de bombas: ";
  cin >> Qb; //Leitura da qunatidade de bombas

  Bombas(Qb);

  for (i = 0; i < l; i++) {  // Imprimindo a Matriz
  	cout << "|";
    for (j = 0; j < c; j++){
      cout << " * ";
    }
    cout << "|" << endl;
  } 

/* 

'*' -> Não descoberto
 'X' -> Bomba
 '0' -> Vazio ao redor
 '1' - '8' -> Bombas ao redor

 */

  return 0;
}