#include <stdio.h>
#include <windows.h>
#include <conio.h>

//Constantes da tela
#define TELA_LARGURA 125
#define TELA_ALTURA  25
#define DELAY        90

//Coisas do buffer
HANDLE hConsole;
CHAR_INFO consoleBuffer[TELA_LARGURA * TELA_ALTURA];
COORD bufferSize = {TELA_LARGURA, TELA_ALTURA};
COORD bufferCoord = {0, 0};
SMALL_RECT consoleWriteArea = {0, 0, TELA_LARGURA-1, TELA_ALTURA-1};

//Enzo Capitani: Criação do desenhaTela();
void desenhaTela()
{
    for(int i = 0; i < TELA_LARGURA*TELA_ALTURA; i++){
        consoleBuffer[i].Char.AsciiChar = '#';
        consoleBuffer[i].Attributes = BACKGROUND_BLUE;
    }

    WriteConsoleOutputA(hConsole, consoleBuffer, bufferSize, bufferCoord, &consoleWriteArea);
}

//acho que é o main
int main(){
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    while(1)
    {
        desenhaTela();
        Sleep(DELAY);
    }

    return 0;
}