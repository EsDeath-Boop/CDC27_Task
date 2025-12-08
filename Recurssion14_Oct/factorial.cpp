int factorial(int n){
    // Calculating factorial of number
    if (n == 0 || n == 1)
        return 1;
    return n * factorial(n - 1);
}