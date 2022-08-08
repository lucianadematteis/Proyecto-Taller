#include <iostream>
#include <stdio.h>
#include <mysql.h>
#include <stdlib.h>

using namespace std;

int main()
{
    MYSQL *conexion;
    MYSQL_RES *res;
    MYSQL_ROW row;
    char *server ="localhost";
    char *password="altd";
    char *user="root";
    char *base="empresa";
    //char *base="obd12020";

    conexion=mysql_init(NULL);
    if(!mysql_real_connect(conexion, server, user, password, base, 0, NULL, 0)){
        printf("\n error de conexi'on");
        exit(1);
    }
    if(mysql_query(conexion, "show tables")){
        printf("\n error de comando sql");
        exit(1);
    }
    res=mysql_use_result(conexion);

    while((row=mysql_fetch_row(res))!=NULL){
        printf("%s \n",row[0]);
    }

    if(mysql_query(conexion,"select * from personal")){
        printf("\n error");

    }
    res=mysql_use_result(conexion);

    while((row=mysql_fetch_row(res))!=NULL){
        printf("\n");

        printf("%s",row[0]);
        printf("%s",row[1]);


    }
    mysql_free_result(res);
    mysql_close(conexion);
    return 0;
}
