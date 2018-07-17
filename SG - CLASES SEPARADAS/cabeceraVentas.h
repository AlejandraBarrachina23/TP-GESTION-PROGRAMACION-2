#ifndef CABECERAVENTAS_H_INCLUDED
#define CABECERAVENTAS_H_INCLUDED

void CabeceraVentas::cargarDatos(){

    NrodeFactura=cuentaRegistros(rutaCabeceraVentas,tamanioCabeceraVentas)+1;
}
void CabeceraVentas::mostrarArchivo(){
CabeceraDocumento::mostrarArchivo();
cout << "\tCLIENTE: "<<cliente <<importeTotal<<endl;
cout <<"====================================================================================================="<<endl;
}
bool CabeceraVentas::grabarenDisco(){
bool escribio;
FILE*p;
p=fopen("archivos/cabeceraVentas.dat","ab");
if(p==NULL)return false;
escribio=fwrite(this,sizeof (CabeceraVentas),1,p);
fclose(p);
return escribio;
}
bool CabeceraVentas::leerenDisco(int pos){
bool leyo;
FILE*p;
p=fopen("archivos/cabeceraVentas.dat", "rb");
if(p==NULL)return false;
fseek(p,pos*sizeof(CabeceraVentas),0);
leyo=fread(this,sizeof (CabeceraVentas),1,p);
fclose(p);
return leyo;
}
#endif // CABECERAVENTAS_H_INCLUDED
