#ifndef PRODUCTOS_H_INCLUDED
#define PRODUCTOS_H_INCLUDED


Producto::Producto(){

    codigoProducto=0;
    strcpy(descripcion," ");
    cantidadxBulto=0;
    stockSucursal=0;
    stockCritico=0;
    stockDeposito=0;
    strcpy(rubro," ");
    codigoProveedor=0;
    precioCosto=0;
    precioVenta=0;
    descuento=0;
    rentabilidad=0;
    estado=true;
}
bool Producto::grabarArchivo(){
    bool grabo;
    FILE *p;
    p=fopen("archivos/producto.dat","ab");
    if(p==NULL) return false;
    grabo=fwrite(this,sizeof(Producto),1,p);
    fclose(p);
    return grabo;
}
void Producto::modificarArchivo(int cod){

    FILE *p;
    p=fopen("archivos/producto.dat","rb+");
    if(p==NULL) exit(-1);
    fseek(p,sizeof(Producto)*cod,0);
    fwrite(this,sizeof(Producto),1,p);
    fclose(p);

}
void Producto::mostrarEncabezado(){

    recuadro(0, 0,102, 25, cBLANCO, cAZUL);
    recuadro(0, 0,102, 2, cBLANCO, cAZUL);
    textcolor(cBLANCO,cAZUL);
    gotoxy(40,1);cout << "LISTADO DE PRODUCTOS"<<endl;
    cout << endl;
    cout << "====================================================================================================="<<endl;
    cout << "CODIGO\tDETALLE\t\t    B   SC  SS  SD  RUBRO    \t   PC\t PV   PROVEEDOR      IVA   IB    P"<<endl;
    cout << "====================================================================================================="<<endl;


}
void Producto::mostrarProducto(){

    char proveedor[20];
    strcpy(proveedor,buscarProveedor(codigoProveedor));
    if(estado==true){
    std::cout << setiosflags(ios::left)<<setw(8)<<codigoProducto<<setw(20)<<descripcion<<setw(4)<<cantidadxBulto<<setw(4)<<stockCritico;
    std::cout << setiosflags(ios::left)<<setw(4)<< stockSucursal<<setw(4)<< stockDeposito <<setw(15)<< rubro <<setw(6)<<fixed<<setprecision(1)<<precioCosto <<setw(6)<< precioVenta<<setw(13)<<proveedor;
    std::cout << setiosflags(ios::left)<<setw(6)<<setprecision(1)<<porcentuales.getIVA()<<setw(6)<<porcentuales.getIB()<<setw(6)<<porcentuales.getPercepcion()<<endl;
    }
}
void Producto::mostrarStock(){

    cout << "CODIGO\tDESCRIPCION\tS-SUC\tS-DEP\tS-CRI\tBULTO"<<endl;
    cout <<codigoProducto<<"\t"<<descripcion<<"\t"<<stockSucursal<<"\t"<<stockDeposito<<"\t"<<stockCritico<<"\t"<<cantidadxBulto<<endl;

}
bool Producto::cargarDatos(){

    Validador validar;
    char nombreProveedor[20];
    fflush(stdin);
    gotoxy(35,5);cout << "CODIGO DE PRODUCTO: ";
    cin >> codigoProducto;

    while(!validar.intervaloDeNumeros(codigoProducto,1000,9999)){
        textcolor(cROJO_CLARO,cAZUL);
        gotoxy(28,6);cout << "EL CODIGO DEBE ESTAR ENTRE 1000 Y 9999."<<endl;
        getch();
        gotoxy(25,6);cout << "                                           "<<endl;
        gotoxy(55,5);cout << "          "<<endl;
        textcolor(cBLANCO,cAZUL);
        gotoxy(35,5);cout<< "CODIGO DE PRODUCTO: ";
        gotoxy(55,5);cin >> codigoProducto;
    }

    while(validar.existenciaCodigo(codigoProducto)>=0){
        textcolor(cROJO_CLARO,cAZUL);
        gotoxy(32,6);cout << "EL CODIGO INGRESADO YA EXISTE."<<endl;
        getch();
        gotoxy(32,6);cout << "                              "<<endl;
        gotoxy(55,5);cout << "          "<<endl;
        textcolor(cBLANCO,cAZUL);
        gotoxy(35,5);cout << "CODIGO DE PRODUCTO: ";
        gotoxy(55,5);cin >> codigoProducto;
    }

    gotoxy(35,6);cout << "DESCRIPCION: ";
    cin.ignore();
    cin.getline(descripcion,20);
    convierteAMiniscula(descripcion);

    gotoxy(35,7);cout << "CANTIDAD POR BULTO:";
    cin >> cantidadxBulto;

    while(!validar.intervaloDeNumeros(cantidadxBulto,1,999)){
        textcolor(cROJO_CLARO,cAZUL);
        gotoxy(26,8);cout << "NUMERO INVALIDO. SOLO SE PERMITEN DEL 1 AL 999."<<endl;
        getch();
        gotoxy(53,7);cout << "        "<<endl;
        gotoxy(26,8);cout << "                                               "<<endl;
        textcolor(cBLANCO,cAZUL);
        gotoxy(35,7);cout << "CANTIDAD POR BULTO:";
        gotoxy(54,7);cin >> cantidadxBulto;
    }
    gotoxy(35,8);cout << "STOCK CRITICO: ";
    cin >> stockCritico;
    cin.ignore();
    while(!validar.multiplos(cantidadxBulto,stockCritico)){
        textcolor(cROJO_CLARO,cAZUL);
        gotoxy(7,9);cout << "NUMERO INVALIDO. EL STOCK CRITICO DEBE SER IGUAL O MULTIPLO DE LO QUE CONTIENE LA CAJA."<<endl;
        getch();
        gotoxy(7,9);cout << "                                                                                       "<<endl;
        gotoxy(49,8);cout << "        "<<endl;
        textcolor(cBLANCO,cAZUL);
        gotoxy(35,8);cout << "STOCK CRITICO: ";
        gotoxy(49,8);cin >> stockCritico;
        cin.ignore();
    }

    gotoxy(35,9);cout << "CODIGO DE PROVEEDOR: ";
    cin >> codigoProveedor;
    while(validar.existenciaProveedor(codigoProveedor)<0){
        textcolor(cROJO_CLARO,cAZUL);
        gotoxy(32,10);cout << "EL PROVEEDOR INGRESADO NO EXISTE."<<endl;
        getch();
        gotoxy(32,10);cout << "                                  "<<endl;
        gotoxy(56,9);cout << "       "<<endl;
        textcolor(cBLANCO,cAZUL);
        gotoxy(35,9);cout << "CODIGO DE PROVEEDOR:";
        gotoxy(56,9);cin >> codigoProveedor;
    }
    textcolor(cGRIS_CLARO,cAZUL);
    gotoxy(35,10);cout << "NOMBRE DE PROVEEDOR: "<< strcpy(nombreProveedor,buscarProveedor(codigoProveedor))<<endl;
    gotoxy(35,11);cout << "RUBRO: ";
    strcpy(rubro,buscarRubro(codigoProveedor));
    cout <<rubro<<endl;

    textcolor(cBLANCO,cAZUL);
    gotoxy(35,12);cout << "RENTABILIDAD: ";
    cin >> rentabilidad;
    cin.ignore();
    while(!validar.intervaloDeNumeros(rentabilidad,1,100)){
        textcolor(cROJO_CLARO,cAZUL);
        gotoxy(26,13);cout << "NUMERO INVALIDO. SOLO SE PERMITEN DEL 1 AL 100."<<endl;
        getch();
        gotoxy(26,13);cout << "                                               "<<endl;
        gotoxy(49,12);cout << "        "<<endl;
        textcolor(cBLANCO,cAZUL);
        gotoxy(35,12);cout << "RENTABILIDAD:";
        gotoxy(50,12);cin >> rentabilidad;
        cin.ignore();
    }
    accionAceptada();
    estado=true;
    return true;
}
void Producto::cargarDatosCompra(float pv,float pc,int stockD){

    precioCosto=pc;
    precioVenta=pv;
    stockDeposito=stockD;
}
void Producto::cargarStock(int cantidadATransferir){

    stockSucursal+=cantidadATransferir;
    stockDeposito-=cantidadATransferir;

}
bool Producto::leerArchivo(int pos){

    bool leyo;
    FILE *p;
    p=fopen("archivos/producto.dat","rb");
    if(p==NULL) return false;
    fseek(p,sizeof(Producto)*pos,0);
    leyo=fread(this,sizeof(Producto),1,p);
    fclose(p);
    return leyo;

}
bool Producto::leerBackup(int pos){

    bool leyo;
    FILE *p;
    p=fopen("backup/producto.dat","rb");
    if(p==NULL) return false;
    fseek(p,sizeof(Producto)*pos,0);
    leyo=fread(this,sizeof(Producto),1,p);
    fclose(p);
    return leyo;

}

#endif // PRODUCTOS_H_INCLUDED
