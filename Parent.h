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

    public:
        
        /**
         * @brief Construct a new Parent object
         * 
         * @param t 
         * @param l 
         * @param m 
         * @param n 
         */
        Parent(double t, double l, int m, int n); 

        /**
         * @brief Getter pour la valeur de T
         * 
         * @return double 
         */
        double get_T() const
        {
            return T;
        }

        /**
         * @brief Getter pour la valeur de L
         * 
         * @return double 
         */
        double get_L() const
        {
            return L;
        }

        /**
         * @brief Getter pour la valeur de M
         * 
         * @return double 
         */
        double get_M() const
        {
            return M;
        }

        /**
         * @brief Getter pour la valeur de N
         * 
         * @return double 
         */
        double get_N() const
        {
            return N;
        }

        /**
         * @brief Multiplie la matrice A avec C_ et lui additione le vecteur delta
         * 
         * @param A 
         * @param C_ 
         * @param delta 
         * @param P 
         * @param N 
         */
        void Multiplication(double **A, double*C_,double *delta,double *P,int N);

        /**
         * @brief Retourne le maximum entre les deux doubles en paramètres
         * 
         * @param u 
         * @param v 
         * @return double 
         */
        double Maximum(double u, double v)
        {
            return ((u > v) ? u : v);
        }

        /**
         * @brief Inverse la matrice tridiagonale A en résolvant Ax=b grâce à la décomposition LU
         * 
         * @param A 
         * @param b 
         * @param x 
         * @param n 
         */
        void Inverse_tridiag_LU(double **A,double*b,double *x, int n);                                                                                  
};

#endif