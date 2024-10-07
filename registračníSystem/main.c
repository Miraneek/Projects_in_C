#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct User {
    char *first_name;
    char *last_name;
    char *email;
};

struct User create_user(char *first_name, char *last_name, char *email) {
    struct User user;
    user.first_name = first_name;
    user.last_name = last_name;
    user.email = email;
    return user;
}

struct User create_user_from_console() {
    char *first_name = malloc(100 * sizeof(char) + 1);
    char *last_name = malloc(100 * sizeof(char) + 1);
    char *email = malloc(100 * sizeof(char) + 1);

    printf("Enter the first name of the user: ");
    scanf("%s", first_name);
    printf("Enter the last name of the user: ");
    scanf("%s", last_name);
    printf("Enter the email of the user: ");
    scanf("%s", email);

    const struct User user = create_user(strdup(first_name), strdup(last_name), strdup(email));

    free(first_name);
    free(last_name);
    free(email);

    return user;
}

struct User *add_user(struct User *users, int *current_size, const struct User user) {
    // Resize the array to make space for the new user
    struct User *new_users = realloc(users, (*current_size + 1) * sizeof(struct User));
    if (new_users == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    // Add the new user to the end of the array
    new_users[*current_size] = user;

    // Increment the current size of the array
    (*current_size)++;

    return new_users;
}

struct User get_user_by_email(const struct User *users, int max_users, char *email) {
    if (!users) {
        fprintf(stderr, "User with email %s not found\n", email);
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < max_users; ++i) {
        if (users[i].email == email) {
            return users[i];
        }
    }

    return create_user("noFirstName", "noLastName", "noEmail");
}

int print_users(struct User *users, int max_users) {
    for (int i = 0; i < max_users; ++i) {
        if (NULL != users[i].email) {
            printf("User %d: %s %s %s\n", i, users[i].first_name, users[i].last_name, users[i].email);
        }
    }
    return 0;
}

enum Input {
    ADD_USER = 1,
    GET_USER_BY_EMAIL = 2,
    EXIT = 3
};

int get_input(struct User *users, int max_users) {
    enum Input input;

    printf("What do you want to do with your %d users?\n", max_users);
    printf("===========================\n");
    print_users(users, max_users);
    printf("===========================\n");
    printf("1 -> Add new user\n");
    printf("2 -> Get user by email\n");
    printf("3 -> Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &input);
    while (input != ADD_USER && input != GET_USER_BY_EMAIL && input != EXIT) {
        fprintf(stderr, "Invalid input. Please enter 1, 2 or 3.");
        scanf("\n %d", &input);
    }
    printf("\nYou selected %s\n",
           input == ADD_USER ? "ADD_USER" : input == GET_USER_BY_EMAIL ? "Get user by email choice" : "EXIT");
    return input;
}

int main() {
    int number_of_users = 0;
    struct User *users = NULL; // Start with a null pointer, indicating no users

    enum Input input = get_input(users, number_of_users);

    while (input != EXIT) {
        switch (input) {
            case ADD_USER: {
                users = add_user(users, &number_of_users, create_user_from_console());
                break;
            }
            case GET_USER_BY_EMAIL: {
                char email[100];
                printf("Enter the email of the user: ");
                scanf("%s", email);
                struct User user = get_user_by_email(users, number_of_users, email);
                printf("User: %s %s %s\n", user.first_name, user.last_name, user.email);
                free(email);
                break;
            }
            default: fprintf(stderr, "Invalid input\n");
        }

        input = get_input(users, number_of_users);
    }
    // Free the allocated memory after use
    free(users);

    return 0;
}
