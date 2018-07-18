#ifndef DECLARACIONES_H_INCLUDED
#define DECLARACIONES_H_INCLUDED

using namespace std;

enum Color{
cNEGRO=0,
cAZUL=1,
cVERDE=2,
cCIAN=3,
cROJO=4,
cMAGENTA=5,
cMARRON=6,
cGRIS_CLARO=7,
cGRIS=8,
cAZUL_CLARO=9,
cVERDE_CLARO=10,
cCIAN_CLARO=11,
cROJO_CLARO=12,
cMAGENTA_CLARO=13,
cAMARILLO=14,
cBLANCO=15,
cTurquesa=34
};
void clrscr(void){
    system("cls");
}
void pause(void){
    system("pause >nul");
}
void gotoxy(short x, short y){
    COORD a;
    a.X = x;
    a.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),a);
}
void textcolor(short colorTexto=15, short colorFondo=0){
    short color = colorTexto + colorFondo * 16;
    SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE), color);
}
void recuadro(short iniX, short iniY, short ancho, short alto, short colorLinea=cBLANCO, short colorFondo=cNEGRO){
    int i, j;
    for(i=iniX; i<=iniX+ancho; i++){
        for(j=iniY; j<=iniY+alto; j++){
            gotoxy(i, j);
            textcolor(colorLinea, colorFondo);
            //Arriba izquierda
            if(i==iniX && j==iniY){
                cout << (char) 201;
            }
            //Arriba derecha
            else if(i==iniX+ancho && j==iniY){
                cout << (char) 187;
            }
            //Abajo izquierda
            else if(i==iniX && j==iniY+alto){
                cout << (char) 200;
            }
            //Abajo derecha
            else if(i==iniX+ancho && j==iniY+alto){
                cout << (char) 188;
            }
            //Lineas arriba y abajo
            else if(j==iniY || j==iniY+alto){
                cout << (char) 205;
            }
            //Lineas izquierda y derecha
            else if(i==iniX || i==iniX+ancho){
                cout << (char) 186;
            }
            //Dentro del recuadro
            else{
                cout << " ";
            }
        }
    }
}

///CLASES
class Usuario{
    private:
        int codigo;
        char nombre[20];
        char password[20];
        int sector; //SECTOR 1-ADMINISTRADOR 2-VENTAS 3-COMPRAS 4-TRANSFERENCIAS
        bool estado;
    public:
        //CONSTRUCTOR
        Usuario(){
            strcpy(nombre,"invitado");
            strcpy(password,"1234");
            sector=1;
            estado=true;
        }
        //METODOS
        char *getNombre(){return nombre;};
        char *getPassword(){return password;};
        int getSector(){return sector;};
        void setNombre(char *_nombre){strcpy(nombre,_nombre);};
        void setPassword(char *_password){strcpy(password,_password);};
        void setSector(int _sector){sector=_sector;};
        void setEstado(bool _estado){estado=_estado;};
        int getCodigo(){return codigo;}
        bool getEstado(){return estado;}
        bool leerArchivo(int existenciaUsuariocant);
        bool grabarArchivo();
        void mostrarArchivo();
        void mostrarEncabezado();
        void cargarDatos();
        void modificarRegistro(int pos);
        bool operator!=(Usuario &aux);
};
class Validador{
    private:
        int i;
    public:
        int longitudVector(char *v,int tamanioMaximo);
        bool intentosDeInicio(int intentos, int valorLimite);
        bool intervaloDeNumeros(int numero, int base, int tope);
        int existencia(int _codigo);
        int existenciaUsuario(char *usuario);
        int existenciaCodigo(int cod);
        int existenciaProveedor(char *proveedor);
        int existenciaProveedor(int codigo);
        int existenciaRubro(char *rubro);
        int existenciaCodigoUsuario(int cod);
        bool multiplos(int n2, int n1);
        bool validarStockSucursal(int codigo,int cantidad);
        int perteneceAproveedor(int pos, int cproveedor);


};
class RetencionesImpositivas{

private:
    float IVA;
    float percepcion;
    float IB;
public:
    RetencionesImpositivas();
    float getIVA(){return IVA;}
    float getPercepcion(){return percepcion;}
    float getIB(){return IB;}
    void setPercepcion(float _percepcion){percepcion=_percepcion;}
    void setIB(float _IB){IB=_IB;}
    void setIVA(float _IVA){IVA=_IVA;}
    void cargarDatos();
    void mostrarArchivo();
    bool grabarArchivo();
    bool leerArchivo(int pos);
};
class Producto{

private:
    int codigoProducto;
    char descripcion[20];
    int cantidadxBulto;
    int stockSucursal;
    int stockCritico;
    int stockDeposito;
    int codigoProveedor;
    char rubro[20];
    float precioCosto;
    float precioVenta;
    float descuento;
    float rentabilidad;
    bool estado;
    RetencionesImpositivas porcentuales;
    public:
        Producto();

        RetencionesImpositivas getPorcentuales(){return porcentuales;}
        void setPorcentuales(RetencionesImpositivas _porcentuales){porcentuales=_porcentuales;}
        int getCodigoProducto(){return codigoProducto;}
        void setEstado(bool _estado){estado=_estado;}
        bool getEstado(){return estado;}
        char *getDescripcion(){return descripcion;}
        void setDescipcion(char *_descripcion){strcpy(descripcion,_descripcion);}
        int getStockSucursal(){return stockSucursal;}
        void setStockSucursal(int _stockSucursal){stockSucursal=_stockSucursal;}
        int getStockDeposito(){return stockDeposito;}
        int getStockCritico(){return stockCritico;}
        void setStockCritico(int _stockCritico){stockCritico=_stockCritico;}
        void getStockCritico(int _stockCritico){stockCritico=_stockCritico;}
        int getCantidadxBulto(){return cantidadxBulto;}
        void setCantidadxBulto(int _cantidadxBulto){cantidadxBulto=_cantidadxBulto;}
        float getPrecioCosto(){return precioCosto;}
        void setPrecioCosto(float _costo){precioCosto=_costo;}
        float getPrecioVenta(){return precioVenta;}
        void setPrecioVenta(float _precioVenta){precioVenta=_precioVenta;}
        void setStockDeposito(int _cantidad){stockDeposito=_cantidad;}
        void setRentabilidad(float _rentabilidad){rentabilidad=_rentabilidad;}
        float getRentabilidad(){return rentabilidad;}
        int getCodigoProveedor(){return codigoProveedor;}
        void agregarProducto();
        void modificarArchivo(int cod);
        bool grabarArchivo();
        bool cargarDatos();
        void cargarDatosCompra(float pb,float pn,int stockD);
        void cargarStock(int cantidadATransferir);
        bool leerArchivo(int pos);
        void mostrarProducto();
        void mostrarStock();
        void mostrarEncabezado();
};
class Fecha {
    protected:
        int dia;
        int mes;
        int anio;
    public:
        Fecha(int d=0,int m=0, int a=0);
        int getDia(){return dia;}
        int getMes(){return mes;}
        int getAnio(){return anio;}
        void setDia(int _dia){dia = _dia;}
        void setMes(int _mes){mes = _mes;}
        void setAnio(int _anio){anio = _anio;}
        bool operator == (Fecha aux);
};
class CabeceraDocumento {

    protected:
        Fecha FechaDeEmision;
        char usuario[20];
        int NrodeFactura;
    public:
        Fecha getFechaDeEmision(){return FechaDeEmision;}
        char *getUsuario(){return usuario;}
        void setUsuario(char *_usuario){strcpy(usuario,_usuario);}
        int getNrodeFactura(){return NrodeFactura;}
        void mostrarArchivo();
};
class CabeceraCompra:public CabeceraDocumento{
    private:
        int codigoProveedor;
        char tipo[20];
    public:
        int getCodigoProveedor(){return codigoProveedor;}
        char *getTipo(){return tipo;}
        void setProveedor(int _codigoProveedor){(codigoProveedor=_codigoProveedor);}
        void setTipo(char *_tipo){strcpy(tipo,_tipo);}
        void cargarDatos(char *_usuario);
        bool leerArchivo(int pos);
        void mostrarArchivo();
        bool grabarArchivo();

};
class CabeceraMovimientos:public CabeceraDocumento{
    private:
        int tipo; //1-TRANSFERENCIA 2-DEVOLUCION
    public:
        int getTipo(){return tipo;}
        void setTipo(int _tipo){tipo=_tipo;}
        void mostrarArchivo();
        bool leerArchivo(int pos);
        void cargarDatos(char *_usuario, int _tipo);
        bool grabarArchivo();
};
class CabeceraVentas:public CabeceraDocumento{

private:
        char cliente[20];
        int metodoDePago; //1 -EFECTIVO 2-DEBITO 3- CREDITO
public:
        CabeceraVentas(){
            strcpy(cliente,"CONSUMIDOR FINAL");
        }

        int getMetodoDePago(){return metodoDePago;}
        void setMetodoDePago(int _metodoDePago){metodoDePago=_metodoDePago;}
        void mostrarArchivo();
        void cargarDatos(char *_usuario);
        bool leerenDisco(int);
        bool grabarenDisco();

};
class DetalleDocumento{

    protected:
        int nroFactura;
        int nroLinea;
        int codigoProducto;
        int cantidad;
    public:
        int getcodigoProducto(){return codigoProducto;}
        void setCodigoProducto(int _codigoProducto){codigoProducto=_codigoProducto;}
        int getCantidad(){return cantidad;}
        void setCantidad(int _cantidad){(cantidad=_cantidad);}
        void setNroLinea(int _nroLinea){nroLinea=_nroLinea;}
        int getNroLinea(){return nroLinea;}
        int getNroFactura(){return nroFactura;}
        void setNroFactura(int _nroFactura){nroFactura=_nroFactura;}

};
class DetalleCompra:public DetalleDocumento{

    private:
        float precioNeto;
        float precioBruto;
        float precioVenta;
    public:
        float getPrecioNeto(){return precioNeto;}
        void setPrecioNeto(float _precioNeto){precioNeto=precioNeto;}
        float getPrecioBruto(){return precioBruto;}
        void setPrecioBruto(float _precioBruto){precioBruto=_precioBruto;}
        float getPrecioVenta(){return precioVenta;}
        void setPrecioVenta(float _precioVenta){precioVenta=_precioVenta;}
        void cargarDatos(int,int,int);
        void calculoPrecioBruto(Producto &unProducto);
        void stockValorizado(Producto &unProducto);
        void calculoPrecioVenta(Producto &unProducto);
        bool grabarArchivo();
        bool leerArchivo(int pos);
        void mostrarArchivo();

};
class DetalleMovimientos:public DetalleDocumento{

    private:

    public:
        void mostrarArchivo();
        bool grabarArchivo();
        bool leerArchivo(int);
        void cargarDatos(int _nroFactura, int _nroLinea, int _codigoProducto, int cantidadTransferida);
        void mostrarFaltantes (int);
        void mostrarEncabezadoFaltantes();
        void cargarDatosDevoluciones(int _nroFactura, int _nroLinea);
};
class DetalleVentas:public DetalleDocumento{
private:
    float precioCosto;
    float precioVenta;
    float subtotal;
public:
    DetalleVentas(){
        precioCosto=0;
        precioVenta=0;
        subtotal=0;
    }
    int getsubtotal(){return subtotal;}
    void setSubtotal(int _subtotal){subtotal=_subtotal;}
    int getPrecioVenta(){return precioVenta;}
    int getCantidad(){return cantidad;}
    bool grabarenDisco();
    bool leerenDisco(int pos);
    void mostrarArchivo();
    void mostrarEncabezado();
    void mostrarPieDePagina(int nroFactura);
    void cargarArchivo(int _codigoFactura,int _codigoLinea);
    int calculoConFormaDePago();
    void calculoDeVuelto();

};
class Proveedor{
    private:
        int codigo;
        char nombre[20];
        char rubro[20];
        bool estado;
        RetencionesImpositivas porcentuales;
    public:
        void cargarDatos();
        void mostrarArchivo();
        void mostrarEncabezado();
        bool grabarArchivo();
        bool leerArchivo(int pos);
        void modificarArchivo(int pos);
        int getCodigoProveedor(){return codigo;}
        void setNombre(char *_nombre){strcpy(nombre,_nombre);}
        void setEstado(bool _estado){estado=_estado;}
        bool getEstado(){return estado;}
        char *getNombre(){return nombre;}
        char *getRubro(){return rubro;}
        void setPorcentuales(RetencionesImpositivas ri){porcentuales=ri;}
        RetencionesImpositivas getPorcentuales(){return porcentuales;}
};

char rutaProducto[30]="archivos/producto.dat";
int tamanioProducto = sizeof(Producto);
char rutaCabeceraCompra[30]="archivos/cabeceraCompra.dat";
int tamanioCabeceraCompra=sizeof(CabeceraCompra);
char rutaCabeceraVentas[30]="archivos/cabeceraVentas.dat";
int tamanioCabeceraVentas=sizeof(CabeceraVentas);
char rutaCabeceraMovimientos[35]="archivos/cabeceraMovimientos.dat";
int tamanioCabeceraMovimientos=sizeof(CabeceraMovimientos);
char rutaDetalleCompra[30]="archivos/detalleCompra.dat";
int tamanioDetalleCompra=sizeof(DetalleCompra);

void convierteAMiniscula(char *mayuscula);
void mostrarVector(Producto *v,int tam);
void ordenarVector(Producto *vo, int t);
void ordenarArchivoAscendente(int cantidad);
void limpiar();
void gotoxy(int x, int y);
void cuentaRegresiva(int tam);
void mostrarEncabezado();
char *buscardescripcion(int cod);
int buscarStockSucursal(int cod);
char *buscarProveedor(int cod);
char *buscarRubro(int cod);
float buscarPV(int cod);
int buscarMetodoDePago(int cod);
int buscarSumatoriaVentas(int cod);
float buscarPC(int cod);
void cuentaVentaUsuario(Fecha fechaDeHoy, char *usuario, int *pEfectivo, int *pDebito, int *pCredito);
int cuentaRegistros(char *ruta, int tamanio);
void ocultarContrasenia(char *password);
void pantallaBienvenida(char *nombre,int sector);
int navegacionMenu(int cX, int cY, int limiteA, int limiteB);
int navegacionMenuHorizontal(int cX, int cY, int limiteA, int limiteB,int valor);
bool advertenciaDeBorrado();
void accionCancelada();
void accionAceptada();

#endif // DECLARACIONES_H_INCLUDED
