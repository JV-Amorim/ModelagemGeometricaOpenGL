#include "cena-cavalo.h"

// CENA-CAVALO VARIABLES:

float anguloCabeca;
float anguloTronco;
float anguloRabo = 0.0;
float deslocamento = 0.0;

float angulosCaminhada[6][4][4];  // [estagio][posicao][quadril/femur/canela/pata].
float angulosTrote[6][4][4];

int estagio = 0;
int passo = 0;  // Valor de 0 a 10.
int caminhando = 1;
float deslocamentoYTronco = 0.0;
int movimentarCavalo = 1;
float anguloCavalo = 0.0;
int passoRabo = 0;
int passoRaboSubindo = 1;
int iluminacao = 1;
int arvores = 1;
float anguloPescoco = 0.0;
int anguloPescocoSubindo = 1;

float xCavalo = 0.0;
float zCavalo = 1.5;

static float angle = 0.0, ratio;
static float x = 0.0f, y = 0.75f, z = 5.0f;
static float lx = 0.0f, ly = 0.0f, lz = -1.0f;

GLUquadricObj *params = gluNewQuadric();

// "PUBLIC" FUNCTIONS:

void inicializarCena() {
  glEnable(GL_DEPTH_TEST);
  inicializarAngulos();
}

void inicializarAngulos() {
  angulosCaminhada[0][ESQUERDA_POSTERIOR][FEMUR] = 7;
  angulosCaminhada[0][ESQUERDA_POSTERIOR][CANELA] = -33;
  angulosCaminhada[0][ESQUERDA_POSTERIOR][PATA] = 0;
  angulosCaminhada[0][DIREITA_POSTERIOR][FEMUR] = 4;
  angulosCaminhada[0][DIREITA_POSTERIOR][CANELA] = -4;
  angulosCaminhada[0][DIREITA_POSTERIOR][PATA] = 0;
  angulosCaminhada[0][ESQUERDA_ANTERIOR][QUADRIL] = 15;
  angulosCaminhada[0][ESQUERDA_ANTERIOR][FEMUR] = -35;
  angulosCaminhada[0][ESQUERDA_ANTERIOR][CANELA] = 70;
  angulosCaminhada[0][ESQUERDA_ANTERIOR][PATA] = 0;
  angulosCaminhada[0][DIREITA_ANTERIOR][QUADRIL] = -20;
  angulosCaminhada[0][DIREITA_ANTERIOR][FEMUR] = -26;
  angulosCaminhada[0][DIREITA_ANTERIOR][CANELA] = 39;
  angulosCaminhada[0][DIREITA_ANTERIOR][PATA] = 0;

  angulosCaminhada[1][ESQUERDA_POSTERIOR][FEMUR] = 43;
  angulosCaminhada[1][ESQUERDA_POSTERIOR][CANELA] = -81;
  angulosCaminhada[1][ESQUERDA_POSTERIOR][PATA] = 0;
  angulosCaminhada[1][DIREITA_POSTERIOR][FEMUR] = -8;
  angulosCaminhada[1][DIREITA_POSTERIOR][CANELA] = -6;
  angulosCaminhada[1][DIREITA_POSTERIOR][PATA] = -4;
  angulosCaminhada[1][ESQUERDA_ANTERIOR][QUADRIL] = 5;
  angulosCaminhada[1][ESQUERDA_ANTERIOR][FEMUR] = -20;
  angulosCaminhada[1][ESQUERDA_ANTERIOR][CANELA] = 38;
  angulosCaminhada[1][ESQUERDA_ANTERIOR][PATA] = 0;
  angulosCaminhada[1][DIREITA_ANTERIOR][QUADRIL] = -27;
  angulosCaminhada[1][DIREITA_ANTERIOR][FEMUR] = -25;
  angulosCaminhada[1][DIREITA_ANTERIOR][CANELA] = 30;
  angulosCaminhada[1][DIREITA_ANTERIOR][PATA] = 0;

  angulosCaminhada[2][ESQUERDA_POSTERIOR][FEMUR] = 35;
  angulosCaminhada[2][ESQUERDA_POSTERIOR][CANELA] = -30;
  angulosCaminhada[2][ESQUERDA_POSTERIOR][PATA] = 0;
  angulosCaminhada[2][DIREITA_POSTERIOR][FEMUR] = -20;
  angulosCaminhada[2][DIREITA_POSTERIOR][CANELA] = 0;
  angulosCaminhada[2][DIREITA_POSTERIOR][PATA] = 0;
  angulosCaminhada[2][ESQUERDA_ANTERIOR][QUADRIL] = 20;
  angulosCaminhada[2][ESQUERDA_ANTERIOR][FEMUR] = -60;
  angulosCaminhada[2][ESQUERDA_ANTERIOR][CANELA] = 38;
  angulosCaminhada[2][ESQUERDA_ANTERIOR][PATA] = 0;
  angulosCaminhada[2][DIREITA_ANTERIOR][QUADRIL] = 5;
  angulosCaminhada[2][DIREITA_ANTERIOR][FEMUR] = -70;
  angulosCaminhada[2][DIREITA_ANTERIOR][CANELA] = 40;
  angulosCaminhada[2][DIREITA_ANTERIOR][PATA] = 0;

  angulosTrote[0][ESQUERDA_POSTERIOR][FEMUR] = 70;
  angulosTrote[0][ESQUERDA_POSTERIOR][CANELA] = -70;
  angulosTrote[0][ESQUERDA_POSTERIOR][PATA] = -50;
  angulosTrote[0][DIREITA_POSTERIOR][FEMUR] = -15;
  angulosTrote[0][DIREITA_POSTERIOR][CANELA] = 0;
  angulosTrote[0][DIREITA_POSTERIOR][PATA] = -10;
  angulosTrote[0][ESQUERDA_ANTERIOR][QUADRIL] =-5;
  angulosTrote[0][ESQUERDA_ANTERIOR][FEMUR] = -25;
  angulosTrote[0][ESQUERDA_ANTERIOR][CANELA] = 30;
  angulosTrote[0][ESQUERDA_ANTERIOR][PATA] = -20;
  angulosTrote[0][DIREITA_ANTERIOR][QUADRIL] = 33;
  angulosTrote[0][DIREITA_ANTERIOR][FEMUR] = -75;
  angulosTrote[0][DIREITA_ANTERIOR][CANELA] = 95;
  angulosTrote[0][DIREITA_ANTERIOR][PATA] = -05;

  angulosTrote[1][ESQUERDA_POSTERIOR][FEMUR] = 45;
  angulosTrote[1][ESQUERDA_POSTERIOR][CANELA] = 0;
  angulosTrote[1][ESQUERDA_POSTERIOR][PATA] = 0;
  angulosTrote[1][DIREITA_POSTERIOR][FEMUR] = 25;
  angulosTrote[1][DIREITA_POSTERIOR][CANELA] = -75;
  angulosTrote[1][DIREITA_POSTERIOR][PATA] = 15;
  angulosTrote[1][ESQUERDA_ANTERIOR][QUADRIL] = -25;
  angulosTrote[1][ESQUERDA_ANTERIOR][FEMUR] = -35;
  angulosTrote[1][ESQUERDA_ANTERIOR][CANELA] = 75;
  angulosTrote[1][ESQUERDA_ANTERIOR][PATA] = 0;
  angulosTrote[1][DIREITA_ANTERIOR][QUADRIL] = 10;
  angulosTrote[1][DIREITA_ANTERIOR][FEMUR] = -5;
  angulosTrote[1][DIREITA_ANTERIOR][CANELA] = 45;
  angulosTrote[1][DIREITA_ANTERIOR][PATA] = 0;

  anguloCabeca = 90.0;
  anguloTronco = -3.75;
}

void renderizarCena(void) {
  int i;
  int j;

  // Limpa a tela e o buffer.
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  // Iluminacao.
  GLfloat diffuseLight[] = {1, 1, 1, 1};
  GLfloat ambientLight[] = {1, 1, 1, 1};
  GLfloat specularLight[] = {0.2, 0.3, 0.3, 1};
  GLfloat lightPos[] = {300.0f, 2000.0f, -20.0f, 1.0f};
  if (iluminacao) {
    glEnable(GL_LIGHTING);
  }
  else {
    glDisable(GL_LIGHTING);
  }
  glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);
  glLightfv(GL_LIGHT0, GL_SPECULAR, specularLight);
  glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);
  glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
  glEnable(GL_LIGHT0);
  glEnable(GL_COLOR_MATERIAL);
  glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, diffuseLight );
  glMateriali(GL_FRONT_AND_BACK, GL_SHININESS, 50);

  // Piso.
  glPushMatrix();
      glColor3f(0.05f, 0.25f, 0.05f);
    glBegin(GL_QUADS);
      glVertex3f(-100.0f, 0.1f, -100.0f);
      glVertex3f(-100.0f, 0.1f,  100.0f);
      glVertex3f( 100.0f, 0.1f,  100.0f);
      glVertex3f( 100.0f, 0.1f, -100.0f);
    glEnd();
  glPopMatrix();

  // 64 arvores.
  if (arvores) {
    for (i = -4; i < 4; i++) {
      for (j=-4; j < 4; j++) {
        glPushMatrix();
          glTranslatef(i * 10.0, 0, j * 10.0);
          desenharArvore();
        glPopMatrix();
      }
    }
  }

  glPushMatrix();
    glTranslatef(xCavalo, 0.945, zCavalo);
    glRotatef(anguloCavalo, 0, 1, 0);
    desenharCorpo();
  glPopMatrix();
  glutSwapBuffers();
}

void redimensionarWindow(int w, int h) {
  bool isTheHeightInvalid = h == 0;
  if (isTheHeightInvalid) {
    h = 1;
  }

  ratio = 1.0f * w / h;
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  glViewport(0, 0, w, h);

  gluPerspective(45, ratio, 1, 1000);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(x, y, z, x + lx, y + ly, z + lz, 0.0f, 1.0f, 0.0f);
}

void processarTeclasEspeciais(int key, int x, int y) {
  switch (key) {
    case GLUT_KEY_LEFT:
      angle -= 0.05f;
      orientarCamera(angle);
      break;
    case GLUT_KEY_RIGHT:
      angle += 0.05f;
      orientarCamera(angle);
      break;
    case GLUT_KEY_UP:
      movimentarCamera(5);
      break;
    case GLUT_KEY_DOWN:
      movimentarCamera(-5);
      break;
    case GLUT_KEY_F1:
      deslocamentoYTronco = 0.0;
      caminhando = !caminhando;
      break;
    case GLUT_KEY_F2:
      movimentarCavalo = !movimentarCavalo;
      break;
    case GLUT_KEY_F3:
      iluminacao = !iluminacao;
      break;
    case GLUT_KEY_F4:
      arvores = !arvores;
      break;
    case GLUT_KEY_F11:
      glutFullScreen();
      break;
    case GLUT_KEY_F12:
      glutReshapeWindow(WINDOW_INITIAL_WIDTH, WINDOW_INITIAL_HEIGHT);
      break;
  }
  renderizarCena();
}

void processarTeclasNormais(unsigned char key, int x, int y) {
  switch (key) {
    case 27:
      exit(0);
      break;
    case 'w':
      movimentarCavaloParaFrenteOuParaTras(1);
      break;
    case 's':
      movimentarCavaloParaFrenteOuParaTras(-1);
      break;
    case 'a':
      anguloCavalo += 5;
      break;
    case 'd':
      anguloCavalo -= 5;
      break;
  }
  renderizarCena();
}

void timer(int value) {
  if (passoRabo > 15) {
    passoRaboSubindo = 0;
    if (caminhando) {
      passoRabo--;
    }
    else {
      passoRabo -= 2;
    }
  }
  else if (passoRabo < -15) {
    passoRaboSubindo = 1;
    if (caminhando) {
      passoRabo++;
    }
    else {
      passoRabo += 2;
    }
  }
  else {
    if (caminhando) {
      passoRaboSubindo ? passoRabo++ : passoRabo--;
    }
    else {
      passoRaboSubindo ? passoRabo += 2 : passoRabo -=2;
    }
  }
  renderizarCena();
  glutTimerFunc(50, timer, 0);
}

// "PRIVATE" METHODS:

void desenharArvore() {
  glColor3f(0.54, 0.4, 0.3);
  glRotatef(-90, 1, 0, 0);
  gluCylinder(params, 0.2, 0.2,2 , 15, 2);
  glTranslatef(0, 0,2);
  glColor3f(0.14, 0.42, 0.13);
  gluCylinder(params, 0.8, 0.0, 2, 15, 2);
}

void desenharEsfera() {
  glColor3f(0.6, 0.5, 0.3);
  glutSolidSphere(TAMANHO_ESFERA, 8, 8);
  glColor3f(1.0, 0.8, 0);
}

void desenharCabeca() {
  glPushMatrix();
  glRotatef(45 - anguloPescoco, 0, 0, 1);
  glPushMatrix();
  glScalef(LARG_PESCOCO, ALT_PESCOCO, COMP_PESCOCO);
  glutSolidCube(0.5);
  glPopMatrix();
  glTranslatef(LARG_PESCOCO * 0.19, - ALT_PESCOCO * 0.4, 0);
  glRotatef(anguloCabeca, 0, 0, 1);
  glScalef(LARG_CABECA,ALT_CABECA, COMP_CABECA);
  glutSolidCube(0.5);
  glPopMatrix();
}

void desenharRabo() {
  float angulo = caminhando ? 0.0 : 5.0;
  float angulo2 = caminhando ? passoRabo : passoRabo / 2;

  // Primeiro segmento.
  glColor3f(0.6, 0.5, 0.3);
  glutSolidSphere(TAMANHO_ESFERA / 1.25, 8, 8);
  glColor3f(1.0, 0.8, 0);
  glRotatef(90 - angulo2, 0, 1, 0);
  glRotatef(- 45 + angulo, 1, 0, 0);
  glTranslatef(0, 0, -0.20);
  gluCylinder(params,0.020, 0.03, 0.20, 15, 2);

  // Segundo segmento.
  glColor3f(0.6, 0.5, 0.3);
  glutSolidSphere(TAMANHO_ESFERA / 1.5, 8, 8);
  glColor3f(1.0, 0.8, 0);
  glRotatef(- angulo2 * 2,0, 1, 0);
  glRotatef(- 24 + angulo / 2, 1, 0, 0);
  glTranslatef(0, 0, -0.15);
  gluCylinder(params, 0.015, 0.020, 0.15, 15, 2);

  // Terceiro segmento.
  glColor3f(0.6, 0.5, 0.3);
  glutSolidSphere(TAMANHO_ESFERA / 2, 8, 8);
  glRotatef(- angulo2 * 3, 0, 1, 0);
  glColor3f(1.0, 0.8, 0);
  glTranslatef(0, 0, - 0.25);
  gluCylinder(params, 0.0, 0.015, 0.25, 15, 2);

}

void desenharQuadril(int posicao) {
  glPushMatrix();
  glRotatef(obterAngulo(posicao, QUADRIL), 0, 0, 1);
  glTranslatef(0.0, - TAMANHO_ESFERA, 0.0);
  glPushMatrix();
  glScalef(LARG_QUADRIL, ALT_QUADRIL, COMP_QUADRIL);

  glRotatef(90, 1, 0, 0);
  gluCylinder(params, 0.3, 0.3, 0.5, 15, 2);

  glPopMatrix();
  glTranslatef(0.0, - ALT_QUADRIL * 0.5 - TAMANHO_ESFERA, 0.0);
  desenharEsfera();
  desenharFemur(posicao);
  glPopMatrix();
}

void desenharFemur(int posicao) {
  glPushMatrix();
  glRotatef(obterAngulo(posicao, FEMUR), 0, 0, 1);
  glTranslatef(0.0, - TAMANHO_ESFERA, 0.0);
  glPushMatrix();
  glScalef(LARG_FEMUR, ALT_FEMUR, COMP_FEMUR);

  glRotatef(90, 1, 0, 0);
  gluCylinder(params, 0.3, 0.3, 0.5, 15, 2);

  glPopMatrix();
  glTranslatef(0.0, - ALT_FEMUR * 0.5 - TAMANHO_ESFERA, 0.0);
  desenharEsfera();
  desenharCanela(posicao);
  glPopMatrix();
}

void desenharCanela(int posicao) {
  glPushMatrix();
  glRotatef(obterAngulo(posicao, CANELA), 0, 0, 1);
  glTranslatef(0.0, - TAMANHO_ESFERA, 0.0);
  glPushMatrix();
  glScalef(LARG_CANELA, ALT_CANELA, COMP_CANELA);

  glRotatef(90, 1, 0, 0);
  gluCylinder(params, 0.3, 0.3, 0.5, 15, 2);

  glPopMatrix();
  glTranslatef(0.0, - ALT_CANELA * 0.5 - TAMANHO_ESFERA, 0.0);
  desenharEsfera();
  desenharPata(posicao);
  glPopMatrix();
}

void desenharPata(int posicao) {
  glPushMatrix();
  glRotatef(obterAngulo(posicao, PATA), 0, 0, 1);
  glTranslatef(0.0, - TAMANHO_ESFERA, 0.0);
  glTranslatef(0.0, - ALT_PATA * 0.35, 0.0);
  glScalef(BASE_PATA, ALT_PATA, BASE_PATA);
  glRotatef(-90, 1, 0, 0);
  glutSolidCone (0.5, 0.6, 8,6);
  glPopMatrix();
}

void desenharTronco() {
  if (!caminhando) {
    glTranslatef(0.0, deslocamentoYTronco, 0.0);
  }

  glPushMatrix();
  glColor3f(0.6, 0.4, 0.1);
  glPushMatrix();
    glTranslatef(- LARG_TRONCO * 0.2, 0, 0.0);
    glPushMatrix();
      glScalef(1, ALT_TRONCO * 1.5, 1);
      glutSolidSphere(COMP_TRONCO * 0.335, 8, 8);
    glPopMatrix();
    glScalef(LARG_TRONCO, ALT_TRONCO, COMP_TRONCO);
    glRotatef(90, 0, 1, 0);
    gluCylinder(params, 0.25, 0.25, 0.4, 15, 2);
  glPopMatrix();
  glPushMatrix();
    glTranslatef(LARG_TRONCO * 0.2, 0, 0.0);
    glScalef(1, ALT_TRONCO * 1.5, 0.75);
    glutSolidSphere(COMP_TRONCO * 0.335, 8, 8);
  glPopMatrix();

  glColor3f(0.6, 0.25, 0.1);
  glPopMatrix();
}

void desenharPerna(int posicao) {
  glPushMatrix();
  if (posicao == ESQUERDA_ANTERIOR || posicao == DIREITA_ANTERIOR) {
    desenharQuadril(posicao);
  }
  else {
    desenharFemur(posicao);
  }
  glPopMatrix();
}

void desenharCorpo() {
  desenharTronco();

  glPushMatrix();
  glTranslatef(- LARG_TRONCO * 0.17, ALT_TRONCO * 0.1, COMP_TRONCO * 0.3);
  desenharEsfera();
  desenharPerna(ESQUERDA_ANTERIOR);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(LARG_TRONCO * 0.22, - ALT_TRONCO * 0.2, COMP_TRONCO * 0.2);
  desenharEsfera();
  desenharPerna(ESQUERDA_POSTERIOR);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(LARG_TRONCO * 0.22, - ALT_TRONCO * 0.2, - COMP_TRONCO * 0.2);
  desenharEsfera();
  desenharPerna(DIREITA_POSTERIOR);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(- LARG_TRONCO * 0.17, ALT_TRONCO * 0.1, - COMP_TRONCO * 0.3);
  desenharEsfera();
  desenharPerna(DIREITA_ANTERIOR);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(LARG_TRONCO * 0.25, ALT_TRONCO * 0.2, 0.0);
  desenharCabeca();
  glPopMatrix();
  glPushMatrix();
  glTranslatef(- LARG_TRONCO * 0.28, ALT_TRONCO * 0.1, 0.0);
  desenharRabo();
  glPopMatrix();
}

void orientarCamera(float ang) {
  lx = sin(ang);
  lz = - cos(ang);
  glLoadIdentity();
  gluLookAt(x, y, z,  x + lx, y + ly, z + lz, 0.0f, 1.0f, 0.0f);
}

void movimentarCamera(int i) {
  x = x + i * lx * 0.1;
  z = z + i * lz * 0.1;
  glLoadIdentity();
  gluLookAt(x, y, z, x + lx, y + ly, z + lz, 0.0f, 1.0f, 0.0f);
}

void movimentarCavaloParaFrenteOuParaTras(int direcao) {
  float maiorAngulo = caminhando ? 20.0 : 15.0;

  if (anguloPescoco > maiorAngulo || anguloPescoco < 0.0) {
    anguloPescocoSubindo = !anguloPescocoSubindo;
  }

  float incremento = caminhando ? 1.5 : 3.0;
  anguloPescoco = anguloPescocoSubindo ? anguloPescoco + incremento : anguloPescoco - incremento;

  if (passo < 10) {
    caminhando ? passo += 2 : passo += 3;

    if (estagio == 0 || estagio == 2) {
      deslocamentoYTronco += 0.01;
    }
    else if (estagio == 1 || estagio == 3) {
      deslocamentoYTronco -= 0.01;
    }
  }
  else {
    passo = 0;
    int estagioFinal = 5;

    if (!caminhando) {
      estagioFinal = 3;
    }
    if (estagio < estagioFinal) {
      estagio++;
    }
    else {
      estagio = 0;
    }
  }

  if (movimentarCavalo) {
    float deslocamento = caminhando ? 0.03 * direcao : 0.12 * direcao;
    float anguloGraus = anguloCavalo * (M_PI / 180);
    xCavalo += deslocamento * cos(anguloGraus);
    zCavalo -= deslocamento * sin(anguloGraus);
  }
}

float obterAngulo(int posicao, int parte, bool posicaoAtual) {
  int estagioDoAngulo = estagio;
  int estagioFinal = caminhando ? 5 : 3;
  if (!posicaoAtual) {
    if (estagioDoAngulo == estagioFinal) {
      estagioDoAngulo = 0;
	}
    else {
      estagioDoAngulo++;
	}
  }

  float (*vetor)[4][4] = caminhando ? angulosCaminhada : angulosTrote;

  int estagioDeTroca = caminhando ? 2 : 1;
  if (estagioDoAngulo > estagioDeTroca) {
    switch (posicao) {
      case ESQUERDA_ANTERIOR:
        return vetor[estagioDoAngulo - estagioDeTroca - 1][DIREITA_ANTERIOR][parte];
      case DIREITA_ANTERIOR:
        return vetor[estagioDoAngulo - estagioDeTroca - 1][ESQUERDA_ANTERIOR][parte];
      case ESQUERDA_POSTERIOR:
        return vetor[estagioDoAngulo - estagioDeTroca - 1][DIREITA_POSTERIOR][parte];
      case DIREITA_POSTERIOR:
        return vetor[estagioDoAngulo - estagioDeTroca - 1][ESQUERDA_POSTERIOR][parte];
    }
  }
  else {
    return vetor[estagioDoAngulo][posicao][parte];
  }
  return 0.0;
}

float obterAngulo(int posicao, int parte) {
  float fatorPasso = passo / 10.0;
  float anguloAtual = obterAngulo(posicao, parte, true);
  float proximoAngulo = obterAngulo(posicao, parte, false);
  return anguloAtual + (proximoAngulo - anguloAtual) * fatorPasso;
}
