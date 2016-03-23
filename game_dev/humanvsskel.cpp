#include <iostream>
#include <vector>
#include <cstdio>
#include <iterator>
using namespace std;

void start_game();
//void spawn_humans();


class human;
class skeleton;
void spawn_skeletons(vector<skeleton>&,int);
class human
{
    int health=100;
    int damage=6; 
public:
	int dam();	
	void attack(skeleton& enemy);
	void takehit(skeleton& enemy);
	int gethealth();
};

class skeleton
{
    int health=60;
    int damage=4;
public:
	int dam();	
	void attack(human& enemy);
	void takehit(human& enemy);
	int gethealth();
};

int main()
{
  start_game();
  return 0;
}

void start_game()
{
  vector<skeleton> enemies;
  human* player=new human;
  char c;
  bool status=true;
  //int deadenemies;
  cout<<"--------------------------Game Begins-------------------------------------"<<endl;
  spawn_skeletons(enemies,1);
  while(status)
  {
  		if(enemies.size()==0)
  		{
  			cout<<"No more Enemies Left! You win !"<<endl;
  			break;
  		}
  		c=getchar();
  		for(int i=0;i<enemies.size();++i)
  		{
  			enemies.at(i).attack(*player);
  		}
  		if(c=='q')
  		{
  			break;
  		}
  		else if(c=='a')
  		{
  			for(int i=0;i<enemies.size();++i)
  		  {
  			(*player).attack(enemies.at(i));
  		  }
  		}
  		if((*player).gethealth()==0)
  		{
  			cout<<"You've Lost !Quitting";
  			status=false;
  		}
  		for(vector<skeleton>::iterator i=enemies.begin();i<enemies.end();++i)
  		  {
  			if((*i).gethealth()==0)
  			{
  				enemies.erase(i);
  			}
  		  }

  }
}

    int human::dam()
	{
		return this->damage;
	}
	int human::gethealth()
	{
		return this->health;
	}
	void human::attack(skeleton& enemy)
	{
		enemy.takehit(*this);
	}
	void human::takehit(skeleton& enemy)
	{
		health=health-enemy.dam();	
	}

	int skeleton::dam()
	{
		return this->damage;
	}
	int skeleton::gethealth()
	{
		return this->health;
	}
	void skeleton::attack(human& enemy)
	{
		enemy.takehit(*this);
	}
	void skeleton::takehit(human& enemy)
	{
		health=health-enemy.dam();	
	}

void spawn_skeletons(vector<skeleton>& enemies,int count)
{
		int i=0;
		while(i<count)
		{	enemies.push_back(*(new skeleton));
			++i;
		}
}