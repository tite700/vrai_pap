#include "Parent.h"

Parent::Parent(double t, double l, int m, int n, double mu){
    T = t;
    L = l;
    M = m;
    N = n;
    Mu = mu;
}

void Parent::Multiplication(double **A, double*C_,double *delta,double *P,int N){
    for(int i = 0 ; i < (N-1) ; i++)
    {
        double a = 0;
        for(int j = 0 ; j < (N-1) ; j++)
        {
            a += A[i][j] * C_[j];
            P[i] = a + delta[i];
        }
    }
}

void Parent::Inverse_tridiag_LU(double **A, double *b, double *x, int length){
    int N = length - 1;

    double *y = new double[N];
    double **L = new double*[N];
    double **U = new double*[N];
    for(int i = 0 ; i < N ; i++)
    {
        L[i] = new double[N];
    }
    for(int i = 0 ; i < N ; i++)
    {
        U[i] = new double[N];
    }

    L[0][0] = A[0][0];
    U[0][1] = A[0][1] / L[0][0];
    for(int i = 1 ; i <= (N-2) ; i++)
    {
        L[i][i-1] = A[i][i-1];
        L[i][i] = A[i][i] - L[i][i-1] * U[i-1][i];
        U[i][i+1] = A[i][i+1] / L[i][i];
    }
    L[N-1][N-2] = A[N-1][N-2];
    L[N-1][N-1]=A[N-1][N-1] - L[N-1][N-2] * U[N-2][N-1];

    y[0] = b[0] / L[0][0];
    for(int i = 1 ; i <= (N-1) ; i++)
    {
        y[i] = (b[i] - L[i][i-1] * y[i-1]) / L[i][i];
    }

    x[N-1] = y[N-1];
    for(int i = (N-2); i >= 0 ; i--)
    {
        x[i] = y[i] - U[i][i+1] * x[i+1];
    }

    delete[]y;
    for(int j = 0 ; j < N ; j++)
    {
        delete[] L[j];
        delete[] U[j];
    } 
    delete[] L;
    delete[] U;
}