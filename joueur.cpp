#include "joueur.h"


bool game::validation_deplacement(string instr)
{
	if(instr == "UP" && this->joueur.pos[1] != (this->taille_level[1]-1))
	{
		if(this->level[this->joueur.pos[0]][this->joueur.pos[1]+1] == "G" ||
			this->level[this->joueur.pos[0]][this->joueur.pos[1]+1] == "I" ||
			this->level[this->joueur.pos[0]][this->joueur.pos[1]+1] == "H")
		{
			return true;
		}
	}

	else if(instr == "DOWN" && this->joueur.pos[1] != (this->taille_level[1]-1))
	{
		if(this->level[this->joueur.pos[0]][this->joueur.pos[1]-1] == "G" ||
			this->level[this->joueur.pos[0]][this->joueur.pos[1]-1] == "I" ||
			this->level[this->joueur.pos[0]][this->joueur.pos[1]-1] == "H")
		{
			return true;
		}
	}

	else if(instr == "LEFT" && this->joueur.pos[0] != 0)
	{
		if(this->level[this->joueur.pos[0]-1][this->joueur.pos[1]] == "G" ||
			this->level[this->joueur.pos[0]-1][this->joueur.pos[1]] == "I" ||
			this->level[this->joueur.pos[0]-1][this->joueur.pos[1]] == "H")
		{
			return true;
		}
	}
	else if(instr == "RIGHT" && this->joueur.pos[0] != (this->taille_level[0]-1))
	{
		if(this->level[this->joueur.pos[0]+1][this->joueur.pos[1]] == "G" ||
			this->level[this->joueur.pos[0]-1][this->joueur.pos[1]] == "I" ||
			this->level[this->joueur.pos[0]-1][this->joueur.pos[1]] == "H")
		{
			return true;
		}
	}
	else if(instr == "DEPLOY" && this->joueur.ammo == 0)
	{
		return true;
	}
	else if(instr == "NOP")
	{
		return true;
	}

	return false;
}


void game::deplacement(string inst)
{
	if(game::validation_deplacement(inst))
	{
		if(inst == "UP")
		{
			this->joueur.pos[1] = this->joueur.pos[1]+1;
		}
		else if(inst == "DOWN")
		{
			this->joueur.pos[1] = this->joueur.pos[1]-1;
		}
		else if(inst == "LEFT")
		{
			this->joueur.pos[1] = this->joueur.pos[0]-1;
		}
		else if(inst == "RIGHT")
		{
			this->joueur.pos[1] = this->joueur.pos[0]+1;
		}
	}
}

string game::best_move_for_first()
{
	if(this->validation_deplacement("UP"))
	{
		return "UP";
	}
	else if(this->validation_deplacement("DOWN"))
	{
		return "DOWN";
	}
	else if(this->validation_deplacement("LEFT"))
	{
		return "LEFT";
	}
	else if(this->validation_deplacement("RIGHT"))
	{
		return "RIGHT";
	}
}

vector<int> game::finding_bonus()
{
	vector<int> coord = vector<int>(2);
	for(int i = 0; i < this->taille_level[0]; i++)
	{
		for(int j = 0; j < this->taille_level[1]; i++)
		{	
			if(this->level[i][j] == "H" || this->level[i][j] == "I")
			{				
				coord[0] = i;
				coord[1] = j;
			}
		}
	}
	return coord;
}

vector<string> game::finding_path()
{
	vector<int> bonus = finding_bonus();
	
	
}

string game::best_move_for_two()
{
	vector<int> bonus = finding_bonus();
	
			

	return "";
}

string game::best_move_for_third()
{
	return "";
}

string game::best_move_for_fourth()
{
	return "";
}


void game::best_move(string arg)
{
	if(arg == "epreuve1")
	{
		this->best_move_for_first();
	}
	else if(arg == "epreuve2")
	{
		this->best_move_for_two();
	}
	else if(arg == "epreuve3")
	{
		this->best_move_for_third();
	}
	else if(arg == "epreuve4") 
	{
		this->best_move_for_fourth();
	}
}

int main()
{
	return 1;
} 
