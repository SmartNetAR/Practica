#ifndef ARGUMENTS_HPP
#define ARGUMENTS_HPP
#define MAX_LEN 20
class Arguments
{
	public:
		
		Arguments(char* str);
		char* GetSTR () ;
		char* GetMethod () ;
		char* GetValue () ;
	private:
		struct sent {
			char method[MAX_LEN] ; //char*
			char value[MAX_LEN] ;  //char*
		} values;
	
		char* str ;
		
		void Parce () ;
};

#endif
