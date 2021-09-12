/*Faça o código fonte estruturado de algoritmo que contenha um STRUCT contendo um atributo do tipo inteiro X e outro atributo do tipo string LETRAS. O usuário deverá digitar uma lista de 5 números e 5 Letras ou palavras. Crie um menu com opções para classificar a coluna X e também para classificar a coluna LETRAS. Coloque opções para buscar uma letra ou palavra dentro do campo LETRAS e outra opção para buscar um número dentro da coluna X,
usando nas duas buscas o algoritmo de busca binária.*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int const n = 5;
int pos = -1;

typedef struct lista xletras;

struct lista {
    int X [n];
    string Letras [n];
};
xletras tab;

int lerX();
string lerLetras();
void novoReg();
void exibir();
void classificar();
int buscaBinX(int nmX);
int buscaBinL(string letraL);
void buscaBin();
void controle();

int main() {
    system("clear");
    setlocale(LC_ALL, "Portuguese");
    controle();
    return 0;
}

int lerX() {
    int numX;
    cout << "\nInforme um valor.: ";
    cin >> numX;
    return numX;
}

string lerLetras() {
    string letras;
    cout << "\nInforme uma letra ou palavra.: ";
    getline(cin, letras);
    return letras;
}

void novoReg() {
    pos++;
    if (pos >= n) {
        system("clear");
        cout << "\nLimite de dados atingido! \nSelecione outra opção!" << endl;
        system("sleep 4");
        return;
    } else {
        int nx_ = lerX();
        tab.X [pos] = nx_;

        cin.ignore();
        string let_ = lerLetras();
        tab.Letras [pos] = let_;
        return;
    }
}

void exibir() {
    int exibirX, posX;
    string exibirLetras;
    system("clear");
    cout << "\nLista de Números e Letras:";
    cout << "\nPos  --  Número  --  Letras" << endl;
    for (int i = 0; i <= n - 1; i++) {
        exibirX = tab.X [i];
        exibirLetras = tab.Letras [i];
        cout << "[" << i << "]  --  " << "[" << exibirX << "]"
                << "  --  " << "[" << exibirLetras << "]" << endl;
    }
    system("sleep 4");
}

void classificar() {
    int opClass, auxX;
    string auxLetras;
    cout << "\nInforme a opção de Classificação: \n1 - Classificar por número"
            " \n2 - Classificar por letra / palavra \nOpção.: ";
    cin >> opClass;
    if (opClass == 1) {

        for (int i = 0; i <= (n - 2); i++) {
            for (int j = i; j <= (n - 1); j++) {
                if (tab.X [i] > tab.X [j]) {
                    auxX = tab.X [i];
                    tab.X [i] = tab.X [j];
                    tab.X [j] = auxX;

                    auxLetras = tab.Letras [i];
                    tab.Letras [i] = tab.Letras [j];
                    tab.Letras [j] = auxLetras;
                }
            }
        }
    } else if (opClass == 2) {

        for (int i = 0; i <= (n - 2); i++) {
            for (int j = i; j <= (n - 1); j++) {
                if (tab.Letras [i] > tab.Letras [j]) {
                    auxLetras = tab.Letras [i];
                    tab.Letras [i] = tab.Letras [j];
                    tab.Letras [j] = auxLetras;
                    
                    auxX = tab.X [i];
                    tab.X [i] = tab.X [j];
                    tab.X [j] = auxX;
                }
            }
        }
    } else {
        cout << "\nOpção Inválida!" << endl;
        system("sleep 4");
        return;
    }
    system("clear");
    cout << "\nÍtens classificados com Sucesso!" << endl;
    system("sleep 4");
    return;
}

int buscaBinX(int nmX) {
    int esq = 0, mei, dir = n;
    for (int i = esq; i <= dir; i++) {
        mei = (esq + dir) / 2;
        if (nmX == tab.X [mei]) {
            return mei;
        } else if (nmX > tab.X [mei]) {
            esq = mei;
        } else {
            dir = mei;
        }
    }
    return -1;
}

int buscaBinL(string letraL) {
    int esq = 0, mei, dir = n;
    for (int i = esq; i <= dir; i++) {
        mei = (esq + dir) / 2;
        if (letraL == tab.Letras [mei]) {
            return mei;
        } else if (letraL > tab.Letras [mei]) {
            esq = mei;
        } else {
            dir = mei;
        }
    }
    return -1;
}

void buscaBin() {
    int opBusca, xBusca, valBusca;
    string letBusca;
    cout << "\nInforme a opção de Busca.:\n1 - Buscar por número "
            "\n2 - Buscar por letra/palavra \nOpção de Busca.: ";
    cin >> opBusca;
    if (opBusca == 1) {
        xBusca = lerX();
        valBusca = buscaBinX(xBusca);
        if (valBusca == -1) {
            cout << "\nO valor " << xBusca << " não foi localizado!" << endl;
        } else {
            cout << "\nO valor " << xBusca << " foi localizado na posição " << valBusca << endl;
        }
        system("sleep 4");

    } else if (opBusca == 2) {
        cin.ignore();
        letBusca = lerLetras();
        valBusca = buscaBinL(letBusca);
        if (valBusca == -1) {
            cout << "\nA letra / palavra " << letBusca << " não foi localizada!" << endl;
        } else {
            cout << "\nA letra / palavra " << letBusca << " foi localizada na posição " << valBusca << endl;
        }
        system("sleep 4");

    } else {
        cout << "\nOpção Inválida!" << endl;
        system("sleep 4");
    }
    return;
}

void controle() {
    int menuOp;
    while (true) {
        system("clear");
        cout << "\n***   Menu de Controle   ***";
        cout << "\n1 - Novo Registro \n2 - Exibir \n3 - Classificar "
                "\n4 - Buscar \n5 - Sair \nOpção.: ";
        cin >> menuOp;

        switch (menuOp) {
            case 1: novoReg();
                break;
            case 2: exibir();
                break;
            case 3: classificar();
                break;
            case 4: buscaBin();
                break;
            case 5: exit(0);
        }
    }
}