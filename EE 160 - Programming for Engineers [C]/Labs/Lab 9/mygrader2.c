char assign_grade(int score, int a, int b, int c, int d) {
    if(score < 0 || score > 100)
        return '?';
    else if(score >= a)
        return 'A';
    else if(score >= b)
        return 'B';
    else if(score >= c)
        return 'C';
    else if(score >= d)
        return 'D';
    
    return 'F';
}

int is_valid(int a, int b, int c, int d) {

    if(a > 100 || d < 0)
        return 0;

    if(a > b)
        if(b > c)
            if(c > d)
                return 1;
    return 0;
}