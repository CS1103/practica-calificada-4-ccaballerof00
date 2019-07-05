//
// Created by Cristian on 5/07/2019.
//
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "main.cpp"

SCENARIO("Hallando el mayor valor de un vector de 30 elementos de tipo entero")
{
    GIVEN("")
    {
        WHEN("")
        {
            vector<int> numeros_enteros = {1,10,20,95,4,120,2,7,90,991,281,291,472,933,1000,18274,2718,294,461,400,90,482,991,123,100000000,191283,61273127,9,1182,3};
            int num_hilos = thread::hardware_concurrency();
            auto rpta = hallando_max(numeros_enteros, num_hilos);
                    THEN("El valor máximo debe ser 100000000")
                    {
                        REQUIRE(rpta ==100000000);
                    }
        }
    }
}
