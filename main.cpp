//using namespace std ;
//#include <iostream>
//#include <stdio.h>
#include <stdlib.h>
#include "pqConnect.hpp"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	char* arguments ;
    //printf("<!DOCTYPE html>\n");
	//printf("Content-Type: text/json\n\n");
	printf("Content-Type: text/html; charset=utf-8\n\n") ;
	printf("<html>\n") ;
	printf("<head>\n") ;
	printf("<title>Conectando Postgress con cgi c++</title>\n") ;
	printf("</head> \n");
	pqConnect pq( "localhost", "5432", "apaaa","postgres", "1234" ) ;
	
	arguments = getenv("QUERY_STRING") ;
	printf("Argumentos: %s\n\n", arguments ) ;
	
	pq.Show( arguments ) ;
	
	pq.Disconnect() ;
	printf("<body>\n") ;
    printf("</body>\n") ;
    printf("</html>\n") ;
	return 0 ;
}

