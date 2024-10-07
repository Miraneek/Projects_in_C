#include <stdio.h>
#include <stdlib.h>

struct User {
    char * first_name;
    char * last_name;
    char * email;
    int age;
};

struct User create_user(char * first_name, char * last_name, char * email, int age) {
    struct User user;
    user.first_name = first_name;
    user.last_name = last_name;
    user.email = email;
    user.age = age;
    return user;
}

int print_user_info(struct User user) {
    printf("First name: %s\n", user.first_name);
    printf("Last name: %s\n", user.last_name);
    printf("Email: %s\n", user.email);
    printf("Age: %d\n", user.age);
    return 0;
}

int main(){

    printf("How many letters has your first name?\n");
    int first_name_length;
    scanf("%d", &first_name_length);
    char * first_name = malloc(first_name_length * sizeof(char) + 1);
    printf("Enter your first name: ");
    scanf("%s", first_name);

    printf("How many letters has your last name?\n");
    int last_name_length;
    scanf("%d", &last_name_length);
    char * last_name = malloc(last_name_length * sizeof(char) + 1);
    printf("Enter your last name: ");
    scanf("%s", last_name);

    printf("How many letters has your email?\n");
    int email_length;
    scanf("%d", &email_length);
    char * email = malloc(email_length * sizeof(char) + 1);
    printf("Enter your email: ");
    scanf("%s", email);

    printf("How old are you?\n");
    int age;
    scanf("%d", &age);

    struct User user = create_user(first_name, last_name, email, age);
    free(first_name);
    free(last_name);
    free(email);

    print_user_info(user);
    return 0;
}
