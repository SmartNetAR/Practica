//using namespace std ;
//#include <iostream>
//#include <stdio.h>
#include <string>
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
	pq.Connect() ;
	

	arguments = getenv("QUERY_STRING") ;
	//arguments = "table:animals" ; //getenv("QUERY_STRING") ;

	Arguments argumentos( arguments ) ;
	printf( "Argumentos: %s\n\n\n", argumentos.GetSTR() ) ;
	printf( "Metodo: %s\n\n", argumentos.GetMethod() ) ;
	printf( "Valor: %s\n\n", argumentos.GetValue() ) ;
	
	//solucionado con string, ver otra solución de comparación con char*
	if ( std::string( argumentos.GetMethod()) == "table") {
		pq.Show( argumentos.GetValue() ) ;
	}
	else if( std::string( argumentos.GetMethod()) == "get") {
		printf( "Crear un metodo para Get\n\n") ;
	}
	else if( std::string( argumentos.GetMethod()) == "post") {
		printf( "Crear un metodo para Post\n\n") ;
	}
	else {
		printf( "No se conoce el argumento: %s\n\n", argumentos.GetMethod() )  ;
	}

	pq.Disconnect() ;
	printf("<body>\n") ;
    printf("</body>\n") ;
    printf("</html>\n") ;
	return 0 ;
}

