#ifndef COMPLETE_H
#define COMPLETE_H

#include "Parent.h"

class Complete_put : public Parent {
    
    double** matrix;

    public:

        Complete_put(double t, double l,int m, int n,double mu);

        ~Complete_put();

        double operator()(int i, int j) const
        {
            return matrix[i][j];
        }
        
        void Solution(double K, double r, double sig);
};



class Complete_call : public Parent {
 
    double** matrix;

    public:

        Complete_call(double t, double l,int m, int n,double mu);

        ~Complete_call();

        double operator()(int i, int j) const
        {
            return matrix[i][j];
        }
        
        void Solution(double K, double r, double sig);
};

#endif