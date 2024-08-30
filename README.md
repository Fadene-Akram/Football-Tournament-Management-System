# Football Tournament Management System (FTMS)
Welcome to the Football Tournament Management System (FTMS) project! This system is designed to streamline the management of a football league championship, specifically focusing on player statistics, game details, and league standings.

## Table of Contents
Introduction
How It Works
Dataset
Functions Running Time Comparison
Conclusion
Installation
Usage
Contributing
License
## Introduction
The Football Tournament Management System (FTMS) aims to streamline the management of a football league championship with 20 teams, each having 23 players and additional staff. The system will track player statistics, game details, and league standings.

## How It Works
Data Input:

The system reads data from CSV files for teams, players, game details, and statistics. This data is then organized and stored in appropriate data structures (either Binary Search Trees or AVL Trees, depending on the version).
Tournament Management:

The FTMS manages various aspects of the tournament, including:
Tracking game results and player statistics.
Ranking teams based on their performance.
Listing top scorers and player performances.
Data Structures:

The system uses either Binary Search Trees (BST) or AVL Trees to store and manage the data. Both structures allow efficient insertion, deletion, and lookup operations but have different performance characteristics.
Output:

The system provides various outputs such as team rankings, top scorers, and detailed player statistics. These can be printed or displayed as needed.
## Dataset
The dataset includes information from the 2018/2019 La Liga season, focusing on 20 teams and their games. The dataset consists of CSV files for teams, players, games, and statistics.

## Functions Running Time Comparison
The running time for various functions was compared using both BST and AVL trees. Here is a summary of the results:

PrintTeamsRanking:

AVL Tree: Average running time is 51.505 milliseconds.
BST: Average running time is 52.92 milliseconds.
TeamsKmRun:

AVL Tree: Average running time is 53.57 milliseconds.
BST: Average running time is 54.12 milliseconds.
TeamBestScorersList:

AVL Tree: Average running time is 57.69 milliseconds.
BST: Average running time is 58.15 milliseconds.
TournamentBestScorersList (single):

AVL Tree: Average running time is 35.845 milliseconds.
BST: Average running time is 35.933 milliseconds.
TournamentBestScorersList (all):

AVL Tree: Average running time is 310.45 milliseconds.
BST: Average running time is 315.99 milliseconds.
## Conclusion
While AVL trees generally offer better performance for large datasets, BSTs can still be useful in certain scenarios. The choice of data structure should be based on the specific requirements and constraints of the project. The performance differences, while present, are not drastic for small to medium-sized datasets.
