/*
***Projeto desenvolvido com o intuito de demonstrar o comportamento dos algoritmos de ordenação: Bubble, Insertion e Selection.
***Autor: Arthur Rodrigues Proença
***Não foram usadas funções somente por questão 'didática', uma vez que devo seguir o momento atual de meu módulo no curso de AED's I.
*/

#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>
#include<time.h>


int main()
{
    int n, *vector = 0, *vector2 = 0, i, j, opt, aux, counter = 0, counterS = 0, counterI = 0, min;

    printf("Welcome! This project creates a vector composed by 'n' positions and compair his ordenation by Bubble, Selection or Insertion \n");
    printf("\nType the size of vector: ");
    scanf("%i", &n);

    vector = (int*) malloc(sizeof(int*) * n);
    vector2 = (int*) malloc(sizeof(int*) *n);

    srand(time(NULL)); 

    for(i = 0; i < n; i++)
    {
        vector[i] = rand()%(n*3);
    }
    
    printf("\nThe array generated are -> ");

    for(i = 0; i < n; i++)
    {
        printf("%i ", vector[i]);
    }

    printf("\n\nWhich sort algorithm do you want?");
    printf("\n1- Bubble sort");
    printf("\n2- Insertion sort");
    printf("\n3- Selection sort\n");
    scanf("%i", &opt);

    if(opt==1)
    {
        printf("\nWe'll use the Bubble sort method.\n");

        for(i=(n-1); i>0; i--)
        {
            for(j=0; j<i; j++)
            {
                if(vector[j] > vector[j+1])
                {
                    aux = vector[j];
                    vector[j] = vector[j+1];
                    vector[j+1] = aux;
                    counter+=3;
                }
            }
        }

        /*Now we can compair when the array is already sorted.*/
        for(i=(n-1); i>0; i--)
        {
            for(j=0; j<i; j++)
            {
                if(vector[j] > vector[j+1])
                {
                    aux = vector[j];
                    vector[j] = vector[j+1];
                    vector[j+1] = aux;
                    counterS+=3;
                }
            }
        }

        /*Inverting the vector*/   
        for(j=0; j<n; j++)
        {
            vector2[j] = vector[(n-j)];
        }

        /*Now we can compair when the array is inverted sorted.*/
        for(i=(n-1); i>0; i--)
        {
            for(j=0; j<i; j++)
            {
                if(vector2[j] > vector2[j+1])
                {
                    aux = vector2[j];
                    vector2[j] = vector2[j+1];
                    vector2[j+1] = aux;
                    counterI+=3;
                }
            }
        }
    }
    else 
        if (opt == 2)
        {  
            printf("\nWe'll use the Insertion sort method.\n");

            for(i=1; i<n; i++)
            {
                aux = vector[i];
                counter++;
                for(j=(i-1); j>=0 && vector[j] > aux; j--)
                {
                    vector[j+1] = vector[j];
                    counter++;
                }
                vector[j+1] = aux;
                counter++;
            }
            
            /*Now we can compair when the array is already sorted.*/
            for(i=1; i<n; i++)
            {
                aux = vector[i];
                counterS++;
                for(j=(i-1); j>=0 && vector[j] > aux; j--)
                {
                    vector[j+1] = vector[j];
                    counterS++;
                }
                vector[j+1] = aux;
                counterS++;
            }

            /*Inverting the vector*/   
            for(j=0; j<n; j++)
            {
                vector2[j] = vector[(n-j)];
            }

            /*Now we can compair when the array is inverted sorted.*/
            for(i=1; i<n; i++)
            {
                aux = vector2[i];
                counterI++;
                for(j=(i-1); j>=0 && vector2[j] > aux; j--)
                {
                    vector2[j+1] = vector2[j];
                    counterI++;
                }
                vector2[j+1] = aux;
                counterI++;
            }
        }
     else 
        if (opt == 3)
        {  
            printf("\nWe'll use the Selection sort method.\n");

            for(i=0; i<(n-1); i++)
            {
                aux = vector[i];
                min = i;
                counter++;
                for(j=(i+1); j<n; j++)
                { 
                    if (vector[j] < aux)
                    {
                        min = j;
                        aux = vector[j];
                        counter++;
                    }
                }
                vector[min] = vector[i];
                vector[i] = aux;
                counter+=2;
            }

            /*Now we can compair when the array is already sorted.*/
            for(i=0; i<(n-1); i++)
            {
                aux = vector[i];
                min = i;
                counterS++;
                for(j=i+1; j<n; j++)
                { 
                    if (vector[j] < aux)
                    {
                        min = j;
                        aux = vector[j];
                        counterS++;
                    }
                    
                }
                vector[min] = vector[j];
                vector[i] = aux;
                counterS+=2;
            }

            /*Inverting the vector*/   
            for(j=0; j<n; j++)
            {
                vector2[j] = vector[(n-j)];
            }

            /*Now we can compair when the array is inverted sorted.*/
            for(i=0; i<(n-1); i++)
            {
                aux = vector2[i];
                min = i;
                counterI++;
                for(j=i+1; j<n; j++)
                { 
                    if (vector2[j] < aux)
                    {
                        min = j;
                        aux = vector2[j];
                        counterI++;
                    }
                    
                }
                vector2[min] = vector2[j];
                vector2[i] = aux;
                counterI+=2;
            }

        }

    printf("\nThe array sorted are ->");

    for(i=0; i<n; i++)
    {
        printf("%i ", vector[i]);
    }

    printf("\n\nThe number of iterations with the selected method is: %i\n\n", counter);
    printf("\nThe number of iterations in a array ordened with the selected method is: %i\n\n", counterS);
    printf("\nThe number of iterations in a array inverted sorted with the selected method is: %i\n\n", counterI);
    
    free(vector);
    free(vector2);

    return 0;
}