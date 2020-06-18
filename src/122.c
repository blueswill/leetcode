int maxProfit(int *p, int size) {
    if (!p)
        return 0;
    int sum = 0;
    for (int i = 1; i < size; ++i) {
        if (p[i] > p[i - 1])
            sum += p[i] - p[i - 1];
    }
    return sum;
}
