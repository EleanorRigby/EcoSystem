//#include "Headers.h"


/* OUTPUT */
void Universe::Output ()
{
	int i;
	int j;

	for(i = 0; i < vDim_X; ++i) {

		for(j = 0; j < vDim_Y; ++j) 
			std::cout << Map [i][j] << "   ";

		std::cout << std::endl;
	}
}


/* LAYING EGG */

void Universe::Laying_Egg (int x, int y)
{
	assert (x >= 0 && x < vDim_X && y >= 0 && y < vDim_Y);

	int count [8] = {-1};
	int counter   = -1;
	int i;
	int random;
	int j;

	Position_XY	  organism_position (x, y);
	Position_XY * position_around_organism = organism_position.Position_Locater (vDim_X, vDim_Y);


	for (i = 0; i <= 7; i++)
	{
		if (position_around_organism[i].x != -1  &&  position_around_organism[i].y != -1  &&  Map[position_around_organism[i].x][position_around_organism[i].y] == 'E')
		{
			counter++;
			count [counter] = i;
		}
		
	}

	if (counter == -1)
		return;
		
	random = rand () % (counter + 1) ;
	
	j = 0;

	while (j <= random) {

		Position_XY selected_position (position_around_organism[count[j]].x, position_around_organism[count[j]].y);
		
		Creature * create_creature = new Creature (selected_position.x, selected_position.y, 0, -1, true, false);
		assert                                    (create_creature != NULL);
		LL_org.AddElement                         (create_creature);
		
		Map[selected_position.x][selected_position.y] = 'e';
	
		++j;

	}

	delete [] position_around_organism;

}



/* MOVE */
void Universe::Move (int posx, int posy)
{
	assert (posx >= 0 && posx < vDim_X && posy >= 0 && posy < vDim_Y);

	int random;

	Position_XY		organism_position (posx, posy);
	Position_XY * position_around_organism;
	
	position_around_organism = organism_position.Position_Locater (vDim_X, vDim_Y); 
	
	random = current_creature->Move_Decision ();
		
	if (random == 8)
		return;

	Position_XY selected_position (position_around_organism[random].x, position_around_organism[random].y);
	
	if (selected_position.x == -1 || selected_position.y == -1 || Map[selected_position.x][selected_position.y] == 'O' || Map[selected_position.x][selected_position.y] == 'e')
		return;
		
	if (Map[selected_position.x][selected_position.y] == 'F') 
		current_creature->health += vHealth_per_food;

	Map[selected_position.x][selected_position.y]                                     = 'O';
	Map[current_creature->position_creature.x][current_creature->position_creature.y] = 'E';

	current_creature->position_creature.x = selected_position.x;
	current_creature->position_creature.y = selected_position.y;
		
	delete [] position_around_organism;
	
}


/* PLACE FOOD */
void Universe::Place_Food () {

	int rand_x; 
	int rand_y;
	int count_limit = 0;

	do {

		rand_x = rand () % (vDim_X);
		rand_y = rand () % (vDim_Y);

		assert (rand_x >=0 && rand_x <= vDim_X - 1);
		assert (rand_y >=0 && rand_y <= vDim_Y - 1);

		++count_limit;

	} while (Map[rand_x][rand_y] != 'E' && count_limit <= ((vDim_X*vDim_Y)/4));

	if (Map[rand_x][rand_y] == 'E') 
		Map[rand_x][rand_y] = 'F';
	
}


/* BIG BANG */
void Universe::BigBang ()
{
	int  integervalue;
	char s [20];

	while (!LL_org.IsEmpty ()) {

			current_creature = (Creature *) LL_org.GetFirst ();
			
			while (current_creature) {
			
			
			
			
			if (current_creature->Is_egg) {		// when its an Egg
				
				if (current_creature->age >= vEgg_hatch_age) {

					current_creature->Is_egg			= false;
					current_creature->health			= vOrg_init_health;
					current_creature->age				= 0;
					current_creature->Has_laid_egg		= false;

					Map[current_creature->position_creature.x][current_creature->position_creature.y] = 'O';

				}
			} else {									  // when its an Organism

				// Deletion_of_Organism
				if (current_creature->health <= 0) {

					Map[current_creature->position_creature.x][current_creature->position_creature.y] = 'E';
					
					current_creature = (Creature *)LL_org.DeleteElement (current_creature);
					//current_creature = (Creature *) LL_org.GetNext (current_creature);
					continue;

				}
				

				// To Move or Lay
				if (current_creature->age >= vEgg_lay_age  &&  current_creature->health >= vEgg_lay_health && current_creature->Has_laid_egg == false) {
					
					integervalue = current_creature->Move_or_Lay();

					if (integervalue == 0) {
						Move (current_creature->position_creature.x, current_creature->position_creature.y);
					} else {
						Laying_Egg (current_creature->position_creature.x, current_creature->position_creature.y);
						current_creature->Has_laid_egg = true;
					}

				} else {
					Move (current_creature->position_creature.x, current_creature->position_creature.y);
				}



				if (current_creature->age >= vAge_health_decrease)
					current_creature->health -= (vDeterioration_health_rate + vStarvation_health_rate);
				else
					current_creature->health -= vStarvation_health_rate;

			}


			current_creature->age    += vAge_per_turn;
			current_creature = (Creature *) LL_org.GetNext (current_creature);
					
		}

		Place_Food ();

		// Code for User View
		integervalue = 0;
		
		std::cout << "Press enter to view ecosystem and q to quit";
		gets (s);
		
		if ( strcmp (s,"q") == 0 || strcmp (s,"Q") == 0 )
			return;
		
		while (integervalue < strlen (s) ) {
			if (s[integervalue] != '\n') {
				std::cout << "Please press only enter key\n";
				break;
			}
			integervalue++;
		}

		if (integervalue >= strlen (s)) {
			Output ();
		}

	}
}
 
