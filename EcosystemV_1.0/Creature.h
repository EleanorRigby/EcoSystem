// Class for Linked List
class Creature {								

private:
		
		Position_XY  position_creature;
		int			 age;
		int			 health;
		bool		 Is_egg;
		bool		 Has_laid_egg;
		

		//Parameterized Constructor
		Creature (int position_x, int position_y, int age, int health, bool Is_egg, bool Has_laid_egg)
			: position_creature (position_x, position_y)
		{
			this->age					= age;
			this->Is_egg				= Is_egg;
			this->Has_laid_egg		= Has_laid_egg;
			this->health				= health;

		}

			  //Destructor
		 ~Creature ()
		 {
			 
	     }
		

public:
		
	int Move_Decision ()
	{
		int random_value;

		random_value = rand() % 9;
		
		assert (random_value >= 0 && random_value <= 8);
		return random_value;
	}


	int Move_or_Lay ()
	{
		int random_value;

		random_value = rand() % 2;
		
		assert (random_value >= 0 && random_value <= 1);
		return random_value;
	}

	int Egg_Lay ()
	{
		int random_value;

		random_value = rand() % 9;
		
		assert (random_value >= 0 && random_value <= 8);
		return random_value;
	}

	friend class Universe;
};