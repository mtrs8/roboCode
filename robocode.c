#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


struct ficha{
  char robo[10];
  int municao;
  int hp;
};

int mover();
void tamanho();
void dimencao();
void batalha();
void criarRobo();
void converte();
void carregando();



int linha, coluna;

int main() {

  int i, j, x=0, a = 58, b=0,c=60, A=15, B=10, I=5, J=55, X=20, Y=10, y=0, k=0, direcao1=0, direcao2=0, count=0, o=0, p=0, tI=3, tJ=62, hits=0, t1=0, linhaTiro=2, loopT1=0, loopT2=0, loopT3=0, I_t1R1, J_t1R1;
  int tempo = clock();
  int round=1;
  struct ficha robo1, robo2, robo3;


  criarRobo(&robo1, &robo2, &robo3);

  tamanho();


  while(round < 4){
    batalha(robo1, robo2, robo3, round);
    round++;
  }

  return 0;
}


int mover(){

  int i;

  srand(time(NULL));

  i = rand() % 8;

  return i;
}

void tamanho(){

  int i;

  do{

    printf("\n\nEscolha o tamanho da arena:\n");
    printf("\n1 - Pequena");
    printf("\n2 - Media");
    printf("\n3 - Grande\n\n");

    scanf(" ");
    scanf("%d", &i);

    if(i == 1){
      linha = 30;
      coluna = 75;
    }
    else if(i == 2){
      linha = 40;
      coluna = 85;
    }
    else if(i == 3){
      linha = 50;
      coluna = 115;
    }
    else{
      printf("\n\nOpcao invalida!\n\n");
    }
  }while(i != 1 && i != 2 && i != 3);


}


void criarRobo(struct ficha *robo1, struct ficha *robo2, struct ficha *robo3){

  strcpy(robo1 -> robo, "ROBO #");
  robo1 -> municao = 50;
  robo1 -> hp = 100;

  strcpy(robo2 -> robo, "ROBO @");
  robo2 -> municao = 30;
  robo2 -> hp = 70;

  strcpy(robo3 -> robo, "ROBO O");
  robo3 -> municao = 70;
  robo3 -> hp = 120;

}

void converte(struct ficha *robo1, struct ficha *robo2, struct ficha *robo3, char hp1[], char hp2[], char hp3[], char m1[], char m2[], char m3[]){

  sprintf(m1, "MUN = %d", robo1 -> municao);
  sprintf(m2, "MUN = %d", robo2 -> municao);
  sprintf(m3, "MUN = %d", robo3 -> municao);

  sprintf(hp1, "HP = %d", robo1 -> hp);
  sprintf(hp2, "HP = %d", robo2 -> hp);
  sprintf(hp3, "HP = %d", robo3 -> hp);

}

void carregando(){

  int i, j;

  printf("\n\nCARREGANDO ");

  for(i = 0; i < 50; i++){
    for(j = 0; j < 15000000; j++){
    }
      printf("#");
  }
}

void batalha(struct ficha robo1, struct ficha robo2, struct ficha robo3, int round){

  char campo[linha][coluna];
  int i, j, x=0, a = 58, b=0,c=60, A=15, B=10, I=5, J=55, X=20, Y=10, y=0, k=0, direcao1=0, direcao2=0, count=0, o=0, p=0, tI=3, tJ=62, hits=0, z;
  int movimento=0, t1=0, linhaTiroI=2, linhaTiroJ=65, loopT1=0, loopT2=0, loopT3=0, loopT4=0, I_t1R1, J_t1R1, I_t2R1, J_t2R1, I_t3R1, J_t3R1, I_t4R1, J_t4R1;
  int t2=0, linhaTiroX, loopT1R2=0, loopT2R2=0, loopT3R2=0, loopT4R2=0, loopT5R2=0, X_t1R2, Y_t1R2, X_t2R2, Y_t2R2, X_t3R2, Y_t3R2, X_t4R2, Y_t4R2, X_t5R2, Y_t5R2;
  int t3=0, linhaTiroA=14, loopT1R3=0, loopT2R3=0, A_t1R3, B_t1R3, A_t2R3, B_t2R3, vencedor;
  char hp1[10], hp2[10], hp3[10], m1[10], m2[10], m3[10];
  int tempo = clock();
  //int round = 1;

  carregando();

  do{



    for(i=0; i< 20000000; i++) {
    }

    for(i = 0; i < linha; i++){
      for(j = 0; j < coluna; j++){
        if(j == coluna - 1){
          campo[i][j] = '\n';
        }
        else if( i == 0 || i == linha - 1 || (i == 0 && j > coluna -16 && j < coluna - 2) ||
                (i == 10 && j > coluna - 16 && j < coluna - 2) || (i == 19 && j > coluna - 16 && j < coluna - 2) ||
                (i == 29 && j > coluna - 16 && j < coluna - 2)){
          campo[i][j] = '-';
        }
        else if(j == 0 || j == coluna - 17 || j == coluna - 16 || j == coluna - 2){
          campo[i][j] = '|';
        }
        else{
            campo[i][j] = ' ';
            campo[linha - 1][coluna] = ' ';
        }
      }

    }


      if(robo1.hp > 0){
        if(movimento == 0 || movimento == 1 || movimento == 4){
          campo[I][J] = '#';
          campo[I][J+1] = '#';
          campo[I][J+2] = '#';
          campo[I][J+3] = '#';
          campo[I][J+4] = '#';
          campo[I+1][J] = '*';
          campo[I+1][J+1] = '*';
          campo[I+1][J+2] = '*';
          campo[I+1][J+3] = '#';
          campo[I+1][J+4] = '#';
          campo[I+2][J] = '#';
          campo[I+2][J+1] = '#';
          campo[I+2][J+2] = '#';
          campo[I+2][J+3] = '#';
          campo[I+2][J+4] = '#';
        }
        else if(movimento == 2 || movimento == 3){
          if(movimento == 2 && o == 0 && count != 8){
            count++;
          }
          else if(movimento == 3 && o == 1 && count != 0){
            count--;
            if(count == 0){
              movimento = 4;
              o = 0;
            }
          }

          if(count == 0 || count == 1 || count == 2){
            campo[I][J] = '#';
            campo[I][J+1] = '#';
            campo[I][J+2] = '#';
            campo[I][J+3] = '#';
            campo[I][J+4] = '#';
            campo[I+1][J] = '*';
            campo[I+1][J+1] = '*';
            campo[I+1][J+2] = '*';
            campo[I+1][J+3] = '#';
            campo[I+1][J+4] = '#';
            campo[I+2][J] = '#';
            campo[I+2][J+1] = '#';
            campo[I+2][J+2] = '#';
            campo[I+2][J+3] = '#';
            campo[I+2][J+4] = '#';
          }
          else if(count == 3 || count == 4 || count == 5){
            campo[I][J] = '*';
            campo[I][J+1] = ' ';
            campo[I][J+2] = '#';
            campo[I][J+3] = '#';
            campo[I][J+4] = '#';
            campo[I+1][J] = '#';
            campo[I+1][J+1] = '#';
            campo[I+1][J+2] = '*';
            campo[I+1][J+3] = '#';
            campo[I+1][J+4] = '#';
            campo[I+2][J] = '#';
            campo[I+2][J+1] = '#';
            campo[I+2][J+2] = '#';
            campo[I+2][J+3] = '#';
            campo[I+2][J+4] = '#';
          }
          else if(count == 6 || count == 7 || count == 8){
            campo[I][J] = '#';
            campo[I][J+1] = '#';
            campo[I][J+2] = '*';
            campo[I][J+3] = '#';
            campo[I][J+4] = '#';
            campo[I+1][J] = '#';
            campo[I+1][J+1] = '#';
            campo[I+1][J+2] = '*';
            campo[I+1][J+3] = '#';
            campo[I+1][J+4] = '#';
            campo[I+2][J] = '#';
            campo[I+2][J+1] = '#';
            campo[I+2][J+2] = '#';
            campo[I+2][J+3] = '#';
            campo[I+2][J+4] = '#';
          }
        }
      }


      if(robo2.hp > 0){
        campo[X][Y] = '@';
        campo[X][Y+1] = '@';
        campo[X][Y+2] = '@';
        campo[X][Y+3] = '@';
        campo[X][Y+4] = '@';
        campo[X+1][Y] = '@';
        campo[X+1][Y+1] = '@';
        campo[X+1][Y+2] = '+';
        campo[X+1][Y+3] = '+';
        campo[X+1][Y+4] = '+';
        campo[X+2][Y] = '@';
        campo[X+2][Y+1] = '@';
        campo[X+2][Y+2] = '@';
        campo[X+2][Y+3] = '@';
        campo[X+2][Y+4] = '@';
      }


      if(robo3.hp > 0){
        campo[A][B] = 'O';
        campo[A][B+1] = 'O';
        campo[A][B+2] = 'O';
        campo[A][B+3] = 'O';
        campo[A][B+4] = 'O';
        campo[A+1][B] = '=';
        campo[A+1][B+1] = '=';
        campo[A+1][B+2] = 'o';
        campo[A+1][B+3] = '=';
        campo[A+1][B+4] = '=';
        campo[A+2][B] = 'O';
        campo[A+2][B+1] = 'O';
        campo[A+2][B+2] = 'O';
        campo[A+2][B+3] = 'O';
        campo[A+2][B+4] = 'O';
      }

      direcao1 = mover();
      if(y >= 20){
        if(y < 30){
          y++;
          direcao2 = 0;
        }
        else{
          y = 0;
        }
      }
      else{
        direcao2 += 2;
        y++;
      }


      if(direcao1 == 0){
        if(X == 1 || campo[X-2][Y] == 'O' || campo[X-2][Y+1] == 'O' || campo[X-2][Y+2] == 'O' || campo[X-2][Y+3] == 'O' || campo[X-2][Y+4] == 'O'
                  || campo[X-2][Y] == '#' || campo[X-2][Y+1] == '#' || campo[X-2][Y+2] == '#' || campo[X-2][Y+3] == '#' || campo[X-2][Y+4] == '#'){

        }
        else{
          X--;
        }
      }
      else if(direcao1 == 1){
        if(   X == 1 || Y == coluna - 23
           || campo[X-4][Y+5] == 'O'
           || campo[X-3][Y+5] == 'O'
           || campo[X-2][Y-5] == 'O' || campo[X-2][Y-4] == 'O' || campo[X-2][Y-3] == 'O' || campo[X-2][Y-2] == 'O' || campo[X-2][Y-1] == 'O'
           || campo[X-2][Y] == 'O' || campo[X-2][Y+1] == 'O' || campo[X-2][Y+2] == 'O' || campo[X-2][Y+3] == 'O' || campo[X-2][Y+4] == 'O' || campo[X-2][Y+5] == 'O'
           || campo[X-4][Y+5] == '#'
           || campo[X-3][Y+5] == '#'
           || campo[X-2][Y-5] == '#' || campo[X-2][Y-4] == '#' || campo[X-2][Y-3] == '#' || campo[X-2][Y-2] == '#' || campo[X-2][Y-1] == '#'
           || campo[X-2][Y] == '#' || campo[X-2][Y+1] == '#' || campo[X-2][Y+2] == '#' || campo[X-2][Y+3] == '#' || campo[X-2][Y+4] == '#' || campo[X-2][Y+5] == '#'){

        }
        else{
          X--;
          Y++;
        }
      }
      else if(direcao1 == 2){
        if(   Y == coluna - 23
           || campo[X][Y+6] == 'O'
           || campo[X+1][Y+6] == 'O'
           || campo[X+2][Y+6] == 'O'
           || campo[X][Y+6] == '#'
           || campo[X+1][Y+6] == '#'
           || campo[X+2][Y+6] == '#'){

        }
        else{
          Y++;
        }
      }
      else if(direcao1 == 3){
        if(   X == linha - 4 || Y == coluna - 23
           || campo[X+4][Y-5] == 'O' || campo[X+4][Y-4] == 'O' || campo[X+4][Y-3] == 'O' || campo[X+4][Y-2] == 'O' || campo[X+4][Y-1] == 'O'
           || campo[X+4][Y] == 'O' || campo[X+4][Y+1] == 'O' || campo[X+4][Y+2] == 'O' || campo[X+4][Y+3] == 'O' || campo[X+4][Y+4] == 'O' || campo[X+4][Y+5] == 'O'
           || campo[X+5][Y+5] == 'O'
           || campo[X+6][Y+5] == 'O'
           || campo[X+4][Y-5] == '#' || campo[X+4][Y-4] == '#' || campo[X+4][Y-3] == '#' || campo[X+4][Y-2] == '#' || campo[X+4][Y-1] == '#'
           || campo[X+4][Y] == '#' || campo[X+4][Y+1] == '#' || campo[X+4][Y+2] == '#' || campo[X+4][Y+3] == '#' || campo[X+4][Y+4] == '#' || campo[X+4][Y+5] == '#'
           || campo[X+5][Y+5] == '#'
           || campo[X+6][Y+5] == '#'){

        }
        else{
          X++;
          Y++;
        }
      }
      else if(direcao1 == 4){
        if(X == linha - 4 || campo[X+4][Y+1] == 'O' || campo[X+4][Y+2] == 'O' || campo[X+4][Y+3] == 'O' || campo[X+4][Y+4] == 'O' || campo[X+4][Y+5] == 'O'
                   || campo[X+4][Y+1] == '#' || campo[X+4][Y+2] == '#' || campo[X+4][Y+3] == '#' || campo[X+4][Y+4] == '#' || campo[X+4][Y+5] == '#'){

        }
        else{
          X++;
        }
      }
      else if(direcao1 == 5){
        if(   X == linha - 4 || Y == 2
           || campo[X+4][Y-5] == 'O' || campo[X+4][Y-4] == 'O' || campo[X+4][Y-3] == 'O' || campo[X+4][Y-2] == 'O' || campo[X+4][Y-1] == 'O'
           || campo[X+4][Y] == 'O' || campo[X+4][Y+1] == 'O' || campo[X+4][Y+2] == 'O' || campo[X+4][Y+3] == 'O' || campo[X+4][Y+4] == 'O' || campo[X+4][Y+5] == 'O'
           || campo[X+5][Y-1] == 'O'
           || campo[X+6][Y-1] == 'O'
           || campo[X+4][Y-5] == '#' || campo[X+4][Y-4] == '#' || campo[X+4][Y-3] == '#' || campo[X+4][Y-2] == '#' || campo[X+4][Y-1] == '#'
           || campo[X+4][Y] == '#' || campo[X+4][Y+1] == '#' || campo[X+4][Y+2] == '#' || campo[X+4][Y+3] == '#' || campo[X+4][Y+4] == '#' || campo[X+4][Y+5] == '#'
           || campo[X+5][Y-1] == '#'
           || campo[X+6][Y-1] == '#'){

        }
        else{
          X++;
          Y--;
        }
      }
      else if(direcao1 == 6){
        if(   Y == 2
           || campo[X][Y-2] == 'O'
           || campo[X+1][Y-2] == 'O'
           || campo[X+2][Y-2] == 'O'
           || campo[X][Y-2] == '#'
           || campo[X+1][Y-2] == '#'
           || campo[X+2][Y-2] == '#'){

        }
        else{
          Y--;
        }
      }
      else if(direcao1 == 7){
        if(   X == 1 || Y == 2
           || campo[X-4][Y-1] == 'O'
           || campo[X-3][Y-1] == 'O'
           || campo[X-2][Y-5] == 'O' || campo[X-2][Y-4] == 'O' || campo[X-2][Y-3] == 'O' || campo[X-2][Y-2] == 'O' || campo[X-2][Y-1] == 'O'
           || campo[X-2][Y] == 'O' || campo[X-2][Y+1] == 'O' || campo[X-2][Y+2] == 'O' || campo[X-2][Y+3] == 'O' || campo[X-2][Y+4] == 'O' || campo[X-2][Y+5] == 'O'
           || campo[X-4][Y-1] == '#'
           || campo[X-3][Y-1] == '#'
           || campo[X-2][Y-5] == '#' || campo[X-2][Y-4] == '#' || campo[X-2][Y-3] == '#' || campo[X-2][Y-2] == '#' || campo[X-2][Y-1] == '#'
           || campo[X-2][Y] == '#' || campo[X-2][Y+1] == '#' || campo[X-2][Y+2] == '#' || campo[X-2][Y+3] == '#' || campo[X-2][Y+4] == '#' || campo[X-2][Y+5] == '#'){

        }
        else{
          X--;
          Y--;
        }
      }


      if(A != (linha / 2) - 2 || B != (coluna / 2) - 4){
        if(A > (linha / 2) - 2){
          A--;
        }
        if(A < (linha / 2) - 2){
          A++;
        }
        if(B > (coluna / 2) - 4){
          B--;
        }
        if(B < (coluna / 2) - 4){
          B++;
        }
      }
      else if(A == linha / 2 && B == coluna / 2){
        if(t3 == 0 && robo3.municao != 0 && robo3.hp > 0){
          for(a = 1; a < coluna - 17; a++){
            if(campo[linhaTiroA][a] == '@' || campo[linhaTiroA][a] == '#' || campo[linhaTiroA][a] == '+' || campo[linhaTiroA][a] == '*'){
              robo3.municao -= 2;
              t3 = 1;
              loopT1R3 = 1;
              loopT2R3 = 1;
              A_t1R3 = linhaTiroA;
              B_t1R3 = coluna / 2;
              A_t2R3 = linhaTiroA;
              B_t2R3 = (coluna / 2);
              break;
            }
          }
        }
      }


      if((I != 1 || J != coluna - 22) && movimento == 0){
        if(I != 1){
          I--;
        }
        if(J != coluna - 22){
          J++;
        }
        if(I == 1 && J == coluna - 22){
          movimento = 1;
        }
      }
      else if(movimento == 1){
        if(t1 == 0 && robo1.municao != 0 && robo1.hp > 0){
          for(a = 1; a < coluna - 23; a++){
            if(campo[linhaTiroI][a] == '@' || campo[linhaTiroI][a] == 'O' || campo[linhaTiroI][a] == '=' || campo[linhaTiroI][a] == '+'){
              robo1.municao--;
              t1 = 1;
              loopT1 = 1;
              I_t1R1 = linhaTiroI;
              J_t1R1 = coluna - 23;
              break;
            }
            else if(a == coluna - 24){
              linhaTiroI++;
            }
          }
        }

        if(   campo[I+4][J-1] == '@' || campo[I+4][J] == '@' || campo[I+4][J+1] == '@' || campo[I+4][J+2] == '@' || campo[I+4][J+3] == '@' || campo[I+4][J+4] == '@'
           || campo[I+4][J-1] == 'O' || campo[I+4][J] == 'O' || campo[I+4][J+1] == 'O' || campo[I+4][J+2] == 'O' || campo[I+4][J+3] == 'O' || campo[I+4][J+4] == 'O'){

        }
        else{
          if(I < linha - 4){
            I++;
          }
          else if(robo1.hp <= 50){
            movimento = 2;
            t1 = 0;
            o = 0;
          }
          else if(robo1.hp > 50){
            movimento = 4;
            linhaTiroI = linha - 3;
            t1 = 0;
          }
        }
      }
      else if(movimento == 2 && count == 8){
        if(t1 == 0 && robo1.municao != 0 && robo1.hp > 0){
          for(a = 1; a < linha - 4; a++){
            if(campo[a][linhaTiroJ] == '@' || campo[a][linhaTiroJ] == 'O' || campo[a][linhaTiroJ] == '=' || campo[a][linhaTiroJ] == '+'){
              robo1.municao--;
              t1 = 1;
              loopT2 = 1;
              I_t2R1 = linha - 5;
              J_t2R1 = linhaTiroJ;
              break;
            }
            else if(a == linha - 6){
              linhaTiroJ--;
            }
          }
        }


        if(   campo[I-1][J-3] == '@' || campo[I][J-3] == '@' || campo[I+1][J-3] == '@' || campo[I+2][J-3] == '@'
           || campo[I-1][J-3] == 'O' || campo[I][J-3] == 'O' || campo[I+1][J-3] == 'O' || campo[I+2][J-3] == 'O'){

        }
        else{
          if(J > 1 && count == 8){
            J -= 2;
          }
          else{
            movimento = 3;
            linhaTiroJ = 2;
            t1 = 0;
            o = 0;
          }
        }


      }
      else if(movimento == 3 && count == 8){
        if(t1 == 0 && robo1.municao != 0 && robo1.hp > 0){
          for(a = 1; a < linha - 4; a++){
            if(campo[a][linhaTiroJ] == '@' || campo[a][linhaTiroJ] == 'O' || campo[a][linhaTiroJ] == '=' || campo[a][linhaTiroJ] == '+'){
              robo1.municao--;
              t1 = 1;
              loopT3 = 1;
              I_t3R1 = linha - 5;
              J_t3R1 = linhaTiroJ;
              break;
            }
            else if(a == linha - 6){
              linhaTiroJ++;
            }
          }
        }

        if(   campo[I-1][J+6] == '@' || campo[I][J+6] == '@' || campo[I+1][J+6] == '@' || campo[I+2][J+6] == '@'
           || campo[I-1][J+6] == 'O' || campo[I][J+6] == 'O' || campo[I+1][J+6] == 'O' || campo[I+2][J+6] == 'O'){

        }
        else{
          if(J < coluna - 22 && count == 8){
             J += 2;
           }
           else{
             linhaTiroJ = coluna - 20;
             t1 = 0;
             o = 1;
           }
        }



      }
      else if(movimento == 4){
        if(t1 == 0 && robo1.municao != 0 && robo1.hp > 0){
          for(a = 1; a < coluna - 23; a++){
            if(campo[linhaTiroI][a] == '@' || campo[linhaTiroI][a] == 'O' || campo[linhaTiroI][a] == '=' || campo[linhaTiroI][a] == '+'){
              robo1.municao--;
              t1 = 1;
              loopT4 = 1;
              I_t4R1 = linhaTiroI;
              J_t4R1 = coluna - 23;
              break;
            }
            else if(a == coluna - 24){
              linhaTiroI--;
            }
          }
        }

        if(   campo[I-2][J-1] == '@' || campo[I-2][J] == '@' || campo[I-2][J+1] == '@' || campo[I-2][J+2] == '@' || campo[I-2][J+3] == '@' || campo[I-2][J+4] == '@'
           || campo[I-2][J-1] == 'O' || campo[I-2][J] == 'O' || campo[I-2][J+1] == 'O' || campo[I-2][J+2] == 'O' || campo[I-2][J+3] == 'O' || campo[I-2][J+4] == 'O'){

        }
        else{
          if(I > 1){
             I--;
           }
           else{
             movimento = 1;
             linhaTiroI = 2;
             t1 = 0;
           }
        }
      }

// -----------------------------------------------
      if(direcao2 >= 0){
        if(t2 == 0 && robo2.municao != 0 && robo2.hp > 0){
          linhaTiroX = X + 1;
          for(a = Y + 5; a < coluna - 18; a++){
            if(campo[linhaTiroX][a] == '#' || campo[linhaTiroX][a] == 'O' || campo[linhaTiroX][a] == '*' || campo[linhaTiroX][a] == '='){
              robo2.municao--;
              t2 = 1;
              loopT1R2 = 1;
              X_t1R2 = linhaTiroX;
              Y_t1R2 = Y + 5;
              break;
            }
          }
        }
      }


      if(loopT1 == 1){
        campo[I_t1R1][J_t1R1] = '.';
        if(   campo[I_t1R1][J_t1R1 + 1] == '.' || campo[I_t1R1][J_t1R1 - 1] == '|' || campo[I_t1R1][J_t1R1 - 1] == '.' || campo[I_t1R1][J_t1R1 - 2] == '|' || campo[I_t1R1][J_t1R1 - 2] == '.' || campo[I_t1R1][J_t1R1 + 2] == '.'
           || campo[I_t1R1][J_t1R1 - 1] == '@' || campo[I_t1R1][J_t1R1 - 1] == 'O' || campo[I_t1R1][J_t1R1 - 2] == '@' || campo[I_t1R1][J_t1R1 - 2] == 'O'
           || campo[I_t1R1][J_t1R1 - 1] == '+' || campo[I_t1R1][J_t1R1 - 1] == '=' || campo[I_t1R1][J_t1R1 - 2] == '+' || campo[I_t1R1][J_t1R1 - 2] == '='){
          loopT1 = 0;

          if(campo[I_t1R1][J_t1R1 - 1] == '@' || campo[I_t1R1][J_t1R1 - 2] == '@' || campo[I_t1R1][J_t1R1 - 1] == '+' || campo[I_t1R1][J_t1R1 - 2] == '+'){
            robo2.hp -= 10;
          }
          else if(campo[I_t1R1][J_t1R1 - 1] == 'O' || campo[I_t1R1][J_t1R1 - 2] == 'O' || campo[I_t1R1][J_t1R1 - 1] == '=' || campo[I_t1R1][J_t1R1 - 2] == '='){
            robo3.hp -= 10;
          }
        }
        else{
          J_t1R1--;
          if(campo[I_t1R1][J_t1R1 - 1] == '.' || campo[I_t1R1][J_t1R1 - 2] == '.' || campo[I_t1R1][J_t1R1 + 2] == '.'){
            loopT1 = 0;
          }
          else{
            J_t1R1--;
          }

        }
      }

      if(loopT2 == 1){
        campo[I_t2R1][J_t2R1] = '.';
        if(   campo[I_t2R1 - 1][J_t2R1] == '-' || campo[I_t2R1 - 1][J_t2R1] == '.'
           || campo[I_t2R1 - 1][J_t2R1] == '@' || campo[I_t2R1 - 1][J_t2R1] == 'O'){
          loopT2 = 0;

          if(campo[I_t2R1 - 1][J_t2R1] == '@'){
            robo2.hp -= 10;
          }
          else if(campo[I_t2R1 - 1][J_t2R1] == 'O'){
            robo3.hp -= 10;
          }
        }
        else{
          I_t2R1--;
        }
      }

      if(loopT3 == 1){
        campo[I_t3R1][J_t3R1] = '.';
        if(   campo[I_t3R1 - 1][J_t3R1] == '-' || campo[I_t3R1 - 1][J_t3R1] == '.'
           || campo[I_t3R1 - 1][J_t3R1] == '@' || campo[I_t3R1 - 1][J_t3R1] == 'O'){
          loopT3 = 0;

          if(campo[I_t3R1 - 1][J_t3R1] == '@'){
            robo2.hp -= 10;
          }
          else if(campo[I_t3R1 - 1][J_t3R1] == 'O'){
            robo3.hp -= 10;
          }
        }
        else{
          I_t3R1--;
        }
      }

      if(loopT4 == 1){
        campo[I_t4R1][J_t4R1] = '.';
        if(   campo[I_t4R1][J_t4R1 + 1] == '.' || campo[I_t4R1][J_t4R1 - 1] == '|' || campo[I_t4R1][J_t4R1 - 1] == '.' || campo[I_t4R1][J_t4R1 - 2] == '|' || campo[I_t4R1][J_t4R1 - 2] == '.' || campo[I_t4R1][J_t4R1 + 2] == '.'
           || campo[I_t4R1][J_t4R1 - 1] == '@' || campo[I_t4R1][J_t4R1 - 1] == 'O' || campo[I_t4R1][J_t4R1 - 2] == '@' || campo[I_t4R1][J_t4R1 - 2] == 'O'
           || campo[I_t4R1][J_t4R1 - 1] == '+' || campo[I_t4R1][J_t4R1 - 1] == '=' || campo[I_t4R1][J_t4R1 - 2] == '+' || campo[I_t4R1][J_t4R1 - 2] == '='){
          loopT4 = 0;

          if(campo[I_t4R1][J_t4R1 - 1] == '@' || campo[I_t4R1][J_t4R1 - 2] == '@' || campo[I_t4R1][J_t4R1 - 2] == '+' || campo[I_t4R1][J_t4R1 - 2] == '+'){
            robo2.hp -= 10;
          }
          else if(campo[I_t4R1][J_t4R1 - 1] == 'O' || campo[I_t4R1][J_t4R1 - 2] == 'O' || campo[I_t4R1][J_t4R1 - 1] == '=' || campo[I_t4R1][J_t4R1 - 2] == '='){
            robo3.hp -= 10;
          }
        }
        else{
          J_t4R1--;
          if(campo[I_t4R1][J_t4R1 - 1] == '.' || campo[I_t4R1][J_t4R1 - 2] == '.' || campo[I_t4R1][J_t4R1 + 2] == '.'){
            loopT4 = 0;
          }
          else{
            J_t4R1--;
          }
        }
      }

//------------------------------------------------
      if(loopT1R2 == 1){
        campo[X_t1R2][Y_t1R2] = '.';
        if(   campo[X_t1R2][Y_t1R2 + 2] == '|' || campo[X_t1R2][Y_t1R2 - 1] == '.' || campo[X_t1R2][Y_t1R2 - 2] == '.' || campo[X_t1R2][Y_t1R2 + 1] == '.' || campo[X_t1R2][Y_t1R2 + 2] == '.'
           || campo[X_t1R2][Y_t1R2 + 1] == '#' || campo[X_t1R2][Y_t1R2 + 1] == 'O' || campo[X_t1R2][Y_t1R2 + 1] == '*' || campo[X_t1R2][Y_t1R2 + 1] == '='){
          loopT1R2 = 0;
          t2 = 0;

          if(campo[X_t1R2][Y_t1R2 + 1] == '#' || campo[X_t1R2][Y_t1R2 + 1] == '*'){
            robo1.hp -= 10;
          }
          else if(campo[X_t1R2][Y_t1R2 + 1] == 'O' || campo[X_t1R2][Y_t1R2 + 1] == '='){
            robo3.hp -= 10;
          }
        }
        else{
          Y_t1R2++;
          if(campo[X_t1R2][Y_t1R2 + 1] == '.' || campo[X_t1R2][Y_t1R2 + 2] == '.' || campo[X_t1R2][Y_t1R2 - 2] == '.'){
            loopT1R2 = 0;
            t2 = 0;
          }
          else{
           Y_t1R2++;
          }
        }
      }

//--------------------------------------------------------
      if(loopT1R3 == 1){
        campo[A_t1R3][B_t1R3] = '.';
        if(   campo[A_t1R3][B_t1R3 - 1] == '|' || campo[A_t1R3][B_t1R3 - 1] == '.' || campo[A_t1R3][B_t1R3 - 2] == '.' || campo[A_t1R3][B_t1R3 + 1] == '.' || campo[A_t1R3][B_t1R3 + 2] == '.'
           || campo[A_t1R3][B_t1R3 - 1] == '#' || campo[A_t1R3][B_t1R3 - 1] == '@' || campo[A_t1R3][B_t1R3 - 1] == '*' || campo[A_t1R3][B_t1R3 - 1] == '+'){
          loopT1R3 = 0;

          if(campo[A_t1R3][B_t1R3 - 1] == '#' || campo[A_t1R3][B_t1R3 - 1] == '*'){
            robo1.hp -= 10;
          }
          else if(campo[A_t1R3][B_t1R3 - 1] == '@' || campo[A_t1R3][B_t1R3 - 1] == '+'){
            robo2.hp -= 10;
          }
        }
        else{
          B_t1R3--;
          if(campo[A_t1R3][B_t1R3 + 2] == '.' || campo[A_t1R3][B_t1R3 - 1] == '.' || campo[A_t1R3][B_t1R3 - 2] == '.'){
            loopT1R3 = 0;
          }
          else{
            B_t1R3--;
          }
        }
      }

      if(loopT2R3 == 1){
        campo[A_t2R3][B_t2R3] = '.';
        if(   campo[A_t2R3][B_t2R3 + 1] == '|' || campo[A_t2R3][B_t2R3 - 1] == '.' || campo[A_t2R3][B_t2R3 - 2] == '.' || campo[A_t2R3][B_t2R3 + 1] == '.' || campo[A_t2R3][B_t2R3 + 2] == '.'
           || campo[A_t2R3][B_t2R3 + 1] == '#' || campo[A_t2R3][B_t2R3 + 1] == '@' || campo[A_t2R3][B_t2R3 + 1] == '*' || campo[A_t2R3][B_t2R3 + 1] == '+'){
          loopT2R3 = 0;

          if(campo[A_t2R3][B_t2R3 + 1] == '#' || campo[A_t2R3][B_t2R3 + 1] == '*'){
            robo1.hp -= 10;
          }
          else if(campo[A_t2R3][B_t2R3 + 1] == '@' || campo[A_t2R3][B_t2R3 + 1] == '+'){
            robo2.hp -= 10;
          }
        }
        else{
          B_t2R3++;
          if(campo[A_t2R3][B_t2R3 + 1] == '.' || campo[A_t2R3][B_t2R3 + 2] == '.' || campo[A_t2R3][B_t2R3 - 2] == '.'){
            loopT2R3 = 0;
          }
          else{
            B_t2R3++;
          }
        }
      }

      if(loopT1R3 == 0 && loopT2R3 == 0){
        t3 = 0;
      }


    converte(&robo1, &robo2, &robo3, hp1, hp2, hp3, m1, m2, m3);

    for(i = 3, k = 1; i < 8; i = i + 2, k++){
      for(j = coluna - 14, z = 0; ; j++, z++){
        if(k == 1){
          campo[i][j] = robo1.robo[z];
          if(robo1.robo[z+1] == '\0'){
            break;
          }
        }
        else if(k == 2){
          campo[i][j] = hp1[z];
          if(hp1[z+1] == '\0'){
            break;
          }
        }
        else if(k == 3){
          campo[i][j] = m1[z];
          if(m1[z+1] == '\0'){
            break;
          }
        }
      }
    }

    for(i = 12, k = 1; i < 17; i = i + 2, k++){
      for(j = coluna - 14, z = 0; ; j++, z++){
        if(k == 1){
          campo[i][j] = robo2.robo[z];
          if(robo2.robo[z+1] == '\0'){
            break;
          }
        }
        else if(k == 2){
          campo[i][j] = hp2[z];
          if(hp2[z+1] == '\0'){
            break;
          }
        }
        else if(k == 3){
          campo[i][j] = m2[z];
          if(m2[z+1] == '\0'){
            k = 0;
            i = i + 3;
            break;
          }
        }
      }
    }

    for(i = 21, k = 1; i < 26; i = i + 2, k++){
      for(j = coluna - 14, z = 0; ; j++, z++){
        if(k == 1){
          campo[i][j] = robo3.robo[z];
          if(robo3.robo[z+1] == '\0'){
            break;
          }
        }
        else if(k == 2){
          campo[i][j] = hp3[z];
          if(hp3[z+1] == '\0'){
            break;
          }
        }
        else if(k == 3){
          campo[i][j] = m3[z];
          if(m3[z+1] == '\0'){
            k = 0;
            i = i + 3;
            break;
          }
        }
      }
    }

    system("clear");
    printf("\n\n                ######## BATALHA DE ROBOS 3 X 3 ########\n");
    printf("                               ROUND %d\n\n", round--);
    round++;
    printf("%s", campo);


    if(robo1.municao == 0 && robo2.municao == 0 && robo3.municao == 0){
      vencedor = 0;
      x = 1;
    }

    if(robo2.hp == 0 && robo3.hp == 0){
      vencedor = 1;
      x = 1;
    }
    else if(robo1.hp == 0 && robo3.hp == 0){
      vencedor = 2;
      x = 1;
    }
    else if(robo1.hp == 0 && robo2.hp == 0){
      vencedor = 3;
      x = 1;
    }



  }while(x == 0);

  if(vencedor == 0){
    printf("\n\n                ######## EMPATE ########\n");
  }
  else if(vencedor == 1){
    printf("\n\n                ######## ROBO # VENCEU ########\n");
  }
  else if(vencedor == 2){
    printf("\n\n                ######## ROBO @ VENCEU ########\n");
  }
  else if(vencedor == 3){
    printf("\n\n                ######## ROBO O VENCEU ########\n");
  }

}

