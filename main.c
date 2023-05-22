#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <windows.h>
#include <time.h>
#include "biblioteca.h"

int main(){
	setlocale(LC_ALL, "Portuguese");
	srand(time(NULL));
	
	char p1[8][8]; //Tabuleiro do jogador 1
	char p2[8][8]; //Tabuleiros do jogador 2(pc)
	char p2censurada[8][8];	//Tabuleiro criado para censurar/limpar p2

	char p_1 [8][8]; //Tabuleiros usados para salvar o jogo
	char p_2 [8][8]; //Tabuleiros usados para salvar o jogo
	char p_2c [8][8];
	char sdica;
	
	int contdica=0, menu;	 
	
	FILE *ler; //Ponteiro que aponta para o arquivo
		
	int r=1, menu2; //Variáveis	
	
	//Menu
		while(r!=4){
			char pos1; //Coordenada x
			int pos2;  //Coordenada y
			int i, j; //Usadas nos for's
			
			system("cls");
			
			//Printa o nome do jogo
			printf("\n");			
			printf("\t########     ###    ########    ###    ##       ##     ##    ###          ##    ##    ###    ##     ##    ###    ##       \n");
			printf("\t##     ##   ## ##      ##      ## ##   ##       ##     ##   ## ##         ###   ##   ## ##   ##     ##   ## ##   ##       \n");
			printf("\t##     ##  ##   ##     ##     ##   ##  ##       ##     ##  ##   ##        ####  ##  ##   ##  ##     ##  ##   ##  ##       \n");
			printf("\t########  ##     ##    ##    ##     ## ##       ######### ##     ##       ## ## ## ##     ## ##     ## ##     ## ##       \n");
			printf("\t##     ## #########    ##    ######### ##       ##     ## #########       ##  #### #########  ##   ##  ######### ##       \n");
			printf("\t##     ## ##     ##    ##    ##     ## ##       ##     ## ##     ##       ##   ### ##     ##   ## ##   ##     ## ##       \n");
			printf("\t########  ##     ##    ##    ##     ## ######## ##     ## ##     ##       ##    ## ##     ##    ###    ##     ## ######## \n");
			printf("\n");

			//Printa o menu principal
			printf("\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~\n");
			printf("\t\t\t\t\t\t|  1 - Jogo aleatório  |\n");
			printf("\t\t\t\t\t\t|  2 - Carregar jogo   |\n");
			printf("\t\t\t\t\t\t|  3 - Sobre o jogo    |\n");
			printf("\t\t\t\t\t\t|  4 - Sair            |\n");
			printf("\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~\n");
			scanf("%d",&r); //receber a opção do menu para entrar em um dos casos do switch
			
			int soma_2=11; //Variável usada para contagem de navios (soma_2=0 ---> o jogador1 ganha)
			int soma_1=11; //Variável usada para contagem de navios (soma_1=0 ---> o jogador2(pc) ganha)
			
			switch(r){
				case 1: //Jogo Aleatório
						limpar(p1,p2,p2censurada);
						posicionar_PORTAAVIAO_P1(p1);
						posicionar_PORTAAVIAO_P2(p2);
						posicionar_ESCOLTA_P1(p1);
						posicionar_ESCOLTA_P2(p2);
						posicionar_SUBMARINO_P1(p1);
						posicionar_SUBMARINO_P2(p2);
						posicionar_CACA_P1(p1);
						posicionar_CACA_P2(p2);
						menuselect(p1, p2, p2censurada, contdica); //Entra para o segundo menu 
						return 0;
						break;					
				case 2:	//Carregar o jogo
					ler = fopen("banco.txt","r"); //Abre o arquivo
								
					if(ler==NULL){ //Teste para saber se o arquivo realmente abriu
						perror("ERRO:");
					}
					else{
						printf("Abriu o arquivo\n");		
						for(i=0;i<8;i++){
							for(j=0;j<8;j++){
								
								fscanf(ler,"\t%c",&p_1[i][j]);
										if(p_1[i][j]=='9'){
											p1[i][j]='~';
										}
										if(p_1[i][j]=='O'){
											p1[i][j]='O';	
										}
										if(p_1[i][j]=='X'){
											p1[i][j]='X';
										}
										if(p_1[i][j]=='4'){
											p1[i][j]=4;
										}
										if(p_1[i][j]=='1'){
											p1[i][j]=1;	
										}
										if(p_1[i][j]=='5'){
											p1[i][j]=5;	
										}
										if(p_1[i][j]=='3'){
											p1[i][j]=3;	
										}
							}
						}			
						for(i=0;i<8;i++){
							for(j=0;j<8;j++){
								
								fscanf(ler,"\t%c",&p_2[i][j]);
										if(p_2[i][j]=='9'){
											p2[i][j]='~';
										}
										if(p_2[i][j]=='O'){
											p2[i][j]='O';	
										}
										if(p_2[i][j]=='X'){
											p2[i][j]='X';
										}
										if(p_2[i][j]=='4'){
											p2[i][j]=4;
										}
										if(p_2[i][j]=='1'){
											p2[i][j]=1;	
										}
										if(p_2[i][j]=='5'){
											p2[i][j]=5;	
										}
										if(p_2[i][j]=='3'){
											p2[i][j]=3;	
										}	
							}
						}
						for(i=0;i<8;i++){
							for(j=0;j<8;j++){
								
								fscanf(ler,"\t%c",&p_2c[i][j]);
										if(p_2c[i][j]=='9'){
											p2censurada[i][j]='~';
										}
										if(p_2c[i][j]=='O'){
											p2censurada[i][j]='O';	
										}
										if(p_2c[i][j]=='X'){
											p2censurada[i][j]='X';
										}
								
								
							}
						}
					}						
					fclose(ler);
					ler = fopen("dica.txt","r");
					fscanf(ler,"%c",&sdica);
					if(sdica=='0'){contdica=0;}
					if(sdica=='1'){contdica=1;}
					if(sdica=='2'){contdica=2;}
					if(sdica=='3'){contdica=3;}
					fclose(ler);
					menuselect(p1, p2, p2censurada, contdica);
					
					return 0;
					break;
				case 3: //Sobre o jogo
					sobrejogo(); //Chama a função sobre o jogo
					system("pause");
					break;
				case 4:	//Sair
					printf("Obrigado por jogar!!!");
					system("pause");					
					return 0;
					break;		
			}
	}
}

