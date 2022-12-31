#ifndef PARENT_H
#define PARENT_H

/*                                                                                                                                            
    @requires: nothing                                                                                                                          
    @assigns: nothing                                                                                                                             
    @ensures: a parent class for the 2 equation systems                                                                                                                         
*/

class Parent {

    double T; // terminal time                                                                                                                   
    double L; // terminal asset price                                                                                                      
    int M; // temporal mesh                                                                                       
    int N; // price mesh                                                                                        
    double Mu;

    public:
        
        Parent(double t, double l, int m, int n, double mu); 

        double get_T() const
        {
            return T;
        }

        double get_L() const
        {
            return L;
        }

        double get_M() const
        {
            return M;
        }

        double get_N() const
        {
            return N;
        }

        double get_Mu() const
        {
            return Mu;
        }

        void Multiplication(double **A, double*C_,double *delta,double *P,int N);

        double Maximum(double u, double v)
        {
            return ((u > v) ? u : v);
        }

        void Inverse_tridiag_LU(double **A,double*b,double *x, int n);                                                                                  
};

#endif