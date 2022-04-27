#include <iostream>
#include <stdlib.h> // Biblioteca rand, srand
#include <iomanip>
#include <ctime>
#include <bits/stdc++.h>
#define facil 8

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

  for (linha = 0; linha < facil; linha++){ // Percorre cada coordenada da Matriz
    for (coluna = 0; coluna < facil; coluna++){
      Matriz[linha][coluna].Vbomb = 0; // zera a quantidade de bombas na Matriz
      Matriz[linha][coluna].VerificaAberta = 0;// Zera a quantidade de casas abertas 
      Matriz[linha][coluna].Vadj = 0; //Zera as o numero de bombas adjacentes a celula
    } 
  }
}

void Bombas(int Qb){ // Função que gera as bombas

  int i = 0;

    srand(time(NULL));//Sorteia um numero diferente cada vez que o codigo é executado

    while(i != Qb){ //gera um numero aleatorio com um tamanho maximo igual ao tamanho da matriz
      linha = rand() % facil;
        coluna = rand() % facil;

        if(Matriz[linha][coluna].Vbomb == 0){ //Caso não tenha uma bomba nessa coordenada 
            Matriz[linha][coluna].Vbomb = 1; //Coloca uma bombas
            i++;
        }
    }
}

int Verifica(int linha, int coluna){ // Verifica se uma coordenada é válida 
    if (linha >= 0  && linha < facil && coluna >= 0 && coluna < facil) //Se a coordenada digitada for maior que zero e menor que o tamanho da matriz, a coordenada é válida
      return 1;
    else
      return 0;
  }

int Vizinhas(int linha, int coluna){ //Função que conta a quantidade de bombas nas casas vizinhas

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

void ContarBombas(){ // Passa por toda matriz alocando em cada celula a quantidade de bombas adjacentes à célula
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

            l = linha; //Por ter usado as mesmas variaveis muitas vezes estavam surgindo alguns erros
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

  fstream arquivo; //arquivo
  clock_t start, end;
  string usuario, linhas;
  int opcoes;

  do{
  	cout << "OPCOES:" << endl;
  	cout << "1: jogar" << endl;
  	cout << "2: historico de players" << endl;
  	cout << "3: encerrar jogo" << endl;
  	cout << "4: limpar tela" << endl;
  	cin >> opcoes;
    
  	switch(opcoes){
  		case 1:{
  			cout << "DIGITE O NOME DO PLAYER: " ;
  			cin >> usuario;
  			Start();
  			cout << "______Campo Minado______" << endl;    
			
			cout << "Escolha a quantidade de bombas: ";
			cin >> Qb; //Leitura da qunatidade de bombas
  			Bombas(Qb); //Chama a função bombas, colocando as bombas no Campo 
  			ContarBombas();
  			start = clock();
    		Jogo();
			end = clock();
			double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
			cout << "Tempo de jogo " << fixed << time_taken << setprecision(5);
			cout << " sec " << endl;
			
			arquivo.open("Historico", fstream::in|fstream::out| fstream::app);
			arquivo << usuario << " " << time_taken << endl;
			arquivo.close();
			
			break;
		  }
		case 2:{
			arquivo.open("Historico", fstream::in);
			while(getline(arquivo, linhas)){
				cout << linhas << endl;
			}
			arquivo.close();
			cout << endl;
			break;
		}
		case 3:{
			cout << "Encerrando..." << endl;
			break;
		}
		case 4:{
			system("cls");
			break;
		}
		default:{
			cout << "OPCAO INVALIDA" << endl;
			break;
		}
	  }
  	
  }while(opcoes != 3);
  
  return 0;
}

/* 
'*' -> Não descoberto
 'X' -> Bomba
 '0' -> Vazio ao redor
 '1' - '8' -> Bombas ao redor
 */