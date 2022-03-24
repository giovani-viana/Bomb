#include <iostream>
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

}

int ContarVizinhas(int l, int c){

}

int Vizinhas(){
  for (int i = 0; i < l; i++){
    for (int j = 0; j < c; j++)
    {
      Matriz[l][c].Vadj = 0;
    }   
  } 
}
  

Campo Matriz[l][c]; //Definição da matriz aonde irá ocorrer o jogo

int main()
{
  int i, j; //Contadores
  int l, c; //Variáveis das linhas e das colunas
  int Qb; //Variável que vai definir a quantidade de bombas

  cout << "______Campo Minado______" << endl;
  cout << "Escolha o numero de linhas e colunas: " << endl;

  cin >> l >> c; //leitura da variável do número de linhas e colunas	       

  for (i = 0; i < l; i++){ //Leitura das linhas
    for (j = 0; j < c; j++){ //Leitura das colunas       
      cin >> Matriz[l][c];
    }        
  }

  cout << "Escolha a quantidade de bombas: "
  cin >> Qb; //Leitura da qunatidade de bombas

  Bombas(Qb); // Função que aleatoriza as bombas no campo

  for (i = 0; i < l; i++) {  // Imprimindo a Matriz
    for (j = 0; j < c; j++){
      cout << Matriz[l][c] << endl;
    }  
  }
   
    return 0;
}
