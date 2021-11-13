/**************************************************************************
 *  $Id$
 *  File:	CS21M070.c
 *
 *  Purpose: Finds the root of the the given equation using recursive Newton-Raphson Method
 *
 *  Author:	Varun Gumma
 *
 *  Date:	30-8-2021
 *
 *  Bugs:   Not all values can we initial starting values for this program.
 *          Starting at a stationary point for the function or reaching there during recursion will cause a division-by-zero error
 *
 *  Change Log:	<Date> <Author>
 *  		    <Changes>
 *
 **************************************************************************/
#include "stdio.h"
#include "math.h"
#include "stdlib.h"


/**************************************************
 * Function            : Function
 * Purpose             : computes the value of the function 'f' for a particular input
 * Input               : parameter x for the function
 * Output              : function value at given input
 *************************************************/	
 
float Function (float x)
{
    return (x*x*x - 2*x - 5);   /*function for which root has to be calculated, can be replaced with any arbitrary function*/
}

/**************************************************
 * Function            : DerivativeFunction
 * Purpose             : computes the derivative of the function 'f', i.e. 'df' for a particular input
 * Input               : parameter x for the derivative function
 * Output              : derivative function value at the given input
 *************************************************/	
 
float DerivativeFunction (float x) 
{
    return (3*x*x - 2);      /*derivative of the function for which root has to be calulated*/
}

/**************************************************
 * Function            : NewtonRaphson
 * Purpose             : Computes the real valued solution (root) for the given function 
 * Input               : An initial starting point for the function, threshold of error for recursion
 * Output              : An approximation of the root of the given function
 *************************************************/	
 
float NewtonRaphson (float currentRoot, float eps) 
{
    static float currentRootCopy, nextRoot;
    currentRootCopy = currentRoot;  /*Create a copy of the current root estimate, to compare it with the next root estimate*/
    nextRoot = currentRoot-Function(currentRoot)/DerivativeFunction(currentRoot);   /*Compute the next root estimate using newton-raphson formula, i.e. root2 = root1 - f(x)/f'(x)*/
    if (fabs(nextRoot-currentRootCopy) < eps)   /*If distance between current root estimate and next root estimate is less than the threshold*/
        return currentRoot;                     /*Return the current root estimate*/
    else 
    {
        currentRoot = currentRoot - Function(currentRoot)/DerivativeFunction(currentRoot); /*If the distance is greater than the threshold*/
        return NewtonRaphson(currentRoot, eps);  /*Apply Newton-Raphson again at this point to find next root estimate*/
    }
}

int main () 
{
    float init, eps; /*An initial estimate for the root and a threshold to keep recursing*/
    scanf ("%f %f", &init, &eps);
    printf ("Root is %f\n", NewtonRaphson(init, eps));  /*Find the real root of the given function*/
    return 0;
}


/**************************************************************************
 * $Log$
 *
 *                        End of Program.c
 **************************************************************************/

/**************************************************************************
 * About the program:
 * This program find the root of a given function using Newton-Raphson method using recursion.
 * 
 * In Newton-Raphson method, we start with an initial guess for the root and refine our guess,
 * till the distance between the current estimate and old estimate is less than some threshold. 
 * 
 * We take f'(x) (derivative) as the slope of the function at the point x, and the computation is as follows
 * y = f'(x0)(x-x0) + f(x0); generic line equation
 * As we want to find the point of the X-axis, we set y = 0
 * Hence, x = x0 - f(x0)/f'(x0)
 * This value is a refined estimate of the root from the initial point
 * We can recurse this method, to get better and finer estimates till the value of the root shifts less than a particular threshold.
 *
 * We can see that this method obviously fails when f'(x) = 0 (or almost 0), i.e. we begin or land at a stationary point.
 *
 **************************************************************************/