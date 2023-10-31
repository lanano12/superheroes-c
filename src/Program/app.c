#include "main.h"
#include "app.h"

int read_csv(FILE *fp, Battle *battles, int max_battles) {
    char line[MAX_LINE_LEN];
    int battle_count = 0;
    int parse_result;

    // skip the header
    fgets(line, sizeof(line), fp);

    while (fgets(line, sizeof(line), fp) && battle_count < max_battles) {
        parse_result = sscanf(line, "%[^,],%f,%[^,],%f", 
                              battles[battle_count].hero_name,
                              &battles[battle_count].hero_score, 
                              battles[battle_count].villain_name,
                              &battles[battle_count].villain_score);

        // Check if the line was parsed successfully
        if (parse_result != 4) {  // sscanf should successfully parse 4 items for valid lines
            fprintf(stderr, "Warning: Invalid CSV format encountered: %s", line);
            continue;  // skip the invalid line
        }

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
            printf("Draw, as both have equal scores.\n");
        }
    }
}
