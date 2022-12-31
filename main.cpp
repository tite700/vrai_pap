#include "Parent.h"
#include "Complete.h"
#include "Reduite.h"
#include "Graph.h"

#include <stdio.h>
#include <iostream>

int main(){

    Complete_put put_c = Complete_put(1.0,300.0,1000,1000,1);
    put_c.Solution(100.0,0.1,0.1);
    /*for(int i = 0 ; i < 40 ; i++)
    {
        std::cout<<put_c(0,i)<<std::endl;
    }*/

    Complete_call call_c = Complete_call(1.0,300.0,1000,1000,1);
    call_c.Solution(100.0,0.1,0.1);
    /*for(int i = 0 ; i < 40 ; i++)
    {
        std::cout<<call_c(0,i)<<std::endl;
    }*/

    Reduite_put put_r = Reduite_put(1.0,300.0,1000,1000,1);
    put_r.Solution(100.0,0.1,0.1);
    /*for(int i = 0 ; i < 40 ; i++)
    {
        std::cout<<put_r(0,i)<<std::endl;
    }*/

    Reduite_call call_r = Reduite_call(1.0,300.0,1000,1000,1);
    call_r.Solution(100.0,0.1,0.1);
    /*for(int i = 0 ; i < 40 ; i++)
    {
        std::cout<<call_r(0,i)<<std::endl;
    }*/

    /*----------*/
    /* ESSAI D'AFFICHAGE */
    /*----------*/

    // Création de l'objet graphique
    Graph graph1(640, 480, "put_c");
    Graph graph2(640, 480, "call_c");
    Graph graph3(640, 480, "put_r");
    Graph graph4(640, 480, "call_r");

    // Ajout des valeurs au graphique
    for (int i=0;i<40;i++){
        graph1.addPoint(i, put_c(1,i));
        graph2.addPoint(i, call_c(1,i));
        graph3.addPoint(i, put_r(1,i));
        graph4.addPoint(i, call_r(1,i));
    }

    // Affichage du graphique
    graph1.draw();
    graph2.draw();
    graph3.draw();
    graph4.draw();

    // Attente de fermerture de la fenêtre
    bool running = true;
    while (running) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }
    }

    return 0;
}
