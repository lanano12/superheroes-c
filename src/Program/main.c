#include "main.h"
#include "app.h"

#ifndef UNIT_TEST
int main() {
    const char *filename = "dc_battles.csv";
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        char cwd[1024];
        if (getcwd(cwd, sizeof(cwd)) != NULL) {
            fprintf(stderr, "Failed to open file %s in directory %s: %s\n", filename, cwd, strerror(errno));
        } else {
            perror("getcwd() error");
        }
        return 1;
    }

    Battle battles[10];  // assuming a max of 10 battles for simplicity
    int battle_count = read_csv(fp, battles, 10);

    calculate_winners(battles, battle_count);

    fclose(fp);
    
    return 0;
}
#endif