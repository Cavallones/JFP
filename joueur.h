#include<iostream>
#include<vector>
#include <stdlib.h>    
#include <time.h>
#include<utility>   

using namespace std;

struct player{
	string name;
	int productivite;
	int power;
	int score;
	int ammo;
	bool alive;
	int pos[2];
};

class game{
	private:
		int taille_level[2];
		int nbPlayers;
		int nbTurn;
		vector<vector<string> > level;
		player joueur;
		

	public:
		game();
		game(int pos[2]);
		void deplacement(string instruction);
		bool validation_deplacement(string instruction);
		void best_move(string trial);
		vector<int> finding_bonus();
		vector<string> finding_path();
		string best_move_for_first();
		string best_move_for_two();
		string best_move_for_third();
		string best_move_for_fourth();
};
