#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

void limpar(char p1[8][8], char p2[8][8], char p2censurada[8][8]);
void mostrarp1(char p1[8][8]);
void mostrarp2(char p2[8][8]);
void mostrarp2censurada(char p2censurada[8][8]);
void posicionar_CACA_P2(char p2[8][8]);
void posicionar_CACA_P1(char p1[8][8]);
void posicionar_PORTAAVIAO_P2(char p2[8][8]);
void posicionar_PORTAAVIAO_1(char p1[8][8]);
void posicionar_SUBMARINO_P2(char p2[8][8]);
void posicionar_SUBMARINO_P1(char p1[8][8]);
void posicionar_ESCOLTA_P2(char p2[8][8]);
void posicionar_ESCOLTA_P1(char p1[8][8]);
int ataque(char p2[8][8],char p2censurada[8][8], char x, int y,int r);
int dica(char p2[8][8], char x, int y);
int sobrejogo();
void BufferLimpar(void);
void contarNaviosp1(char p1[8][8]);
void contarNaviosp2(char p2[8][8]);
void ataqueinimigo(char p1[8][8], int pn_2,int cn_2,int sn_2,int en_2);
int menuselect(char p1[8][8],char p2[8][8], char p2censurada[8][8], int contdica);
int xparanumero(char x);
void limpartela(void);
#endif
