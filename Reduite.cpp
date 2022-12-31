#include "Reduite.h"
#include <math.h>
#include <iostream>
                                                                                                                              
Reduite_put::Reduite_put(double t, double l,int m, int n,double mu): Parent(t, l, m, n, mu)
{
    matrix = new double *[m+1];
    for (int i = 0 ; i < m+1 ; i++)
    {
        matrix[i] = new double[n+1];
    }

    if(!matrix)
    {
        throw ("Unallocated or misallocated memory");
    }
}
                                                                                                                               
Reduite_put::~Reduite_put()
{
    int M = get_M();
    for (int i = 0 ; i < (M+1) ; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;

}

void Reduite_put::Solution(double K, double r, double sig)
{
    double T = get_T();
    double L = get_L();    
    int M = get_M();
    int N = get_N();
    double Mu = get_Mu();
    double Dt = T/M;
    double Ds = L/N;                                                                                                         
                                                                                                         
    for(int i = 0 ; i < M ; i++)
    {                                                                       
        matrix[i][0] = exp(-0.25*(T-Dt*i)*((2*r/pow(sig,2))+1)-r);
        matrix[i][N] = 0.0;
    }
                                                                                                                           
    for(int j = 0 ; j < N ; j++)
    {
        matrix[M][j] = exp(0.5*((2*r/pow(sig,2))-1)*log(Ds*j/K))*Maximum(0.0,1 - exp(log(Ds*j/K)));
    }

    double a = (1 + 2*Mu*Dt/pow(Ds,2));
    double b = (-Mu*Dt/pow(Ds,2));

    double **A = new double*[N-1];
    for (int i = 0 ; i < (N-1) ; i++)
    {
        A[i] = new double[N-1];
    }

    double *C_ = new double[N-1];
    double *delta = new double[N-1];
    double *P = new double[N-1];

    for (int i = 0 ; i < (N-1) ; i++)
    {
        A[i][i] = a;
    }
    for (int i = 0 ; i < (N-2) ; i++)
    {
        A[i][i+1] = b;
        A[i+1][i] = b;    
    }

    for(int j = 0 ; j < (N-1) ; j++)
    {
        C_[j] = matrix[M][j+1];
    }

    for (int j = 0 ; j < (N-1) ; j++)
    {
        delta[j] = 0.0;
    }

    for(int j = M ; j > 0 ; j--)
    {
        Multiplication(A,C_,delta,P,M);

        for (int i = 0 ; i < N ; i++){
            matrix[j-1][i] = P[i];
        }   
    }

    delete[] C_;
    delete[] delta;
    delete[] P;
    for(int j = 0 ; j < (N-1) ; j++)
    {
        delete[] A[j];
    }
    delete[] A;
}

Reduite_call::Reduite_call(double t, double l,int m, int n,double mu): Parent(t, l, m, n, mu)
{
    matrix = new double *[m+1];
    for (int i = 0 ; i < m+1 ; i++)
    {
        matrix[i] = new double[n+1];
    }

    if(!matrix)
    {
        throw ("Unallocated or misallocated memory");
    }
}
                                                                                                                               
Reduite_call::~Reduite_call()
{
    int M = get_M();
    for (int i = 0 ; i < (M+1) ; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;

}

void Reduite_call::Solution(double K, double r,double sig)
{
    double T = get_T();
    double L = get_L();    
    int M = get_M();
    int N = get_N();
    double Mu = get_Mu();
    double Dt = T/M;
    double Ds = L/N;                                                                                                         
                                                                                                         
    for(int i = 0 ; i < M ; i++)
    {                                                                       
        matrix[i][0] = 0.0;
        matrix[i][N] = exp(-0.25*(T-Dt*i)*((2*r/pow(sig,2))+1)+r);
    }
                                                                                                                           
    for(int j = 0 ; j < (N+1) ; j++)
    {
        matrix[M][j] = exp(0.5*((2*r/pow(sig,2))-1)*log(Ds*j/K))*Maximum(0.0,exp(log(Ds*j/K)) - 1);
    }

    double a = (1 + 2*Mu*Dt/pow(Ds,2));
    double b = (-Mu*Dt/pow(Ds,2));

    double **A = new double*[N-1];
    for (int i = 0 ; i <(N-1) ; i++)
    {
        A[i] = new double[N-1];
    }

    double *C_ = new double[N-1];
    double *delta = new double[N-1];
    double *P = new double[N-1];

    for (int i = 0 ; i < (N-1) ; i++)
    {
        A[i][i] = a;
    }
    for (int i = 0 ; i < (N-2) ; i++)
    {
        A[i][i+1] = b;
        A[i+1][i] = b;    
    }

    for(int j = 0 ; j < (N-1) ; j++)
    {
        C_[j] = matrix[M][j+1];
    }

    for (int j = 0 ; j < (N-1) ; j++)
    {
        delta[j] = 0.0;
    }

    for(int j = M ; j > 0 ; j--)
    {
        Multiplication(A,C_,delta,P,M);

        for (int i = 0 ; i < N ; i++){
            matrix[j-1][i] = P[i];
        }   
    }
    
    delete[] C_;
    delete[] delta;
    delete[] P;
    for(int j = 0 ; j < (N-1) ; j++)
    {
        delete[] A[j];
    }
    delete[] A;
}