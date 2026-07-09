#include <stdio.h>
#include <string.h>

enum {name_length=50, birth_length=20};

struct pers_info {
    char name[name_length];
    char last_name[name_length];
};

struct included_info {
    struct pers_info nm_lm; // embedded structures 
    char sex;
    unsigned short age;
    char birth_data[birth_length];

};



int main(void) {

    struct included_info exmpl_man = {
        {"Maksym", "Nakonechnyi"},
        'M',
        29,
        "20000"
    };

    printf("Name = %s\nlastname = %s\n", exmpl_man.nm_lm.name, exmpl_man.nm_lm.last_name);

    exmpl_man.age = 16;
    strcpy(exmpl_man.birth_data, "31.05.2007");

    printf("new age = %d\nnew birth data = %s\n", exmpl_man.age, exmpl_man.birth_data);

    return 0;
}