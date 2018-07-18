#ifndef RETENCIONESIMPOSITIVAS_H_INCLUDED
#define RETENCIONESIMPOSITIVAS_H_INCLUDED

RetencionesImpositivas::RetencionesImpositivas(){ //CONSTRUCTOR

    IVA = 21;
    percepcion = 0;
    IB = 0;
}
void RetencionesImpositivas::cargarDatos(){

    Validador validar;

    gotoxy(33,8);cout << "IVA: ";
    cin >> IVA;
    while(!validar.intervaloDeNumeros(IVA,0,21)){
        textcolor(cROJO_CLARO,cAZUL);
        gotoxy(25,9);cout << "VALOR INCORRECTO. DEBE INGRESAR UN VALOR DE 1 A 21."<<endl;
        getch();
        gotoxy(25,9);cout << "                                                   "<<endl;
        gotoxy(38,8);cout << "           "<<endl;
        textcolor(cBLANCO,cAZUL);
        gotoxy(33,8);cout << "IVA: ";
        gotoxy(38,8);cin >> IVA;
    }

    gotoxy(33,9);cout << "PERCEPCION: ";
    cin >>percepcion;
    while(!validar.intervaloDeNumeros(percepcion,0,100)){
        textcolor(cROJO_CLARO,cAZUL);
        gotoxy(25,10);cout << "VALOR INCORRECTO. DEBE INGRESAR UN VALOR ENTRE 1 Y 100."<<endl;
        getch();
        gotoxy(25,10);cout << "                                                       "<<endl;
        gotoxy(45,9);cout << "           "<<endl;
        textcolor(cBLANCO,cAZUL);
        gotoxy(33,9);cout << "PERCEPCION: ";
        gotoxy(45,9);cin >>percepcion;
    }

    gotoxy(33,10);cout << "IB: ";
    cin >>IB;
    while(!validar.intervaloDeNumeros(IB,0,100)){
        textcolor(cROJO_CLARO,cAZUL);
        gotoxy(25,11);cout << "VALOR INCORRECTO. DEBE INGRESAR UN VALOR ENTRE 1 Y 100."<<endl;
        getch();
        gotoxy(25,11);cout << "                                                       "<<endl;
        gotoxy(37,10);cout << "           "<<endl;
        textcolor(cBLANCO,cAZUL);
        gotoxy(33,10);cout << "IB: ";
        gotoxy(37,10);cin >>IB;
    }
}

void RetencionesImpositivas::mostrarArchivo(){

    cout <<"\t"<<IVA<<"\t"<<percepcion<<"\t"<<IB<<endl;
    cout << "-----------------------------------------------------------------------------------------------------"<<endl;
}

#endif // RETENCIONESIMPOSITIVAS_H_INCLUDED
