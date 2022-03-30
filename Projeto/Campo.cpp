#include <iostream>
#include<fstream>
#include <iomanip>

using namespace std;

/* OBJETIVOS: Gerar uma matriz de acordo com a preferencia do jogados
->Função para sortear bombas
->Função que verifica a quantidade de bombas vizinhas
*/

int **le_matriz(int& l, int& c) {
  ifstream fr;
  int **v;
  int i,j;

  fr.open ("m-in.txt");

  if (!fr.is_open()) {
    cerr << "ERRO ao abrir m-in.txt\n";
    return 0;  /* retorna ponteiro nulo */
  }

  fr >> l >> c; //dimensoes da tabela

  v = new int*[l]; //aloca vetor de vetores int

  for (i = 0; i < l; i++)
    v[i] = new int[c]; //aloca em cada posicao um vetor de int

    for (i = 0; i < l; i++)
      for (j = 0; j < c; j++)
        fr >> v[i][j]; //leitura dos elementos

  fr.close();

  return v;
}

void escreve_matriz(int **v, int l, int c) {
  ofstream fw;
  int i, j;

  fw.open("m-out.txt", ios::trunc);

  if (!fw.is_open()) {
    cerr << "ERRO ao abrir m-out.txt\n";
    return;  /* Abandona a função */
  }

  fw << "linhas = " << l << '\n'; /* Dimensão da matriz */
  fw << "colunas = " << c << '\n';

  for (i = 0; i < l; i++)
    for (j = 0; j < c; j++)
      fw << "mat[" << i << "][" << j << "] = " << v[i][j] << '\n';//imprime matriz

  fw.close();
}

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
  int **v;
  int i, j; //Contadores
  int l, c; //Variáveis das linhas e das colunas
  int Qb; //Variável que vai definir a quantidade de bombas

  cout << "______Campo Minado______" << endl;
  cout << "Escolha o numero de linhas e colunas: " << endl;

  v = le_matriz(l, c); //passagem por referencia
  
  cout << "Escolha a quantidade de bombas: "
  cin >> Qb; //Leitura da qunatidade de bombas

  Bombas(Qb); // Função que aleatoriza as bombas no campo

  if(v != 0){
    escreve_matriz(v, l, c);
    delete[] v;
    return 0;
  }

  else {//erro na abertura do arquivo, encerra programa com codigo de erro    
    return 1;
  }
   
    return 0;
}
