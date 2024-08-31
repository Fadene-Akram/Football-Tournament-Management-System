#include "Table.h"

int main()
{
   Tournament t1("Male", 18, "2018-2019");
   File f;
   std::string filePath = "../data/";
   f.readTeamsFromCSV("../data/", t1);
   f.readGamesFromCSV(filePath + "games.csv", t1);
   bool exit = false;
   int year, month, day;
   std::string teamName;
  std::cout << "======================================================================================================================" << std::endl
            << "________________________________Welcome To Football Tournament Management System_____________________________________" << std::endl
            << "======================================================================================================================" << std::endl
            << std::endl;
   do {
       TableMenu ECMSMeneu({">>>> F T M S     M a i n     M e n u <<<<<",
                            " >>>> 1 - Print Teams Ranking in any date .",
                            " >>>> 2 - Teams Kilometers Run in any date.",
                            " >>>> 3 - Team Best Scorers List .",
                            " >>>> 4 - Tournament Best Scorers List until any date .",
                            " >>>> 5 - Tournament Best Scorers List until last day of the tournament.",
                            " >>>> 6 - Exit the Menu."
                           });

       int userTypeChoice = ECMSMeneu.showMenu();

       switch (userTypeChoice)
       {
           case 1:
          std::cout << "Enter the year: ";
          std::cin >> year;
          std::cout << "Enter the month: ";
          std::cin >> month;
          std::cout << "Enter the day: ";
          std::cin >> day;
          std::cout<<std::endl<<std::endl;
          t1.PrintTeamsRanking(Date(year, month, day));
          break;
      case 2:
          std::cout << "Enter the year: ";
          std::cin >> year;
          std::cout << "Enter the month: ";
          std::cin >> month;
          std::cout << "Enter the day: ";
          std::cin >> day;
          std::cout << "Enter the team Name: ";
          ws(std::cin);
          std::getline(std::cin, teamName);
          std::cout<<std::endl<<std::endl;
          t1.TeamsKmRun(teamName, Date(year, month, day));
          break;
      case 3:
          std::cout << "Enter the team Name: ";
          ws(std::cin);
          std::getline(std::cin, teamName);
          std::cout<<std::endl<<std::endl;
          t1.TeamBestScorersList(teamName);
          break;
      case 4:
          std::cout << "Enter the year: ";
          std::cin >> year;
          std::cout << "Enter the month: ";
          std::cin >> month;
          std::cout << "Enter the day: ";
          std::cin >> day;
          std::cout<<std::endl<<std::endl;
          t1.TournamentBestScorersList(Date(year, month, day));
          break;
      case 5:
          t1.TournamentBestScorersList();
          break;
      case 6:
          exit = true;
          std::cout << "Thanks for using our FTMS." << std::endl;
          break;

      default:
          std::cout << "Error !!!!. Please enter a valid choice." << std::endl;
          break;
      }
   } while (!exit);


   return 0;
}