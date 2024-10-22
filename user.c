#include <stdio.h>
#include <string.h>
#include "user.h"

#define USER_FILE "users.txt"

// Function to register a new user
int register_user(const char *username, const char *password) {
    FILE *file = fopen(USER_FILE, "a");
    if (!file) {
        printf("Error opening file for user registration.\n");
        return 0;
    }

    // Check if the user already exists
    User user;
    FILE *readFile = fopen(USER_FILE, "r");
    while (fscanf(readFile, "%s %s", user.username, user.password) != EOF) {
        if (strcmp(user.username, username) == 0) {
            fclose(readFile);
            printf("User already exists.\n");
            return 0;
        }
    }
    fclose(readFile);

    // Write the new user details to the file
    fprintf(file, "%s %s\n", username, password);
    fclose(file);
    printf("User registered successfully.\n");
    return 1;
}

// Function to login a user
int login_user(const char *username, const char *password) {
    FILE *file = fopen(USER_FILE, "r");
    if (!file) {
        printf("Error opening file for user login.\n");
        return 0;
    }

    User user;
    while (fscanf(file, "%s %s", user.username, user.password) != EOF) {
        if (strcmp(user.username, username) == 0 && strcmp(user.password, password) == 0) {
            fclose(file);
            printf("Login successful.\n");
            return 1;
        }
    }

    fclose(file);
    printf("Login failed. Incorrect username or password.\n");
    return 0;
}

