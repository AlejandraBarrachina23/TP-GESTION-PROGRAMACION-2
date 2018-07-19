#ifndef FECHAS_H_INCLUDED
#define FECHAS_H_INCLUDED

Fecha::Fecha(int d,int m,int a){
    time_t tiempo;
    struct tm *tmPtr;
    tiempo = time(NULL);
    tmPtr = localtime(&tiempo);
    anio=tmPtr->tm_year+1900;
    mes=tmPtr->tm_mon+1;
    dia=tmPtr->tm_mday;
}
bool Fecha::operator == (Fecha aux) {

    if(dia!=aux.dia) return false;
    if(mes!=aux.mes) return false;
    if(anio!=aux.anio) return false;
    return true;
}
bool Fecha::operator >= (Fecha aux){
    if(10000*anio+100*mes+dia >= 10000*aux.anio+100*aux.mes+aux.dia) return true;
    return false;
}
bool Fecha::operator <= (Fecha aux){
    if(10000*anio+100*mes+dia <= 10000*aux.anio+100*aux.mes+aux.dia) return true;
    return false;
}
bool Fecha::operator < (Fecha aux){
    if(10000*anio+100*mes+dia < 10000*aux.anio+100*aux.mes+aux.dia) return true;
    return false;
}
void Fecha::cargarDatos(){
    int Vmeses[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    Validador validar;

    gotoxy(40,6);cout << "ANIO: ";
    cin >> anio;
    while(anio<2015 || anio>2018){
        textcolor(cROJO_CLARO,cAZUL);
        gotoxy(28,7);cout << "ANIO INVALIDO. INGRESE DEL 2015 AL 2018."<<endl;
        getch();
        gotoxy(28,7);cout << "                                        "<<endl;
        textcolor(cBLANCO,cAZUL);
        gotoxy(46,6);cout << "            "<<endl;
        gotoxy(40,6);cout << "ANIO: ";
        gotoxy(46,6);cin >> anio;
    }

    gotoxy(40,7);cout << "MES: ";
    cin >>mes;
    while(!validar.intervaloDeNumeros(mes,1,12)){
        textcolor(cROJO_CLARO,cAZUL);
        gotoxy(30,8);cout <<"MES INVALIDO. INGRESE DEL 1 AL 12."<<endl;
        getch();
        gotoxy(30,8);cout <<"                                  "<<endl;
        gotoxy(45,7);cout <<"              "<<endl;
        textcolor(cBLANCO,cAZUL);
        gotoxy(40,7);cout << "MES: ";
        gotoxy(45,7);cin >>mes;
    }

    gotoxy(40,8);cout << "DIA: ";
    cin >>dia;
    while(dia>Vmeses[mes-1]){
        textcolor(cROJO_CLARO,cAZUL);
        gotoxy(20,9);cout << "DIA INVALIDO. INGRESE UN DIA QUE CORRESPONDA AL MES INGRESADO."<<endl;
        getch();
        gotoxy(20,9);cout << "                                                               "<<endl;
        gotoxy(45,8);cout << "       "<<endl;
        textcolor(cBLANCO,cAZUL);
        gotoxy(40,8);cout << "DIA: ";
        gotoxy(45,8);cin >>dia;

    }

}
void Fecha::mostrarArchivo(){

    cout<<dia<<"/"<<mes<<"/"<<anio<<endl;
}

#endif // FECHAS_H_INCLUDED
