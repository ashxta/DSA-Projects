#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PEOPLE 100

typedef struct {
    char name[50];
    int amount;
} Person;

typedef struct {
    int payer;
    int payee;
    int amount;
} Transaction;

void calculateBalances(int numPeople, Person people[], int balances[]) {
    int totalSpent = 0, average, i;
    for (i = 0; i < numPeople; i++) {
        totalSpent += people[i].amount;
    }
    average = totalSpent / numPeople;
    for (i = 0; i < numPeople; i++) {
        balances[i] = people[i].amount - average;
    }
}

void settleTransactions(int numPeople, int balances[], Transaction transactions[], int *numTransactions) {
    int giver = 0, receiver = 0, settlement;
    *numTransactions = 0;
    while (1) {
        while (giver < numPeople && balances[giver] >= 0) giver++;
        while (receiver < numPeople && balances[receiver] <= 0) receiver++;
        if (giver == numPeople || receiver == numPeople) break;
        settlement = balances[receiver] < -balances[giver] ? balances[receiver] : -balances[giver];
        balances[receiver] -= settlement;
        balances[giver] += settlement;
        transactions[*numTransactions].payer = giver;
        transactions[*numTransactions].payee = receiver;
        transactions[*numTransactions].amount = settlement;
        (*numTransactions)++;
    }
}

int main() {
    int numPeople, i;
    Person people[MAX_PEOPLE];
    int balances[MAX_PEOPLE];
    Transaction transactions[MAX_PEOPLE];
    int numTransactions;

    printf("Enter the number of people: ");
    scanf("%d", &numPeople);

    for (i = 0; i < numPeople; i++) {
        printf("Enter name of person %d: ", i + 1);
        scanf("%s", people[i].name);
        printf("Enter amount spent by %s: ", people[i].name);
        scanf("%d", &people[i].amount);
    }

    calculateBalances(numPeople, people, balances);
    settleTransactions(numPeople, balances, transactions, &numTransactions);

    printf("\nTransactions to settle expenses:\n");
    for (i = 0; i < numTransactions; i++) {
        printf("%s pays %s: %d\n", people[transactions[i].payer].name, people[transactions[i].payee].name, transactions[i].amount);
    }

    return 0;
}

