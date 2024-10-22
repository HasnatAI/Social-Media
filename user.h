#ifndef USER_H
#define USER_H

typedef struct {
    char username[30];
    char password[30];
} User;

int register_user(const char *username, const char *password);
int login_user(const char *username, const char *password);

#endif

