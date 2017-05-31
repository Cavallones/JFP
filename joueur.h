#include<iostream>
#include<vector>

using namespace std;

class Joueur{
	private:
		int life;
		int power;
		int pos[2];
		bool isAlive;
		vector<vector<string>> level;
		

	public:
		Joueur();
		Joueur(int pos[2]);
		void deplacement(string instruction);
		bool validation_deplacement(stringh instruction);
		string best_move(string trial);
		string best_move_for_first();
		string best_move_for_two();
		string best_move_for_third();
		string best_move_for_fourth();
};
