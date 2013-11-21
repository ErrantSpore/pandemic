#include "View.h"

void View::printTitle() {
	cout << "******************************" << endl;
	cout << "*    Welcome to Pandemic     *" << endl;
	cout << "******************************" << endl << endl << endl;
}

void View::printInvalidInputMsg() {
    cout << "Invalid input.  Try again: ";
}

void View::printGoodbye() {
    cout << "\nGoodbye...\n";
}

void View::printProgressSavedMsg() {
    cout << "\nYour progress has been saved.\n\n";
}

void View::printCharterFlightMsg() {
     cout << "Charter flight to city...\n";
}

void View::printShareKnowledgeMsg() {
    cout << "share knowledge, are you crazy???\n";
}

void View::printTreatDiseaseMsg() {
    cout << "Treat disease...\n";
}

void View::printSaveGameMsg() {
    cout << "Save game...\n";
}

void View::askNumOfPlayers() {
    cout << "\nSet player count: ";
}

void View::displayPlayerInfo(string name, string role, string city) {
	cout <<  "\n**Player: " << name <<  " Role: " << role << " Current Location: "  << city << "**" << endl;
}

void View::printCubeCount(int red, int yellow, int blue, int black) {
	cout << "Cubes remaining:\n";
	cout << "Black: " << black << " Blue: " << blue << " Red: " << red<< " Yellow: " << yellow <<  endl;
}

void View::printAdj(vector<string>cities)
{
	cout << "\nAdjacent cities:\n";
	while(!cities.empty())
	{
		cout << cities.front() << endl;
		cities.erase(cities.begin());
	}
	cout << "Type a city's name to move: \n";
}

void View::askLoadGame() {
	cout << "Would you like to load a game? (Y/N) ";
}

void View::askLoadScenario() {
	cout << "Would you like to load a scenario? (Y/N) ";
}

void View::askFileName() {
	cout << "Please enter a file name (Leave blank for autosave): ";
}

void View::askWhereTo() {
    cout << "Where to (\"10\" to return to main menu) ? ";
}

void View::printReasearchStations(vector<string> cities){
    cout << menuRSCities(cities);
}

void View::printAdjCities(City* toCheck){
    cout << menuAdjCities(toCheck);
}

void View::askCanCure(string color){
    cout << "Do you want to cure the "
         << color
         << " disease? (y/n)\n";
    
}


