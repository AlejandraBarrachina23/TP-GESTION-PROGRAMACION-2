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

void Fecha::cargarDatos(){

    cout << "DIA: ";
    cin >>dia;
    cout << "MES ";
    cin >>mes;
    cout << "AÑO: ";
    cin >> anio;

}

void Fecha::mostrarArchivo(){

    cout<<dia<<"/"<<mes<<"/"<<anio<<endl;
}

#endif // FECHAS_H_INCLUDED
