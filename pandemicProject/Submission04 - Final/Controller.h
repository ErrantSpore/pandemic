//
// Controller class - controls the flow of pandemic
//

#include "Model.h"
#include "View.h"
#include "Menu.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <limits>
#include <vector>
#include <stdlib.h>


using std::cin;
using std::cout;
using std::setw;
using std::string;
using std::streamsize;
using std::numeric_limits;
using std::ostringstream;

class Controller;
typedef void (Controller::*menuFunctions)();
class Controller
{
public:
  Controller();
  void setPlayerCount();
  void setPlayerNames();
  void setDifficulty();
  // menu functions
  void do_drive_ferry();
  void do_direct_flight();
  void do_charter_flight();
  void do_shuttle_flight();
  void do_treat_disease();
  void do_cure_disease();
  void do_share_knowledge();
  void do_build_station();
  void do_save_game();
  void do_quit_game();
  void do_event_card();
  // map menu functions
  void setMappedFunctions() {
      menuFunctions fns[] = {
          &Controller::do_drive_ferry,
          &Controller::do_direct_flight,
          &Controller::do_charter_flight,
          &Controller::do_shuttle_flight,
          &Controller::do_treat_disease,
          &Controller::do_cure_disease,
          &Controller::do_share_knowledge,
          &Controller::do_build_station,
		  &Controller::do_event_card,
          &Controller::do_save_game/*,
          &Controller::do_quit_game*/     // not needed
      };
      int fnsSize = sizeof(fns) / sizeof(fns[0]);
      for ( size_t idx = 0; idx < fnsSize; idx++ ) {
          mappedFuncs[idx] = fns[idx];
      }
  }

  bool getLoadGame();
  bool getLoadScenario();
  map<int, menuFunctions> getMappedFunctions()
    { return mappedFuncs; }
  void doPlayerTurns();
  void doDrawRound(int);
  void doDiscard(vector<Card*>, int);
  void doInfectRound();
  void doProcessMenu(Player*);
  void doEpidemic();
  void forceDiscard(Player*);
  int run();
  bool isInVector(int, vector<int>&);
  
private:
  View view;                //the view we're using
  Model model;                //the model
  Menu menu;                //the menu
  int temp;
  string tempStr;
  City* cityP;                //pointer to a city
  ICard* iCardP;            //pointer to an iCard
  map<int, menuFunctions> mappedFuncs;
  vector<string> commands;
};


