#ifndef COMPLETE_H
#define COMPLETE_H

#include "Parent.h"

class Complete_put : public Parent {
    
    double** matrix;

    public:

        /**
         * @brief Construct a new Complete_put object
         * 
         * @param t 
         * @param l 
         * @param m 
         * @param n 
         */
        Complete_put(double t, double l,int m, int n);
        
        /**
         * @brief Destroy the Complete_put object
         * 
         */
        ~Complete_put();

        /**
         * @brief Retourne l'élément de rangs (i,j) de la matrice
         * 
         * @param i 
         * @param j 
         * @return double 
         */
        double operator()(int i, int j) const
        {
            return matrix[i][j];
        }
        
        /**
         * @brief Calcule la solution de l'EDP
         * 
         * @param K 
         * @param r 
         * @param sig 
         */
        void Solution(double K, double r, double sig);
};



class Complete_call : public Parent {
 
    double** matrix;

    public:

        /**
         * @brief Construct a new Complete_call object
         * 
         * @param t 
         * @param l 
         * @param m 
         * @param n 
         */
        Complete_call(double t, double l,int m, int n);

        /**
         * @brief Destroy the Complete_call object
         * 
         */
        ~Complete_call();

        /**
         * @brief Retourne l'élément de rangs (i,j) de la matrice
         * 
         * @param i 
         * @param j 
         * @return double 
         */
        double operator()(int i, int j) const
        {
            return matrix[i][j];
        }
        
        /**
         * @brief Calcule la solution de l'EDP
         * 
         * @param K 
         * @param r 
         * @param sig 
         */
        void Solution(double K, double r, double sig);
};

#endif