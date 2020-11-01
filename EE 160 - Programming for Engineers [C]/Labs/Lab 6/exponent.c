float pos_power(float base, int exponent) {
    float product = 1;

    if(exponent < 0)
        return 0;

    for(int i = 0; i < exponent; i++) {
        product *= base;
    }

    return product;
}