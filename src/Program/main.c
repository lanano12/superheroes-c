#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

#define MAX_NAME_LEN 50
#define MAX_LINE_LEN 200

typedef struct {
    char hero_name[MAX_NAME_LEN];
    float hero_score;
    char villain_name[MAX_NAME_LEN];
    float villain_score;
} Battle;


int read_csv(FILE *fp, Battle *battles, int max_battles) {
    char line[MAX_LINE_LEN];
    int battle_count = 0;

    // skip the header
    fgets(line, sizeof(line), fp);

    while (fgets(line, sizeof(line), fp) && battle_count < max_battles) {
        sscanf(line, "%[^,],%f,%[^,],%f", battles[battle_count].hero_name,
               &battles[battle_count].hero_score, battles[battle_count].villain_name,
               &battles[battle_count].villain_score);
        battle_count++;
    }
    return battle_count;
}

void calculate_winners(Battle *battles, int battle_count) {
    for (int i = 0; i < battle_count; i++) {
        printf("Battle between %s (score: %.2f) and %s (score: %.2f): ", 
               battles[i].hero_name, battles[i].hero_score, 
               battles[i].villain_name, battles[i].villain_score);

        if (battles[i].hero_score > battles[i].villain_score) {
            printf("Winner is %s due to higher score.\n", battles[i].hero_name);
        } else if (battles[i].hero_score < battles[i].villain_score) {
            printf("Winner is %s due to higher score.\n", battles[i].villain_name);
        } else {
            printf("Tie, as both have equal scores.\n");
        }
    }
}


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


