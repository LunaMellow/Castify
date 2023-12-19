
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
#include "ReadData.h"

// Enums
enum SubscriptionType {
    BASIC,          // HD
    PREMIUM,        // FullHD
    ULTRA           // FullHD Dolby Atmos 5.1
};
enum AcceptedPaymentMethod {
    CREDIT_CARD,    // Debit or credit
    PAYPAL,         // Paypal payment
    APPLE_PAY,      // Apple payment
    GOOGLE_PAY,     // Google payment
    INVOICE         // 30 day invoice
};
enum SubscriptionActivity {
    ACTIVE,         // Active subscription
    INACTIVE,       // Inactive subscription
    PAUSED,         // Paused subscription
    INELIGIBLE      // Ineligible for subscribing
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

// Functions
void printMenu();

/**
 *      Main program
 */
int main() {
    char command;

    do {

        printMenu();
        command = readChar("\n\nCommand");

        switch (command)  {
            default: break;
        }

    } while (command != 'Q');

    // Linebreak
    printf("\n\n");

    return 0;
}

/**
 * @brief Prints the command menu
 */
void printMenu() {
    printf("\n--------------- Welcome! ---------------\n"
           "\n"
           // --> Commands here
           "\n"
           "Q = Exit"
           "\n"
           "-----------------------------------------\n");
}