#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct person {
    int age;
    char gender;
};

struct planet {
    struct person *people;
    int people_count;
    int age;
};

struct person create_person(const int age) {
    const struct person person = {age, rand() % 2 < 0.5 ? 'F' : 'M'};
    return person;
}

struct person *resize_array(const struct planet planet) {
    struct person *temp = realloc(planet.people, (planet.people_count + 1) * sizeof(struct person));
    if (temp == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return nullptr;
    }
    return temp;
}

void spawn_people(struct planet *p, int count) {
    for (int i = 0; i < count; i++) {
        p->people[p->people_count] = create_person(0);
        p->people_count++;
        p->people = resize_array(*p);
    }
}

void print_All_people(struct planet *p) {
    for (int i = 0; i < p->people_count; ++i) {
        printf("Age: %d, Gender: %c\n", p->people[i].age, p->people[i].gender);
    }
}

int number_of_gender(struct planet *p, char gender) {
    int count = 0;
    for (int i = 0; i < p->people_count; ++i) {
        if (p->people[i].gender == gender) {
            count++;
        }
    }
    return count;
}

void remove_element(struct person *array, int index, int array_length)
{
    for(int i = index; i < array_length - 1; i++) array[i] = array[i + 1];
}

int number_of_fuckable_people_of_gender(struct planet *p, char gender) {
    int count = 0;
    for (int i = 0; i < p->people_count; ++i) {
        if (p->people[i].age >= 15 && p->people[i].gender == gender) {
            count++;
        }
    }
    return count;
}

void age_the_planet(struct planet *p) {
    const int woman_count = number_of_fuckable_people_of_gender(p, 'F');
    const int man_count = number_of_fuckable_people_of_gender(p, 'M');

    for (int i = 0; i < p->people_count; ++i) {
        p->people[i].age++;
        if (rand() % 20 < 2) {
            printf("Person died at the age of %d\n", p->people[i].age);
            remove_element(p->people, i, p->people_count);
            p->people_count--;
        }
    }

    if (rand() % 2 < 0.5) {
        int babies_count = woman_count > man_count ? man_count : woman_count;

        babies_count = rand() % babies_count + 1;

        spawn_people(p, babies_count);
    }
}


int main() {
    struct planet earth;

    srand(time(NULL));

    earth.people_count = 0;

    earth.people = malloc(sizeof(struct person) * 10);
    spawn_people(&earth, 5);

    for (int i = 0; i < 20; ++i) {
        printf("=========================\n");
        printf("Number of people this generation: %d\n", earth.people_count);
        printf("=========================\n");
        age_the_planet(&earth);
        print_All_people(&earth);
    }

    free(earth.people);
    return 0;
}
