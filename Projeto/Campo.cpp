#include <iostream>
#include <stdlib.h> // Biblioteca rand, srand
#include <iomanip>
#include <ctime>
#define facil 8
#define medio 12
#define dificil 20

using namespace std;

/*
Projeto criação de um Campo minado
Alunos: Matrícula:
Giovani Viana 211067424
Davi Lima Santana 211067504
Victor Baião 211067460

Descrição: Utilizando aa linguagem de programação C++, para o nosso projeto computacional
decidimos criar a partir do zero um jogo já existente chamado campo minado,
utilizando o que aprendemos durante as aulas e com a ajuda dos monitores e
professores buscamos desenvolver do melhor jeito possivel o nosso trabalho.
*/

struct Campo { //Nessa struct está contido as variáveis que iremos usar para fazer a verificação de uma coordenada 

  int Vbomb; // 1 = tem uma bomba na celula, 0 = não tem bomba
  int Vadj; //1 = Há bombas na celula ao lado, 0 = não há
  int VerificaAberta; // 1 = celula ja aberta, 0 = não aberta

};

int linha, coluna;
Campo Matriz[facil][facil];

void Start(){

  for (linha = 0; linha < facil; linha++){
    for (coluna = 0; coluna < facil; coluna++){
      Matriz[linha][coluna].Vbomb = 0; // zera a quantidade de bombas na Matriz
      Matriz[linha][coluna].VerificaAberta = 0; 
      Matriz[linha][coluna].Vadj = 0;
    } 
  }
}

void Bombas(int Qb){ // Função que gera as bombas

  int i = 0;

    srand(time(NULL));//Sorteia um numero diferente cada vez que o codigo é executado

    while(i != Qb){
      linha = rand() % facil;
        coluna = rand() % facil;

        if(Matriz[linha][coluna].Vbomb == 0){ //Caso não tenha uma bomba nessa coordenada 
            Matriz[linha][coluna].Vbomb = 1; //Coloca uma bombas
            i++;
        }
    }
}

int Verifica(int linha, int coluna){ // Verifica se uma coordenada é válida 
    if (linha >= 0  && linha < facil && coluna >= 0 && coluna < facil)  
      return 1;
    else
      return 0;
  }

int Vizinhas(int linha, int coluna){

  int Quantidade = 0;

  if(Verifica(linha - 1, coluna) == 1)  //verifica a linha da esquerda
    if(Matriz[linha - 1][coluna].Vbomb == 1)
      Quantidade++;
  if(Verifica(linha + 1, coluna) == 1)  //verifica a linha da direita
    if(Matriz[linha + 1][coluna].Vbomb == 1)
      Quantidade++;  
  if(Verifica(linha, coluna - 1) == 1) //verifica a coluna da esquerda
    if(Matriz[linha][coluna - 1].Vbomb == 1)
      Quantidade++; 
  if(Verifica(linha, coluna + 1 )== 1)//verifica a coluna da direita
    if(Matriz[linha][coluna + 1].Vbomb == 1)
      Quantidade++;
  if(Verifica(linha - 1, coluna + 1) == 1)  //verifica a diagonal superior direita
    if(Matriz[linha - 1][coluna + 1].Vbomb == 1)
      Quantidade++; 
  if(Verifica(linha + 1, coluna + 1) == 1)  //verifica a diagonal inferior direita
    if(Matriz[linha + 1][coluna + 1].Vbomb == 1)
      Quantidade++;
  if(Verifica(linha - 1, coluna - 1) == 1)  //verifica a diagonal superior esquerda
    if(Matriz[linha - 1][coluna - 1].Vbomb == 1)
      Quantidade++;    
  if(Verifica(linha + 1, coluna - 1) == 1)  //verifica a diagonal inferior esquerda
    if(Matriz[linha + 1][coluna - 1].Vbomb == 1)
    Quantidade++;

  return Quantidade;
}

void ContarBombas(){
  for (linha = 0; linha < facil; linha++){
    for (coluna = 0; coluna < facil; coluna++){
      Matriz[linha][coluna].Vadj = Vizinhas(linha, coluna);
    } 
  }
}

void AbrirCoordenada(int linha, int coluna){ // verifica as casas ao redor do ponto selecionado
  Matriz[linha][coluna].VerificaAberta = 1;
  for(int k = linha - 1; k< linha + 2; k++){
    for(int i = coluna-1; i < coluna+2; i++){
      if(Verifica(k, i) == 1){
        Matriz[k][i].Vadj = Vizinhas(k, i);
        if(Matriz[k][i].Vbomb != 1){
          Matriz[k][i].VerificaAberta = 1;
        }
      }
    }
  }
}

int Vitoria(){ //Verifica se ganhou o jogo 
  int quantidade = 0;

  for (linha = 0; linha < facil; linha++){
    for (coluna = 0; coluna < facil; coluna++){
      if(Matriz[linha][coluna].VerificaAberta == 0 && Matriz[linha][coluna].Vbomb == 0){
        quantidade++;
      }
    }  
  }
  return quantidade;  
}

int Jogo(){

  int l;
  int c;

    do{
        for (linha  = 0; linha < facil; linha++) {  // Imprimindo a Matriz
          cout << "|";
          for (coluna = 0; coluna < facil; coluna++){
            if(Matriz[linha][coluna].VerificaAberta)//Verifica se a celula já foi aberta
              if(Matriz[linha][coluna].Vbomb) // Verifica se é uma bomba
                cout << " X "; // Se cair nesse if, o jogador perdeu
              else
                cout << " " << Matriz[linha][coluna].Vadj << " ";
              else
                cout << " * ";    
          }
          cout << "|" << endl;
        }
              
        do{

            cout << "Digite as coordenadas desejadas" << endl;
            cin >> linha >> coluna;

            l = linha;
            c = coluna;

            if(Verifica(linha, coluna) == 0 || Matriz[linha][coluna].VerificaAberta == 1)
                cout << "Coordenada invalida, ou ja aberta" << endl;
        }while(Verifica(linha, coluna) == 0 || Matriz[linha][coluna].VerificaAberta == 1);

        AbrirCoordenada(linha, coluna);
    }while(Vitoria() != 0 && Matriz[l][c].Vbomb == 0);

      linha = l;
      coluna = c;

    if(Matriz[linha][coluna].Vbomb == 1){
        cout << "BOOOOOM!!!" << endl;
        return 0;
    }

  return 1;      
}

int main()
{
  int Qb; //Variável que vai definir a quantidade de bombas

  Start();

  cout << "______Campo Minado______" << endl;

  cout << "Escolha a dificuldade: " << endl;      

  cout << "Escolha a quantidade de bombas: ";
  cin >> Qb; //Leitura da qunatidade de bombas

  Bombas(Qb); //Chama a função bombas, colocando as bombas no Campo 
  ContarBombas();
  Jogo();

  return 0;
}

/* 
'*' -> Não descoberto
 'X' -> Bomba
 '0' -> Vazio ao redor
 '1' - '8' -> Bombas ao redor
 */