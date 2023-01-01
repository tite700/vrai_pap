#ifndef REDUITE_H
#define REDUITE_H

#include "Parent.h"

class Reduite_put : public Parent {
    
    double** matrix;

    public:

        /**
         * @brief Construct a new Reduite_put object
         * 
         * @param t 
         * @param l 
         * @param m 
         * @param n 
         */
        Reduite_put(double t, double l,int m, int n);

        /**
         * @brief Destroy the Reduite_put object
         * 
         */
        ~Reduite_put();

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



class Reduite_call : public Parent {
 
    double** matrix;

    public:

        /**
         * @brief Construct a new Reduite_call object
         * 
         * @param t 
         * @param l 
         * @param m 
         * @param n 
         */
        Reduite_call(double t, double l,int m, int n);

        /**
         * @brief Destroy the Reduite_call object
         * 
         */
        ~Reduite_call();

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
         * @brief  Calcule la solution de l'EDP
         * 
         * @param K 
         * @param r 
         * @param sig 
         */
        void Solution(double K, double r, double sig);
};

#endif