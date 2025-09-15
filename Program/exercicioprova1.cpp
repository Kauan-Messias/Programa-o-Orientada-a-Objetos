#include <iostream>

class Data
{
//ATRIBUTOS
private: int dia, mes;
private: int ano;

//VERIFICAR SE UM ANO É BISSEXTO
//INPUT: ano
//OUTPUT: True ou False
public: static bool anoBissexto (int ano)
{
    // CALENDÁRIO JULIANO
    if (ano<1582)
        if (ano%4==0)
            return true;

        else
            return false;

        // CALENDÁRIO GREGORIANO
        if (ano%400==0) 
            return true;

        if (ano% 4==0 && ano%100!=0) 
            return true;

return false;
}

    //VERIFICAR SE UMA DATA É VÁLIDA
    //INPUT: dia, mes,ano
    //OUTPUT: True ou False
    public: static bool dataValidar(int dia, int mes, int ano)
    {
        // ANTES DO CALENDÁRIO JULIANO
        if (ano<-45) 
            return false;

        // NÃO existiu ano 0 do ano 1ac foi direto para o ano 1dc
        if (ano== 0) 
            return false;

        // dias cortados dos calendario pelo Papa Gregorio
        if (ano==1582 && mes==10 && dia>=5 && dia<=14)
            return false;

        if (dia<1 || dia>31 || mes<1 || mes>12)
            return false;

        if (dia>30 && (mes==4 || mes==6 || mes==9 || mes==11))
            return false;

        if (dia>29 && mes==2)
            return false;

        if (dia>28 && mes==2 && !anoBissexto(ano))
            return false;

        return true;
    };

    //MÉTODO CONSTRUTOR
    // d: dia / m: mes / a: ano
    public: Data (int d, int m, int a)
    {
        dia=d;
        mes=m;
        ano=a;
    };

    //MÉTODO CONSTRUTOR
    public: Data ()
    {
        dia=0;
        mes=0;
        ano=0;
    };


    //Setar um dia
    //INPUT: dia
    //OUTPUT: void
    public: void setDia (int d)
    {
        dia = d;
    }

    //Retorna o dia cadastrado na classe
    //INPUT: void
    //OUTPUT: dia
    public: int getDia ()
    {
        return dia;
    }

    //Setar um mes
    //INPUT: mes
    //OUTPUT: void
    public: void setMes (int m)
    {
        mes = m;
    }

    //Retorna o mes cadastrado na classe
    //INPUT: void
    //OUTPUT: mes
    public: int getMes ()
    {
        return mes;
    }

    //SETAR O ANO
    //INPUT: ano
    //OUTPUT: void
    public: void setAno (int a)
    {
        ano = a;
    }

//Retorna o ano cadastrado na classe
    //INPUT: void
    //OUTPUT: ano
    public: int getAno ()
    {
        return ano;
    }

    //ATUALIZA A DATA ATUAL EM 1 DIA
    public: void avanceUmDia()
    {
        int d = dia, m = mes;
        
        d++;
        if(dataValidar(d, m, ano) == true)
        {
            dia = d;        
        }
        else
        {
            d = 1;
            m++;
            if(dataValidar(d, m, ano) == true)
            {
                mes = m;
            }
            else
            {
                m = 1;
                ano++;
            }
        }
    }; 

    //RETORNA A DATA DO DIA SEGUINTE
    // À DATA CORRENTE(ATUAL) DEFINIDA NA CLASSE
    //NÃO ALTERA A DATA CORRENTE
    public: Data getDiaSeguinte()
    {
        Data Aux = Data(dia, mes, ano);
        Aux.avanceUmDia();
        return Aux;
    }; 
};

int main()
{
    Data dd = Data(7, 12, 1941);
    std::cout << "\n DATA CORRENTE: " << dd.getDia() << "/" << dd.getMes() << "/" << dd.getAno();
    dd.avanceUmDia();
    std::cout << "\n AVANCAR DIA:   " << dd.getDia() << "/" << dd.getMes() << "/" << dd.getAno();

    return 0;    
}