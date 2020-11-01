long double pos_power(float base, int exponent) {
    long double product = 1;

    if(exponent < 0)
        return 0;

    for(int i = 0; i < exponent; i++) {
        product *= base;
    }

    return product;
}