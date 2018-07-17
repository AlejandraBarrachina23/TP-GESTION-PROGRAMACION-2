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
    if(mes!=aux.mes) return mes;
    if(anio!=aux.anio) return anio;
    return true;
}

#endif // FECHAS_H_INCLUDED
