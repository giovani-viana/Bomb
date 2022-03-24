#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
  cout << "______Campo Minado______" << endl;
  cout << "Escolha o numero de linhas: " << endl;

  int l, c; //Variáveis das linhas e das colunas
  cin >> l; //leitura da variável do número de linhas	

  cout << "Agora escolha o numero de colunas: " << endl;
  cin >> c; // leitura da variável do número de colunas    

    int i, j; //Contadores
    double Matriz[l][c]; //definição da matriz aonde irá ocorrer o jogo

    for (i = 0; i < l; i++){ //Leitura das linhas
     for (j = 0; j < c; j++){ //Leitura das colunas       
        cin >> Matriz[l][c];
        }        
    }

    for (i = 0; i < l; i++) {  // Imprimindo a Matriz
    for (j = 0; j < c; j++){
      cout << Matriz[l][c] << endl;
    }  
  }
   
    return 0;
}
