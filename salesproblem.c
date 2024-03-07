#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char *month;
    double sales;
} SalesData;

int compareSalesData(const void *a, const void *b) {
    SalesData *dataA = (SalesData *)a;
    SalesData *dataB = (SalesData *)b;
    double diff = dataB->sales - dataA->sales;
    return (diff > 0) - (diff < 0);
}

double findMinimum(double sales[], int numMonths) {
    double min = sales[0];
    for (int i = 1; i < numMonths; i++) {
        if (sales[i] < min) {
            min = sales[i];
        }
    }
    return min;
}

double findMaximum(double sales[], int numMonths) {
    double max = sales[0];
    for (int i = 1; i < numMonths; i++) {
        if (sales[i] > max) {
            max = sales[i];
        }
    }
    return max;
}

double calculateAverage(double sales[], int numMonths) {
    double sum = 0;
    for (int i = 0; i < numMonths; i++) {
        sum += sales[i];
    }
    return sum / numMonths;
}

void calculateMovingAverage(double sales[], double movingAvg[], int numMonths) {
    for (int i = 0; i <= numMonths - 6; i++) {
        double sum = 0;
        for (int j = i; j < i + 6; j++) {
            sum += sales[j];
        }
        movingAvg[i] = sum / 6;
    }
}

int main() {
    int numMonths = 12;
    char *months[] = {"January", "February", "March", "April", "May", "June",
                      "July", "August", "September", "October", "November", "December"};
    double sales[] = {1200, 1500, 1300, 1900, 1800, 1700, 1600, 1800, 2100, 2300, 2200, 2000};
    SalesData salesData[numMonths];
    double movingAvg[numMonths - 5];

    for (int i = 0; i < numMonths; i++) {
        salesData[i].month = months[i];
        salesData[i].sales = sales[i];
    }

    qsort(salesData, numMonths, sizeof(SalesData), compareSalesData);

    printf("Sales Report:\n");
    for (int i = 0; i < numMonths; i++) {
        printf("%-9s\t%7.2f\n", months[i], sales[i]);
    }

    printf("\nStats:\n");
    printf("Min\t%.2f\n", findMinimum(sales, numMonths));
    printf("Max\t%.2f\n", findMaximum(sales, numMonths));
    printf("Avg\t%.2f\n", calculateAverage(sales, numMonths));

    calculateMovingAverage(sales, movingAvg, numMonths);
    printf("\nSix-Month Moving Average:\n");
    for (int i = 0; i < numMonths - 5; i++) {
        printf("%s-%s\t%.2f\n", months[i], months[i + 5], movingAvg[i]);
    }

    printf("\nSales Sorted (High to Low):\n");
    for (int i = 0; i < numMonths; i++) {
        printf("%-9s\t%7.2f\n", salesData[i].month, salesData[i].sales);
    }

    return 0;
}
