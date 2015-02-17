//#include "Universe.h"
//#include "ConfigFileElem.h"

Universe::Universe ()
{

		 std::string	tag;
		 std::string	entry;
		 
		 int			param1		=	0;
		 int			param2		=	0;
		 int			param3		=	0;
		 int			param4		=	0;
		 int			lineCount	=	0;
		 bool			egg_or_org  =	false;
		 char			ErrMsg[100];
		
		 //Initializing all non-constant variable in case user doesnt enter.

		 vStarvation_health_rate	=	1;
         vDeterioration_health_rate	=	5;
		 vAge_per_turn				=	1;
		 vOrg_init_health			=	10;
		 vHealth_per_food			=	5;
		 vAge_health_decrease		=	45;
		 vEgg_hatch_age				=   5;
		 vEgg_lay_age				=	25;
		 vEgg_lay_health			=	30;

		 int  * param  [4];

		 try {

				ConfigFile configFile ("config.txt"); 

				//ConfigFileElem configfilelem(1); 
		 
				tag = configFile.CurrentTag (&lineCount);

				if (configFile.NotEmpty ()) {

					++lineCount;

					if (tag.compare ("dim") == 0) {
				
						param[0] = &vDim_X;
						param[1] = &vDim_Y;
									
						configFile.Read_Param (2, " Config file has wrong Dimensions at Line ", lineCount, param);

						Map = new char *[vDim_X] ;

						//memory allocated for  elements of each column.

						for (int i = 0 ; i < vDim_X ; ++i)

							Map[i] = new char[vDim_Y];

						for (int i = 0; i < vDim_X ; ++i) {

								for(int j = 0; j < vDim_Y ; ++j) {
				
										Map [i][j] = 'E';
								}
						}

				} else {

							throw std::runtime_error ("Dimensions missing in Config file.\n ");

						}
			
				} else {

							throw std::runtime_error (" Config file is Empty.\n ");

						}

				while (configFile.NotEmpty ()) {
			
					param1 = 0;
					param2 = 0;
					param3 = 0;
					param4 = 0;

					tag = configFile.CurrentTag (&lineCount);
										
					++lineCount;
        
					if (tag.compare ("org") == 0) {
													
								param[0] = &param1;
								param[1] = &param2;
								param[2] = &param3;
								param[3] = &param4;
									
								configFile.Read_Param (4, " Config file has wrong organism details at Line ", lineCount, param);

								--param1; //array starts from 0 for us 
								--param2; //array starts from 0 for us 
								
								if (param1 >= vDim_X || param2 >= vDim_Y || Map [param1][param2] != 'E')  {
						
									sprintf_s (ErrMsg, "Config file has wrong organism details at Line: %d", lineCount); 
									throw std::runtime_error (ErrMsg);
							 
								}

								
								Creature * create_creature = new Creature (param1, param2, param3, param4, false, false);
								assert                                    (create_creature != NULL);
								LL_org.AddElement                         (create_creature);

								egg_or_org				= true;
								Map [param1][param2]	= 'O';
				
				
					} else if (tag.compare ("egg") == 0) {

									param[0] = &param1;
									param[1] = &param2;
									param[2] = &param3;
									
									configFile.Read_Param (3, " Config file has wrong egg details at Line: ", lineCount, param);

									--param1; //array starts from 0 for us 
									--param2; //array starts from 0 for us 

									if (param1 >= vDim_X || param2 >= vDim_Y || Map [param1][param2] != 'E') {
						
										sprintf_s (ErrMsg, "Config file has wrong egg details at Line: %d", lineCount); 
										throw std::runtime_error (ErrMsg);
								
									}

									//Adding Egg

									Creature * create_creature = new Creature(param1, param2, param3, 0, true, false);
									assert(create_creature != NULL);
									LL_org.AddElement (create_creature);

									egg_or_org				= true;
									Map [param1][param2]	= 'e';
            
				
					 } else if (tag.compare ("foo") == 0) {

									param[0] = &param1;
									param[1] = &param2;

									configFile.Read_Param (2, " Config file has wrong food details at Line: ", lineCount, param);
									
									--param1; //array starts from 0 for us 
									--param2; //array starts from 0 for us 

									if (param1 >= vDim_X || param2 >= vDim_Y || Map[param1][param2] != 'E') {
						
										sprintf_s (ErrMsg, "Config file has wrong food details at Line: %d", lineCount); 
										
										throw std::runtime_error (ErrMsg);

									}

									//Adding Food

									Map [param1][param2] = 'F';
            
					} else if (tag.compare ("hda") == 0) {

									// hda - is age after which health decreases
									param[0] = &vAge_health_decrease;
									
									configFile.Read_Param (1, " Config file has wrong 'hda' detail at Line: ", lineCount, param);
						
			
					 }  else if (tag.compare ("shr") == 0) {

									// shr - health decreases rate due to starvation
									param[0] = &vStarvation_health_rate;
									
									configFile.Read_Param (1, " Config file has wrong 'shr' detail at Line: ", lineCount, param);
						
						 		
					}  else if (tag.compare ("hdr") == 0) {

									// hdr - health decreases rate due to ageing.
									param[0] = &vDeterioration_health_rate;
									
									configFile.Read_Param (1, " Config file has wrong 'hdr' detail at Line: ", lineCount, param);
						
							
					}  else if (tag.compare ("apt") == 0) {

									// apt - agr per turn.
									param[0] = &vAge_per_turn;
						
									configFile.Read_Param (1, " Config file has wrong 'apt' detail at Line: ", lineCount, param);
						
				
					}  else if (tag.compare ("oih") == 0) {

								// oih - ogranisms initial health (After hatching).
								param[0] = &vOrg_init_health;
					
								configFile.Read_Param (1, " Config file has wrong 'oih' detail at Line: ", lineCount, param);
					
					} else if (tag.compare ("hpf") == 0) {

								// hpf - health per Food.
								param[0] = &vHealth_per_food;
					
								configFile.Read_Param (1, " Config file has wrong 'hpf' detail at Line: ", lineCount, param);
											
					} else if (tag.compare ("eha") == 0) {
			
								// ehg - Egg Hatching age.
								param[0] = &vEgg_hatch_age;
					
								configFile.Read_Param (1, " Config file has wrong 'eha' detail at Line: ", lineCount, param);
					
					} else if (tag.compare ("ela") == 0) {

								// ela - Egg laying age.
								param[0] = &vEgg_lay_age;
								
								configFile.Read_Param (1, " Config file has wrong 'ela' detail at Line: ", lineCount, param);
						
					} else if (tag.compare ("elh") == 0) {

								// elh - Egg laying health.
								param[0] = &vEgg_lay_health;
					
								configFile.Read_Param (1, " Config file has wrong 'elh' detail at Line: ", lineCount, param);
					
					}	else {
			
								std::cout << "Config file has invalid tag at Line:" << lineCount<<"\n";
								entry = configFile.CurrentEntry ();
					}

	
			}//end of while

			if (!egg_or_org) {

				throw std::runtime_error (" Config file should have atleast one Egg or Organism.\n ");

			}
		
	}

	catch (std::runtime_error err)  {

		throw err;

	}

}

Universe::~Universe ()
{

	for(int i=0; i < vDim_X; ++i)

		delete Map[i];

	delete Map;

}