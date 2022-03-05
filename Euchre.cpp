// Euchre.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include "Deck.h"
#include "Player.h"
#include "Team.h"

void Start();
void SetTeams();
void Deal();
void Game();
int GetWinner();
void Round();
Suit SetTrump();
void Trick(Suit trump);


Team teams[2];
Player players[4];

Deck deck;

int main()
{
    std::cout << "Press enter to start Euchre.";
    std::cin;
    Start();
}

void Start()
{
    SetTeams();
    Deal();
    Game();
}

void SetTeams()
{
    teams[0].players[0] = players[0];
    teams[0].players[1] = players[1];

    teams[1].players[0] = players[2];
    teams[1].players[1] = players[3];
}

void Deal()
{
    int location = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            players[i].hand[j] = deck.cards[location];
            location++;
        }
    }
}

void Game()
{
    for (int i = 0; i < 100; i++)
    {
        Round();
    }

    std::cout << "Team " << GetWinner() << " is the winner with " << teams[GetWinner() - 1].score << " points!";
}

int GetWinner()
{
    if (teams[0].score > teams[1].score)
    {
        return 1;
    }
    else
    {
        return 2;
    }
}

void Round()
{
    for (int i = 0; i < 5; i++)
    {
        Trick(SetTrump());
    }
}

Suit SetTrump()
{
    return deck.cards[20].suit;
}

void Trick(Suit trump)
{
    Card table[4];

    Suit suit;

    for (int i = 0; i < 4; i++)
    {
        table[i] = players[i].PlayCard(trump, suit);
        if (i == 0)
        {
            suit = table[i].suit;
        }
    }

    //determine winner of trick
    std::vector<Card> trumps_on_table;

    for (int i = 0; i < sizeof(table); i++)
    {
        if (table[i].suit == trump)
        {
            trumps_on_table.push_back(table[i]);
        }

        //get index of max element
        //std::distance(trumps_on_table.begin(), std::max_element(trumps_on_table[0], trumps_on_table[trumps_on_table.size()]));
        std::max_element(trumps_on_table.begin(), trumps_on_table.end()) - trumps_on_table.end();
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
