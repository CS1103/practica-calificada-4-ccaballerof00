#include <iostream>
#include <vector>
#include <thread>

using namespace std;

template <typename T>
void comparador(vector<T> lista,int begin, int end, int& result);

template <typename T>
T hallando_max(vector<T> numeros, int num_hilos);








/*int main()
{
    int num_hilos = thread::hardware_concurrency();
    vector<int> numeros = {1,10,20,95,4,120,2,7,90,991,281,291,472,933,1000,18274,2718,294,461,400,90,482,991,123,100000000};
    int maximo = hallando_max(numeros, num_hilos);
    cout<<maximo;
}*/








template<typename T>
void comparador(vector<T> lista,T begin, T end, T& result)
{
    for( ; begin < end; begin++ )
    {
        if(result<lista.at(begin))
            result = lista.at(begin);
    }
}

template<typename T>
T hallando_max(vector<T> numeros, int num_hilos)
{
    vector<thread*> hilos;
    vector <T> maximos;
    int intervalo = (int)(numeros.size()/num_hilos);
    for(T i = 0;i < num_hilos; i++)
    {
        maximos.push_back(0);
        if(i == num_hilos-1)
        {
            hilos.push_back(new thread(comparador<T>, numeros, (i*intervalo),numeros.size(),ref(maximos.at(i))));
            hilos.at(i)->join();
        }
        else {
            hilos.push_back(new thread(comparador<T>, numeros, (i * intervalo), ((i + 1) * intervalo), ref(maximos.at(i))));
            hilos.at(i)->join();
        }
    }
    T num_max = 0;
    comparador(maximos,0,maximos.size(),num_max);
    return num_max;
}
