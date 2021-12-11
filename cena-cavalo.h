#ifndef CAVALO_H
#define CAVALO_H

#include <windows.h>
#include <GL/glut.h>
#include <math.h>
#include "constantes.h"

// FUNCOES DE INICIALIZACAO:
void inicializarCena();
void inicializarAngulos();

// FUNCOES DE SOBREESCRITA OPENGL:
void renderizarCena();
void redimensionarWindow(int w, int h);
void processarTeclasEspeciais(int key, int x, int y);
void processarTeclasNormais(unsigned char key, int x, int y);
void timer(int value);

// FUNCOES DE MODELAGEM DOS OBJETOS:
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

// FUNCOES DE CAMERA:
void orientarCamera(float ang);
void movimentarCamera(int i);

// FUNCAO DE MOVIMENTACAO DO CAVALO:
void movimentarCavaloParaFrenteOuParaTras(int direcao);

// FUNCOES AUXILIARES:
float obterAngulo(int posicao, int parte, bool posicaoAtual);
float obterAngulo(int posicao, int parte);

#endif // CAVALO_H
