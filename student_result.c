#include <stdio.h>

#define SUBJECTS 3

/* Using typedef for structures */
typedef struct {
    int sub[SUBJECTS];
} Marks;

/* Union to store either total OR percentage (memory optimization example) */
typedef union {
    int total;
    float percentage;
} Result;

/* Student details structure */
typedef struct {
    int roll;
    char name[20];
    Marks m;
    Result r;
} Student;

int main() {
    int n, i, j;

    /* Maximum marks for each subject */
    int maxMarks[SUBJECTS] = {100, 70, 80};
    int totalMax = 0;

    for (i = 0; i < SUBJECTS; i++) {
        totalMax += maxMarks[i];
    }

    printf("Enter the number of students: ");
    scanf("%d", &n);

    Student s[n];

    /* Input section */
    for (i = 0; i < n; i++) {
        printf("\nEnter details for student %d\n", i + 1);

        printf("Roll number: ");
        scanf("%d", &s[i].roll);

        printf("Name: ");
        scanf("%s", s[i].name);

        s[i].r.total = 0;

        for (j = 0; j < SUBJECTS; j++) {
            while (1) {
                printf("Enter marks for subject %d (0 to %d): ",
                       j + 1, maxMarks[j]);
                scanf("%d", &s[i].m.sub[j]);

                if (s[i].m.sub[j] >= 0 &&
                    s[i].m.sub[j] <= maxMarks[j]) {
                    break;
                } else {
                    printf("❌ Invalid marks! Enter again.\n");
                }
            }
            s[i].r.total += s[i].m.sub[j];
        }

        /* Overwriting union with percentage */
        s[i].r.percentage = (s[i].r.total / (float)totalMax) * 100;
    }

    /* Output section */
    printf("\n===== STUDENT RESULTS =====\n");

    for (i = 0; i < n; i++) {
        printf("\nStudent %d", i + 1);
        printf("\nName       : %s", s[i].name);
        printf("\nRoll No    : %d", s[i].roll);
        printf("\nPercentage : %.2f%%", s[i].r.percentage);

        if (s[i].r.percentage >= 90)
            printf("\nGrade      : A");
        else if (s[i].r.percentage >= 80)
            printf("\nGrade      : B");
        else if (s[i].r.percentage >= 70)
            printf("\nGrade      : C");
        else
            printf("\nGrade      : F");

        printf("\n----------------------------");
    }

    return 0;
}
