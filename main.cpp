#include <stdlib.h>
#include <windows.h>
#include <GL/glut.h>
#include "cena-cavalo.h"
#include "constantes.h"

int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
  glutInitWindowPosition(WINDOW_INITIAL_X, WINDOW_INITIAL_Y);
  glutInitWindowSize(WINDOW_INITIAL_WIDTH, WINDOW_INITIAL_HEIGHT);
  glutCreateWindow("IFNMG - CG - TP4 - Modelagem Geometrica");

  glutSpecialFunc(processarTeclasEspeciais);
  glutKeyboardFunc(processarTeclasNormais);
  glutDisplayFunc(renderizarCena);
  glutReshapeFunc(redimensionarWindow);
  glutTimerFunc(100, timer, 0);

  inicializarCena();
  glutMainLoop();

  return 0;
}
