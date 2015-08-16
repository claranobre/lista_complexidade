#include <ctime>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <string.h>
#include <assert.h>
#include <unistd.h> // Define a função sleep no Linux

using namespace std;


// Declaração das assinaturas das funções do programa.
// Dessa maneira, podemos chamar as funções antes de defini-las.
void printVector( const vector<int> & a );
int maxSubSumLinear( const vector<int> & a );
int maxSubSumQuadratic( const vector<int> & a );
int maxSubSumCubic(const vector<int> &a );
//int maxSubSumNlogN(const vector<int> &a );
void showTimeResults( const clock_t & begin, const clock_t & end );
void showClockResults( const clock_t & begin, const clock_t & end );

int main ( int argc, char* argv[])
{
    vector<int> a;
    clock_t begin, end;

    // O programa só continua se a quantidade de parâmetros estiver correta.
    // Isso pode ser mudado para um if com return.
    assert(argc >= 2);

    // Alimenta o gerador randomico com um seed baseado no tempo atual.
    // Assim, garantimos que os valores para o vetor a mudem em cada execução.
    srand(std::time(0));

    for ( long int c = 0; c < 100; c++ )
    {
        a.push_back(rand());
    }

    sleep(7);

    if ( strcmp(argv[1], "linear") == 0 )
    {
        for ( register int i = 0; i < 100; i++ )
        {
            begin = clock();
            maxSubSumLinear(a);
            end = clock();
            showClockResults(begin, end);
        }
    }
    else if ( strcmp(argv[1], "quadratic") == 0 )
    {
        for ( register int i = 0; i < 100; i++ )
        {
            begin = clock();
            maxSubSumQuadratic(a);
            end = clock();
            showClockResults(begin, end);
        }
    }
    else if ( strcmp(argv[1], "cubic") == 0 )
    {
        for ( register int i = 0; i < 100; i++ )
        {
            begin = clock();
            maxSubSumCubic(a);
            end = clock();
            showClockResults(begin, end);
        }
    }
/*  else if ( strcmp(argv[1], "nlogn") == 0 )
    {
        for ( register int i = 0; i < 100; i++ )
        {
            begin = clock();
            maxSubSumNlogN(a);
            end = clock();
            showClockResults(begin, end);
        }
    }*/

    return 0;
}

// Esta função só foi utilizada nos testes e pode ser removida.
void printVector( const vector<int> & a)
{
    cout << "[ ";
    // Imprime o vetor a na tela.
    // Usa uma coisa chamada iterator para "visitar" cada elemento de a.
    // Esse assunto vale uma pesquisada ou consultada no livro de C++.
    for ( vector<int>::const_iterator i = a.begin(); i != a.end(); ++i )
    {
        cout << *i << " ";
    }
    cout << "]" << endl;
}

int maxSubSumLinear( const vector<int> & a )
{
    int sum = 0, maxSum = 0;

    for ( unsigned int i = 0; i < a.size(); ++i )
    {
        sum += a[i];

        if ( sum > maxSum ) maxSum = sum;
        if ( sum < 0 ) sum = 0;
    }

    return maxSum;
}

int maxSubSumQuadratic( const vector<int> & a )
{
    int sum, maxSum = 0;

    for ( unsigned int i = 0; i < a.size(); ++i )
    {
        sum = 0;

        for ( unsigned int j = i; j < a.size(); ++j )
        {
            sum += a[j];

            if ( sum > maxSum ) maxSum = sum;
        }
    }

    return maxSum;
}
int maxSubSumCubic( const vector<int> & a )
{
    int sum = 0, maxSum = 0;

    for ( unsigned int i = 0; i < a.size(); ++i )
    {
        sum += pow(a[i],3);

        if ( sum > maxSum ) maxSum = sum;
        if ( sum < 0 ) sum = 0;
    }

    return maxSum;
}
/*int maxSubSumNlogN( const vector<int> & a )
{
    int sum = 0, maxSum = 0;

    for ( unsigned int i = 0; i < a.size(); ++i )
    {
        sum += a[i];

        if ( sum > maxSum ) maxSum = sum;
        if ( sum < 0 ) sum = 0;
    }

    return maxSum;
}*/

void showClockResults( const clock_t & begin, const clock_t & end )
{
    // Exibe tempo de execução em segundos.
    cout << (double)(end - begin)/CLOCKS_PER_SEC << endl;

    // cout << "begin (CPU): " << begin << endl;
    // cout << "end (CPU): " << end << endl;
    // cout << "elapsed CPU time: " << (end - begin) / CLOCKS_PER_SEC << " second(s)\n";
}
