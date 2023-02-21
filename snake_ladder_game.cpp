#include "iostream"
#include "unistd.h"
#include "stdlib.h"
#include "stdio.h"
#include "time.h"
#include "random"
// #include "cstdlib"

using namespace std;

void draw_line(int n, char ch);
void board();
void gamescore(string name1, string name2, int p1, int p2);
void play_dice(int &score);

int main()
{
    int player1 = 0, player2 = 0, lastposition;
    string player1_name;
    string player2_name;
    srand(time(0));
    system("clear");
    draw_line(50, '=');
    cout << "\n\n\t\t\t\t\t\t SNAKE LADDER GAME\n\n\n\n";
    draw_line(50, '=');
    cout << "\n\n\n\t\t\t\tEnter Name of player 1 : ";
    getline(cin, player1_name);
    cout << "\n\n\t\t\t\tEnter Name of player 2 : ";
    getline(cin, player2_name);
    while (player1 <= 100 && player2 <= 100)
    {
        board();
        gamescore(player1_name, player2_name, player1, player2);
        cout << "\n\n\t\t\t\t---> " << player1_name << " Now your Turn >> Press any key to play ";
        cin.get();
        lastposition = player1;
        play_dice(player1);
        if (player1 < lastposition)
            cout << "\n\a\t\t\t\tOops!! Snake found !! You are at position " << player1 << "\n";
        else if (player1 > lastposition + 6)
            cout << "\n\t\t\t\tGreat !! you got a ladder !! You are at position " << player1;
        cout << "\n\n\t\t\t\t---> " << player2_name << " Now your Turn >> Press any key to play ";
        cin.get();
        lastposition = player2;
        play_dice(player2);
        if (player2 < lastposition)
            cout << "\n\n\a\t\t\t\tOops!! Snake found !! You are at position" << player2 << "\n";
        else if (player2 > lastposition + 6)
            cout << "\n\n\t\t\t\tGreat!! You got a ladder !! You are at position " << player2 << "\n";
        cin.get();
    }

    system("clear");
    cout << "\n\n\n";

    draw_line(50, '+');
    cout << "\n\n\t\t\t\t\t\tRESULT\n\n";
    draw_line(50, '+');
    cout << endl;
    gamescore(player1_name, player2_name, player1, player2);
    cout << "\n\n\n";
    if (player1 >= player2)
        cout << player1_name << "\t\t\t\t !! You are the winner of the game\n\n";
    else
        cout << player2_name << "\t\t\t\t !! You are the winner of the game\n\n";
    draw_line(50, '+');
}

void draw_line(int n, char ch)
{
    for (int i = 0; i < n; i++)
        cout << ch;
}

void board()
{
    system("clear");
    cout << "\n\n";
    draw_line(50, '-');
    cout << "\n\tSNAKE AT POSITION\n";
    draw_line(50, '-');
    cout << "\n\t\t\t\t\tFrom 98 to 28 \n\t\t\t\t\tFrom 95 to 24 \n\t\t\t\t\tFrom 92 to 51\n\t\t\t\t\tFrom 83 to 19\n\t\t\t\t\tFrom 73 to 1\n\t\t\t\t\tFrom 69 to 33 \n\t\t\t\t\tFrom 64 to 36 \n\t\t\t\t\tFrom 59 to 17 \n\t\t\t\t\tFrom 55 to7 \n\t\t\t\t\tFrom 52 to 11\n\t\t\t\t\tFrom 48 to 9\n\t\t\t\t\tFrom 46 to 5\n\t\t\t\t\tFrom 44 to 22\n\n";
    draw_line(50, '-');
    cout << "\n\t LADDER AT POSITION\n";
    draw_line(50, '-');
    cout << "\n\t\t\t\t\tFrom 8 to 26\n\t\t\t\t\tFrom 21 to 82 \n\t\t\t\t\tFrom 43 to 77\n\t\t\t\t\tFrom 58 to 91\n\t\t\t\t\tFrom 62 to 96\n\t\t\t\t\tFrom 66 to 87\n\t\t\t\t\tFrom 80 to 100\n";
    draw_line(50, '-');
    cout << endl;
}

void gamescore(string name1, string name2, int p1, int p2)
{
    cout << "\n";
    draw_line(50, '~');
    cout << "\n\t\tGAME STATUS\n";
    draw_line(50, '~');
    cout << "\n\t--->" << name1 << " is at position " << p1 << endl;
    cout << "\t--->" << name2 << " is at position " << p2 << endl;
    draw_line(50, '_');
    cout << endl;
}

void play_dice(int &score)
{
    int dice;
    dice = rand() % 6 + 1;
    cout << "\nYou got " << dice << " Point!!";
    score += dice;
    cout << "Now you are at position " << score;
    switch (score)
    {
    case 98:
        score = 28;
        break;
    case 95:
        score = 24;
        break;
    case 92:
        score = 51;
        break;
    case 83:
        score = 19;
        break;
    case 73:
        score = 1;
        break;
    case 69:
        score = 33;
        break;
    case 64:
        score = 36;
        break;
    case 59:
        score = 17;
        break;
    case 55:
        score = 7;
        break;
    case 52:
        score = 11;
        break;
    case 48:
        score = 9;
        break;
    case 46:
        score = 5;
        break;
    case 44:
        score = 22;
        break;
    case 8:
        score = 26;
        break;
    case 21:
        score = 82;
        break;
    case 43:
        score = 77;
        break;
    case 58:
        score = 91;
        break;
    case 62:
        score = 96;
        break;
    case 66:
        score = 87;
        break;
    case 80:
        score = 100;
        break;

    default:
        break;
    }
}
