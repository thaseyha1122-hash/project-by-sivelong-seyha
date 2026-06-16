#include<stdio.h>

int main(){
    FILE *file;
    int id,age;
    char name[100];
    file = fopen("C:\\Users\\Acer\\OneDrive - Cambodia Academy of Digital Technology\\University\\Year1\\Term2\\Algorithm&Computational Thinking 2\\Project\\cfile\\user.csv","r");
    if (file == NULL) {
        perror("fopen");
        return 1;
    }

    /* Read lines and handle either plain CSV (123,John,45)
       or labelled lines like: ID : 1,Name : seyha,Age : 18 */
    /* require string functions */
    char line[256];
    while (fgets(line, sizeof line, file)) {
        char *tok1 = NULL, *tok2 = NULL, *tok3 = NULL;
        char *s = line;
        tok1 = strtok(s, ",");
        if (tok1) tok2 = strtok(NULL, ",");
        if (tok2) tok3 = strtok(NULL, ",");
        if (!tok1 || !tok2 || !tok3) {
            if (sscanf(line, "%d,%99[^,],%d", &id, name, &age) == 3) {
                printf("Id : %d, Name : %s, Age : %d\n", id, name, age);
            }
            continue;
        }

        char *p;
        char *val;

        p = strchr(tok1, ':');
        val = p ? p + 1 : tok1;
        while (isspace((unsigned char)*val)) val++;
        id = atoi(val);

        p = strchr(tok2, ':');
        val = p ? p + 1 : tok2;
        while (isspace((unsigned char)*val)) val++;
        size_t len = strcspn(val, "\r\n");
        if (len >= sizeof name) len = sizeof name - 1;
        strncpy(name, val, len);
        name[len] = '\0';

        p = strchr(tok3, ':');
        val = p ? p + 1 : tok3;
        while (isspace((unsigned char)*val)) val++;
        age = atoi(val);

        printf("Id : %d, Name : %s, Age : %d\n", id, name, age);
    }

    fclose(file);
    return 0;
}