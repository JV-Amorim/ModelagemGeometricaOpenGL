#ifndef CAVALO_H
#define CAVALO_H

#include <windows.h>
#include <GL/glut.h>
#include <math.h>
#include "constantes.h"

void inicializarCena();
void inicializarAngulos();
void renderizarCena();
void redimensionarWindow(int w, int h);
void processarTeclasEspeciais(int key, int x, int y);
void processarTeclasNormais(unsigned char key, int x, int y);
void timer(int value);

void desenharArvore();
void desenharEsfera();
void desenharCabeca();
void desenharRabo();
void desenharQuadril(int posicao);
void desenharFemur(int posicao);
void desenharCanela(int posicao);
void desenharPata(int posicao);
void desenharTronco();
void desenharPerna(int posicao);
void desenharCorpo();
void orientarCamera(float ang);
void movimentarCamera(int i);
void movimentarCavaloParaFrenteOuParaTras(int direcao);
float obterAngulo(int posicao, int parte, bool posicaoAtual);
float obterAngulo(int posicao, int parte);

#endif // CAVALO_H
