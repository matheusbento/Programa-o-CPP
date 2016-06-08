#include <iostream>
#include <stdio.h>
#include <ctype.h>
#include <windows.h>
#include <time.h>
#include <vector>
#include <fstream>
#include <stdlib.h>

using namespace std;
typedef struct theGame theGame;

struct theGame{
    string vez;
    string status;
    string nome1;
    string nome2;
    string peca1;
    string peca2;
    string posis[3][3];
};
void aloneJogo(char conf);
int p=0;
int main();
theGame aux;
string gameov;
void saveGame(){
    fstream file;
    file.open("mpbc.dat", ios::out);
    file << aux.nome1 << ";" << aux.peca1 << ";" << aux.nome2 << ";" << aux.peca2 << ";" << aux.vez;
    for (int i=0;i<3;i++){
        for (int j=0;j<3;j++){
           file << ";" << aux.posis[i][j];
        }
    }
    file.close();
    if (gameov == "s"){
        remove ("mpbc.dat");
    }
}

void tacaW(){
      cout << "     |                                                                   |    "<<endl;
      cout << "     |                              |     |                              |    "<<endl;
      cout << "     |                              | WIN |                              |    "<<endl;
      cout << "     |                               =====                               |    "<<endl;
      cout << "     |                                 |                                 |    " << endl;
      cout << "     |                                 |                                 |    " << endl;
      cout << "     |                                ---                                |    " << endl;
}
void bemVindos(){
    cout << " " << endl;
    cout << " " << endl;
    cout << " " << endl;
    cout << " " << endl;
    cout << " " << endl;
    cout << " " << endl;
    cout << "     ---------------------------------------------------------------------     "<<endl;
    cout << "    -----------------------------------------------------------------------    "<<endl;
    cout << "   -------------------------------------------------------------------------   "<<endl;
    cout << " ----------------------------------------------------------------------------- "<<endl;
    cout << "|                                     BEM                                     |"<<endl;
    cout << "|                                    VINDOS                                   |"<<endl;
    cout << "|                                      AO                                     |"<<endl;
    cout << "|                                JOGO DA VELHA                                |"<<endl;
    cout << " ----------------------------------------------------------------------------- "<<endl;
    cout << "   -------------------------------------------------------------------------   "<<endl;
    cout << "    -----------------------------------------------------------------------    "<<endl;
    cout << "     ---------------------------------------------------------------------     "<<endl;
    Sleep (3000);
}
void comecarJogo(){
    cout << " " << endl;
    cout << " " << endl;
    cout << " " << endl;
    cout << " " << endl;
    cout << "     ---------------------------------------------------------------------     "<<endl;
    cout << "    -----------------------------------------------------------------------    "<<endl;
    cout << "   -------------------------------------------------------------------------   "<<endl;
    cout << " ----------------------------------------------------------------------------- "<<endl;
    cout << "|                                      O                                      |"<<endl;
    cout << "|                                JOGO DA VELHA                                |"<<endl;
    cout << "|                                    ESTA                                     |"<<endl;
    cout << "|                                  COMECANDO                                  |"<<endl;
    cout << " ----------------------------------------------------------------------------- "<<endl;
    cout << "   -------------------------------------------------------------------------   "<<endl;
    cout << "    -----------------------------------------------------------------------    "<<endl;
    cout << "     ---------------------------------------------------------------------     "<<endl;
    Sleep (3000);
}
void pvpJogo(){
    string velha[3][3];
    comecarJogo();
    int posx=0, posy=0,stop=0,bye=9,i=0,j=0,choice=0;
    string pvez;
    string player1, player2;
    cout << "     |              JOGADOR 1 PECA: O | JOGADOR 2 PECA: X                |    "<<endl;
    cout << "     |                                                                   |    "<<endl;
    cout << "\tDigite o nome do Jogador 1 --> ";
    getline(cin,player1);
    cout << "\tDigite o nome do Jogador 2 --> ";
    getline(cin,player2);
    cout << "     |                                                                   |    "<<endl;
    cout << "      ----------------------- AGUARDE UM INSTANTE -----------------------     "<<endl;
    reniciar:
    bye=9;
    Sleep(2500);
    if (choice==1){
    pvez="1";
    }else{
    pvez="2";
    }
    for (i=0;i<3;i++){
        for (j=0;j<3;j++){
                velha[i][j]=" ";
        }
    }
    while(true){
    system("CLS");
    cout << "      -------------------------------------------------------------------  "<<endl;
    cout << "     |                    JOGO DA VELHA (MULTI-PLAYER)                   | "<<endl;
    cout << " ----------------------------------------------------------------------------- "<<endl;
    cout << "  ---------------------------------------------------------------------------  "<<endl;
    cout << "||                                    Y                                      ||"<<endl;
    cout << "||                               1    2    3                                 ||"<<endl;
    cout << "||                           1  " << velha[0][0] << "  |  " << velha[0][1] << "  |  " << velha[0][2] << "  1                             ||" << endl;
    cout << "||                              ---" << "|"<< "-----|" << "---                                ||" <<endl;
    cout << "||                      X-   2  " << velha[1][0] << "  |  " << velha[1][1] << "  |  " << velha[1][2] << "  2  -X                         ||" << endl;
    cout << "||                              ---" << "|"<< "-----|" << "---                                ||" <<endl;
    cout << "||                           3  " << velha[2][0] << "  |  " << velha[2][1] << "  |  " << velha[2][2] << "  3                             ||" << endl;
    cout << "||                               1    2    3                                 ||"<<endl;
    cout << "||                                    Y                                      ||"<<endl;
    cout << "  ---------------------------------------------------------------------------  "<<endl;
    cout << " ----------------------------------------------------------------------------- "<<endl;
    if (bye==0){
                    cout << "     |                                                                   |    "<<endl;
                    cout << "     |                          JOGO EMPATOU!!                           |    "<<endl;
                    goto gameover;
                }else{
                        if (velha[0][0]=="O" and velha[0][1]=="O" and velha[0][2]=="O"){
                            tacaW();
                            cout << "\tJOGADOR -- > " << player1 << " (GANHOU!!)" << endl;
                            cout << endl;
                            goto gameover;
                        }else if (velha[0][0]=="X" and velha[0][1]=="X" and velha[0][2]=="X"){
                            tacaW();
                            cout << "\tJOGADOR -- > " << player2 << " (GANHOU!!)" << endl;
                            cout << endl;
                            goto gameover;
                        }
                        if (velha[1][0]=="O" and velha[1][1]=="O" and velha[1][2]=="O"){
                            tacaW();
                            cout << "\tJOGADOR -- > " << player1 << " (GANHOU!!)" << endl;
                            cout << endl;
                            goto gameover;
                        }else if (velha[1][0]=="X" and velha[1][1]=="X" and velha[1][2]=="X"){
                            tacaW();
                            cout << "\tJOGADOR -- > " << player2 << " (GANHOU!!)" << endl;
                            cout << endl;
                            goto gameover;
                        }
                        if (velha[2][0]=="O" and velha[2][1]=="O" and velha[2][2]=="O"){
                            tacaW();
                            cout << "\tJOGADOR -- > " << player1 << " (GANHOU!!)" << endl;
                            cout << endl;
                            goto gameover;
                        }else if (velha[2][0]=="X" and velha[2][1]=="X" and velha[2][2]=="X"){
                            tacaW();
                            cout << "\tJOGADOR -- > " << player2 << " (GANHOU!!)" << endl;
                            cout << endl;
                            goto gameover;
                        }
                        if (velha[0][0]=="O" and velha[1][0]=="O" and velha[2][0]=="O"){
                            tacaW();
                            cout << "\tJOGADOR -- > " << player1 << " (GANHOU!!)" << endl;
                            cout << endl;
                            goto gameover;
                        }else if (velha[0][0]=="X" and velha[1][0]=="X" and velha[2][0]=="X"){
                            tacaW();
                            cout << "\tJOGADOR -- > " << player2 << " (GANHOU!!)" << endl;
                            cout << endl;
                            goto gameover;
                        }
                        if (velha[0][1]=="O" and velha[1][1]=="O" and velha[2][1]=="O"){
                            tacaW();
                            cout << "\tJOGADOR -- > " << player1 << " (GANHOU!!)" << endl;
                            cout << endl;
                            goto gameover;
                        }else if (velha[0][1]=="X" and velha[1][1]=="X" and velha[2][1]=="X"){
                            tacaW();
                            cout << "\tJOGADOR -- > " << player2 << " (GANHOU!!)" << endl;
                            cout << endl;
                            goto gameover;
                        }
                        if (velha[0][2]=="O" and velha[1][2]=="O" and velha[2][2]=="O"){
                            tacaW();
                            cout << "\tJOGADOR -- > " << player1 << " (GANHOU!!)" << endl;
                            cout << endl;
                            goto gameover;
                        }else if (velha[0][2]=="X" and velha[1][2]=="X" and velha[2][2]=="X"){
                            tacaW();
                            cout << "\tJOGADOR -- > " << player2 << " (GANHOU!!)" << endl;
                            cout << endl;
                            goto gameover;
                        }
                        if (velha[0][0]=="O" and velha[1][1]=="O" and velha[2][2]=="O"){
                            tacaW();
                            cout << "\tJOGADOR -- > " << player1 << " (GANHOU!!)" << endl;
                            cout << endl;
                            goto gameover;
                        }else if (velha[0][0]=="X" and velha[1][1]=="X" and velha[2][2]=="X"){
                            tacaW();
                            cout << "\tJOGADOR -- > " << player2 << " (GANHOU!!)" << endl;
                            cout << endl;
                            goto gameover;
                        }
                        if (velha[2][0]=="O" and velha[1][1]=="O" and velha[0][2]=="O"){
                            tacaW();
                            cout << "\tJOGADOR -- > " << player1 << " (GANHOU!!)" << endl;
                            cout << endl;
                            goto gameover;
                        }else if (velha[2][0]=="X" and velha[1][1]=="X" and velha[0][2]=="X"){
                            tacaW();
                            cout << "\tJOGADOR -- > " << player2 << " (GANHOU!!)" << endl;
                            cout << endl;
                            goto gameover;
                        }else{
                        cout << "     |                                                                   |    "<<endl;
                        if (pvez=="1"){
                            bye--;
                            cout << "\tVEZ DO(A) " << player1 << " JOGAR; " <<endl;
                            refazer:
                            cout << "\tDIGITE A POSICAO Y --> ";
                                cin >> posy;
                        if (posy>3){
                            cout << endl;
                            cout << "\tOPS!, NUMERO GRANDE MAIOR QUE 3 POSICAO Y." << endl;
                            cout << endl;
                            goto refazer;
                        }
                        rposx:
                        cout << "\tDIGITE A POSICAO X --> ";
                        cin >> posx;
                        if (posx>3){
                            cout << endl;
                            cout << "\tOPS!, NUMERO GRANDE MAIOR QUE 3 POSICAO X." << endl;
                            cout << endl;
                            goto rposx;
                        }
                        if (velha[posx-1][posy-1]==" "){
                        velha[posx-1][posy-1]="O";
                        pvez = "2";
                        }else{
                        cout << endl;
                        cout <<"\tOPS!, JOGUE EM OUTRO LUGAR." << endl;
                        cout << endl;
                        goto refazer;
                        }
                        }else if(pvez=="2"){
                        bye--;
                        cout << "\tVEZ DO(A) " << player2 << " JOGAR; " <<endl;
                        refazer2:
                        cout << "\tDIGITE A POSICAO Y --> ";
                        cin >> posy;
                        if (posy>3){
                            cout << endl;
                            cout << "\tOPS!, NUMERO GRANDE MAIOR QUE 3 POSICAO Y." << endl;
                            cout << endl;
                            goto refazer2;
                        }
                        rposx2:
                        cout << "\tDIGITE A POSICAO X --> ";
                        cin >> posx;
                        if (posx>3){
                            cout << endl;
                            cout << "\tOPS!, NUMERO GRANDE MAIOR QUE 3 POSICAO X." << endl;
                            cout << endl;
                            goto rposx2;
                        }
                        if (velha[posx-1][posy-1]==" "){
                        velha[posx-1][posy-1]="X";
                        pvez = "1";
                        }else{
                        cout << endl;
                        cout <<"\tOPS!, JOGUE EM OUTRO LUGAR!." << endl;
                        cout << endl;
                        goto refazer2;
                        }
                    }
                }
                cout << "     |                                                                   |    "<<endl;
                cout << "      -------------------------------------------------------------------  "<<endl;
                    Sleep(1000);
                }
        }
        gameover:
        cout << "     |                                                                   |    "<<endl;
        cout << "      -------------------------------------------------------------------  "<<endl;
        int op;
        decide:
        cout << "      -------------------------------------------------------------------  "<<endl;
        cout << "     |                                                                   |    "<<endl;
        cout << "     | 1 - REINICIAR PARTIDA                                             |    " << endl;
        cout << "     | 2 - SAIR                                                          |    " << endl;
        cout << "     |                                                                   |    "<<endl;
        cout << "      -------------------------------------------------------------------  "<<endl;
        cout << "     |                                                                   |    "<<endl;
        cout << "     |  --> ";
        cin >> op;
        if (op==1){
        cout << "     |                        AGUARDE UM INSTANTE                        |    "<<endl;
        cout << "      -------------------------------------------------------------------     "<<endl;
            Sleep(1500);
            system("CLS");
        goto reniciar;
        }else if (op==2){
        cout << "     |                        AGUARDE UM INSTANTE                        |    "<<endl;
        cout << "      -------------------------------------------------------------------     "<<endl;
        Sleep(1500);
        system("CLS");
        main();
        }else{
        cout << "|                               OPCAO INVALIDA                                |"<<endl;
        cout << " ----------------------------------------------------------------------------- "<<endl;
        Sleep(1500);
        system("CLS");
        goto decide;
        }
        system("PAUSE");
}
void aloneJogo(char conf){
    atexit (saveGame);
    string velha[3][3];
    int escolha,i,j,choice=0,bye=9,posx, posy;
    string pvez;
    string p1;
    string player1[2],player2[2]="COMPUTADOR";
    srand (time(NULL));
    if (conf=='s'){
        fstream check;
        string linha;
        int pos[15];
        check.open("mpbc.dat", ios::in);
        getline (check,linha);
        if (linha.length()>15){
            pos[0] = linha.find(";");
            pos[1] = linha.find(";", pos[0]);
            pos[2] = linha.find(";", pos[1]);
            pos[3] = linha.find(";", pos[2]+1);
            pos[4] = linha.find(";", pos[3]+1);
            pos[5] = linha.find(";", pos[4]+1);
            pos[6] = linha.find(";", pos[5]+1);
            pos[7] = linha.find(";", pos[6]+1);
            pos[8] = linha.find(";", pos[7]+1);
            pos[9] = linha.find(";", pos[8]+1);
            pos[10] = linha.find(";", pos[9]+1);
            pos[11] = linha.find(";", pos[10]+1);
            pos[12] = linha.find(";", pos[11]+1);
            pos[13] = linha.find(";", pos[12]+1);
            pos[14] = linha.find(";", pos[13]+1);
            player1[0] = linha.substr(0, pos[0]);
            player1[1] = linha.substr(pos[0]+1, 1);
            player2[0] = linha.substr(pos[0]+3, 10);
            player2[1] = linha.substr(pos[4]+1, (pos[4]-pos[3])-10);
            pvez = linha.substr(pos[5]+1, (pos[5]-pos[4])-1);
            velha[0][0] = linha.substr(pos[6]+1, (pos[6]-pos[5])-1);
            velha[0][1] = linha.substr(pos[7]+1, (pos[7]-pos[6])-1);
            velha[0][2] = linha.substr(pos[8]+1, (pos[8]-pos[7])-1);
            velha[1][0] = linha.substr(pos[9]+1, (pos[9]-pos[8])-1);
            velha[1][1] = linha.substr(pos[10]+1, (pos[10]-pos[9])-1);
            velha[1][2] = linha.substr(pos[11]+1, (pos[11]-pos[10])-1);
            velha[2][0] = linha.substr(pos[12]+1, (pos[12]-pos[11])-1);
            velha[2][1] = linha.substr(pos[13]+1, (pos[13]-pos[12])-1);
            velha[2][2] = linha.substr(pos[14]+1, (pos[14]-pos[13])-1);
            /*
            cout << "JOGADOR1 --> " << player1[0] << endl;
            cout << "PECA1 --> " << player1[1] << endl;
            cout << "JOGADOR2 --> " << player2[0] << endl;
            cout << "PECA2 --> " << player2[1] << endl;
            cout << "VEZ -- > " << pvez << endl;
            cout << "POSICOES -> " << velha[0][0] << ")-(" << velha[0][1] << ")-(" << velha[0][2] << ")-(" << velha[1][0] << ")-(" << velha[1][1] << ")-(" << velha[1][2] << ")-(" << velha[2][0]<< ")-(" << velha[2][1]<< ")-(" << velha[2][2]<< endl;
            */
            cout << "|                                                                             |"<<endl;
            cout << " ----------------------------------------------------------------------------- "<<endl;
            cout << "     |                                                                   |    "<<endl;
            cout << "     |               AGUARDE UM INSTANTE - CARREGANDO JOGO               |    "<<endl;
            cout << "      -------------------------------------------------------------------     "<<endl;
            Sleep(5000);
        }
        check.close();
        remove ("mpbc.dat");
        goto letsgo;
    }
    //---------------------------------------------
    //---------------------------------------------
    //ESCOLHER QUAL PE�A JOGA
    escolha = rand() % 10;
        if (escolha%2==0){
            player1[1] = "O";
        }else{
            player1[1] = "X";
        }
        if (player1[1] == "O"){
            player2[1] = "X";
        }else{
            player2[1] = "O";
        }
        //ESCOLHER QUAL PE�A JOGA - END
    comecarJogo();
    //COMECO DE ESCOLHA PLAYER
    cout << "     |                                                                   |    "<<endl;
    cout << "\tDigite o nome do Jogador --> ";
    getline(cin, p1);
    player1[0] = p1;
    start:
    cout << "     |-------------------------------------------------------------------|     "<<endl;
    cout << "     |                                                                   |    "<<endl;
    cout << "\t O(a)   "<< player1[0] <<"   JOGARA COM " << player1[1] <<endl;
    cout << "\t O   " << player2[0] << "   JOGARA COM " << player2[1] << endl;
    cout << "     |                                                                   |    "<<endl;
    cout << "      ----------------------- AGUARDE UM INSTANTE -----------------------     "<<endl;
    Sleep(2500);
    //COMECO DE ESCOLHA PLAYER - END
    reniciar:
    bye = 9;
        //COMECO PREENCHER VAZIO
    for (i=0;i<3;i++){
        for (j=0;j<3;j++){
                velha[i][j]=" ";
                aux.posis[i][j]=" ";
            }
    }
    //COMECO PREENCHER VAZIO - END
    //COMECO ESCOLHER QUEM JOGA
        srand (time(NULL));
        choice = rand() % 3;
        if (choice==1){
            pvez="1";
            }else{
                pvez="2";
        }
        //COMECO ESCOLHER QUEM JOGA - END
        letsgo:
    while(true){
            //COMECO DA MATRIZ - MOSTRANDO
    if (pvez == "2"){
        aux.vez = "2";
    }else if (pvez == "1"){
        aux.vez = "1";
    }
    aux.nome1 = player1[0];
    aux.nome2 = "COMPUTADOR";
    aux.peca1 = player1[1];
    aux.peca2 = player2[1];
    for (int i = 0;i<3;i++){
        for (int j=0;j<3;j++){
            aux.posis[i][j]=velha[i][j];
        }
    }
    system("CLS");
    cout << "      -------------------------------------------------------------------  "<<endl;
    cout << "     |                   JOGO DA VELHA (SINGLE-PLAYER)                   | "<<endl;
    cout << " ----------------------------------------------------------------------------- "<<endl;
    cout << "  ---------------------------------------------------------------------------  "<<endl;
    cout << "||                                    Y                                      ||"<<endl;
    cout << "||                               1    2    3                                 ||"<<endl;
    cout << "||                           1  " << velha[0][0] << "  |  " << velha[0][1] << "  |  " << velha[0][2] << "  1                             ||" << endl;
    cout << "||                              ---" << "|"<< "-----|" << "---                                ||" <<endl;
    cout << "||                      X-   2  " << velha[1][0] << "  |  " << velha[1][1] << "  |  " << velha[1][2] << "  2  -X                         ||" << endl;
    cout << "||                              ---" << "|"<< "-----|" << "---                                ||" <<endl;
    cout << "||                           3  " << velha[2][0] << "  |  " << velha[2][1] << "  |  " << velha[2][2] << "  3                             ||" << endl;
    cout << "||                               1    2    3                                 ||"<<endl;
    cout << "||                                    Y                                      ||"<<endl;
    cout << "  ---------------------------------------------------------------------------  "<<endl;
    cout << " ----------------------------------------------------------------------------- "<<endl;
    //COMECO DA MATRIZ - MOSTRANDO - END
        if (bye<0){
            cout << "     |                                                                   |    "<<endl;
            cout << "     |                          JOGO EMPATOU!!                           |    "<<endl;
            goto gameover;
        }else if(bye==0){
            goto verifica;
        }else{
        //VERIFICAR QUEM GANHOU
    verifica:
    if (player1[1]=="O"){
        if (velha[0][0]=="O" and velha[0][1]=="O" and velha[0][2]=="O"){
        tacaW();
        cout << "\tJOGADOR -- > " << player1[0] << " (GANHOU!!)" << endl;
        cout << endl;
        goto gameover;
            }else if (velha[1][0]=="O" and velha[1][1]=="O" and velha[1][2]=="O"){
        tacaW();
        cout << "\tJOGADOR -- > " << player1[0] << " (GANHOU!!)" << endl;
        cout << endl;
        goto gameover;
            }else if (velha[2][0]=="O" and velha[2][1]=="O" and velha[2][2]=="O"){
        tacaW();
        cout << "\tJOGADOR -- > " << player1[0] << " (GANHOU!!)" << endl;
        cout << endl;
        goto gameover;
            }else if (velha[0][0]=="O" and velha[1][0]=="O" and velha[2][0]=="O"){
        tacaW();
        cout << "\tJOGADOR -- > " << player1[0] << " (GANHOU!!)" << endl;
        cout << endl;
        goto gameover;
            }else if (velha[0][1]=="O" and velha[1][1]=="O" and velha[2][1]=="O"){
        tacaW();
        cout << "\tJOGADOR -- > " << player1[0] << " (GANHOU!!)" << endl;
        cout << endl;
        goto gameover;
            }else if (velha[0][2]=="O" and velha[1][2]=="O" and velha[2][2]=="O"){
        tacaW();
        cout << "\tJOGADOR -- > " << player1[0] << " (GANHOU!!)" << endl;
        cout << endl;
        goto gameover;
            }else if (velha[0][0]=="O" and velha[1][1]=="O" and velha[2][2]=="O"){
        tacaW();
        cout << "\tJOGADOR -- > " << player1[0] << " (GANHOU!!)" << endl;
        cout << endl;
        goto gameover;
            }else if (velha[2][0]=="O" and velha[1][1]=="O" and velha[0][2]=="O"){
        tacaW();
        cout << "\tJOGADOR -- > " << player1[0] << " (GANHOU!!)" << endl;
        cout << endl;
        goto gameover;
        }
    }else if (player1[1]=="X"){
        if (velha[0][0]=="X" and velha[0][1]=="X" and velha[0][2]=="X"){
        tacaW();
        cout << "\tJOGADOR -- > " << player1[0] << " (GANHOU!!)" << endl;
        cout << endl;
        goto gameover;
            }else if (velha[1][0]=="X" and velha[1][1]=="X" and velha[1][2]=="X"){
        tacaW();
        cout << "\tJOGADOR -- > " << player1[0] << " (GANHOU!!)" << endl;
        cout << endl;
        goto gameover;
            }else if (velha[2][0]=="X" and velha[2][1]=="X" and velha[2][2]=="X"){
        tacaW();
        cout << "\tJOGADOR -- > " << player1[0] << " (GANHOU!!)" << endl;
        cout << endl;
        goto gameover;
            }else if (velha[0][0]=="X" and velha[1][0]=="X" and velha[2][0]=="X"){
        tacaW();
        cout << "\tJOGADOR -- > " << player1[0] << " (GANHOU!!)" << endl;
        cout << endl;
        goto gameover;
            }else if (velha[0][1]=="X" and velha[1][1]=="X" and velha[2][1]=="X"){
        tacaW();
        cout << "\tJOGADOR -- > " << player1[0] << " (GANHOU!!)" << endl;
        cout << endl;
        goto gameover;
            }else if (velha[0][2]=="X" and velha[1][2]=="X" and velha[2][2]=="X"){
        tacaW();
        cout << "\tJOGADOR -- > " << player1[0] << " (GANHOU!!)" << endl;
        cout << endl;
        goto gameover;
            }else if (velha[0][0]=="X" and velha[1][1]=="X" and velha[2][2]=="X"){
        tacaW();
        cout << "\tJOGADOR -- > " << player1[0] << " (GANHOU!!)" << endl;
        cout << endl;
        goto gameover;
            }else if (velha[2][0]=="X" and velha[1][1]=="X" and velha[0][2]=="X"){
        tacaW();
        cout << "\tJOGADOR -- > " << player1[0] << " (GANHOU!!)" << endl;
        cout << endl;
        goto gameover;
            }
            cout << "     |                                                                   |    "<<endl;
        }
        if (player2[1]=="O"){
            if (velha[0][0]=="O" and velha[0][1]=="O" and velha[0][2]=="O"){
        tacaW();
        cout << "\tJOGADOR -- > " << player2[0] << " (GANHOU!!)" << endl;
        cout << endl;
        goto gameover;
            }else if (velha[1][0]=="O" and velha[1][1]=="O" and velha[1][2]=="O"){
        tacaW();
        cout << "\tJOGADOR -- > " << player2[0] << " (GANHOU!!)" << endl;
        cout << endl;
        goto gameover;
            }else if (velha[2][0]=="O" and velha[2][1]=="O" and velha[2][2]=="O"){
        tacaW();
        cout << "\tJOGADOR -- > " << player2[0] << " (GANHOU!!)" << endl;
        cout << endl;
        goto gameover;
            }else if (velha[0][0]=="O" and velha[1][0]=="O" and velha[2][0]=="O"){
        tacaW();
        cout << "\tJOGADOR -- > " << player2[0] << " (GANHOU!!)" << endl;
        cout << endl;
        goto gameover;
            }else if (velha[0][1]=="O" and velha[1][1]=="O" and velha[2][1]=="O"){
        tacaW();
        cout << "\tJOGADOR -- > " << player2[0] << " (GANHOU!!)" << endl;
        cout << endl;
        goto gameover;
            }else if (velha[0][2]=="O" and velha[1][2]=="O" and velha[2][2]=="O"){
        tacaW();
        cout << "\tJOGADOR -- > " << player2[0] << " (GANHOU!!)" << endl;
        cout << endl;
        goto gameover;
            }else if (velha[0][0]=="O" and velha[1][1]=="O" and velha[2][2]=="O"){
        tacaW();
        cout << "\tJOGADOR -- > " << player2[0] << " (GANHOU!!)" << endl;
        cout << endl;
        goto gameover;
            }else if (velha[2][0]=="O" and velha[1][1]=="O" and velha[0][2]=="O"){
        tacaW();
        cout << "\tJOGADOR -- > " << player2[0] << " (GANHOU!!)" << endl;
        cout << endl;
        goto gameover;
            }
    }else if (player2[1]=="X"){
            if (velha[0][0]=="X" and velha[0][1]=="X" and velha[0][2]=="X"){
        tacaW();
        cout << "\tJOGADOR -- > " << player2[0] << " (GANHOU!!)" << endl;
        cout << endl;
        goto gameover;
            }else if (velha[1][0]=="X" and velha[1][1]=="X" and velha[1][2]=="X"){
        tacaW();
        cout << "\tJOGADOR -- > " << player2[0] << " (GANHOU!!)" << endl;
        cout << endl;
        goto gameover;
            }else if (velha[2][0]=="X" and velha[2][1]=="X" and velha[2][2]=="X"){
        tacaW();
        cout << "\tJOGADOR -- > " << player2[0] << " (GANHOU!!)" << endl;
        cout << endl;
        goto gameover;
            }else if (velha[0][0]=="X" and velha[1][0]=="X" and velha[2][0]=="X"){
        tacaW();
        cout << "\tJOGADOR -- > " << player2[0] << " (GANHOU!!)" << endl;
        cout << endl;
        goto gameover;
            }else if (velha[0][1]=="X" and velha[1][1]=="X" and velha[2][1]=="X"){
        tacaW();
        cout << "\tJOGADOR -- > " << player2[0] << " (GANHOU!!)" << endl;
        cout << endl;
        goto gameover;
            }else if (velha[0][2]=="X" and velha[1][2]=="X" and velha[2][2]=="X"){
        tacaW();
        cout << "\tJOGADOR -- > " << player2[0] << " (GANHOU!!)" << endl;
        cout << endl;
        goto gameover;
            }else if (velha[0][0]=="X" and velha[1][1]=="X" and velha[2][2]=="X"){
        tacaW();
        cout << "\tJOGADOR -- > " << player2[0] << " (GANHOU!!)" << endl;
        cout << endl;
        goto gameover;
            }else if (velha[2][0]=="X" and velha[1][1]=="X" and velha[0][2]=="X"){
        tacaW();
        cout << "\tJOGADOR -- > " << player2[0] << " (GANHOU!!)" << endl;
        cout << endl;
        goto gameover;
            }
            //VERIFICAR QUEM GANHOU - END
        }
    }
    cout << "     |                                                                   |    "<<endl;
    if (pvez=="1"){
        bye--;
            cout << "\tVEZ DO(A) " << player1[0] << " JOGAR; " <<endl;
            refazer:
            cout << "\tDIGITE A POSICAO Y --> ";
                cin >> posy;
            if (posy<1){
                cout << endl;
                cout << "\tOPS!, NUMERO MENOR QUE 1 NA POSICAO Y." << endl;
                cout << endl;
                goto refazer;
            }else if (posy>3){
                cout << endl;
                cout << "\tOPS!, NUMERO GRANDE MAIOR QUE 3 POSICAO Y." << endl;
                cout << endl;
                goto refazer;
            }
            rposx:
                cout << "\tDIGITE A POSICAO X --> ";
                cin >> posx;
            if (posx<1){
                cout << endl;
                cout << "\tOPS!, NUMERO MENOR QUE 1 NA POSICAO X." << endl;
                cout << endl;
                goto rposx;
            }if (posx>3){
                cout << endl;
                cout << "\tOPS!, NUMERO MAIOR QUE 3 POSICAO X." << endl;
                cout << endl;
                goto rposx;
            }
            if (velha[posx-1][posy-1]==" "){
                velha[posx-1][posy-1]=player1[1];
                pvez = "2";
            }else{
                cout << endl;
                cout <<"\tOPS JA JOGARAM NESSA POSICAO!, JOGUE EM OUTRO LUGAR." << endl;
                cout << endl;
                goto refazer;
            }
        }else if(pvez=="2"){
            bye--;
            cout << "\tVEZ DO " << player2[0] << " JOGAR; " <<endl;
            refazer2:
            posy = rand() % 3 + 1;
            cout << "\tDIGITE A POSICAO Y --> " << posy << endl;
        if (posy<1){
            cout << endl;
            cout << "\tOPS!, NUMERO MENOR QUE 1 NA POSICAO Y." << endl;
            cout << endl;
            goto refazer2;
        }else if (posy>3){
            cout << endl;
            cout << "\tOPS!, NUMERO GRANDE MAIOR QUE 3 POSICAO Y." << endl;
            cout << endl;
            goto refazer2;
        }
            rposx2:
            posx = rand() % 3 + 1;
            cout << "\tDIGITE A POSICAO X --> " << posx << endl;
        if (posx<1){
            cout << endl;
            cout << "\tOPS!, NUMERO MENOR QUE 1 NA POSICAO X." << endl;
            cout << endl;
            goto rposx2;
        }if (posx>3){
            cout << endl;
            cout << "\tOPS!, NUMERO MAIOR QUE 3 POSICAO X." << endl;
            cout << endl;
            goto rposx2;
        }
        if (velha[posx-1][posy-1]==" "){
            velha[posx-1][posy-1]=player2[1];
            pvez = "1";
        }else{
            cout << endl;
            cout <<"\tOPS!, JOGUE EM OUTRO LUGAR!." << endl;
            cout << endl;
            goto refazer2;
        }

        }
            cout << "     |                                                                   |    "<<endl;
            cout << "      -------------------------------------------------------------------  "<<endl;
            Sleep(3000);
    }
    gameover:
        gameov = "s";
        cout << "     |                                                                   |    "<<endl;
        cout << "      -------------------------------------------------------------------  "<<endl;
        int op;
        decide:
        cout << "      -------------------------------------------------------------------  "<<endl;
        cout << "     |                                                                   |    "<<endl;
        cout << "     | 1 - REINICIAR PARTIDA                                             |    " << endl;
        cout << "     | 2 - SAIR                                                          |    " << endl;
        cout << "     |                                                                   |    "<<endl;
        cout << "      -------------------------------------------------------------------  "<<endl;
        cout << "     |                                                                   |    "<<endl;
        cout << "     |  --> ";

            cin >> op;

        if (op==1){
            cout << "     |                        AGUARDE UM INSTANTE                        |    "<<endl;
            cout << "      -------------------------------------------------------------------     "<<endl;
            gameov = " ";
            Sleep(1500);
            system("CLS");
            goto reniciar;
        }else if (op==2){
            cout << "     |                        AGUARDE UM INSTANTE                        |    "<<endl;
            cout << "      -------------------------------------------------------------------     "<<endl;
            Sleep(1500);
            system("CLS");
            main();
        }else{
            cout << "|                               OPCAO INVALIDA                                |"<<endl;
            cout << " ----------------------------------------------------------------------------- "<<endl;
            Sleep(1500);
            system("CLS");
            goto decide;
        }
            system("PAUSE");
}
int main(){
    string op;
    string op2;
    string linha;
    switch(p){
        case 0:
            bemVindos();
            system("CLS");
            p++;
        break;
        }
        system("CLS");
        inicio:
        cout << "      -------------------------------------------------------------------  "<<endl;
        cout << "     |                           JOGO DA VELHA                           | "<<endl;
        cout << " ----------------------------------------------------------------------------- "<<endl;
        cout << "|  sair - ENCERRAR O JOGO                                                     |"<<endl;
        cout << " ----------------------------------------------------------------------------- "<<endl;
        cout << "|  1 - JOGAR SINGLE-PLAY                                                      |"<<endl;
        cout << "|  2 - JOGAR MULTI-PLAY                                                       |"<<endl;
        cout << " ----------------------------------------------------------------------------- "<<endl;
        cout << "|                                                                             |"<<endl;
        cout << "  ---> ";
        cin >> op;
        cout << "|                                                                             |"<<endl;
        cout << " ----------------------------------------------------------------------------- "<<endl;
            Sleep(1500);
        cin.ignore();
        if (op=="1"){
                volta:
            system("CLS");
            cout << "      -------------------------------------------------------------------  "<<endl;
            cout << "     |                   JOGO DA VELHA (SINGLE-PLAYER)                   | "<<endl;
            cout << " ----------------------------------------------------------------------------- "<<endl;
            cout << "|  0 - VOLTAR AO MENU ANTERIOR                                                |"<<endl;
            cout << " ----------------------------------------------------------------------------- "<<endl;
            fstream ver;
            ver.open("mpbc.dat", ios::in);
            getline (ver, linha);
            ver.close();

            cout << "|  1 - NOVO JOGO                                                              |"<<endl;
             if (linha.length()>13){
                cout << "|  2 - CONTINUAR JOGO (JA POSSUI UM JOGO)                                     |"<<endl;
            }else{
            remove ("mpbc.dat");
            }
            cout << " ----------------------------------------------------------------------------- "<<endl;
            cout << "|                                                                             |"<<endl;
            cout << "  ---> ";
            cin >> op2;
            cin.ignore();
            cout << "|                                                                             |"<<endl;
            cout << " ----------------------------------------------------------------------------- "<<endl;
            Sleep(1500);
            if (op2=="2"){
                if (linha.length()>13){
                    char conf= 's';
                    aloneJogo(conf);
                }else{
                    goto volta;
                }
                }else if(op2=="1"){
                    system("CLS");
                    char conf;
                    aloneJogo(conf);
                }else if (op2=="0"){
                    system("CLS");
                    goto inicio;
                }else{
                    cout << "|                               OPCAO INVALIDA                                |"<<endl;
                    cout << " ----------------------------------------------------------------------------- "<<endl;
                    Sleep(1500);
                }
        }else if(op=="2"){
            system("CLS");
            cout << "      -------------------------------------------------------------------  "<<endl;
            cout << "     |                    JOGO DA VELHA (MULTI-PLAYER)                   | "<<endl;
            cout << " ----------------------------------------------------------------------------- "<<endl;
            cout << "|  0 - VOLTAR AO MENU ANTERIOR                                                |"<<endl;
            cout << " ----------------------------------------------------------------------------- "<<endl;
            cout << "|  1 - NOVO JOGO                                                              |"<<endl;
            cout << " ----------------------------------------------------------------------------- "<<endl;
            cout << "|                                                                             |"<<endl;
            cout << "  ---> ";
            cin >> op2;
            cin.ignore();
            cout << "|                                                                             |"<<endl;
            cout << " ----------------------------------------------------------------------------- "<<endl;
            Sleep(1500);
            if(op2=="1"){
                system("CLS");
                pvpJogo();
            }else if (op2=="0"){
                    system("CLS");
                    goto inicio;
            }else{
                cout << "|                               OPCAO INVALIDA                                |"<<endl;
                cout << " ----------------------------------------------------------------------------- "<<endl;
                Sleep(1500);
            }

        }else if(op=="sair"){
            cout << "|                           ADEUS, ATE A PROXIMA                              |"<<endl;
            cout << " ----------------------------------------------------------------------------- "<<endl;
            exit(0);
        }else{
            cout << "|                               OPCAO INVALIDA                                |"<<endl;
            cout << " ----------------------------------------------------------------------------- "<<endl;
            Sleep(1500);
            system("CLS");
            goto inicio;
        }


}
