#include <iostream>
#include <string>

using namespace std;

void playGame(string first, string second);

char userPlay[9] = {0};

const string winningPlaces[9] = {
    "012",
    "345",
    "678",
    "048",
    "048",
    "246",
    "036",
    "147",
    "258"};

void displayRule(string first, string second)
{
    cout << "========================================================" << endl;
    cout << "                  Jogo da Velha                         " << endl;
    cout << "====================Regras==============================" << endl;
    cout << "Jogo da Velha é um jogo para dois jogadores, X e O" << endl;
    cout << "que se revezam marcando os espaços em uma grade 3x3." << endl;
    cout << "O jogador que conseguir colocar três de suas marcas" << endl;
    cout << "Em uma linha horizontal, diagonal ou vertical ganha o jogo" << endl;
    cout << "Escreva um número onde será exibida sua marca." << endl;
    cout << "========================================================" << endl;
    cout << endl;
    cout << "Nome do primeiro jogador (X) : " << first << endl;
    cout << "Nome do segundo jogador (O) : " << second << endl;
    cout << endl;
    cout << "========================================================" << endl;
    cout << endl;
}

void displayDesk()
{
    cout << char(201) << char(205) << char(203) << char(205) << char(203) << char(205) << char(187) << endl;
    cout << char(186) << userPlay[0] << char(186) << userPlay[1] << char(186) << userPlay[2] << char(186) << endl;
    cout << char(204) << char(205) << char(206) << char(205) << char(206) << char(205) << char(185) << endl;
    cout << char(186) << userPlay[3] << char(186) << userPlay[4] << char(186) << userPlay[5] << char(186) << endl;
    cout << char(204) << char(205) << char(206) << char(205) << char(206) << char(205) << char(185) << endl;
    cout << char(186) << userPlay[6] << char(186) << userPlay[7] << char(186) << userPlay[8] << char(186) << endl;
    cout << char(200) << char(205) << char(202) << char(205) << char(202) << char(205) << char(188) << endl;
}

bool checkWinner(string first, string second, int runCounter)
{
    string winner = "";
    bool tempWinner = false;
    int firstPlayerMap[5] = {0};
    int secondPlayerMap[4] = {0};
    int counter = 0;
    int secondCounter = 0;
    int length = 0;
    string temp = "";
    string firstPlayerStringValue = "";
    string secondPlayerStringValue = "";
    for (int i = 0, j = 0, k = 0; i < 9; i++)
    {
        if (userPlay[i] == 'X')
        {
            firstPlayerMap[j] = i;
            j++;
        }
        else if (userPlay[i] == 'O')
        {
            secondPlayerMap[k] = i;
            k++;
        }
        else
            continue;
    }
    cout << endl;
    for (int i = 0; i < 5; i++)
    {
        firstPlayerStringValue += to_string(firstPlayerMap[i]);
    }
    for (int i = 0; i < 4; i++)
    {
        secondPlayerStringValue += to_string(secondPlayerMap[i]);
    }
    if (runCounter == 1)
    {
        length = 1;
        firstPlayerStringValue.erase(1);
        secondPlayerStringValue = "0";
    }
    else if (runCounter == 2)
    {
        length = 1;
        firstPlayerStringValue.erase(1);
        secondPlayerStringValue.erase(1);
    }
    else if (runCounter == 3)
    {
        length = 2;
        firstPlayerStringValue.erase(2);
        secondPlayerStringValue.erase(1);
    }
    else if (runCounter == 4)
    {
        length = 2;
        firstPlayerStringValue.erase(2);
        secondPlayerStringValue.erase(2);
    }
    else if (runCounter == 5)
    {
        length = 3;
        firstPlayerStringValue.erase(3);
        secondPlayerStringValue.erase(2);
    }
    else if (runCounter == 6)
    {
        length = 3;
        firstPlayerStringValue.erase(3);
        secondPlayerStringValue.erase(3);
    }
    else if (runCounter == 7)
    {
        length = 4;
        firstPlayerStringValue.erase(4);
        secondPlayerStringValue.erase(3);
    }
    else if (runCounter == 8)
    {
        length = 4;
        firstPlayerStringValue.erase(4);
        secondPlayerStringValue.erase(4);
    }
    else if (runCounter == 9)
    {
        length = 5;
        firstPlayerStringValue.erase(5);
        secondPlayerStringValue.erase(4);
    }
    else
    {
        cout << "Erro no sistema" << endl;
    }
    if (runCounter >= 5)
    {
        for (int i = 0; i < 9; i++)
        {
            counter = 0;
            secondCounter = 0;
            for (int j = 0; j < 3; j++)
            {
                for (int k = 0; k < length; k++)
                {
                    if (winningPlaces[i][j] == firstPlayerStringValue[k])
                    {
                        counter++;
                        if (counter == 3)
                        {
                            tempWinner = true;
                            winner = first;
                            break;
                        }
                    }
                    if (winningPlaces[i][j] == secondPlayerStringValue[k])
                    {
                        secondCounter++;
                        if (secondCounter == 3)
                        {
                            tempWinner = true;
                            winner = second;
                            break;
                        }
                    }
                }
            }
        }
    }
    if (tempWinner)
    {
        char answer = 'n';
        cout << "O ganhador é: " << winner << endl;
        cout << endl
             << "Quer jogar novamente (S/N) ? : ";
        cin >> answer;
        if (answer == 's' || answer == 'S')
        {
            playGame(first, second);
        }
        else if (answer == 'n' || answer == 'N')
        {
            cout << "O vencedor é " << winner << endl;
            exit(0);
        }
        else
        {
            cout << "Não consigo entender se é sim ou não,\n então vou me fechar, tente executar novamente" << endl;
            exit(0);
        }
    }
    return tempWinner;
}

void fillArray()
{
    char temp[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    for (int i = 0; i < 9; i++)
    {
        userPlay[i] = temp[i];
    }
}

void playGame(string first, string second)
{
    fillArray();
    bool firstRun = true;
    int counter = 0;
    int number = 0;
    int runCounter = 1;
    cout << endl;
    while (true)
    {
        if (firstRun)
        {
            displayDesk();
        }
        else
        {
            system("CLS");
            displayDesk();
            if (checkWinner(first, second, runCounter))
                break;
            runCounter++;
            if (runCounter == 10)
            {
                char answer = 'n';
                cout << "Desenhe !" << endl;
                cout << endl
                     << "Quer jogar novamente (S/N) ? : ";
                cin >> answer;
                if (answer == 's' || answer == 'S')
                {
                    playGame(first, second);
                }
                else if (answer == 'n' || answer == 'N')
                {
                    cout << "Ok, então o vencedor é a velha rs." << endl;
                    exit(0);
                }
                else
                {
                    cout << "Jogo acabou!!!" << endl;
                    exit(0);
                }
            }
            if (runCounter >= 11)
            {
                cout << "Erro!!!" << endl;
                exit(0);
            }
        }
        if (counter == 0)
        {
            cout << "Agora é a vez do " << first << " comece seu turno. " << endl;
            cout << "Mova entre as casas 1-9" << endl;
            cout << "Seu movimento foi: ";
            cin >> number;
            if (number <= 0 || number > 9)
            {
                cout << "Disse para você inserir um número entre 1-9" << endl;
                cout << "Vamos tentar novamente, insira o número: ";
                cin >> number;
            }
            if (userPlay[number - 1] == 'X' || userPlay[number - 1] == 'O')
            {
                cout << endl;
                cout << endl;
                cout << "Você não pode colocar sua marca duas vezes em um só lugar!" << endl;
                cout << "Mova entre as casas 1-9" << endl;
                cout << "Seu movimento: ";
                cin >> number;
                if (number <= 0 || number > 9)
                {
                    cout << "Disse para você inserir um número entre 1-9" << endl;
                    cout << "Vamos tentar novamente, insira o número: ";
                    cin >> number;
                    if (number <= 0 || number > 9)
                    {
                        cout << "Acabou o Jogo!" << endl;
                        exit(0);
                    }
                }
                if (userPlay[number - 1] == 'X' || userPlay[number - 1] == 'O')
                {
                    cout << endl;
                    cout << "Programa fechando...." << endl;
                    system("PAUSE");
                    exit(0);
                }
                else
                {
                    userPlay[number - 1] = 'X';
                    displayDesk();
                    counter++;
                    firstRun = false;
                }
            }
            else
            {
                userPlay[number - 1] = 'X';
                displayDesk();
                counter++;
                firstRun = false;
            }
        }
        else
        {
            cout << "Agora é a vez do" << second << " comece seu turno." << endl;
             cout << "Mova entre as casas 1-9" << endl;
            cout << "Seu movimento foi: ";
            cin >> number;
            if (number <= 0 || number > 9)
            {
                cout << "Disse para você inserir um número entre 1-9" << endl;
                    cout << "Vamos tentar novamente, insira o número: ";
                cin >> number;
                if (number <= 0 || number > 9)
                {
                     cout << "Acabou o Jogo!" << endl;
                    exit(0);
                }
            }
            if (userPlay[number - 1] == 'X' || userPlay[number - 1] == 'O')
            {
                cout << endl;
                cout << endl;
                 cout << "Você não pode colocar sua marca duas vezes em um só lugar!" << endl;
                cout << "Mova entre as casas 1-9" << endl;
                cout << "Seu movimento: ";
                cin >> number;
                if (number <= 0 || number > 9)
                {
                    cout << "Told you to input number between 1-9" << endl;
                    cout << "Let's try again , input number : ";
                    cin >> number;
                    if (number <= 0 || number > 9)
                    {
                         cout << "Acabou o Jogo!" << endl;
                        exit(0);
                    }
                }
                if (userPlay[number - 1] == 'X' || userPlay[number - 1] == 'O')
                {
                    
                    cout << "Programa fechando ..." << endl;
                    system("PAUSE");
                    exit(0);
                }
                else
                {
                    userPlay[number - 1] = 'O';
                    displayDesk();
                    counter--;
                    firstRun = false;
                }
            }
            else
            {
                userPlay[number - 1] = 'O';
                displayDesk();
                counter--;
                firstRun = false;
            }
        }
    }
}

void startGame(string first, string second)
{
    displayRule(first, second);
    string start;
    cout << "Começar o jogo (S/N) ? : ";
    cin >> start;
    if (start == "s" || start == "S")
    {
        playGame(first, second);
    }
    else if (start == "n" || start == "N")
    {
        cout << "Tem certeza\nFeche o programa (N)\nContinue (S): ";
        cin >> start;
        if (start == "s" || start == "S")
        {
            playGame(first, second);
        }
        else
        {
            cout << "Fechando..." << endl;
            exit(0);
        }
    }
    else
    {
        cout << "Resposta errada, a resposta deve ser S ou N, vamos começar de novo" << endl;
        system("PAUSE");
        system("CLS");
        startGame(first, second);
    }
}

int main(int argc, char const *argv[])
{
    string firstPlayerName = "Kosta";
    cout << "Escreva o nome do primeiro jogador: ";
    cin >> firstPlayerName;
    string secondPLayerName = "Doe";
    cout << "Escreva o nome do segundo jogador: ";
    cin >> secondPLayerName;
    startGame(firstPlayerName, secondPLayerName);
    return 0;
}