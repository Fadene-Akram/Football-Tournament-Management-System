#include "Tournament.h"
#include "BinarySearchTree.h"
#include "Date.h"
#include "utilityFunctions.h"
#include "TeamStatistics.h"
#include "Game.h"
#include <iomanip>
// int Tournament::CurrentGamePlayed = 0;


Tournament::Tournament(std::string gender, int age, std::string season) : Gender(gender), Age(age), Season(season)
{
    // CurrentGamePlayed++;
}

void Tournament::SetTournamentTeams(const std::vector<Team> &Tournamentteams)
{
    this->TournamentTeams = Tournamentteams;
}

void Tournament::SetTournamentGames(BinarySearchTree<Game>& games)
{
    this->Games = games;
}


void Tournament::PrintTeamsRanking(const Date &Date) const
{
    BinarySearchTree<TeamStatistics> Tree ;
    for (const auto & TournamentTeam : TournamentTeams)
    {
        Tree.insert(TournamentTeam.GetStatistics(Date));
    }
    std::cout<<std::endl;

    std::cout <<"Teamrank  TeamName                    Point       Goalsscored      GoalsConceded      GoalsDifference         Numberofgamesplayed"<<std::endl;
    std::cout<<"__________________________________________________________________________________________________________________________________"<<std::endl;

    printReverseInOrderTeam(Tree.getRoot());
}

void Tournament::TournamentBestScorersList(const Date &date)
{
    std::cout << "List of best Scorers in the Tournament :" << std::endl;
    BinarySearchTree<PlayerStatistics> PlayerStatTree;
    std::cout << std::left;
    std::cout << setw(30) << "Player name: " << setw(40) << "Number of goals scored: " << setw(40) << "player rank: " << std::endl;
    std::cout << "________________________________________________________________________________________________________" << std::endl;
    for (size_t i = 0; i < TournamentTeams.size(); i++)
    {
        for (size_t j = 0; j < TournamentTeams[i].getPlayers().size(); j++)
        {
            if (TournamentTeams[i].getPlayers()[j].GetStatistics(date).Get_goals_scored() >= 1)
                // when inserting we enter statistic in that date and compare scores
                PlayerStatTree.insert(TournamentTeams[i].getPlayers()[j].GetStatistics(date));
        }
    }
    printReverseInOrder(PlayerStatTree.getRoot(), date);
}

Team& Tournament::FindTeam(const std::string &teamName)
{
    for (size_t i = 0; i < 20; i++)
    {
        if (TournamentTeams.at(i).getTeamName() == teamName)
        {
            return TournamentTeams.at(i);
        }
    }
}

void Tournament::TeamsKmRun(const std::string &teamName, const Date &date)
{
    Team TheTeam = FindTeam(teamName);
    std::cout << std::left;
    std::cout << setw(36) << "Player name" << setw(20) << "Player number" << setw(40) << "Number of KM run in this game " << setw(40) << "Average of KM run until this game" << std::endl;
    std::cout << "__________________________________________________________________________________________________________________________________" << std::endl;
    for (size_t i = 0; i < TheTeam.getPlayers().size(); i++)
    {
        std::cout << std::left;
        std::cout << setw(36) << TheTeam.getPlayers()[i].Get_player_name() << setw(20) << TheTeam.getPlayers()[i].Get_playerNumber() << setw(40) << TheTeam.getPlayers()[i].GameKmRun(date) << setw(40) << TheTeam.getPlayers()[i].AverageKmRun(date);

        std::cout << std::endl
                  << "__________________________________________________________________________________________________________________________________" << std::endl;
    }
}

void Tournament::TeamBestScorersList(const std::string &teamName)
{
    Team theTeam = this->FindTeam(teamName);
    BinarySearchTree<Player> PlayersTree;
    std::cout << std::left;
    std::cout << setw(26) << "player rank: " << setw(40) << "Player name: " << setw(40) << "Player number: " << setw(40) << "Number of goals scored: " << std::endl;
    std::cout << "__________________________________________________________________________________________________________________________________" << std::endl;
    for (size_t i = 0; i < theTeam.getPlayers().size(); i++)
    {
        PlayersTree.insert(theTeam.getPlayers()[i]);
    }
    PlayersprintReverseInOrder(PlayersTree.getRoot());
}

void Tournament::TournamentBestScorersList()
{
    BinarySearchTree<PlayerStatistics> PlayersTree;
    std::cout << std::left;
    std::cout << setw(26) << "player rank: " << setw(40) << "Player name: " << setw(40) << "Number of goals scored: " << std::endl;
    std::cout << "__________________________________________________________________________________________________" << std::endl;
    for (size_t i = 0; i < TournamentTeams.size(); i++)
    {
        for (size_t j = 0; j < TournamentTeams[i].getPlayers().size(); j++)
        {
            PlayersTree.insert(TournamentTeams[i].getPlayers()[j].GetStatistics()[TournamentTeams[i].getPlayers()[j].GetStatistics().size() - 1]);
        }
    }
    PlayersStatprintReverseInOrder(PlayersTree.getRoot());
}