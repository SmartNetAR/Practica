//
//  pqConnect.cpp
//  Practica Profecional
//
//  Created by Leonardo Casales on 26/8/17.
//  Copyright © 2017 Leo. All rights reserved.
//

#include "pqConnect.hpp"


pqConnect::pqConnect() {
    PGconn *cnn = NULL;
    PGresult *result = NULL;
}

bool pqConnect::Connect() {

    int i;
    
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
        return true ;
        // Ahora nos toca liberar la memoria
        //PQclear(result);
        
    } else {
        cout << "Error de conexion" << endl;
        PQfinish(cnn);
        return false ;
    }
    
    //PQfinish(cnn);
}

void pqConnect::Disconnect() {
    PQclear(result);
    PQfinish(cnn);
}

int pqConnect::Show() {
    
}
