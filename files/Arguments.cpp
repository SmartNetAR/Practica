#include "Arguments.hpp"


Arguments::Arguments(char* strValue )
{
	str = strValue ;
	for ( int i = 0; i < MAX_LEN; i++ ) {
		values.method[i] = '\0' ;
		values.value[i] = '\0' ;
	}
	Parce() ;
}

char* Arguments::GetMethod() {
	return values.method ;
}

char* Arguments::GetValue() {
	return values.value ;
}

char* Arguments::GetSTR() {
	return str ;
}

void Arguments::Parce() {
	int i = 0 ;
	int j = 0 ;
	bool value = false ;
	while ( !str[i] == '\0' ) {
		if ( str[i] == ':' ) {
			value = true ;
			values.method[i+1] = '\0' ;
			i++ ;
		}
		if ( value == false ) {
			values.method[i] = str[i] ;
		} else {
			values.value[j] = str[i] ;
			j++ ;
		}
		i++ ;
	}
	values.value[j+1] = '\0' ;
}

/*Arguments::~Arguments()
{
}*/
