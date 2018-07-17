#ifndef CABECERAMOVIMIENTOS_H_INCLUDED
#define CABECERAMOVIMIENTOS_H_INCLUDED

void CabeceraMovimientos::mostrarArchivo(){
CabeceraDocumento::mostrarArchivo();
cout << "\tTIPO: "<<tipo<<endl;
cout <<"====================================================================================================="<<endl;

}
void CabeceraMovimientos::cargarDatos(char *_usuario, int _tipo){

    strcpy(usuario,_usuario);
    tipo=_tipo;
    NrodeFactura=cuentaRegistros(rutaCabeceraMovimientos,tamanioCabeceraMovimientos)+1;

}
bool CabeceraMovimientos::grabarArchivo(){

    bool grabo;
    FILE *p;
    p=fopen("archivos/cabeceraMovimientos.dat","ab");
    if(p==NULL)return false;
    grabo=fwrite(this,sizeof(CabeceraMovimientos),1,p);
    fclose(p);
    return grabo;

}



#endif // CABECERAMOVIMIENTOS_H_INCLUDED
