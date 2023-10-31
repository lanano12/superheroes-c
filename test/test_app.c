#include "unity.h"
#include "app.h"  // Ensure you're including the correct header
#include <stdio.h>

void setUp(void) {}
void tearDown(void) {}

// Test for read_csv function
void test_read_csv_should_ParseValidCsvCorrectly(void) {
    printf("\nTest: Reading and parsing a valid CSV file...\n");    
    FILE *test_file = fopen("test_data.csv", "w");
    if (test_file == NULL) {
        TEST_FAIL_MESSAGE("Failed to open test_data.csv for writing.");
    }

    fprintf(test_file, "Header\n"); // Write the header
    fprintf(test_file, "Hero1,45,Villain1,50\n");
    fprintf(test_file, "Hero2,60,Villain2,55\n");
    fclose(test_file);

    Battle battles[10];

    test_file = fopen("test_data.csv", "r");
    if (test_file == NULL) {
        TEST_FAIL_MESSAGE("Failed to open test_data.csv for reading.");
    }

    int count = read_csv(test_file, battles, 10);
    fclose(test_file);

    TEST_ASSERT_EQUAL(2, count);
    TEST_ASSERT_EQUAL_STRING("Hero1", battles[0].hero_name);
    TEST_ASSERT_EQUAL_FLOAT(45, battles[0].hero_score);
    TEST_ASSERT_EQUAL_STRING("Villain1", battles[0].villain_name);
    TEST_ASSERT_EQUAL_FLOAT(50, battles[0].villain_score);

    TEST_ASSERT_EQUAL_STRING("Hero2", battles[1].hero_name);
    TEST_ASSERT_EQUAL_FLOAT(60, battles[1].hero_score);
    TEST_ASSERT_EQUAL_STRING("Villain2", battles[1].villain_name);
    TEST_ASSERT_EQUAL_FLOAT(55, battles[1].villain_score);
}


// Test for calculate_winners function
void test_calculate_winners_should_IdentifyCorrectWinners(void) {
    printf("\nTest: Calculating winners for valid battles...\n");
    Battle battles[] = {
        {"Hero1", 45, "Villain1", 50},
        {"Hero2", 60, "Villain2", 55}
    };
    
    // Redirect stdout to a temporary file
    FILE *original_stdout = stdout;
    FILE *temp_file = tmpfile();
    if (!temp_file) {
        TEST_FAIL_MESSAGE("Failed to create temporary file.");
    }
    stdout = temp_file;

    calculate_winners(battles, 2);

    // Reset stdout to its original state
    stdout = original_stdout;

    // Read the contents of the temporary file to check the output
    rewind(temp_file);  // set file position to the beginning

    char output_line[MAX_LINE_LEN];
    fgets(output_line, sizeof(output_line), temp_file);
    TEST_ASSERT_EQUAL_STRING("Battle between Hero1 (score: 45.00) and Villain1 (score: 50.00): Winner is Villain1 due to higher score.\n", output_line);

    fgets(output_line, sizeof(output_line), temp_file);
    TEST_ASSERT_EQUAL_STRING("Battle between Hero2 (score: 60.00) and Villain2 (score: 55.00): Winner is Hero2 due to higher score.\n", output_line);

    fclose(temp_file);
}

// Test read_csv with an empty CSV
void test_read_csv_should_HandleEmptyCsv(void) {
    printf("\nTest: Reading an empty CSV file...\n");
    FILE *test_file = fopen("test_empty_data.csv", "w");
    if (test_file == NULL) {
        TEST_FAIL_MESSAGE("Failed to open test_empty_data.csv for writing.");
    }
    fclose(test_file);

    Battle battles[10];

    test_file = fopen("test_empty_data.csv", "r");
    if (test_file == NULL) {
        TEST_FAIL_MESSAGE("Failed to open test_empty_data.csv for reading.");
    }

    int count = read_csv(test_file, battles, 10);
    fclose(test_file);

    TEST_ASSERT_EQUAL(0, count);
}

// Test read_csv with more battles than the array can handle
void test_read_csv_should_HandleArrayOverflow(void) {
    printf("\nTest: Reading CSV with more battles than the array can handle...\n");
    FILE *test_file = fopen("test_overflow_data.csv", "w");
    if (test_file == NULL) {
        TEST_FAIL_MESSAGE("Failed to open test_overflow_data.csv for writing.");
    }
    fprintf(test_file, "Header\n");
    for (int i = 0; i < 12; i++) {
        fprintf(test_file, "Hero%d,45,Villain%d,50\n", i, i);
    }
    fclose(test_file);

    Battle battles[10];

    test_file = fopen("test_overflow_data.csv", "r");
    if (test_file == NULL) {
        TEST_FAIL_MESSAGE("Failed to open test_overflow_data.csv for reading.");
    }

    int count = read_csv(test_file, battles, 10);
    fclose(test_file);

    TEST_ASSERT_EQUAL(10, count); // We should only be able to read 10 battles, even if there are 12
}

// Test for invalid CSV format (e.g., missing fields, wrong delimiter, etc.)
void test_read_csv_should_HandleInvalidCsvFormat(void) {
    printf("\nTest: Reading CSV with invalid format...\n");
    FILE *test_file = fopen("test_invalid_data.csv", "w");
    if (test_file == NULL) {
        TEST_FAIL_MESSAGE("Failed to open test_invalid_data.csv for writing.");
    }
    fprintf(test_file, "Header\n");
    fprintf(test_file, "Hero1|45|Villain1|50\n"); // Using | instead of , as delimiter
    fclose(test_file);

    Battle battles[10];

    test_file = fopen("test_invalid_data.csv", "r");
    if (test_file == NULL) {
        TEST_FAIL_MESSAGE("Failed to open test_invalid_data.csv for reading.");
    }

    int count = read_csv(test_file, battles, 10);
    fclose(test_file);

    TEST_ASSERT_EQUAL(0, count); // Invalid lines should be skipped
}

// Test calculate_winners with no battles
void test_calculate_winners_should_HandleNoBattles(void) {
    printf("\nTest: Calculating winners with no battles...\n");
    Battle battles[10];
    calculate_winners(battles, 0);
    // Since there are no battles, calculate_winners shouldn't print anything or crash
}

void test_calculate_winners_should_HandleScoreDraw(void) {
    printf("\nTest: Calculating winners when there's a score draw...\n");

    Battle battles[] = {
        {"HeroDraw", 50, "VillainDraw", 50}
    };
    
    // Redirect stdout to a temporary file
    FILE *original_stdout = stdout;
    FILE *temp_file = tmpfile();
    if (!temp_file) {
        TEST_FAIL_MESSAGE("Failed to create temporary file.");
    }
    stdout = temp_file;

    calculate_winners(battles, 1);

    // Reset stdout to its original state
    stdout = original_stdout;

    // Read the contents of the temporary file to check the output
    rewind(temp_file);  // set file position to the beginning

    char output_line[MAX_LINE_LEN];
    fgets(output_line, sizeof(output_line), temp_file);
    TEST_ASSERT_EQUAL_STRING("Battle between HeroDraw (score: 50.00) and VillainDraw (score: 50.00): Draw, as both have equal scores.\n", output_line);

    fclose(temp_file);
}
