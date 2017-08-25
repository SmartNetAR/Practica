using namespace std ;
#include <iostream>
#include <libpq-fe.h>

/* la tabla probada es la siguiente:
CREATE TABLE public.users
(
id numeric NOT NULL,
name text COLLATE pg_catalog."default" NOT NULL,
admin boolean,
CONSTRAINT users_pkey PRIMARY KEY (id)
)
WITH (
OIDS = FALSE
)
TABLESPACE pg_default;

ALTER TABLE public.users
OWNER to postgres;
*/

/*datos de prueba:
INSERT INTO users (id, name, admin) values(1,'leo',true);
INSERT INTO users (id, name, admin) values(2,'caro',true);
INSERT INTO users (id, name, admin) values(3,'nano',false);
*/

PGconn *cnn = NULL;
PGresult *result = NULL;

char *host = "localhost";
char *port = "5432";
char *dataBase = "apaaa";//char *dataBase = "postgres";
char *user = "postgres";
char *passwd = "1234";
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
    int i;
    //printf("<!DOCTYPE html>\n");
	//printf("Content-Type: text/json\n\n");
	printf("Content-Type: text/html; charset=utf-8\n\n");
	printf("<html>\n");
	printf("<head>\n");
	printf("<title>Conectando Postgress con cgi c++</title>\n");
	printf("</head> \n");
	
	printf("<body>\n");
    cnn = PQsetdbLogin(host,port,NULL,NULL,dataBase,user,passwd);
    if (PQstatus(cnn) != CONNECTION_BAD) {
        cout << "Estamos conectados a PostgreSQL!" << endl;
        result = PQexec(cnn, "SELECT * FROM users");//result = PQexec(cnn, "SELECT * FROM test");

        if (result != NULL) {
            int tuplas = PQntuples(result);
            int campos = PQnfields(result);
            cout << "No. Filas:" << tuplas << "<br>" << endl ;
            cout << "No. Campos:" << campos << "<br>" << endl ;

            cout << "Los nombres de los campos son:" << "<br>" << endl ;

            for (i=0; i<campos; i++) {
                cout << PQfname(result,i) << " | ";
            }

            cout << endl << "Contenido de la tabla" << "<br>" << endl ;

            for (i=0; i<tuplas; i++) {
                for (int j=0; j<campos; j++) {
                    cout << PQgetvalue(result,i,j) << " | ";
                }
                cout << "<br>" << endl ;
            }
        }

        // Ahora nos toca liberar la memoria
        PQclear(result);

    } else {
        cout << "Error de conexion" << endl;
        return 0;
    }

    PQfinish(cnn);
    printf("</body>\n");
    printf("</html>\n");
	return 0;
}
