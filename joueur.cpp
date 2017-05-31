#include"joueur.h"
int StoI(string s)
{
	int res=0;
	for(int i=0;i<s.size();i++)
	{
		if(((int)s.at(i)-48)>=0 && ((int)s.at(i)-48)<=9)
		{
			res=res*10+((int)s.at(i)-48);
		}
		else{return -1;}
	}
	return res;
}

int StoII(char s)
{
	
		if(((int)s-48)>=0 && ((int)s-48)<=9)
		{
			return 0;
		}
		else{return -1;}
	
}

game::game()
{
	string ligne="";
	string token="";

	getline(cin, ligne);
	cout<<"NoIdea";
	getline(cin, ligne);
cout<<"r"<<ligne<<endl;

	int i=0;
	while(i<ligne.length() && ligne.at(i)!=' ')
	{
		token+=ligne.at(i);
		i++;
	}
i++;

	this->nbPlayers=StoI(token);

cout<<this->nbPlayers<<endl;
cout<<"i :"<<i<<ligne.length()<<endl;


	token="";
	while(i<ligne.length())
	{
		token+=ligne.at(i);
		i++;
	}
i++;
	this->nbTurn=StoI(token);

cout<<"i :"<<i<<ligne.length()<<endl;
cout<<this->nbTurn<<endl;


getline(cin, ligne);
	i=0;
	token="";
bool cestnous=false;
while(StoII(ligne.at(i))==-1)
{
	
	while(i<ligne.size() && ligne.at(i)!=' ')
	{
		token+=ligne.at(i);
		i++;
	}
i++;
	if(token=="NOIDEA")
	{
		cestnous=true;
		this->joueur.name=token;
	}
	else
	{
		cestnous=false;
		player p={"",0,0,0,0,true,0};
		this->autresJoueurs.push_back(p);
		this->autresJoueurs.back().name=token;
	}

	
cout<<"name"<<this->joueur.name<<endl;

	token="";
	while(i<ligne.size() && ligne.at(i)!=' ')
	{
		token+=ligne.at(i);
		i++;
	}
i++;
	if(cestnous)
	{
		this->joueur.productivite=StoI(token);
	}
	else
	{
		this->autresJoueurs.back().productivite=StoI(token);
	}
	

	token="";
	while(i<ligne.size() && ligne.at(i)!=' ')
	{
		token+=ligne.at(i);
		i++;
	}
i++;
if(cestnous)
	{
		this->joueur.power=StoI(token);
	}
	else
	{
		this->autresJoueurs.back().power=StoI(token);
	}
	

	token="";
	while(i<ligne.size() && ligne.at(i)!=' ')
	{
		token+=ligne.at(i);
		i++;
	}
i++;
if(cestnous)
	{
		this->joueur.score=StoI(token);
	}
	else
	{
		this->autresJoueurs.back().score=StoI(token);
	}


	

	token="";
	while(i<ligne.size() && ligne.at(i)!=' ')
	{
		token+=ligne.at(i);
		i++;
	}
i++;
if(cestnous)
	{
		this->joueur.ammo=StoI(token);
	}
	else
	{
		this->autresJoueurs.back().ammo=StoI(token);
	}
	this->joueur.ammo=StoI(token);

	token="";
	while(i<ligne.size() && ligne.at(i)!=' ')
	{
		token+=ligne.at(i);
		i++;
	}

i++;
if(cestnous)
	{
		this->joueur.pos[0]=StoI(token);
	}
	else
	{
		this->autresJoueurs.back().pos[0]=StoI(token);
	}
	

	token="";
	while(i<ligne.size() && ligne.at(i)!=' ')
	{
		token+=ligne.at(i);
		i++;
	}
i++;
	if(cestnous)
	{
		this->joueur.pos[1]=StoI(token);
	}
	else
	{
		this->autresJoueurs.back().pos[1]=StoI(token);
	}
getline(cin, ligne);
i=0;
token="";
}



	while(i<ligne.size() && ligne.at(i)!=' ')
	{
		token+=ligne.at(i);
		i++;
	}
i++;
	this->taille_level[0]=StoI(token);
cout<<"x"<<this->taille_level[0]<<endl;
	token="";
	while(i<ligne.size())
	{
		token+=ligne.at(i);
		i++;
	}
i++;
	this->taille_level[1]=StoI(token);
cout<<"y"<<this->taille_level[1]<<endl;

getline(cin, ligne);
i=0;
token="";
int k=0;
while(k<this->taille_level[1])
{
	this->level.push_back(vector<string>());
	
	while(i<ligne.size())
	{

		while(i<ligne.size() && ligne.at(i)!='|')
		{
			token+=ligne.at(i);
			i++;
		}
	this->level[k].push_back(token);
	cout<<"tab "<<this->level[k].back()<<endl;
	token="";
	i++;
	}



	k++;
	getline(cin, ligne);
	i=0;
	token="";
}

	
}




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


/*
3 100
NOIDEA 3 1 0 3 1 1
LINUS 2 2 10 2 7 7
DONALD 1 3 50 1 1 7
9 9
|X|X|X|X|X|X|X|X|X|
|X|G|G/1,1,2|O|O|O|G|G|X|
|X|G|Y|O|X|O|X|G|X|
|X|G|G|O|Y|O|Z|O|X|
|X|G|X|Y|X|Y|X|O|X|
|X|G/0,1,5/1,2,3|Z|O|Y|O|Y|O|X|
|X|G|X|O|X|O|X|G|X|
|X|G|G|O|O|O|G|G|X|
|X|X|X|X|X|X|X|X|X|
*/
int main(int argc,char ** argv)
{
game g=game();
g.best_move("epreuve1");
return 0;}

