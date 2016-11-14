/* mathStuff.cpp
 * Roger Priebe and Dennis Bruce
 * CS 3358
 * Prog5
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cmath>

using namespace std;

//**********  Function Prototypes  ******************

//function isPrime
//input parameter - positive integer
//returns true if the number is prime, otherwise false
//

bool isPrime (int number);

bool primeHelper(int number, int divisor);

//function printPrimes
//input parameter - positive integer
//Uses the isPrime method to print a list of prime numbers between 1 and n. 

void printPrimes (int n);

//function findFibo
//input parameter - positive integer
//returns the nth fibonacci number where
//Fib(0) -> 0 
//Fib(1) -> 1 
//Fib(N) -> Fib(N-2) + Fib(N-1)

int findFibo (int n);


//function findFactors
//input parameter - positive integer
//prints the prime factors of the given number to standard output (cout)
//example output: 52=2*2*13 (or 52=1*2*2*13) or 13=prime

void findFactors (int number);
int nextPrime(int number);
void primeFactorsHelper(int number, int divisor);
//******************  MAIN  *****************************

int main () {
    
   
    int testNum;
    
    //test for the isPrime function
    cout << "Enter a test number - ";
    cin >> testNum;
    cout << endl;
    
    if (isPrime(testNum ))  
       cout << testNum << " is prime.";
    else
       cout << testNum << " is not prime.";
    cout << endl << endl;
    //test for printing primes
    cout << "Enter n to print the prime numbers between 1 and n: ";
    cin >> testNum;
    cout << endl;
    
    printPrimes(testNum);
    
    cout << endl << endl;
    
    //test for Fibonacci number finder
    cout << "Which Fibonacci number? ";
    cin >> testNum;
    cout << endl;
    
    cout << "The " << testNum << " Fibonacci number is : " << findFibo(testNum) << endl;
    
    cout << endl;
    
    //test for prime factors
    cout << "Factor what number: ";
    cin >> testNum;
    cout << endl;
    
    findFactors(testNum);
    
    return EXIT_SUCCESS;
}




//function isPrime
//input parameter - positive integer
//returns true if the number is prime, otherwise false
//

bool isPrime (int number) {
   const int START_DIVISOR = 2; //HINT: You may want a helper function
   if(number == START_DIVISOR || number == 3 || number == 5)
       return true;
   else
       return primeHelper(number, START_DIVISOR);

}

bool primeHelper(int number, int divisor){
    
    if((number % divisor) == 0)
        return false;
    else if(divisor > sqrt(number))
        return true;
    else
        primeHelper(number, divisor+1);
}
//function printPrimes
//input parameter - positive integer
//Uses the isPrime method to print a list of prime numbers between 1 and n. 

void printPrimes (int n) {
    if(n != 2)
        printPrimes(n-1);
    if(isPrime(n))
        cout << n << " ";

} 

//function findFibo
//input parameter - positive integer
//returns the nth fibonacci number where
//Fib(0) -> 0 
//Fib(1) -> 1 
//Fib(N) -> Fib(N-2) + Fib(N-1)

int findFibo (int n) {
    
    if(n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return ((findFibo(n-2)) + (findFibo(n-1)));
}


//function findFactors
//input parameter - positive integer
//prints the prime factors of the given number to standard output (cout)
//example output: 52=2*2*13 (or 52=1*2*2*13) or 13=prime


void findFactors (int number) {
    const int START_DIVISOR = 2; //HINT: You may want a helper function
    cout << number << "=";
    if(isPrime(number))
        cout << "prime" << endl;
    else
        primeFactorsHelper(number, START_DIVISOR);
        

}
//function primeFactorsHelper
//does the recursive work for findFactors
void primeFactorsHelper(int number, int divisor){
    
    if(number % divisor == 0) {
        cout << divisor;
        if(number != divisor)
            cout << "*";
        primeFactorsHelper((number/divisor), divisor);
    }
    else if (divisor <= number) 
        primeFactorsHelper(number, divisor +1);
}