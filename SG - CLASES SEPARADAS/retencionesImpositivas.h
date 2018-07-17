#ifndef RETENCIONESIMPOSITIVAS_H_INCLUDED
#define RETENCIONESIMPOSITIVAS_H_INCLUDED

RetencionesImpositivas::RetencionesImpositivas(){ //CONSTRUCTOR

    IVA = 21;
    percepcion = 0;
    IB = 0;
}

void RetencionesImpositivas::cargarDatos(){

    Validador validar;

    cout << "IVA: ";
    cin >> IVA;
    while(!validar.intervaloDeNumeros(IVA,0.1,21)){
        cout << "VALOR INCORRECTO. DEBE INGRESAR UN VALOR DE 1 A 21."<<endl;
        cout << "IVA: ";
        cin >> IVA;
    }
    cout << "PERCEPCION: ";
    cin >>percepcion;

    while(!validar.intervaloDeNumeros(percepcion,0.1,100)){
        cout << "VALOR INCORRECTO. DEBE INGRESAR UN VALOR ENTRE 1 Y 100."<<endl;
        cout << "PERCEPCION: ";
        cin >>percepcion;
    }
    cout << "IB: ";
    cin >>IB;

    while(!validar.intervaloDeNumeros(IB,0.1,100)){
        cout << "VALOR INCORRECTO. DEBE INGRESAR UN VALOR ENTRE 1 Y 100."<<endl;
        cout << "IB: ";
        cin >>IB;
    }
}

void RetencionesImpositivas::mostrarArchivo(){

    cout <<"\t"<<IVA<<"\t"<<percepcion<<"\t"<<IB<<endl;
    cout << "-----------------------------------------------------------------------------------------------------"<<endl;
}

#endif // RETENCIONESIMPOSITIVAS_H_INCLUDED
