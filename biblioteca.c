#include "biblioteca.h"
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include <time.h>

void BufferLimpar(void){
	char c;
	while ((c=getchar()) != '\n' && c != EOF);
}

void limpar(char p1[8][8], char p2[8][8], char p2censurada[8][8]){
	int i, j;
	for(i = 0; i < 8; i++){
	    for(j = 0; j < 8; j++){
	        p2[i][j] = '~';
	        p1[i][j] = '~';
	        p2censurada[i][j] = '~';
		}
	}
}

void mostrarp2censurada(char p2censurada[8][8]){
	int i;
	int j, letras1=64;
	printf("\t\t\ JOGADOR 2(PC)\n\n");
    printf("  1     2     3     4     5     6     7     8   \n");
    printf("  ___________________________________________   \n");
	for(i=0;i<8;i++){
		letras1++;
		printf("%c|", letras1);
		for(j=0;j<8;j++){
			printf("%c     ",p2censurada[i][j]);
		}
		printf("\n\n");
	}
}
void mostrarp1(char p1[8][8]){
	int i,j;
	printf("\t\t  JOGADOR 1\n\n");
    printf("  1     2     3     4     5     6     7     8   \n");
    printf("  ___________________________________________   \n");
    int letras1=64;
	for(i=0;i<8;i++){
		letras1++;
		printf("%c|", letras1);
		for(j=0;j<8;j++){
			printf("%c     ",p1[i][j]);
		}
		printf("\n\n");
	}	
}
void mostrarp2(char p2[8][8]){
	int i,j;
    int letras1=64;
	printf("\t\t\ JOGADOR 2(PC)\n\n");
    printf("  1     2     3     4     5     6     7     8   \n");
    printf("  ___________________________________________   \n");
	for(i=0;i<8;i++){
		letras1++;
		printf("%c|", letras1);
		for(j=0;j<8;j++){
			printf("%c     ",p2[i][j]);
		}
		printf("\n\n");
	}
}
           
void posicionar_CACA_P2(char p2[8][8]){
	int s = 0;
	while(s<1){
		int x = rand() % 8;
		int y = rand() % 7;
		if(x == 0 || y == 0){ //POSSIBILIDADE 1	
		    if((p2[x][y] == '~') && (p2[x+1][y] == '~')){//BAIXO
				s++;
				p2[x][y] = 1;
				p2[x+1][y] = 1;
			}
			else if((p2[x][y] == '~') && (p2[x][y+1] == '~')){//DIREITA
				s++;
				p2[x][y] = 1;
				p2[x][y+1] = 1;
		   	}		
		}
		else if(x>0 && y==0){ //POSSIBILIDADE 2
			if((p2[x][y] == '~') && (p2[x+1][y] == '~')){//BAIXO
				s++;
				p2[x][y] = 1;
				p2[x+1][y] = 1;
			}
			if((p2[x][y] == '~') && (p2[x-1][y] == '~')){//CIMA
				s++;
				p2[x][y] = 1;
				p2[x-1][y] = 1;
			}
			else if((p2[x][y] == '~') && (p2[x][y+1] == '~')){//DIREITA
				s++;
				p2[x][y] = 1;
				p2[x][y+1] = 1;
		   	}	
		}
		else if(x==0 && y>0){//POSSIBILIDADE 3
			if((p2[x][y] == '~') && (p2[x][y-1] == '~')){//ESQUERDA
				s++;
				p2[x][y] = 1;
				p2[x][y-1] = 1;
			}
			else if((p2[x][y] == '~') && (p2[x+1][y] == '~')){//BAIXO
				s++;
				p2[x][y] = 1;
				p2[x+1][y] = 1;
			}
			else if((p2[x][y] == '~') && (p2[x][y+1] == '~')){//DIREITA
				s++;
				p2[x][y] = 1;
				p2[x][y+1] = 1;
		   	}
	   	}
		else if(x>0 && y>0){//POSSIBILIDADE 4	
			if((p2[x][y] == '~') && (p2[x-1][y] == '~')){//CIMA
				s++;
				p2[x][y] = 1;
				p2[x-1][y] = 1;
			}
			else if((p2[x][y] == '~') && (p2[x+1][y] == '~')){//BAIXO
				s++;
				p2[x][y] = 1;
				p2[x+1][y] = 1;
			}
			else if((p2[x][y] == '~') && (p2[x][y-1] == '~')){//ESQUERDA
				s++;
				p2[x][y] = 1;
				p2[x][y-1] = 1;
			}
			else if((p2[x][y] == '~') && (p2[x][y+1] == '~')){//DIREITA
				s++;
				p2[x][y] = 1;
				p2[x][y+1] = 1;
		   	}
		}	
	}  
}
void posicionar_SUBMARINO_P2(char p2[8][8]){
	int s = 0;
	while(s<1){
		int x = rand() % 8;
		int y = rand() % 7;
		if(x == 0 || y == 0){ //POSSIBILIDADE 1	
		    if((p2[x][y] == '~') && (p2[x+1][y] == '~')){//BAIXO
				s++;
				p2[x][y] = 5;
				p2[x+1][y] = 5;
			}
			else if((p2[x][y] == '~') && (p2[x][y+1] == '~')){//DIREITA
				s++;
				p2[x][y] = 5;
				p2[x][y+1] = 5;
		   	}		
		}
		else if(x>0 && y==0){ //POSSIBILIDADE 2
			if((p2[x][y] == '~') && (p2[x+1][y] == '~')){//BAIXO
				s++;
				p2[x][y] = 5;
				p2[x+1][y] = 5;
			}
			if((p2[x][y] == '~') && (p2[x-1][y] == '~')){//CIMA
				s++;
				p2[x][y] = 5;
				p2[x-1][y] = 5;
			}
			else if((p2[x][y] == '~') && (p2[x][y+1] == '~')){//DIREITA
				s++;
				p2[x][y] = 5;
				p2[x][y+1] = 5;
		   	}	
		}
		else if(x==0 && y>0){//POSSIBILIDADE 3
			if((p2[x][y] == '~') && (p2[x][y-1] == '~')){//ESQUERDA
				s++;
				p2[x][y] = 5;
				p2[x][y-1] = 5;
			}
			else if((p2[x][y] == '~') && (p2[x+1][y] == '~')){//BAIXO
				s++;
				p2[x][y] = 5;
				p2[x+1][y] = 5;
			}
			else if((p2[x][y] == '~') && (p2[x][y+1] == '~')){//DIREITA
				s++;
				p2[x][y] = 5;
				p2[x][y+1] = 5;
		   	}
	   	}
		else if(x>0 && y>0){//POSSIBILIDADE 4	
			if((p2[x][y] == '~') && (p2[x-1][y] == '~')){//CIMA
				s++;
				p2[x][y] = 5;
				p2[x-1][y] = 5;
			}
			else if((p2[x][y] == '~') && (p2[x+1][y] == '~')){//BAIXO
				s++;
				p2[x][y] = 5;
				p2[x+1][y] = 5;
			}
			else if((p2[x][y] == '~') && (p2[x][y-1] == '~')){//ESQUERDA
				s++;
				p2[x][y] = 5;
				p2[x][y-1] = 5;
			}
			else if((p2[x][y] == '~') && (p2[x][y+1] == '~')){//DIREITA
				s++;
				p2[x][y] = 5;
				p2[x][y+1] = 5;
		   	}
		}	
	}
}  
void posicionar_PORTAAVIAO_P2(char p2[8][8]){
	int s = 0;
	while(s<1){
		int x = rand() % 8;
		int y = rand() % 5;
		if(x==7){//POSSIBILIDADE 7
			if((p2[x][y] == '~') && (p2[x][y+1] == '~') && (p2[x][y+2] == '~') && (p2[x][y+3] == '~')){//DIREITA
				s++;
				p2[x][y] = 3;
				p2[x][y+1] = 3;
				p2[x][y+2] = 3;
				p2[x][y+3] = 3;
			}
			if((p2[x][y] == '~') && (p2[x-1][y] == '~') && (p2[x-2][y] == '~') && (p2[x-3][y] == '~')){//CIMA
				s++;
				p2[x][y] = 3;
				p2[x-1][y] = 3;
				p2[x-2][y] = 3;
				p2[x-3][y] = 3;
			}	
		}
		if(x==0 && y==0){//POSSIBILIDADE 1
			if((p2[x][y] == '~') && (p2[x+1][y] == '~') && (p2[x+2][y] == '~') && (p2[x+3][y] == '~')){//BAIXO
				s++;
				p2[x][y] = 3;
				p2[x+1][y] = 3;
				p2[x+2][y] = 3;
				p2[x+3][y] = 3;
			}
			else if((p2[x][y] == '~') && (p2[x][y+1] == '~') && (p2[x][y+2] == '~') && (p2[x][y+3] == '~')){//DIREITA
				s++;
				p2[x][y] = 3;
				p2[x][y+1] = 3;
				p2[x][y+2] = 3;
				p2[x][y+3] = 3;
			}	
		}
		if(x>=3 && y==0){//POSSIBILIDADE 2
			if((p2[x][y] == '~') && (p2[x-1][y] == '~') && (p2[x-2][y] == '~') && (p2[x-3][y] == '~')){//CIMA
				s++;
				p2[x][y] = 3;
				p2[x-1][y] = 3;
				p2[x-2][y] = 3;
				p2[x-3][y] = 3;
			}
			else if((p2[x][y] == '~') && (p2[x+1][y] == '~') && (p2[x+2][y] == '~') && (p2[x+3][y] == '~')){//BAIXO
				s++;
				p2[x][y] = 3;
				p2[x+1][y] = 3;
				p2[x+2][y] = 3;
				p2[x+3][y] = 3;
			}
			else if((p2[x][y] == '~') && (p2[x][y+1] == '~') && (p2[x][y+2] == '~') && (p2[x][y+3] == '~')){//DIREITA
				s++;
				p2[x][y] = 3;
				p2[x][y+1] = 3;
				p2[x][y+2] = 3;
				p2[x][y+3] = 3;
			}		
		}
			
		if(x==0 && y>=3){//POSSIBILIDADE 3
			if((p2[x][y] == '~') && (p2[x][y+1] == '~') && (p2[x][y+2] == '~') && (p2[x][y+3] == '~')){//DIREITA
					s++;
					p2[x][y] = 3;
					p2[x][y+1] = 3;
					p2[x][y+2] = 3;
					p2[x][y+3] = 3;
			}
			if((p2[x][y] == '~') && (p2[x][y-1] == '~') && (p2[x][y-2] == '~') && (p2[x][y-3] == '~')){//ESQUERDA
				s++;
				p2[x][y] = 3;
				p2[x][y-1] = 3;
				p2[x][y-2] = 3;
				p2[x][y-3] = 3;
			}
			else if((p2[x][y] == '~') && (p2[x+1][y] == '~') && (p2[x+2][y] == '~') && (p2[x+3][y] == '~')){//BAIXO
				s++;
				p2[x][y] = 3;
				p2[x+1][y] = 3;
				p2[x+2][y] = 3;
				p2[x+3][y] = 3;
			}
		}
		if(x>=3 && y>=3){//POSSIBILIDADE 4
				if((p2[x][y] == '~') && (p2[x][y+1] == '~') && (p2[x][y+2] == '~') && (p2[x][y+3] == '~')){//DIREITA
						s++;
					p2[x][y] = 3;
					p2[x][y+1] = 3;
					p2[x][y+2] = 3;
					p2[x][y+3] = 3;
				}
				else if((p2[x][y] == '~') && (p2[x+1][y] == '~') && (p2[x+2][y] == '~') && (p2[x+3][y] == '~')){//BAIXO
					s++;
					p2[x][y] = 3;
					p2[x+1][y] = 3;
					p2[x+2][y] = 3;
					p2[x+3][y] = 3;
				}
				if((p2[x][y] == '~') && (p2[x][y-1] == '~') && (p2[x][y-2] == '~') && (p2[x][y-3] == '~')){//ESQUERDA
					s++;
					p2[x][y] = 3;
					p2[x][y-1] = 3;
					p2[x][y-2] = 3;
					p2[x][y-3] = 3;
				}
				if((p2[x][y] == '~') && (p2[x-1][y] == '~') && (p2[x-2][y] == '~') && (p2[x-3][y] == '~')){//CIMA
					s++;
					p2[x][y] = 3;
					p2[x-1][y] = 3;
					p2[x-2][y] = 3;
					p2[x-3][y] = 3;
				}	
		}
		if(x<3 && y>=3){//POSSIBILIDADE 5
			if((p2[x][y] == '~') && (p2[x][y+1] == '~') && (p2[x][y+2] == '~') && (p2[x][y+3] == '~')){//DIREITA
				s++;
				p2[x][y] = 3;
				p2[x][y+1] = 3;
				p2[x][y+2] = 3;
				p2[x][y+3] = 3;
			}
				else if((p2[x][y] == '~') && (p2[x+1][y] == '~') && (p2[x+2][y] == '~') && (p2[x+3][y] == '~')){//BAIXO
				s++;
				p2[x][y] = 3;
				p2[x+1][y] = 3;
				p2[x+2][y] = 3;
				p2[x+3][y] = 3;
			}
		}
		if(x>=3 && y<3){//POSSIBILIDADE 6
			if((p2[x][y] == '~') && (p2[x][y+1] == '~') && (p2[x][y+2] == '~') && (p2[x][y+3] == '~')){//DIREITA
				s++;
				p2[x][y] = 3;
				p2[x][y+1] = 3;
				p2[x][y+2] = 3;
				p2[x][y+3] = 3;
			}
			else if((p2[x][y] == '~') && (p2[x+1][y] == '~') && (p2[x+2][y] == '~') && (p2[x+3][y] == '~')){//BAIXO
				s++;
				p2[x][y] = 3;
				p2[x+1][y] = 3;
				p2[x+2][y] = 3;
				p2[x+3][y] = 3;
			}
			else if((p2[x][y] == '~') && (p2[x][y+1] == '~') && (p2[x][y+2] == '~') && (p2[x][y+3] == '~')){//DIREITA
				s++;
				p2[x][y] = 3;
				p2[x][y+1] = 3;
				p2[x][y+2] = 3;
				p2[x][y+3] = 3;
			}
		}	
	}
}  
void posicionar_ESCOLTA_P2(char p2[8][8]){
	int s = 0;
	while(s<1){
		int x = rand() % 8;
		int y = rand() % 6;
	    if(x==7){//POSSIBILIDADE 5
			if((p2[x][y] == '~') && (p2[x][y+1] == '~') && (p2[x][y+2] == '~')){//DIREITA
				s++;
				p2[x][y] = 4;
				p2[x][y+1] = 4;
				p2[x][y+2] = 4;
			}
			else if((p2[x][y] == '~') && (p2[x-1][y] == '~') && (p2[x-2][y] == '~')){//CIMA
				s++;
				p2[x][y] = 4;
				p2[x-1][y] = 4;
				p2[x-2][y] = 4;
			}
		}
		if(x==0 && y==0){ //POSSIBILIDADE 1
			if((p2[x][y] == '~') && (p2[x+1][y] == '~') && (p2[x+2][y] == '~')){//BAIXO
				s++;
				p2[x][y] = 4;
				p2[x+1][y] = 4;
				p2[x+2][y] = 4;
			}
			else if((p2[x][y] == '~') && (p2[x][y+1] == '~') && (p2[x][y+2] == '~')){//DIREITA
				s++;
				p2[x][y] = 4;
				p2[x][y+1] = 4;
				p2[x][y+2] = 4;
			}		
		}
		if(x>=2 && y==0){//POSSIBILIDADE 2
			if((p2[x][y] == '~') && (p2[x-1][y] == '~') && (p2[x-2][y] == '~')){//CIMA
				s++;
				p2[x][y] = 4;
				p2[x-1][y] = 4;
				p2[x-2][y] = 4;
			}
			else if((p2[x][y] == '~') && (p2[x+1][y] == '~') && (p2[x+2][y] == '~')){//BAIXO
				s++;
				p2[x][y] = 4;
				p2[x+1][y] = 4;
				p2[x+2][y] = 4;
			}
			else if((p2[x][y] == '~') && (p2[x][y+1] == '~') && (p2[x][y+2] == '~')){//DIREITA
				s++;
				p2[x][y] = 4;
				p2[x][y+1] = 4;
				p2[x][y+2] = 4;
			}	
		}
		if(x==0 && y>=2){//POSSIBILIDADE 3
			if((p2[x][y] == '~') && (p2[x][y-1] == '~') && (p2[x][y-2] == '~')){//ESQUERDA
				s++;
				p2[x][y] = 4;
				p2[x][y-1] = 4;
				p2[x][y-2] = 4;
			}
			else if((p2[x][y] == '~') && (p2[x+1][y] == '~') && (p2[x+2][y] == '~')){//BAIXO
				s++;
				p2[x][y] = 4;
				p2[x+1][y] = 4;
				p2[x+2][y] = 4;
			}
			else if((p2[x][y] == '~') && (p2[x][y+1] == '~') && (p2[x][y+2] == '~')){//DIREITA
				s++;
				p2[x][y] = 4;
				p2[x][y+1] = 4;
				p2[x][y+2] = 4;
			}
	    }
	    if(x>=2 && y>=2){//POSSIBILIDADE 4
			if((p2[x][y] == '~') && (p2[x][y-1] == '~') && (p2[x][y-2] == '~')){//ESQUERDA
				s++;
				p2[x][y] = 4;
				p2[x][y-1] = 4;
				p2[x][y-2] = 4;
			}
			else if((p2[x][y] == '~') && (p2[x+1][y] == '~') && (p2[x+2][y] == '~')){//BAIXO
				s++;
				p2[x][y] = 4;
				p2[x+1][y] = 4;
				p2[x+2][y] = 4;
			}
			else if((p2[x][y] == '~') && (p2[x][y+1] == '~') && (p2[x][y+2] == '~')){//DIREITA
				s++;
				p2[x][y] = 4;
				p2[x][y+1] = 4;
				p2[x][y+2] = 4;
			}
			else if((p2[x][y] == '~') && (p2[x-1][y] == '~') && (p2[x-2][y] == '~')){//CIMA
				s++;
				p2[x][y] = 4;
				p2[x-1][y] = 4;
				p2[x-2][y] = 4;
			}
		}
	}
} 
void posicionar_CACA_P1(char p1[8][8]){
	int s = 0;
	while(s<1){
		int x = rand() % 8;
		int y = rand() % 7;
		if(x == 0 || y == 0){ //POSSIBILIDADE 1	
		    if((p1[x][y] == '~') && (p1[x+1][y] == '~')){//BAIXO
				s++;
				p1[x][y] = 1;
				p1[x+1][y] = 1;
			}
			else if((p1[x][y] == '~') && (p1[x][y+1] == '~')){//DIREITA
				s++;
				p1[x][y] = 1;
				p1[x][y+1] = 1;
		   	}		
		}
		else if(x>0 && y==0){ //POSSIBILIDADE 2
			if((p1[x][y] == '~') && (p1[x+1][y] == '~')){//BAIXO
				s++;
				p1[x][y] = 1;
				p1[x+1][y] = 1;
			}
			if((p1[x][y] == '~') && (p1[x-1][y] == '~')){//CIMA
				s++;
				p1[x][y] = 1;
				p1[x-1][y] = 1;
			}
			else if((p1[x][y] == '~') && (p1[x][y+1] == '~')){//DIREITA
				s++;
				p1[x][y] = 1;
				p1[x][y+1] = 1;
		   	}	
		}
		else if(x==0 && y>0){//POSSIBILIDADE 3
			if((p1[x][y] == '~') && (p1[x][y-1] == '~')){//ESQUERDA
				s++;
				p1[x][y] = 1;
				p1[x][y-1] = 1;
			}
			else if((p1[x][y] == '~') && (p1[x+1][y] == '~')){//BAIXO
				s++;
				p1[x][y] = 1;
				p1[x+1][y] = 1;
			}
			else if((p1[x][y] == '~') && (p1[x][y+1] == '~')){//DIREITA
				s++;
				p1[x][y] = 1;
				p1[x][y+1] = 1;
		   	}
	   	}
		else if(x>0 && y>0){//POSSIBILIDADE 4	
			if((p1[x][y] == '~') && (p1[x-1][y] == '~')){//CIMA
				s++;
				p1[x][y] = 1;
				p1[x-1][y] = 1;
			}
			else if((p1[x][y] == '~') && (p1[x+1][y] == '~')){//BAIXO
				s++;
				p1[x][y] = 1;
				p1[x+1][y] = 1;
			}
			else if((p1[x][y] == '~') && (p1[x][y-1] == '~')){//ESQUERDA
				s++;
				p1[x][y] = 1;
				p1[x][y-1] = 1;
			}
			else if((p1[x][y] == '~') && (p1[x][y+1] == '~')){//DIREITA
				s++;
				p1[x][y] = 1;
				p1[x][y+1] = 1;
		   	}
		}	
	}
}  
void posicionar_SUBMARINO_P1(char p1[8][8]){
	int s = 0;
	while(s<1){
		int x = rand() % 8;
		int y = rand() % 7;
		if(x == 0 || y == 0){ //POSSIBILIDADE 1	
		    if((p1[x][y] == '~') && (p1[x+1][y] == '~')){//BAIXO
				s++;
				p1[x][y] = 5;
				p1[x+1][y] = 5;
			}
			else if((p1[x][y] == '~') && (p1[x][y+1] == '~')){//DIREITA
				s++;
				p1[x][y] = 5;
				p1[x][y+1] = 5;
		   	}		
		}
		else if(x>0 && y==0){ //POSSIBILIDADE 2
			if((p1[x][y] == '~') && (p1[x+1][y] == '~')){//BAIXO
				s++;
				p1[x][y] = 5;
				p1[x+1][y] = 5;
			}
			if((p1[x][y] == '~') && (p1[x-1][y] == '~')){//CIMA
				s++;
				p1[x][y] = 5;
				p1[x-1][y] = 5;
			}
			else if((p1[x][y] == '~') && (p1[x][y+1] == '~')){//DIREITA
				s++;
				p1[x][y] = 5;
				p1[x][y+1] = 5;
		   	}	
		}
		else if(x==0 && y>0){//POSSIBILIDADE 3
			if((p1[x][y] == '~') && (p1[x][y-1] == '~')){//ESQUERDA
				s++;
				p1[x][y] = 5;
				p1[x][y-1] = 5;
			}
			else if((p1[x][y] == '~') && (p1[x+1][y] == '~')){//BAIXO
				s++;
				p1[x][y] = 5;
				p1[x+1][y] = 5;
			}
			else if((p1[x][y] == '~') && (p1[x][y+1] == '~')){//DIREITA
				s++;
				p1[x][y] = 5;
				p1[x][y+1] = 5;
		   	}
	   	}
		else if(x>0 && y>0){//POSSIBILIDADE 4	
			if((p1[x][y] == '~') && (p1[x-1][y] == '~')){//CIMA
				s++;
				p1[x][y] = 5;
				p1[x-1][y] = 5;
			}
			else if((p1[x][y] == '~') && (p1[x+1][y] == '~')){//BAIXO
				s++;
				p1[x][y] = 5;
				p1[x+1][y] = 5;
			}
			else if((p1[x][y] == '~') && (p1[x][y-1] == '~')){//ESQUERDA
				s++;
				p1[x][y] = 5;
				p1[x][y-1] = 5;
			}
			else if((p1[x][y] == '~') && (p1[x][y+1] == '~')){//DIREITA
				s++;
				p1[x][y] = 5;
				p1[x][y+1] = 5;
		   	}
		}			
	}
}  
void posicionar_PORTAAVIAO_P1(char p1[8][8]){
	int s = 0;
	while(s<1){
			int x = rand() % 8;
			int y = rand() % 5;
			if(x==0 && y==0){//POSSIBILIDADE 1
				if((p1[x][y] == '~') && (p1[x+1][y] == '~') && (p1[x+2][y] == '~') && (p1[x+3][y] == '~')){//BAIXO
					s++;
					p1[x][y] = 3;
					p1[x+1][y] = 3;
					p1[x+2][y] = 3;
					p1[x+3][y] = 3;
				}
				else if((p1[x][y] == '~') && (p1[x][y+1] == '~') && (p1[x][y+2] == '~') && (p1[x][y+3] == '~')){//DIREITA
					s++;
					p1[x][y] = 3;
					p1[x][y+1] = 3;
					p1[x][y+2] = 3;
					p1[x][y+3] = 3;
				}	
			}
			if(x>=3 && y==0){//POSSIBILIDADE 2
				if((p1[x][y] == '~') && (p1[x-1][y] == '~') && (p1[x-2][y] == '~') && (p1[x-3][y] == '~')){//CIMA
					s++;
					p1[x][y] = 3;
					p1[x-1][y] = 3;
					p1[x-2][y] = 3;
					p1[x-3][y] = 3;
				}
				else if((p1[x][y] == '~') && (p1[x+1][y] == '~') && (p1[x+2][y] == '~') && (p1[x+3][y] == '~')){//BAIXO
					s++;
					p1[x][y] = 3;
					p1[x+1][y] = 3;
					p1[x+2][y] = 3;
					p1[x+3][y] = 3;
				}
					else if((p1[x][y] == '~') && (p1[x][y+1] == '~') && (p1[x][y+2] == '~') && (p1[x][y+3] == '~')){//DIREITA
					s++;
					p1[x][y] = 3;
					p1[x][y+1] = 3;
					p1[x][y+2] = 3;
					p1[x][y+3] = 3;
				}		
			}
			
			if(x==0 && y>=3){//POSSIBILIDADE 3
				if((p1[x][y] == '~') && (p1[x][y+1] == '~') && (p1[x][y+2] == '~') && (p1[x][y+3] == '~')){//DIREITA
					s++;
					p1[x][y] = 3;
					p1[x][y+1] = 3;
					p1[x][y+2] = 3;
					p1[x][y+3] = 3;
				}
					if((p1[x][y] == '~') && (p1[x][y-1] == '~') && (p1[x][y-2] == '~') && (p1[x][y-3] == '~')){//ESQUERDA
					s++;
					p1[x][y] = 3;
					p1[x][y-1] = 3;
					p1[x][y-2] = 3;
					p1[x][y-3] = 3;
				}
					else if((p1[x][y] == '~') && (p1[x+1][y] == '~') && (p1[x+2][y] == '~') && (p1[x+3][y] == '~')){//BAIXO
					s++;
					p1[x][y] = 3;
					p1[x+1][y] = 3;
					p1[x+2][y] = 3;
					p1[x+3][y] = 3;
				}
			}
			if(x>=3 && y>=3){//POSSIBILIDADE 4
				if((p1[x][y] == '~') && (p1[x][y+1] == '~') && (p1[x][y+2] == '~') && (p1[x][y+3] == '~')){//DIREITA
					s++;
					p1[x][y] = 3;
					p1[x][y+1] = 3;
					p1[x][y+2] = 3;
					p1[x][y+3] = 3;
				}
					else if((p1[x][y] == '~') && (p1[x+1][y] == '~') && (p1[x+2][y] == '~') && (p1[x+3][y] == '~')){//BAIXO
					s++;
					p1[x][y] = 3;
					p1[x+1][y] = 3;
					p1[x+2][y] = 3;
					p1[x+3][y] = 3;
				}
					if((p1[x][y] == '~') && (p1[x][y-1] == '~') && (p1[x][y-2] == '~') && (p1[x][y-3] == '~')){//ESQUERDA
					s++;
					p1[x][y] = 3;
					p1[x][y-1] = 3;
					p1[x][y-2] = 3;
					p1[x][y-3] = 3;
				}
					if((p1[x][y] == '~') && (p1[x-1][y] == '~') && (p1[x-2][y] == '~') && (p1[x-3][y] == '~')){//CIMA
					s++;
					p1[x][y] = 3;
					p1[x-1][y] = 3;
					p1[x-2][y] = 3;
					p1[x-3][y] = 3;
				}	
			}
			if(x==7){//POSSIBILIDADE 5
				if((p1[x][y] == '~') && (p1[x][y+1] == '~') && (p1[x][y+2] == '~') && (p1[x][y+3] == '~')){//DIREITA
					s++;
					p1[x][y] = 3;
					p1[x][y+1] = 3;
					p1[x][y+2] = 3;
					p1[x][y+3] = 3;
				}
				if((p1[x][y] == '~') && (p1[x-1][y] == '~') && (p1[x-2][y] == '~') && (p1[x-3][y] == '~')){//CIMA
					s++;
					p1[x][y] = 3;
					p1[x-1][y] = 3;
					p1[x-2][y] = 3;
					p1[x-3][y] = 3;
				}	
		}
	}
}  
void posicionar_ESCOLTA_P1(char p1[8][8]){
	int s = 0;
	while(s<1){
		int x = rand() % 8;
		int y = rand() % 6;
		if(x==0 && y==0){ //POSSIBILIDADE 1
			if((p1[x][y] == '~') && (p1[x+1][y] == '~') && (p1[x+2][y] == '~')){//BAIXO
				s++;
				p1[x][y] = 4;
				p1[x+1][y] = 4;
				p1[x+2][y] = 4;
			}
			else if((p1[x][y] == '~') && (p1[x][y+1] == '~') && (p1[x][y+2] == '~')){//DIREITA
				s++;
				p1[x][y] = 4;
				p1[x][y+1] = 4;
				p1[x][y+2] = 4;
			}		
		}
		if(x>=2 && y==0){//POSSIBILIDADE 2
			if((p1[x][y] == '~') && (p1[x-1][y] == '~') && (p1[x-2][y] == '~')){//CIMA
				s++;
				p1[x][y] = 4;
				p1[x-1][y] = 4;
				p1[x-2][y] = 4;
			}
			else if((p1[x][y] == '~') && (p1[x+1][y] == '~') && (p1[x+2][y] == '~')){//BAIXO
				s++;
				p1[x][y] = 4;
				p1[x+1][y] = 4;
				p1[x+2][y] = 4;
			}
			else if((p1[x][y] == '~') && (p1[x][y+1] == '~') && (p1[x][y+2] == '~')){//DIREITA
				s++;
				p1[x][y] = 4;
				p1[x][y+1] = 4;
				p1[x][y+2] = 4;
			}	
		}
		if(x==0 && y>=2){//POSSIBILIDADE 3
			if((p1[x][y] == '~') && (p1[x][y-1] == '~') && (p1[x][y-2] == '~')){//ESQUERDA
				s++;
				p1[x][y] = 4;
				p1[x][y-1] = 4;
				p1[x][y-2] = 4;
			}
			else if((p1[x][y] == '~') && (p1[x+1][y] == '~') && (p1[x+2][y] == '~')){//BAIXO
				s++;
				p1[x][y] = 4;
				p1[x+1][y] = 4;
				p1[x+2][y] = 4;
			}
			else if((p1[x][y] == '~') && (p1[x][y+1] == '~') && (p1[x][y+2] == '~')){//DIREITA
				s++;
				p1[x][y] = 4;
				p1[x][y+1] = 4;
				p1[x][y+2] = 4;
			}
	    }
	    if(x>=2 && y>=2){//POSSIBILIDADE 4
			if((p1[x][y] == '~') && (p1[x][y-1] == '~') && (p1[x][y-2] == '~')){//ESQUERDA
				s++;
				p1[x][y] = 4;
				p1[x][y-1] = 4;
				p1[x][y-2] = 4;
			}
			else if((p1[x][y] == '~') && (p1[x+1][y] == '~') && (p1[x+2][y] == '~')){//BAIXO
				s++;
				p1[x][y] = 4;
				p1[x+1][y] = 4;
				p1[x+2][y] = 4;
			}
			else if((p1[x][y] == '~') && (p1[x][y+1] == '~') && (p1[x][y+2] == '~')){//DIREITA
				s++;
				p1[x][y] = 4;
				p1[x][y+1] = 4;
				p1[x][y+2] = 4;
			}
				if((p1[x][y] == '~') && (p1[x-1][y] == '~') && (p1[x-2][y] == '~')){//CIMA
				s++;
				p1[x][y] = 4;
				p1[x-1][y] = 4;
				p1[x-2][y] = 4;
			}
		}
		if(x==7){//POSSIBILIDADE 6
			if((p1[x][y] == '~') && (p1[x][y+1] == '~') && (p1[x][y+2] == '~')){//DIREITA
				s++;
				p1[x][y] = 4;
				p1[x][y+1] = 4;
				p1[x][y+2] = 4;
			}
			else if((p1[x][y] == '~') && (p1[x-1][y] == '~') && (p1[x-2][y] == '~')){//CIMA
				s++;
				p1[x][y] = 4;
				p1[x-1][y] = 4;
				p1[x-2][y] = 4;
			}
		}				
	}
} 

int xparanumero(char x){
	if(x=='a'){
		x=0;
	}
	if(x=='b'){ 
		x=1;
	}
	if(x=='c'){ 
		x=2;
	}
	if(x=='d'){ 
		x=3;
	}
	if(x=='e'){ 
		x=4;
	}
	if(x=='f'){ 
		x=5;
	}
	if(x=='g'){ 
		x=6;
	}
	if(x=='h'){ 
		x=7;
	}
		
	if(x=='A'){
		x=0;
	}
	if(x=='B'){ 
		x=1;
	}
	if(x=='C'){ 
		x=2;
	}
	if(x=='D'){ 
		x=3;
	}
	if(x=='E'){ 
		x=4;
	}
	if(x=='F'){ 
		x=5;
	}
	if(x=='G'){ 
		x=6;
	}
	if(x=='H'){ 
		x=7;
	}
	return x;
}
		 
int ataque(char p2[8][8], char p2censurada[8][8], char x, int y,int r){
	x=xparanumero(x);
	y=y-1;		

	if(r==1){
		if (p2[x][y]=='X' || p2[x][y]=='O' || y>7 || y<0 || x>7 || x<0){
			printf("\nVocê já atirou nessa posição ou essa posição é inválida!");
			printf("\nVocê perdeu a vez! Pressione qualquer tecla pra continuar...");
			getch();
			return 0;		
		}
		if(x!=7){	
			if(p2[x][y] == 1 || p2[x][y] == 3 || p2[x][y] == 4 || p2[x][y] == 5){
				p2[x][y]='X';
				p2censurada[x][y] = 'X';
			}
			else{
				p2[x][y] = 'O';
				p2censurada[x][y] = 'O';	
			}
			if(p2[x+1][y] == 1 || p2[x+1][y] == 3 || p2[x+1][y] == 4 || p2[x+1][y] == 5 || p2[x+1][y] == 'X'){
				p2[x+1][y]='X';	
				p2censurada[x+1][y] = 'X';	
			}
			else{
				p2[x+1][y] = 'O';
				p2censurada[x+1][y] = 'O';	
			}	
		}
		else {
			if(p2[x][y] == 1 || p2[x][y] == 3 || p2[x][y] == 4 || p2[x][y] == 5 || p2[x][y] == 'X'){
				p2[x][y]='X';
				p2censurada[x][y] = 'X';
			}
			else{
				p2[x][y] = 'O';
				p2censurada[x][y] = 'O';	
			}
		}

	}
	
	if(r==2){
		if (p2[x][y]=='X' || p2[x][y]=='O' || y>7 || y<0 || x>7 || x<0){
			printf("\nVocê já atirou nessa posição ou essa posição é inválida!");
			printf("\nVocê perdeu a vez! Pressione qualquer tecla pra continuar...");
			getch();
			return 0;				
		}
		if (y!=7){
			if(p2[x][y] == 1 || p2[x][y] == 3 || p2[x][y] == 4 || p2[x][y] == 5){
				p2[x][y]='X';
				p2censurada[x][y] = 'X';
			}
			else{
				p2[x][y] = 'O';
				p2censurada[x][y] = 'O';	
			}
			if(p2[x][y+1] == 1 || p2[x][y+1] == 3 || p2[x][y+1] == 4 || p2[x][y+1] == 5 || p2[x][y+1] == 'X'){
				p2[x][y+1]='X';
				p2censurada[x][y+1] = 'X';
			}
			else{
				p2[x][y+1]='O';
				p2censurada[x][y+1] = 'O';	
			}	
		}
		else {
			if(p2[x][y] == 1 || p2[x][y] == 3 || p2[x][y] == 4 || p2[x][y] == 5 || p2[x][y] == 'X'){
				p2[x][y]='X';
				p2censurada[x][y] = 'X';
			}
			else{
				p2[x][y] = 'O';
				p2censurada[x][y] = 'O';	
			}				
		}
	}
	if(r==4){
		if (p2[x][y]=='X' || p2[x][y]=='O' || y>7 || y<0 || x>7 || x<0){
			printf("\nVocê já atirou nessa posição ou essa posição é inválida!");
			printf("\nVocê perdeu a vez! Pressione qualquer tecla pra continuar...");
			getch();
			return 0;				
		}
		if(p2[x][y] == 1 || p2[x][y] == 3 || p2[x][y] == 4 || p2[x][y] == 5){
			p2[x][y]='X';
			p2censurada[x][y] = 'X';
		}
		else{
			p2[x][y] = 'O';
			p2censurada[x][y] = 'O';	
		}
	}
	
	if(r==3){
		if (p2[x][y]=='X' || p2[x][y]=='O' || y>7 || y<0 || x>7 || x<0){
			printf("\nVocê já atirou nessa posição ou essa posição é inválida!");
			printf("\nVocê perdeu a vez! Pressione qualquer tecla pra continuar...");
			getch();
			return 0;				
		}
		
		if(x>=1 && y>=1 && x<=6 && y<=6){
			if(p2[x][y] == 1 || p2[x][y] == 3 || p2[x][y] == 4 || p2[x][y] == 5){
			p2[x][y]='X';
			p2censurada[x][y] = 'X';
			}
			else{
			p2[x][y] = 'O';
			p2censurada[x][y] = 'O';	
			}	
			if(p2[x][y+1] == 1 || p2[x][y+1] == 3 || p2[x][y+1] == 4 || p2[x][y+1] == 5 || p2[x][y+1] == 'X'){
			p2[x][y+1]='X';
			p2censurada[x][y+1] = 'X';
			}
			else{
				p2[x][y+1]='O';
				p2censurada[x][y+1] = 'O';	
			}
			if(p2[x][y-1] == 1 || p2[x][y-1] == 3 || p2[x][y-1] == 4 || p2[x][y-1] == 5 || p2[x][y-1] == 'X'){
				p2[x][y-1]='X';
				p2censurada[x][y-1] = 'X';
			}
			else{
				p2[x][y-1]='O';
				p2censurada[x][y-1] = 'O';	
			}			
			if(p2[x+1][y] == 1 || p2[x+1][y] == 3 || p2[x+1][y] == 4 || p2[x+1][y] == 5 || p2[x+1][y] == 'X'){
				p2[x+1][y]='X';	
				p2censurada[x+1][y] = 'X';	
			}
			else{
				p2[x+1][y] = 'O';
				p2censurada[x+1][y] = 'O';	
			}
			if(p2[x-1][y] == 1 || p2[x-1][y] == 3 || p2[x-1][y] == 4 || p2[x-1][y] == 5 || p2[x-1][y] == 'X'){
				p2[x-1][y]='X';	
				p2censurada[x-1][y] = 'X';	
			}
			else{
				p2[x-1][y] = 'O';
				p2censurada[x-1][y] = 'O';	
			}
			
		}
		
		if(x==0 && y==0){
			if(p2[x][y] == 1 || p2[x][y] == 3 || p2[x][y] == 4 || p2[x][y] == 5){
				p2[x][y]='X';
				p2censurada[x][y] = 'X';
			}
			else{
				p2[x][y] = 'O';
				p2censurada[x][y] = 'O';	
			}	
			if(p2[x][y+1] == 1 || p2[x][y+1] == 3 || p2[x][y+1] == 4 || p2[x][y+1] == 5 || p2[x][y+1] == 'X'){
				p2[x][y+1]='X';
				p2censurada[x][y+1] = 'X';
			}
			else{
				p2[x][y+1]='O';
				p2censurada[x][y+1] = 'O';	
			}			
			if(p2[x+1][y] == 1 || p2[x+1][y] == 3 || p2[x+1][y] == 4 || p2[x+1][y] == 5 || p2[x+1][y] == 'X'){
				p2[x+1][y]='X';	
				p2censurada[x+1][y] = 'X';	
			}
			else{
				p2[x+1][y] = 'O';
				p2censurada[x+1][y] = 'O';	
			}
			
		}
		
		if(x==7 && y==0){
			if(p2[x][y] == 1 || p2[x][y] == 3 || p2[x][y] == 4 || p2[x][y] == 5){
				p2[x][y]='X';
				p2censurada[x][y] = 'X';
			}
			else{
				p2[x][y] = 'O';
				p2censurada[x][y] = 'O';	
			}	
			if(p2[x][y+1] == 1 || p2[x][y+1] == 3 || p2[x][y+1] == 4 || p2[x][y+1] == 5 || p2[x][y+1] == 'X'){
				p2[x][y+1]='X';
				p2censurada[x][y+1] = 'X';
			}
			else{
				p2[x][y+1]='O';
				p2censurada[x][y+1] = 'O';	
			}			
			if(p2[x-1][y] == 1 || p2[x-1][y] == 3 || p2[x-1][y] == 4 || p2[x-1][y] == 5 || p2[x-1][y] == 'X'){
				p2[x-1][y]='X';	
				p2censurada[x-1][y] = 'X';	
			}
			else{
				p2[x-1][y] = 'O';
				p2censurada[x-1][y] = 'O';	
			}		
		}
		
		if(x==7 && y==7){
			if(p2[x][y] == 1 || p2[x][y] == 3 || p2[x][y] == 4 || p2[x][y] == 5){
				p2[x][y]='X';
				p2censurada[x][y] = 'X';
			}
			else{
				p2[x][y] = 'O';
				p2censurada[x][y] = 'O';	
			}
			if(p2[x][y-1] == 1 || p2[x][y-1] == 3 || p2[x][y-1] == 4 || p2[x][y-1] == 5 || p2[x][y-1] == 'X'){
				p2[x][y-1]='X';
				p2censurada[x][y-1] = 'X';
			}
			else{
				p2[x][y-1]='O';
				p2censurada[x][y-1] = 'O';	
			}			
			if(p2[x-1][y] == 1 || p2[x-1][y] == 3 || p2[x-1][y] == 4 || p2[x-1][y] == 5 || p2[x-1][y] == 'X'){
				p2[x-1][y]='X';	
				p2censurada[x-1][y] = 'X';	
			}
			else{
				p2[x-1][y] = 'O';
				p2censurada[x-1][y] = 'O';	
			}			
		}
		
		if(x==0 && y==7){
			if(p2[x][y] == 1 || p2[x][y] == 3 || p2[x][y] == 4 || p2[x][y] == 5){
				p2[x][y]='X';
				p2censurada[x][y] = 'X';
			}
			else{
				p2[x][y] = 'O';
				p2censurada[x][y] = 'O';	
			}	
			if(p2[x][y-1] == 1 || p2[x][y-1] == 3 || p2[x][y-1] == 4 || p2[x][y-1] == 5 || p2[x][y-1] == 'X'){
				p2[x][y-1]='X';
				p2censurada[x][y-1] = 'X';
			}
			else{
				p2[x][y-1]='O';
				p2censurada[x][y-1] = 'O';	
			}			
			if(p2[x+1][y] == 1 || p2[x+1][y] == 3 || p2[x+1][y] == 4 || p2[x+1][y] == 5 || p2[x+1][y] == 'X'){
				p2[x+1][y]='X';	
				p2censurada[x+1][y] = 'X';	
			}
			else{
				p2[x+1][y] = 'O';
				p2censurada[x+1][y] = 'O';	
			}			
		}
		
		if(x==0 && y>=1 && y<7){
			if(p2[x][y] == 1 || p2[x][y] == 3 || p2[x][y] == 4 || p2[x][y] == 5){
				p2[x][y]='X';
				p2censurada[x][y] = 'X';
			}
			else{
				p2[x][y] = 'O';
				p2censurada[x][y] = 'O';	
			}	
			if(p2[x][y+1] == 1 || p2[x][y+1] == 3 || p2[x][y+1] == 4 || p2[x][y+1] == 5 || p2[x][y+1] == 'X'){
				p2[x][y+1]='X';
				p2censurada[x][y+1] = 'X';
			}
			else{
				p2[x][y+1]='O';
				p2censurada[x][y+1] = 'O';	
			}
			if(p2[x][y-1] == 1 || p2[x][y-1] == 3 || p2[x][y-1] == 4 || p2[x][y-1] == 5 || p2[x][y-1] == 'X'){
				p2[x][y-1]='X';
				p2censurada[x][y-1] = 'X';
			}
			else{
				p2[x][y-1]='O';
				p2censurada[x][y-1] = 'O';	
			}			
			if(p2[x+1][y] == 1 || p2[x+1][y] == 3 || p2[x+1][y] == 4 || p2[x+1][y] == 5 || p2[x+1][y] == 'X'){
				p2[x+1][y]='X';	
				p2censurada[x+1][y] = 'X';	
			}
			else{
				p2[x+1][y] = 'O';
				p2censurada[x+1][y] = 'O';	
			}		
		}
		
		if(x>=1 && x<7 && y==0){
			if(p2[x][y] == 1 || p2[x][y] == 3 || p2[x][y] == 4 || p2[x][y] == 5){
				p2[x][y]='X';
				p2censurada[x][y] = 'X';
			}
			else{
				p2[x][y] = 'O';
				p2censurada[x][y] = 'O';	
			}	
			if(p2[x][y+1] == 1 || p2[x][y+1] == 3 || p2[x][y+1] == 4 || p2[x][y+1] == 5 || p2[x][y+1] == 'X'){
				p2[x][y+1]='X';
				p2censurada[x][y+1] = 'X';
			}
			else{
				p2[x][y+1]='O';
				p2censurada[x][y+1] = 'O';	
			}			
			if(p2[x+1][y] == 1 || p2[x+1][y] == 3 || p2[x+1][y] == 4 || p2[x+1][y] == 5 || p2[x+1][y] == 'X'){
				p2[x+1][y]='X';	
				p2censurada[x+1][y] = 'X';	
			}
			else{
				p2[x+1][y] = 'O';
				p2censurada[x+1][y] = 'O';	
			}
			if(p2[x-1][y] == 1 || p2[x-1][y] == 3 || p2[x-1][y] == 4 || p2[x-1][y] == 5 || p2[x-1][y] == 'X'){
				p2[x-1][y]='X';	
				p2censurada[x-1][y] = 'X';	
			}
			else{
				p2[x-1][y] = 'O';
				p2censurada[x-1][y] = 'O';	
			}			
		}
		
		if(x==7 && y>=1 && y<7){
			if(p2[x][y] == 1 || p2[x][y] == 3 || p2[x][y] == 4 || p2[x][y] == 5){
				p2[x][y]='X';
				p2censurada[x][y] = 'X';
			}
			else{
				p2[x][y] = 'O';
				p2censurada[x][y] = 'O';	
			}	
			if(p2[x][y+1] == 1 || p2[x][y+1] == 3 || p2[x][y+1] == 4 || p2[x][y+1] == 5 || p2[x][y+1] == 'X'){
				p2[x][y+1]='X';
				p2censurada[x][y+1] = 'X';
			}
			else{
				p2[x][y+1]='O';
				p2censurada[x][y+1] = 'O';	
			}
			if(p2[x][y-1] == 1 || p2[x][y-1] == 3 || p2[x][y-1] == 4 || p2[x][y-1] == 5 || p2[x][y-1] == 'X'){
				p2[x][y-1]='X';
				p2censurada[x][y-1] = 'X';
			}
			else{
				p2[x][y-1]='O';
				p2censurada[x][y-1] = 'O';	
			}			
			if(p2[x-1][y] == 1 || p2[x-1][y] == 3 || p2[x-1][y] == 4 || p2[x-1][y] == 5 || p2[x-1][y] == 'X'){
				p2[x-1][y]='X';	
				p2censurada[x-1][y] = 'X';	
			}
			else{
				p2[x-1][y] = 'O';
				p2censurada[x-1][y] = 'O';	
			}			
		}		
		
		if(y==7 && x>=1 && x<7){
			if(p2[x][y] == 1 || p2[x][y] == 3 || p2[x][y] == 4 || p2[x][y] == 5){
				p2[x][y]='X';
				p2censurada[x][y] = 'X';
			}
			else{
				p2[x][y] = 'O';
				p2censurada[x][y] = 'O';	
			}	
			if(p2[x][y-1] == 1 || p2[x][y-1] == 3 || p2[x][y-1] == 4 || p2[x][y-1] == 5 || p2[x][y-1] == 'X'){
				p2[x][y-1]='X';
				p2censurada[x][y-1] = 'X';
			}
			else{
				p2[x][y-1]='O';
				p2censurada[x][y-1] = 'O';	
			}			
			if(p2[x+1][y] == 1 || p2[x+1][y] == 3 || p2[x+1][y] == 4 || p2[x+1][y] == 5 || p2[x+1][y] == 'X'){
				p2[x+1][y]='X';	
				p2censurada[x+1][y] = 'X';	
			}
			else{
				p2[x+1][y] = 'O';
				p2censurada[x+1][y] = 'O';	
			}
			if(p2[x-1][y] == 1 || p2[x-1][y] == 3 || p2[x-1][y] == 4 || p2[x-1][y] == 5 || p2[x-1][y] == 'X'){
				p2[x-1][y]='X';	
				p2censurada[x-1][y] = 'X';	
			}
			else{
				p2[x-1][y] = 'O';
				p2censurada[x-1][y] = 'O';	
			}			
		}
	}
	BufferLimpar();
}

int dica(char p2[8][8], char x, int y){
	int j, cont1=0, cont2 = 0;
 	int i;
 	x=xparanumero(x);
	
	y=y-1;
	
	int embarcacao=0, embarcacao2=0, embarcacao3=0, embarcacao4=0 ;
    for(i=0;i<8;i++){
        p2[i][y];
        if(p2[i][y] == 1 && embarcacao == 0){
            cont1++;
           embarcacao++;
       }

       if(p2[i][y] == 3 && embarcacao2 == 0){
            cont1++;
           embarcacao2++;
       }
       if(p2[i][y] == 4 && embarcacao3 == 0){
            cont1++;
           embarcacao3++;
       }
       if(p2[i][y] == 5 && embarcacao4 == 0){
            cont1++;
           embarcacao4++;
       }
    }
    
    if(embarcacao==2){
            printf("Tem um caça nesta coluna.\n");
    }else {
    	if(embarcacao==1){
        	printf("Tem um caça cruzando nesta coluna.\n");
  	  } 
	}  
    if(embarcacao2==4){
        printf("Tem um porta-avião nesta coluna.\n");
    }else{
    	if(embarcacao2==1){
        	printf("Tem um porta avião cruzando nesta coluna.\n");
   		}
    }

    if(embarcacao3==3){
        printf("Tem uma escolta nesta coluna.\n");
    }else{
    	if(embarcacao3==1){
        	printf("Tem uma escolta cruzando nesta coluna.\n");
		}
	}
    if(embarcacao4==2){
        printf("Tem um submarino nesta coluna.\n");
    }else{
    	 if(embarcacao4==1){
        	printf("Tem um submarino cruzando nesta coluna.\n");
    	}
	}
	if(cont1==0){
		printf("Não tem nenhuma embarcação nesta coluna.\n");
	}
    embarcacao=0;
    embarcacao2=0;
    embarcacao3=0;
    embarcacao4=0;
    for(j=0;j<8;j++){
         p2[x][j];
         if(p2[x][j] == 1){
             cont1++;
            embarcacao++;
            cont2++;
        }

        if(p2[x][j] == 3){
			cont2++;
            embarcacao2++;
        }
        if(p2[x][j] == 4){
			cont2++;
            embarcacao3++;
        }
        if(p2[x][j] == 5){
            embarcacao4++;
            cont2++;
        }
    }
    if(embarcacao==2){
        printf("Tem um caça cruzando nesta linha.\n");
    }else{
        if(embarcacao==1){
            printf("Tem um caça nesta linha.\n");
        }
    }
	   
    if(embarcacao2==4){
        printf("Tem um porta-avião nesta linha.\n");
    }else{
    	if(embarcacao2==1){
       		printf("Tem um porta avião cruzando nesta linha.\n");
   		}	
	}
	
    if(embarcacao3==1){
        printf("Tem uma escolta cruzando nesta linha.\n");
    }else{
    	if(embarcacao3==3){
    		printf("Tem uma escolta nesta linha.\n");
  		}
	}
	
    if(embarcacao4==2){
        printf("Tem um submarino nesta linha.\n");
    }else{
    	if(embarcacao4==1){
        	printf("Tem um submarino cruzando nesta linha.\n");
   		}	
	}
	
	if(cont2==0){
		printf("Não tem nenhuma embarcação nesta linha.\n");
	}
    getch();
}


void ataqueinimigo(char p1[8][8], int pn_2,int cn_2,int sn_2,int en_2){
	int x = rand() % 8;
	int y = rand() % 8;
	int r = (rand()%3)+1;	
	
	if(r==1){
		if (p1[x][y]=='X' || p1[x][y]=='O'){
			ataqueinimigo(p1,pn_2,cn_2,sn_2,en_2);			
		}	
		if(x!=7){	
			if(p1[x][y] == 1 || p1[x][y] == 3 || p1[x][y] == 4 || p1[x][y] == 5 || p1[x][y] == 'X'){
				p1[x][y]='X';
			}
			else{
				p1[x][y] = 'O';	
			}
			if(p1[x+1][y] == 1 || p1[x+1][y] == 3 || p1[x+1][y] == 4 || p1[x+1][y] == 5 || p1[x+1][y]== 'X'){
				p1[x+1][y]='X';		
			}
			else{
				p1[x+1][y] = 'O';
			}	
		}
		else {
			if(p1[x][y] == 1 || p1[x][y] == 3 || p1[x][y] == 4 || p1[x][y] == 5 || p1[x][y] == 'X'){
				p1[x][y]='X';
			}
			else{
				p1[x][y] = 'O';	
			}
		}
	}
	
	if(r==2){
		if (p1[x][y]=='X' || p1[x][y]=='O'){
			//getchar();
			ataqueinimigo(p1,pn_2,cn_2,sn_2,en_2);			
		}
		if (y!=7){
			if(p1[x][y] == 1 || p1[x][y] == 3 || p1[x][y] == 4 || p1[x][y] == 5  || p1[x][y]=='X'){
				p1[x][y]='X';
			}
			else{
				p1[x][y] = 'O';	
			}
			if(p1[x][y+1] == 1 || p1[x][y+1] == 3 || p1[x][y+1] == 4 || p1[x][y+1] == 5 || p1[x][y+1] == 'X'){
				p1[x][y+1]='X';
			}
			else{
				p1[x][y+1]='O';
			}	
		}
		else {
			if(p1[x][y] == 1 || p1[x][y] == 3 || p1[x][y] == 4 || p1[x][y] == 5 || p1[x][y] == 'X'){
				p1[x][y]='X';
			}
			else{
				p1[x][y] = 'O';	
			}				
		}
	}
	
	if(r==4){
		
		if (p1[x][y]=='X' || p1[x][y]=='O'){
			ataqueinimigo(p1,pn_2,cn_2,sn_2,en_2);			
		}
		if(p1[x][y] == 1 || p1[x][y] == 3 || p1[x][y] == 4 || p1[x][y] == 5 || p1[x][y]=='X'){
			p1[x][y]='X';
		}
		else{
			p1[x][y] = 'O';	
		}
		
	}
	
	if(r==3){	
		if (p1[x][y]=='X' || p1[x][y]=='O'){
			//getchar();
			ataqueinimigo(p1,pn_2,cn_2,sn_2,en_2);				
		}

		if(x>=1 && y>=1 && x<=6 && y<=6){
			if(p1[x][y] == 1 || p1[x][y] == 3 || p1[x][y] == 4 || p1[x][y] == 5 || p1[x][y]=='X'  || p1[x][y]=='X'){
				p1[x][y]='X';
			}
			else{
				p1[x][y] = 'O';	
			}	
			if(p1[x][y+1] == 1 || p1[x][y+1] == 3 || p1[x][y+1] == 4 || p1[x][y+1] == 5 || p1[x][y+1] == 'X'){
				p1[x][y+1]='X';
			}
			else{
				p1[x][y+1]='O';
	
			}
			if(p1[x][y-1] == 1 || p1[x][y-1] == 3 || p1[x][y-1] == 4 || p1[x][y-1] == 5 || p1[x][y-1] == 'X'){
				p1[x][y-1]='X';
			}
			else{
				p1[x][y-1]='O';
			}			
			if(p1[x+1][y] == 1 || p1[x+1][y] == 3 || p1[x+1][y] == 4 || p1[x+1][y] == 5 || p1[x+1][y] == 'X'){
				p1[x+1][y]='X';	
			}
			else{
				p1[x+1][y] = 'O';
			}
			if(p1[x-1][y] == 1 || p1[x-1][y] == 3 || p1[x-1][y] == 4 || p1[x-1][y] == 5 || p1[x-1][y] == 'X'){
				p1[x-1][y]='X';	
			}
			else{
				p1[x-1][y] = 'O';
			}
		}
		
		if(x==0 && y==0){
			if(p1[x][y] == 1 || p1[x][y] == 3 || p1[x][y] == 4 || p1[x][y] == 5 || p1[x][y]=='X'){
				p1[x][y]='X';
			}
			else{
				p1[x][y] = 'O';
			}	
			if(p1[x][y+1] == 1 || p1[x][y+1] == 3 || p1[x][y+1] == 4 || p1[x][y+1] == 5 || p1[x][y+1] == 'X'){
				p1[x][y+1]='X';
			}
			else{
				p1[x][y+1]='O';	
			}			
			if(p1[x+1][y] == 1 || p1[x+1][y] == 3 || p1[x+1][y] == 4 || p1[x+1][y] == 5 || p1[x+1][y] == 'X'){
				p1[x+1][y]='X';	
			}
			else{
				p1[x+1][y] = 'O';
			}	
		}
		
		if(x==7 && y==0){
			if(p1[x][y] == 1 || p1[x][y] == 3 || p1[x][y] == 4 || p1[x][y] == 5 || p1[x][y]=='X'){
				p1[x][y]='X';
			}
			else{
				p1[x][y] = 'O';
			}	
			if(p1[x][y+1] == 1 || p1[x][y+1] == 3 || p1[x][y+1] == 4 || p1[x][y+1] == 5 || p1[x][y+1] == 'X'){
				p1[x][y+1]='X';
			}
			else{
				p1[x][y+1]='O';
			}			
			if(p1[x-1][y] == 1 || p1[x-1][y] == 3 || p1[x-1][y] == 4 || p1[x-1][y] == 5 || p1[x-1][y] == 'X'){
				p1[x-1][y]='X';	
			}
			else{
				p1[x-1][y] = 'O';
			}		
		}
		
		if(x==7 && y==7){
			if(p1[x][y] == 1 || p1[x][y] == 3 || p1[x][y] == 4 || p1[x][y] == 5 || p1[x][y]=='X'){
				p1[x][y]='X';
			}
			else{
				p1[x][y] = 'O';
			}
			if(p1[x][y-1] == 1 || p1[x][y-1] == 3 || p1[x][y-1] == 4 || p1[x][y-1] == 5 || p1[x][y-1] == 'X'){
				p1[x][y-1]='X';
			}
			else{
				p1[x][y-1]='O';		
			}			
			if(p1[x-1][y] == 1 || p1[x-1][y] == 3 || p1[x-1][y] == 4 || p1[x-1][y] == 5 || p1[x-1][y] == 'X'){
				p1[x-1][y]='X';		
			}
			else{
				p1[x-1][y] = 'O';		
			}			
		}
		
		if(x==0 && y==7){
			if(p1[x][y] == 1 || p1[x][y] == 3 || p1[x][y] == 4 || p1[x][y] == 5 || p1[x][y]=='X'){
				p1[x][y]='X';
			}
			else{
				p1[x][y] = 'O';
			}	
			if(p1[x][y-1] == 1 || p1[x][y-1] == 3 || p1[x][y-1] == 4 || p1[x][y-1] == 5 || p1[x][y-1] == 'X'){
				p1[x][y-1]='X';
			}
			else{
				p1[x][y-1]='O';	
			}			
			if(p1[x+1][y] == 1 || p1[x+1][y] == 3 || p1[x+1][y] == 4 || p1[x+1][y] == 5 || p1[x+1][y] == 'X'){
				p1[x+1][y]='X';	
			}
			else{
				p1[x+1][y] = 'O';
			}			
		}
		
		if(x==0 && y>=1 && y<7){
			if(p1[x][y] == 1 || p1[x][y] == 3 || p1[x][y] == 4 || p1[x][y] == 5 || p1[x][y]=='X'){
				p1[x][y]='X';
			}
			else{
				p1[x][y] = 'O';	
			}	
			if(p1[x][y+1] == 1 || p1[x][y+1] == 3 || p1[x][y+1] == 4 || p1[x][y+1] == 5 || p1[x][y+1] == 'X'){
				p1[x][y+1]='X';
			}
			else{
				p1[x][y+1]='O';	
			}
			if(p1[x][y-1] == 1 || p1[x][y-1] == 3 || p1[x][y-1] == 4 || p1[x][y-1] == 5 || p1[x][y-1] == 'X'){
				p1[x][y-1]='X';	
			}
			else{
				p1[x][y-1]='O';
			}			
			if(p1[x+1][y] == 1 || p1[x+1][y] == 3 || p1[x+1][y] == 4 || p1[x+1][y] == 5 || p1[x][y-1] == 'X'){
				p1[x+1][y]='X';	
			}
			else{
				p1[x+1][y] = 'O';
			}		
		}
		
		if(x>=1 && x<7 && y==0){
			if(p1[x][y] == 1 || p1[x][y] == 3 || p1[x][y] == 4 || p1[x][y] == 5 || p1[x][y]=='X'){
				p1[x][y]='X';
			}
			else{
				p1[x][y] = 'O';
			}	
			if(p1[x][y+1] == 1 || p1[x][y+1] == 3 || p1[x][y+1] == 4 || p1[x][y+1] == 5 || p1[x][y+1] == 'X'){
				p1[x][y+1]='X';
			}
			else{
				p1[x][y+1]='O';
			}			
			if(p1[x+1][y] == 1 || p1[x+1][y] == 3 || p1[x+1][y] == 4 || p1[x+1][y] == 5 || p1[x+1][y] == 'X'){
				p1[x+1][y]='X';		
			}
			else{
				p1[x+1][y] = 'O';		
			}
			if(p1[x-1][y] == 1 || p1[x-1][y] == 3 || p1[x-1][y] == 4 || p1[x-1][y] == 5 || p1[x-1][y] == 'X'){
				p1[x-1][y]='X';	
			}
			else{
				p1[x-1][y] = 'O';
			}			
		}
		
		if(x==7 && y>=1 && y<7){
			if(p1[x][y] == 1 || p1[x][y] == 3 || p1[x][y] == 4 || p1[x][y] == 5 || p1[x][y]=='X'){
				p1[x][y]='X';
			}
			else{
				p1[x][y] = 'O';		
			}	
			if(p1[x][y+1] == 1 || p1[x][y+1] == 3 || p1[x][y+1] == 4 || p1[x][y+1] == 5 || p1[x][y+1] == 'X'){
				p1[x][y+1]='X';
			}
			else{
				p1[x][y+1]='O';	
			}
			if(p1[x][y-1] == 1 || p1[x][y-1] == 3 || p1[x][y-1] == 4 || p1[x][y-1] == 5 || p1[x][y-1] == 'X'){
				p1[x][y-1]='X';
			}
			else{
				p1[x][y-1]='O';		
			}			
			if(p1[x-1][y] == 1 || p1[x-1][y] == 3 || p1[x-1][y] == 4 || p1[x-1][y] == 5 || p1[x-1][y] == 'X'){
				p1[x-1][y]='X';			
			}
			else{
				p1[x-1][y] = 'O';	
			}			
		}		
		
		if(y==7 && x>=1 && x<7){
			if(p1[x][y] == 1 || p1[x][y] == 3 || p1[x][y] == 4 || p1[x][y] == 5 || p1[x][y]=='X'){
				p1[x][y]='X';
			}
			else{
				p1[x][y] = 'O';	
			}	
			if(p1[x][y-1] == 1 || p1[x][y-1] == 3 || p1[x][y-1] == 4 || p1[x][y-1] == 5 || p1[x][y-1] == 'X'){
				p1[x][y-1]='X';		
			}
			else{
				p1[x][y-1]='O';			
			}			
			if(p1[x+1][y] == 1 || p1[x+1][y] == 3 || p1[x+1][y] == 4 || p1[x+1][y] == 5 || p1[x+1][y] == 'X'){
				p1[x+1][y]='X';				
			}
			else{
				p1[x+1][y] = 'O';		
			}
			if(p1[x-1][y] == 1 || p1[x-1][y] == 3 || p1[x-1][y] == 4 || p1[x-1][y] == 5 || p1[x-1][y] == 'X'){
				p1[x-1][y]='X';			
			}
			else{
				p1[x-1][y] = 'O';	
			}			
		}				
	}	
}
int menuselect(char p1[8][8], char p2[8][8], char p2censurada[8][8], int contdica){
	int soma_2=11; //Inicia com 11 partes de navios, vai descontando conforme acertos
	int soma_1=11; //Inicia com 11 partes de navios, vai descontando conforme acertos
	int menu2; //
	int i; //
	int j; //
	char pos1; //ataque
	int pos2; //ataque
	char sdica; //variável que auxilia na dica
					while(soma_2!=0 || soma_1!=0) {//Repetição de Rounds até os návios de uma das tabela ser zerado
					do{	
						limpartela();
						mostrarp1(p1);
						//mostrarp2(p2);	
						mostrarp2censurada(p2censurada);	
						printf("Menu de opções:\n");
						printf("1 - Atirar\n");
						printf("2 - Dica\n");
						printf("3 - Salvar\n");
						printf("4 - Sobre o jogo\n");
						printf("5 - Sair\n");
						printf("Digite sua opção: \n");
						
						if(menu2==10){
							menu2=1;
							limpartela();	
						} else {
							scanf("%d", &menu2);
						}
	
						if(menu2<1 || menu2>5){
							printf("O número inserido é invalido \n");
							int contdica=0;	//conmtagem de dicas
						}	
						if(menu2==1){
							int r=1;
							if(r!=1 || r!=2 || r!=3 ||r!=4 ||r!=5 ){			
								int p_1=0,c_1=0,s_1=0,e_1=0;
								int pn_1=0,cn_1=0,sn_1=0,en_1=0;
								int p_2=0,c_2=0,s_2=0,e_2=0;
								int pn_2=0,cn_2=0,sn_2=0,en_2=0;
								
								mostrarp1(p1); //Mostra o tabuleiro p1
								//mostrarp2(p2); //Mostra o tabuleiro p2
								mostrarp2censurada(p2censurada); //Mostra o tabuleiro p2 censurado, ou seja, com água
								
								for(i=0;i<8;i++){ //Contagem navios p2
									for(j=0;j<8;j++){
										if(p2[i][j]==1){
											c_2++;
											if(c_2>=1){
												cn_2=1;
											}
										}
										if(p2[i][j]==5){
											s_2++;
											if(s_2>=1){
												sn_2=1;
											}	
										}
										if(p2[i][j]==3){
											p_2++;
											if(p_2>=1){
												pn_2=1;
											}	
										}
										if(p2[i][j]==4){
											e_2++;
											if(e_2>=1){
												en_2=1;
											}	
										}
									}
								}
								for(i=0;i<8;i++){ //Contagem navios p1
									for(j=0;j<8;j++){
										if(p1[i][j]==1){
											c_1++;
											if(c_1>=1){
												cn_1=1;
											}
										}
										if(p1[i][j]==5){
											s_1++;
											if(s_1>=1){
												sn_1=1;
											}	
										}
										if(p1[i][j]==3){
											p_1++;
											if(p_1>=1){
												pn_1=1;
											}	
										}
										if(p1[i][j]==4){
											e_1++;
											if(e_1>=1){
												en_1=1;
											}	
										}
									}
								}
								printf(" ---------------------------------   ---------------------------------\n");
								printf(" |         SEUS NAVIOS           |   |         NAVIOS INIMIGOS       |\n");
								printf(" |-------------------------------|   |-------------------------------|  --------------  \n");
								printf(" |  Coração(%c): Porta-avião (%i)  |   |  Coração(%c): Porta-avião (%i)  |  |x -> ACERTO!|  \n ",3, pn_1,3,pn_2);
								printf("|  Diamante(%c): Escolta (%i)     |   |  Diamante(%c): Escolta (%i)     |  |O -> ERRO!  |  \n ",4, en_1,4,en_2); 
								printf("|  Carinha(%c): Caça (%i)         |   |  Carinha(%c): Caça (%i)         |  |~ ->   ÁGUA |  \n ",1, cn_1,1,cn_2);
								printf("|  Trevo(%c): Submarino (%i)      |   |  Trevo(%c): Submarino (%i)      |  --------------  \n ",5, sn_1,5,sn_2);
								printf("---------------------------------   ---------------------------------                  \n");
								soma_1=((pn_1+en_1)+(cn_1+sn_1));
								soma_2=((pn_2+en_2)+(cn_2+sn_2));
								if(soma_2==0){
									int opcao1;
									limpartela();
									printf("\nParabéns, você destruiu as tropas inimigas!");
									printf("Você quer jogar novamente?\n");
									printf("\t1- Jogar\n");
									printf("\t2- Não\n");
									scanf("%d", &opcao1);
									if(opcao1==1){
										limpar(p1, p2, p2censurada);
										posicionar_CACA_P2(p2);
										posicionar_CACA_P1(p1);
										posicionar_PORTAAVIAO_P2(p2);
										posicionar_PORTAAVIAO_P1(p1);
										posicionar_SUBMARINO_P2(p2);
										posicionar_SUBMARINO_P1(p1);
										posicionar_ESCOLTA_P2(p2);
										posicionar_ESCOLTA_P1(p1);
										menuselect(p1, p2, p2censurada, contdica);
										limpartela();
									} else {
										break;
									}
									break;	
								}
								if(soma_1==0){
									int opcao2;
									limpartela();
									printf("YOU LOSE!");
									printf("Você quer jogar novamente?\n");
									printf("\t1- Jogar\n");
									printf("\t2- Não\n");
									scanf("%d", &opcao2);
									if(opcao2==1){
										limpar(p1, p2, p2censurada);
										posicionar_CACA_P2(p2);
										posicionar_CACA_P1(p1);
										posicionar_PORTAAVIAO_P2(p2);
										posicionar_PORTAAVIAO_P1(p1);
										posicionar_SUBMARINO_P2(p2);
										posicionar_SUBMARINO_P1(p1);
										posicionar_ESCOLTA_P2(p2);
										posicionar_ESCOLTA_P1(p1);
										menuselect(p1, p2, p2censurada, contdica);
										limpartela();
									} else {
										break;
									}
									break;	
								}
								printf("Digite qual dos seus návios você deseja utilizar:\n");
								printf("1 - Porta-avião\n");
								printf("2 - Escolta\n");
								printf("3 - Caça\n");
								printf("4 - Submarino\n");
								scanf("%i",&r);
								while(r>4 || r<1){
									printf("Valor incorreto, digite novamente: \n");
									BufferLimpar();
									scanf("%i",&r);
								}
								if(r==1){
									if(pn_1==0){
										printf("Digite um navio que esteja vivo! Pressione uma tecla pra continuar...\n");
										getch();
										menu2=10;
											
									}
									else{
										r=1;
										printf("\nDigite uma linha e uma coluna para atacar com porta-avião:");
										BufferLimpar();
										scanf("%c%i",&pos1,&pos2);	
										ataque(p2,p2censurada,pos1,pos2,r);
										ataqueinimigo(p1,pn_2,cn_2,sn_2,en_2);
										mostrarp1(p1);
										mostrarp2(p2);

									}	
								}
								if(r==2){
									if(en_1==0){
										printf("Digite um navio que esteja vivo! Pressione uma tecla pra continuar...\n");
										getch();
										menu2=10;
									}
									else{
										r=2;
										printf("\nDigite uma linha e uma coluna para atacar com escolta:");
										BufferLimpar();
										scanf("%c%i",&pos1,&pos2);	
										ataque(p2,p2censurada,pos1,pos2,r);	
										ataqueinimigo(p1,pn_2,cn_2,sn_2,en_2);
										mostrarp1(p1);
										mostrarp2(p2);
									}
								}
								if(r==3){
									if(cn_1==0){
										printf("Digite um navio que esteja vivo! Pressione uma tecla pra continuar...\n");
										getch();
										menu2=10;
									}
									else{
										r=3;
										printf("\nDigite uma linha e uma coluna para atacar com caça:");
										BufferLimpar();
										scanf("%c%i",&pos1,&pos2);
										ataque(p2,p2censurada,pos1,pos2,r);
										ataqueinimigo(p1,pn_2,cn_2,sn_2,en_2);	
										mostrarp1(p1);
										mostrarp2(p2);	
									}
								}
								if(r==4){
									if(sn_1==0){
										printf("Digite um navio que esteja vivo! Pressione uma tecla pra continuar...\n");
										getch();
										menu2=10;
									}
									else{
										r=4;
										printf("\nDigite uma linha e uma coluna para atacar com submarino:");
										BufferLimpar();
										scanf("%c%i",&pos1,&pos2);
										ataque(p2,p2censurada,pos1,pos2,r);	
										ataqueinimigo(p1,pn_2,cn_2,sn_2,en_2);
										mostrarp1(p1);
										mostrarp2(p2);
									}
								}
							}
						}
						if(menu2<=0 || menu2>5){
							printf("O número inserido é invalido \n");
							system ("pause");
						}		
						if(menu2==2){	
							if(contdica<3){		
			 					printf("Digite uma linha e coluna para saber se tem alguma embarcação:");
			 					BufferLimpar();
								scanf("%c%i", &pos1,&pos2);	
								dica(p2, pos1, pos2);
								contdica++;	
								
			 				}
							else {
								printf("Você não tem mais dica :( \n");	
								system("pause");
			 					
							}
							sdica = contdica+'0';
						}
						if(menu2==3){
							char p_1[8][8], p_2[8][8], p_2c[8][8];
							FILE *arq = fopen("banco.txt","w+");
							
							int i, j;
							
							if(arq==NULL){
								perror("ERRO:");
							}
							else{
								
																
								for(j=0;j<8;j++){
									fprintf(arq,"\n",p_1[j][i]);
									for(i=0;i<8;i++){
										fflush(stdin);
										if(p1[j][i]=='~'){
											p_1[j][i]='9';
										}
										if(p1[j][i]=='O'){
											p_1[j][i]='O';	
										}
										if(p1[j][i]=='X'){
											p_1[j][i]='X';
										}
										if(p1[j][i]==4){
											p_1[j][i]='4';
										}
										if(p1[j][i]==1){
											p_1[j][i]='1';	
										}
										if(p1[j][i]==5){
											p_1[j][i]='5';	
										}
										if(p1[j][i]==3){
											p_1[j][i]='3';	
										}
										fprintf(arq,"\t%c",p_1[j][i]);										
									}	
								}									
								fprintf(arq,"\n \n");
								for(j=0;j<8;j++){
									fprintf(arq,"\n",p_2[j][i]);
									for(i=0;i<8;i++){
										fflush(stdin);
										if(p2[j][i]=='~'){
											p_2[j][i]='9';
										}
										if(p2[j][i]=='O'){
											p_2[j][i]='O';	
										}
										if(p2[j][i]=='X'){
											p_2[j][i]='X';
										}
										if(p2[j][i]==4){
											p_2[j][i]='4';
										}
										if(p2[j][i]==1){
											p_2[j][i]='1';	
										}
										if(p2[j][i]==5){
											p_2[j][i]='5';	
										}
										if(p2[j][i]==3){
											p_2[j][i]='3';	
										}
										fprintf(arq,"\t%c",p_2[j][i]);		
																		
									}	
								}		
								
								fprintf(arq,"\n \n");
								for(j=0;j<8;j++){
									fprintf(arq,"\n",p_2c[j][i]);
									for(i=0;i<8;i++){
										fflush(stdin);
										if(p2censurada[j][i]=='~'){
											p_2c[j][i]='9';
										}
										if(p2censurada[j][i]=='O'){
											p_2c[j][i]='O';	
										}
										if(p2censurada[j][i]=='X'){
											p_2c[j][i]='X';
										}										
	
										fprintf(arq,"\t%c",p_2c[j][i]);		
																		
									}	
								}									
							
								fclose(arq);									
								printf("Arquivo gravado com sucesso!! \n");									
								system("pause");
								
								arq = fopen("dica.txt","w+");
								if(arq==NULL){
									perror("ERRO:");
								}else{
									if(contdica==0){sdica='0';}
									
									fprintf(arq,"%c",sdica);
							}
							fclose(arq);
							return 0;
							}
							
																					
						}														
						if(menu2==4){
							sobrejogo();
							system("pause");
						}													
					} while(menu2!=5);
					limpartela();
					printf("Obrigado por jogar :) \n");
					return 0;	
					
			}
	
	
	
	
}

int sobrejogo(){	
	limpartela();
	printf("\n");
	printf("\n");
	printf("\tBatalha naval é um jogo de tabuleiro de dois jogadores, no qual os jogadores\n");
	printf("\ttêm de adivinhar em que quadrados estão os navios do oponente.\n");
	printf("\t\n");
	printf("\tEmbora o primeiro jogo em tabuleiro comercializado epublicado pela \n");
	printf("\tMilton Bradley Company em 1931, o jogo foi originalmente jogado com lápis e papel.\n");
	printf("\tSeu objetivo é derrubar os barcos do oponente adversário, \n");
	printf("\tganha quem derrubar todos os navios adversários primeiro.\n");
	printf("\n");	
	printf("\tO jogo original possui duas tabelas para cada jogador — uma que representa\n");
	printf("\ta disposição dos barcos do jogador, e outra que representa a do oponente. \n");	
	printf("\tAs tabelas são tipicamente quadradas, estando identificadas na horizontal \n");
	printf("\tpor letras e na vertical por números.\n");	
	printf("\tEm cada tabela o jogador coloca os seus navios e registra os tiros do oponente.\n");
	printf("\tNo início você posicionará seus návios, e após isso o jogo começa, \n");
	printf("\tHá diferentes tipos de návios, são eles: \n");
	printf("\t\t%c Submarino(%c): OCUPA 2 casas, ACERTA 1 casa \n",16, 5);
	printf("\t\t%c Porta-avião(%c): OCUPA 4 casas, ACERTA 2 casas verticalmente, a casa escolhida e a debaixo \n",16, 3);
	printf("\t\t%c Escolta(%c): OCUPA 3 casas, ACERTA 2 casas horizontalmente, a casa escolhida e a da direita \n",16, 4);
	printf("\t\t%c Caça(%c): OCUPA 2 casas, ACERTA 5 casas, a casa escolhida e em sua volta (cima,baixo,esquerda e direita) \n",16, 1);
	printf("\tGanha quem acabar com os návios do oponente primeiro. Bom jogo!\n\n");
	printf("\tEquipe de desenvolvimento: Bernardo Ferrão\n");
	printf("\t\t\t\t   Edmilson Batista\n");
	printf("\t\t\t\t   Pedro Rosa\n\n");
}

void limpartela(void){
	#ifdef __linux__
		system("clear");
	#elif _WIN32
		system("cls");
	#else
	#endif
}

