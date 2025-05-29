#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100

typedef struct {
    int accNo;
    char name[100];
    float balance;
    int isActive;
} Account;

Account accounts[MAX_ACCOUNTS];
int accCount = 0;

void createAccount();
void viewAccount();
void deposit();
void withdraw();
void checkBalance();
void closeAccount();
void listAccounts();

int main() {
    int choice;
    while (1) {
        printf("\n--- Bank Management System ---\n");
        printf("1. Create Account\n2. View Account\n3. Deposit\n4. Withdraw\n5. Check Balance\n6. Close Account\n7. List All Accounts\n8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: createAccount(); break;
            case 2: viewAccount(); break;
            case 3: deposit(); break;
            case 4: withdraw(); break;
            case 5: checkBalance(); break;
            case 6: closeAccount(); break;
            case 7: listAccounts(); break;
            case 8: exit(0);
            default: printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}

void createAccount() {
    if (accCount >= MAX_ACCOUNTS) {
        printf("Bank is full! Cannot add more accounts.\n");
        return;
    }
    Account acc;
    acc.accNo = 1000 + accCount;
    printf("Enter Name: ");
    scanf(" %[^\n]", acc.name);
    printf("Enter Initial Deposit: ");
    scanf("%f", &acc.balance);
    acc.isActive = 1;
    accounts[accCount++] = acc;
    printf("Account created successfully! Account No: %d\n", acc.accNo);
}

void viewAccount() {
    int accNo, found = 0;
    printf("Enter Account Number: ");
    scanf("%d", &accNo);
    for (int i = 0; i < accCount; i++) {
        if (accounts[i].accNo == accNo && accounts[i].isActive) {
            printf("Account No: %d\nName: %s\nBalance: %.2f\n", accounts[i].accNo, accounts[i].name, accounts[i].balance);
            found = 1;
            break;
        }
    }
    if (!found) printf("Account not found.\n");
}

void deposit() {
    int accNo;
    float amt;
    printf("Enter Account Number: ");
    scanf("%d", &accNo);
    for (int i = 0; i < accCount; i++) {
        if (accounts[i].accNo == accNo && accounts[i].isActive) {
            printf("Enter amount to deposit: ");
            scanf("%f", &amt);
            accounts[i].balance += amt;
            printf("Amount deposited. New Balance: %.2f\n", accounts[i].balance);
            return;
        }
    }
    printf("Account not found.\n");
}

void withdraw() {
    int accNo;
    float amt;
    printf("Enter Account Number: ");
    scanf("%d", &accNo);
    for (int i = 0; i < accCount; i++) {
        if (accounts[i].accNo == accNo && accounts[i].isActive) {
            printf("Enter amount to withdraw: ");
            scanf("%f", &amt);
            if (accounts[i].balance >= amt) {
                accounts[i].balance -= amt;
                printf("Withdrawal successful. New Balance: %.2f\n", accounts[i].balance);
            } else {
                printf("Insufficient balance!\n");
            }
            return;
        }
    }
    printf("Account not found.\n");
}

void checkBalance() {
    int accNo;
    printf("Enter Account Number: ");
    scanf("%d", &accNo);
    for (int i = 0; i < accCount; i++) {
        if (accounts[i].accNo == accNo && accounts[i].isActive) {
            printf("Current Balance: %.2f\n", accounts[i].balance);
            return;
        }
    }
    printf("Account not found.\n");
}

void closeAccount() {
    int accNo;
    printf("Enter Account Number: ");
    scanf("%d", &accNo);
    for (int i = 0; i < accCount; i++) {
        if (accounts[i].accNo == accNo && accounts[i].isActive) {
            accounts[i].isActive = 0;
            printf("Account closed successfully.\n");
            return;
        }
    }
    printf("Account not found.\n");
}

void listAccounts() {
    printf("Active Accounts:\n");
    for (int i = 0; i < accCount; i++) {
        if (accounts[i].isActive) {
            printf("Account No: %d, Name: %s, Balance: %.2f\n", accounts[i].accNo, accounts[i].name, accounts[i].balance);
        }
    }
}
