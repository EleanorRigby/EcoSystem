// Class for Linked List
class LinkedList_Organism {								

private:
	
	class Node_Org {
				
	public:
		
		Position_XY  position_organism;
		int			 age;
		int			 health;
		bool		 Is_egg;
		bool		 Has_laid_egg;
		Node_Org *   next;

	    //Default Constructor
		Node_Org ()
		{
		}

		//Parameterized Constructor
		Node_Org (int position_x, int position_y, int age, int health, bool Is_egg, bool Has_laid_egg)
		{
			this->position_organism.x = position_x;
			this->position_organism.y = position_y ;
			this->next				  = NULL;				
			this->age				  = age;
			this->Is_egg			  = Is_egg;
			this->Has_laid_egg		  = Has_laid_egg;
			this->health			  = health;

		}

			  //Destructor
		 ~Node_Org ()
		 {
			 if (next) {
			 delete next;
			 next = NULL;
		     }
	     }
		
		
	};
		
					
	Node_Org * head;
		

public:
	
	Node_Org * current_org;
	Node_Org * temp_org;
	Node_Org * prev_org;
	
	
	//Contructor
	LinkedList_Organism ()
	{
		
		head = NULL;
		current_org = NULL;
		prev_org = NULL;
		
	}
	
	
	// Destructor
	~LinkedList_Organism ()						
	{
        
        if (head) {
            delete head;    // recursive delete
            head = NULL;
		}
		
	    prev_org = NULL;
        current_org = NULL;
        temp_org = NULL;
        
	}
	
	
	// Adding a Node
	void AddNodeAtHead (int position_x, int position_y, int age, int health, bool Is_egg, bool Has_laid_egg)		
	{
		
		Node_Org * temp = new Node_Org(position_x , position_y ,  age , health , Is_egg , Has_laid_egg ); 
		
		//temp = Createnode (position_x , position_y ,  age , health , Is_egg , Has_laid_egg );

		if (head == NULL) {
			head = temp;
        } else {
			temp->next = head;
			head = temp;
	    }
	
	}
	
	
	/*
	// Creating a Node
	Node_Org * Createnode (int position_x, int position_y, int age, int health, bool Is_egg, bool Has_laid_egg)				
	{
		Node_Org * temp	= new Node_Org;
		
		temp->position_organism.x = position_x;
		temp->position_organism.y = position_y ;
		temp->next				  = NULL;				
		temp->age				  = age;
		temp->Is_egg			  =	Is_egg;
		temp->Has_laid_egg		  = Has_laid_egg;
		temp->health			  = health;
		
		return temp;
	}
	 */
	
	
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