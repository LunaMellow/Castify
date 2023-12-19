
/**
 *      Castify
 *      Subscription Management System
 *
 *      App description:
 *          - Add, remove and manage users using a command interface
 *
 *      @file main.c
 *      @date 19-Nov-23
 *
 *      @author Luna S.
 *      @alias LunaMellow
 *
 */

// Includes
#include <stdio.h>
#include <string.h>     // strtok()
#include "ReadData.h"   // readChar()

/// Const variables
#define MAXUSERS 20     ///< Maximum users allowed

// Enums
enum SubscriptionType {
    BASIC,              // HD
    PREMIUM,            // FullHD
    ULTRA               // FullHD Dolby Atmos 5.1
};
enum AcceptedPaymentMethod {
    CREDIT_CARD,        // Debit or credit
    PAYPAL,             // Paypal payment
    APPLE_PAY,          // Apple payment
    GOOGLE_PAY,         // Google payment
    INVOICE             // 30 day invoice
};
enum SubscriptionActivity {
    ACTIVE,             // Active subscription
    INACTIVE,           // Inactive subscription
    PAUSED,             // Paused subscription
    INELIGIBLE          // Ineligible for subscribing
};

// Structs
struct User {
    int userID;                                   // Unique identifier for the user
    char name[50];                                // User's full name
    char userName[50];                            // User's username
    char email[100];                              // User's email address
    char phone[20];                               // Phone number
    char address[100];                            // Physical address for billing and contact

    enum SubscriptionType subscriptionType;       // Type of subscription (Basic, premium, ultra)
    enum AcceptedPaymentMethod paymentMethod;     // Payment method (Credit card, PayPal, etc.)
    enum SubscriptionActivity isActive;           // Status of the account (Active, inactive, etc.)
};

// String arrays for enum names
const char* subscriptionTypeNames[] = {"Basic", "Premium", "Ultra"};
const char* paymentMethodNames[] = {"Credit Card", "PayPal", "Apple Pay", "Google Pay", "Invoice"};
const char* subscriptionActivityNames[] = {"Active", "Inactive", "Paused", "Ineligible"};

// Struct declarations
struct User* gUsers[MAXUSERS];                    // Struct array for users
int gRegisteredUsers = 0;                         // Registered users

// Functions
void printMenu();
void findUsers();

/**
 *      Main program
 */
int main() {

    char command;

    do {

        // Print menu and get command
        printMenu();
        command = readChar("\nCommand");

        // Command actions
        switch (command)  {
            case 'F': findUsers();              break; // List registered users
            default:                            break; // Placeholder
        }

    } while (command != 'Q');                         // If 'Q' is encountered, exit

    // Linebreak
    printf("\n");

    return 0;
}

/**
 *      Find registered users from file
 *
 *      @param userData - The file where userdata is stored
 */
void findUsers() {
    FILE *file = fopen("C:\\Users\\lunap\\CLionProjects\\Castify\\data\\users.dta", "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    char buffer[512];
    fgets(buffer, sizeof(buffer), file); // Skip header

    printf("\n%-5s %-20s %-15s %-25s %-15s %-35s %-20s %-15s %-10s\n",
           "ID", "Name", "Username", "Email", "Phone", "Address", "Subscription Type", "Payment Method", "Status");
    printf("--------------------------------------------------------------------------------------------------------\n");

    while (fgets(buffer, sizeof(buffer), file)) {
        int userID, subscriptionType, paymentMethod, isActive;
        char name[50], userName[50], email[100], phone[20], address[100];

        // Parse the line into struct fields
        if (sscanf(buffer, "%d|%49[^|]|%49[^|]|%99[^|]|%19[^|]|%99[^|]|%d|%d|%d",
                   &userID, name, userName, email, phone, address, &subscriptionType, &paymentMethod, &isActive) == 9) {
            // Print the data in a nicely formatted way
            printf("%-5d %-20s %-15s %-25s %-15s %-35s %-20s %-15s %-10s\n",
                   userID, name, userName, email, phone, address,
                   subscriptionTypeNames[subscriptionType],
                   paymentMethodNames[paymentMethod],
                   subscriptionActivityNames[isActive]);
        }
    }

    fclose(file);
}


/**
 *      @brief Prints the command menu
 */
void printMenu() {
    printf("\n--------------- Welcome! ---------------\n"
           "\n"
           "F = Find Registered Users"
           "\n"
           "\n"
           "Q = Exit"
           "\n"
           "-----------------------------------------\n");
}