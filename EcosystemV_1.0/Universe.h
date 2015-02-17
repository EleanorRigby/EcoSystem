

class Universe 
{

private:
	int vDim_X;
	int vDim_Y;
	int vAge_health_decrease;
	int vEgg_hatch_age;
	int vEgg_lay_age;
	int vEgg_lay_health;

	int vStarvation_health_rate;
    int vDeterioration_health_rate;
	int vAge_per_turn;
	int vOrg_init_health;
	int vHealth_per_food;
	char **	Map;
	
	LinkedList LL_org;
	Creature * current_creature;
		  
public:

	     Universe             ();
		~Universe             ();
	void BigBang              ();
	void Move                 (int, int );
	void Place_Food           ();
	void Output               ();
	void Laying_Egg           (int, int);
	//void Move_or_Lay          ();

	Position_XY * Position_Locater (int, int);
	
};

// Universe

//