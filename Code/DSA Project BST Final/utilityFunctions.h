#ifndef UTILITY_FUNCTION
#define UTILITY_FUNCTION


#include <iostream>
#include "BinarySearchTree.h"
#include "Date.h"
#include "TeamStatistics.h"
#include <iomanip>

void printReverseInOrderTeam(BinaryNode<TeamStatistics> *&root)
{
    static int rank = 1;
    if (root)
    {
        printReverseInOrderTeam(root->right);
        //add team name
//        std::cout << root->element->
        std::cout << std::left;
        std::cout<< setw(10) << rank  << setw(30) <<root->element.Get_name();
        root->element.printTeamStatistics();
        rank++;
        printReverseInOrderTeam(root->left);
    }
}

void printReverseInOrder( BinaryNode<PlayerStatistics> *&root, const Date &date)
{
    static int rank = 1;
    if (root)
    {
        printReverseInOrder(root->right, date);
        std::cout << std::left;
        std::cout << setw(30) << root->element.getPlayerName() << setw(40) << root->element.Get_goals_scored() << setw(40) << rank << std::endl;
        std::cout << "________________________________________________________________________________________________________" << std::endl;
        rank++;
        printReverseInOrder(root->left, date);
    }
}


void PlayersprintReverseInOrder(BinaryNode<Player> *&root)
{
    static int rank = 1;
    if (root)
    {
        PlayersprintReverseInOrder(root->right);
        std::cout << std::left;
        std::cout << setw(26) << rank << setw(40) << root->element.Get_player_name() << setw(40) << root->element.Get_playerNumber() << setw(40) << root->element.GetStatistics()[root->element.GetStatistics().size() - 1].Get_goals_scored() << std::endl;
        std::cout << "__________________________________________________________________________________________________________________________________" << std::endl;
        rank++;
        PlayersprintReverseInOrder(root->left);
    }
}


void PlayersStatprintReverseInOrder(BinaryNode<PlayerStatistics> *&root)
{
    static int rank = 1;
    if (root)
    {
        PlayersStatprintReverseInOrder(root->right);
        std::cout << std::left;
        std::cout << setw(26) << rank << setw(40) << root->element.getPlayerName() << setw(40) << setw(40) << root->element.Get_goals_scored() << std::endl;
        std::cout << "__________________________________________________________________________________________________" << std::endl;
        rank++;
        PlayersStatprintReverseInOrder(root->left);
    }
}

#endif