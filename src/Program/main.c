#include "main.h"
#include "app.h"

#ifndef UNIT_TEST
int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <path_to_dc_battles.csv>\n", argv[0]);
        return 1;
    }

    const char *filename = argv[1];
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
