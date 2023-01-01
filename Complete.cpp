#include "Complete.h"
#include <math.h>
                                                                                                                              
Complete_put::Complete_put(double t, double l,int m, int n): Parent(t, l, m, n)
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
                                                                                                                               
Complete_put::~Complete_put()
{
    int M = get_M();
    for (int i = 0 ; i < (M+1) ; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;

}

void Complete_put::Solution(double K, double r, double sig)
{
    double T = get_T();
    double L = get_L();    
    int M = get_M();
    int N = get_N();
    double Dt = T/M;
    double Ds = L/N;                                                                                                         
                                                                                                         
    for(int i = 0 ; i < M ; i++)
    {                                                                       
        matrix[i][0] = K * exp((-1)*r*(T - (Dt*i)));
        matrix[i][N] = 0.0;
    }
                                                                                                                           
    for(int j = 0 ; j < (N+1) ; j++)
    {
        matrix[M][j] = Maximum(0.0,K - (Ds*j));
    }

    double *e = new double[N-1];
    double *f = new double[N-1];
    double *g = new double[N-1];
    double *h = new double[N-1];

    double **A = new double*[N-1];
    double **B = new double*[N-1];
    for (int i = 0 ; i <(N-1) ; i++)
    {
        A[i] = new double[N-1];
        B[i] = new double[N-1];
    }

    double *C_ = new double[N-1];
    double *delta = new double[N-1];
    double *P = new double[N-1];

    for (int j = 0; j < (N-1); j++)
    {
        e[j] = 0.25*Ds*j*(r + j*pow(sig,2)/Ds);
        f[j] = (1/Dt) - (pow(sig*j,2)/(2*pow(Ds,2)));
        g[j] = 0.25*Ds*j*(-r + j*pow(sig,2)/Ds);
        h[j] = (pow(sig*j,2)/(2*pow(Ds,2)) + (1/Dt) + r);
    }

    for (int i = 0 ; i < (N-1) ; i++)
    {
        A[i][i] = f[i];
        B[i][i] = h[i];
    }
    for (int i = 0 ; i < (N-2) ; i++)
    {
        A[i][i+1] = g[i];
        A[i+1][i] = e[i+1];
        B[i][i+1] = -g[i];
        B[i+1][i] = -e[i+1];
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
        delta[0] = g[0]*(matrix[j-1][0] + matrix[j][0]);
        delta[N-2] = e[N-2]*(matrix[j-1][N] + matrix[j][N]);

        Multiplication(A,C_,delta,P,M);
        Inverse_tridiag_LU(B,P,C_,M);

        for (int i = 0 ; i < (N-1) ; i++){
            matrix[j-1][i+1] = C_[i];
        }   
    }
    
    delete[] e;
    delete[] f;
    delete[] g;
    delete[] h;
    delete[] C_;
    delete[] delta;
    delete[] P;
    for(int j = 0 ; j < (N-1) ; j++)
    {
        delete[] A[j];
        delete[] B[j];
    }
    delete[] A;
    delete[] B;
}


Complete_call::Complete_call(double t, double l,int m, int n): Parent(t, l, m, n)
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
                                                                                                                               
Complete_call::~Complete_call()
{
    int M = get_M();
    for (int i = 0 ; i < (M+1) ; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;

}

void Complete_call::Solution(double K, double r, double sig)
{
    double T = get_T();
    double L = get_L();    
    int M = get_M();
    int N = get_N();
    double Dt = T/M;
    double Ds = L/N;                                                                                                         
                                                                                                         
    for(int i = 0 ; i < M ; i++)
    {                                                                       
        matrix[i][0] = 0.0;
        matrix[i][N] = K * exp(r*(T - (Dt*i)));
    }
                                                                                                                           
    for(int j = 0 ; j < N ; j++)
    {
        matrix[M][j] = Maximum(0.0,(Ds*j) - K);
    }

    double *e = new double[N-1];
    double *f = new double[N-1];
    double *g = new double[N-1];
    double *h = new double[N-1];

    double **A = new double*[N-1];
    double **B = new double*[N-1];
    for (int i = 0 ; i <(N-1) ; i++)
    {
        A[i] = new double[N-1];
        B[i] = new double[N-1];
    }

    double *C_ = new double[N-1];
    double *delta = new double[N-1];
    double *P = new double[N-1];

    for (int j = 0; j < (N-1); j++)
    {
        e[j] = 0.25*Ds*j*(r + j*pow(sig,2)/Ds);
        f[j] = (1/Dt) - (pow(sig*j,2)/(2*pow(Ds,2)));
        g[j] = 0.25*Ds*j*(-r + j*pow(sig,2)/Ds);
        h[j] = (pow(sig*j,2)/(2*pow(Ds,2)) + (1/Dt) + r);
    }

    for (int i = 0 ; i < (N-1) ; i++)
    {
        A[i][i] = f[i];
        B[i][i] = h[i];
    }
    for (int i = 0 ; i < (N-2) ; i++)
    {
        A[i][i+1] = g[i];
        A[i+1][i] = e[i+1];
        B[i][i+1] = -g[i];
        B[i+1][i] = -e[i+1];
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
        delta[0] = g[0]*(matrix[j-1][0] + matrix[j][0]);
        delta[N-2] = e[N-2]*(matrix[j-1][N] + matrix[j][N]);

        Multiplication(A,C_,delta,P,M);
        Inverse_tridiag_LU(B,P,C_,M);

        for (int i = 0 ; i < (N-1) ; i++){
            matrix[j-1][i+1] = C_[i];
        }   
    }
    
    delete[] e;
    delete[] f;
    delete[] g;
    delete[] h;
    delete[] C_;
    delete[] delta;
    delete[] P;
    for(int j = 0 ; j < (N-1) ; j++)
    {
        delete[] A[j];
        delete[] B[j];
    }
    delete[] A;
    delete[] B;
}