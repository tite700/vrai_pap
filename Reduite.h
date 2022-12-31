#ifndef REDUITE_H
#define REDUITE_H

#include "Parent.h"

class Reduite_put : public Parent {
    
    double** matrix;

    public:

        Reduite_put(double t, double l,int m, int n, double mu);

        ~Reduite_put();

        double operator()(int i, int j) const
        {
            return matrix[i][j];
        }
        
        void Solution(double K, double r, double sig);
};



class Reduite_call : public Parent {
 
    double** matrix;

    public:

        Reduite_call(double t, double l,int m, int n, double mu);

        ~Reduite_call();

        double operator()(int i, int j) const
        {
            return matrix[i][j];
        }
        
        void Solution(double K, double r, double sig);
};

#endif