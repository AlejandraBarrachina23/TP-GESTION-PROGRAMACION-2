#ifndef VALIDADOR_H_INCLUDED
#define VALIDADOR_H_INCLUDED

int Validador::existenciaUsuario(char *usuario){ //VALIDA SI EXISTE EL NOMBRE DE USUARIO.
    int pos=0;
    Usuario unUsuario;
    while(unUsuario.leerArchivo(pos)){
        if(strcmp(unUsuario.getNombre(),usuario)==0&&unUsuario.getEstado()==true){return pos;} //COMPARA LO QUE LEE EN EL ARCHIVO CON EL QUE RECIBE LA FUNCION, SI ES VERDADERO DEVUELVE POSICION.
        pos++;
    }
    return -1; // SINO ES EXISTE RETORNA -1
}
int Validador::existenciaCodigo(int cod){ //VALIDA SI EXISTE EL CODIGO DE PRODUCTO.
    Producto unProducto;
    int pos=0;
    while(unProducto.leerArchivo(pos)){
        if(unProducto.getCodigoProducto()==cod&&unProducto.getEstado()==true)return pos;
    pos++;
    }
    return -1;
}
int Validador::existenciaCodigoUsuario(int cod){

    int pos=0;
    Usuario unUsuario;
    while(unUsuario.leerArchivo(pos)){
        if(unUsuario.getCodigo()==cod&&unUsuario.getEstado()==true){return pos;} //COMPARA LO QUE LEE EN EL ARCHIVO CON EL QUE RECIBE LA FUNCION, SI ES VERDADERO DEVUELVE POSICION.
        pos++;
    }
    return -1; // SINO ES EXISTE RETORNA -1
}
int Validador::longitudVector(char *v,int tamanioMaximo){

    int tam;
    tam = strlen(v);
    if(tam>tamanioMaximo) return false;
    else return true;
}
bool Validador::intentosDeInicio(int intentos, int valorLimite){

    if(intentos==valorLimite) {
        gotoxy(32,18);cout << "SE HAN REGISTRADO VARIOS INTENTOS DE"<<endl;
        gotoxy(30,19);cout << "ACCESO SIN EXITO, EL PROGRAMA SE CERRARA."<<endl;
        gotoxy(37,20);cout << " CONTACTE AL ADMINISTRADOR."<<endl;
        return true;
    }
    else return false;
}
bool Validador::intervaloDeNumeros(int numero, int base, int tope){
    if(numero<base || numero>tope) return false;
    return true;

}
int Validador::existenciaProveedor(char *proveedor){

    Proveedor unProveedor;
    int pos=0;
    while(unProveedor.leerArchivo(pos)){
        if(strcmp(unProveedor.getNombre(),proveedor)==0) return pos;
        pos++;
    }
    return -1;
}
int Validador::existenciaProveedor(int codigo){

    Proveedor unProveedor;
    int pos=0;
    while(unProveedor.leerArchivo(pos)){
        if(unProveedor.getCodigoProveedor()==codigo) return pos;
        pos++;
    }
    return -1;
}
int Validador::existenciaRubro(char *rubro){

    Proveedor unProveedor;
    int pos=0;
    while(unProveedor.leerArchivo(pos)){
        if(strcmp(unProveedor.getRubro(),rubro)==0) return pos;
        pos++;
    }
    return -1;
}
bool Validador::multiplos(int n1, int n2){

    if(n2%n1==0) return true;
    else return false;

}
bool Validador::validarStockSucursal(int codigo,int cantidad){
    int pos;
    Producto unProducto;
    pos=Validador::existenciaCodigo(codigo);
    unProducto.leerArchivo(pos);
    if(cantidad>unProducto.getStockSucursal()||cantidad<=0){
        return false;
    }
    return true;
}
int Validador::perteneceAproveedor(int cproducto, int cproveedor){

    Producto unProducto;
    int pos=0;
    while(unProducto.leerArchivo(pos++)){
        if(cproducto==unProducto.getCodigoProducto()&&unProducto.getEstado()==true){
            if(unProducto.getCodigoProveedor()==cproveedor) return 1;
            else return 0;
        }
    }
    return -1;
}

#endif // VALIDADOR_H_INCLUDED
