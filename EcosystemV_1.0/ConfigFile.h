class ConfigFile 
{
	private:

		std::fstream	vFile;
		std::string		vTag;
		std::string		vEntry;

	public:

		ConfigFile  (const char * pInputFileName)
		{

			// open file, die if DNE....
			vFile.open (pInputFileName, std::ios::in);

			if (!vFile.is_open ()) {

				//Throw runtime exception 
				throw std::runtime_error (" Config file not found.\n "); 
			}	

		}

		~ConfigFile()
		{
			vFile.close ();
		}

		bool NotEmpty ()
		{
			return !vFile.eof ();
		}

		bool IsOpen()
		{
			return vFile.is_open ();
		}
	
		std::string CurrentTag (int * pLineCount)
		{	
		
			vFile >> vTag;

			while (vTag.substr(0,2).compare("//") == 0)  {
			
				std::getline (vFile ,vEntry , '\n');
			
				++ (*pLineCount);
				vFile >> vTag;
			
			}
		
			return vTag;

		}

		std::string CurrentEntry ()
		{

			std::getline (vFile, vEntry, '\n');
			return vEntry;

		}

		void Read_Param (int ParamCount, std::string pErrMsg, int pLineCount, int   *pVar [])
		{
			
			int				Param;
			char			ErrMsg[100];
			char			tempString[100];
			int				position;
			
			vEntry = CurrentEntry ();

			for (int i=0; i < ParamCount ; ++i)  {

				sscanf_s	(vEntry.c_str (), "%d", &Param);
				sprintf_s	(tempString, "%d", Param); 
				
				position	= vEntry.find_first_of (tempString);
				vEntry		= vEntry.erase		   (0, position + strlen(tempString));
								
				if (Param <= 0) {
					
						if (ParamCount>1) {

							sprintf_s (ErrMsg, "%d",pLineCount); 
							pErrMsg += ErrMsg;
							throw std::runtime_error (pErrMsg);

						}

						std::cout << pErrMsg << pLineCount << ".So default value is loaded.\n ";
						std::cin.get ();

						return;

				}  else  					
						*pVar[i] = Param;

				
			}

		}

};