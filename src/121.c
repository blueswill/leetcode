int maxProfit(int *prices, int pricesSize) {
    if (!pricesSize)
        return 0;
    int min = *prices;
    int max = 0;
    for (int i = 1; i < pricesSize; ++i) {
        if (prices[i] - min > max)
            max = prices[i] - min;
        if (prices[i] < min)
            min = prices[i];
    }
    return max;
}
