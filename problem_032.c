// -*- compile-command: "gcc -o problem_032 problem_032.c -Wall" -*-
// Copyright (c) 2014 Michael Caldwell
#include <stdio.h>
#include <stdbool.h>

int main()
{
    printf("Project Euler - Problem 32:\n"
           "Find the sum of all numbers that can be written as pandigital products.\n\n");

    int multiplicand, multiplier, product;
    int multiplicand_d, multiplier_d, product_d, total=0;
    int products_found[100]={};
    int check[10]={0};
    int index;
    int count=0;

    for (multiplicand=1 ; multiplicand<2500; multiplicand++)
        for (multiplier=1 ; multiplier<2500; multiplier++)
        {
            product = multiplicand*multiplier;

            // Create temporary variables for deconstruction
            multiplicand_d = multiplicand;
            multiplier_d = multiplier;
            product_d = product;

            // Clear check array
            for (index=0 ; index<10 ; index++)
                check[index]=0;
            // Mark 0 as 1 since 0 should not be included in pandigital number
            check[0]=1;

            // Deconstruct multiplier, multiplicand, & product into check array
            while (multiplicand_d!=0)
            {
                check[multiplicand_d%10]++;
                multiplicand_d /= 10;
            }
            while (multiplier_d!=0)
            {
                check[multiplier_d%10]++;
                multiplier_d /= 10;
            }
            while (product_d!=0)
            {
                check[product_d%10]++;
                product_d /= 10;
            }

            // Check for duplicate numbers
            bool candidate = true;
            for (index=0 ; index<10 ; index++)
                if (check[index] != 1)
                    candidate = false;

            // If pandigital, record, increment
            if (candidate == true)
            {

                // Check history for product
                bool recorded = false;
                for (index=0 ; index<100 ; index++)
                    if (products_found[index] == product)
                        recorded = true; //Already recorded, ignore

                //Record and add to sum
                if (recorded == false)
                {
                    products_found[count]=product;
                    total += product;
                    count++;
                }
            }
        }

    printf("Sum: %d\n", total);

    return 0;
}
