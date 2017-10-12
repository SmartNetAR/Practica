//using namespace std ;
//#include <iostream>
//#include <stdio.h>
#include <stdlib.h>
#include "files\pqConnect.hpp"
#include "files\Arguments.hpp"

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
	
	
	//arguments = "table:animal" ; //getenv("QUERY_STRING") ;
	arguments = getenv("QUERY_STRING") ;
	Arguments argumentos( arguments ) ;
	printf( "Argumentos: %s\n\n\n", argumentos.GetSTR() ) ;
	printf( "Metodo: %s\n\n", argumentos.GetMethod() ) ;
	printf( "Valor: %s\n\n", argumentos.GetValue() ) ;
	//solucionar esta comparacion
	pq.Show( argumentos.GetValue() ) ;
	/*if (argumentos.GetMethod() == "table") {
		pq.Show( argumentos.GetValue() ) ;
	}*/
	
	pq.Disconnect() ;
	printf("<body>\n") ;
    printf("</body>\n") ;
    printf("</html>\n") ;
	return 0 ;
}

