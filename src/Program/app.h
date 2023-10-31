#ifndef APP_H
#define APP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

#define MAX_NAME_LEN 50
#define MAX_LINE_LEN 200

// Battle struct definition
typedef struct {
    char hero_name[MAX_NAME_LEN];
    float hero_score;
    char villain_name[MAX_NAME_LEN];
    float villain_score;
} Battle;

// Function prototypes
int read_csv(FILE *fp, Battle *battles, int max_battles);
void calculate_winners(Battle *battles, int battle_count);

#endif // APP_H
