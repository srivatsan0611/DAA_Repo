#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MATCH_SCORE 2
#define GAP_SCORE -1
#define MAX_SEQ_LENGTH 10

int max(int a, int b, int c) {
    int max_val = a;
    if (b > max_val) {
        max_val = b;
    }
    if (c > max_val) {
        max_val = c;
    }
    return max_val;
}

void needleman_wunsch(char *seq1, char *seq2, int seq_len, int **score_mat, int **trace_mat, int *score) {
    // Initialize the score and trace matrices
    for (int i = 0; i <= seq_len; i++) {
        score_mat[i][0] = i * GAP_SCORE;
        trace_mat[i][0] = 1;
    }
    for (int j = 0; j <= seq_len; j++) {
        score_mat[0][j] = j * GAP_SCORE;
        trace_mat[0][j] = 2;
    }

    // Fill in the score and trace matrices
    for (int i = 1; i <= seq_len; i++) {
        for (int j = 1; j <= seq_len; j++) {
            int match_score = score_mat[i-1][j-1] + ((seq1[i-1] == seq2[j-1]) ? MATCH_SCORE : -MATCH_SCORE);
            int delete_score = score_mat[i-1][j] + GAP_SCORE;
            int insert_score = score_mat[i][j-1] + GAP_SCORE;
            score_mat[i][j] = max(match_score, delete_score, insert_score);
            if (score_mat[i][j] == match_score) {
                trace_mat[i][j] = 0;
            } else if (score_mat[i][j] == delete_score) {
                trace_mat[i][j] = 1;
            } else {
                trace_mat[i][j] = 2;
            }
        }
    }

    // Trace back the optimal alignment and compute the score
    int i = seq_len;
    int j = seq_len;
    *score = score_mat[i][j];
    while (i > 0 || j > 0) {
        if (trace_mat[i][j] == 0) {
            i--;
            j--;
        } else if (trace_mat[i][j] == 1) {
            i--;
        } else {
            j--;
        }
    }
}

int main() {
    char seq1[MAX_SEQ_LENGTH], seq2[MAX_SEQ_LENGTH];
    printf("Enter sequence 1: ");
    fgets(seq1, MAX_SEQ_LENGTH, stdin);
    seq1[strcspn(seq1, "\n")] = '\0'; // remove newline character

    printf("Enter sequence 2: ");
    fgets(seq2, MAX_SEQ_LENGTH, stdin);
    seq2[strcspn(seq2, "\n")] = '\0'; // remove newline character
    
    int seq_len = strlen(seq1);
    
    int **score_mat = (int **)malloc((seq_len+1) * sizeof(int *));
    int **trace_mat = (int **)malloc((seq_len+1) * sizeof(int *));
    for (int i = 0; i <= seq_len; i++) {
        score_mat[i] = (int *)malloc((seq_len+1) * sizeof(int));
        trace_mat[i] = (int *)malloc((seq_len+1) * sizeof(int));
    }
    int score;
    needleman_wunsch(seq1, seq2, seq_len, score_mat, trace_mat, &score);
    printf("Matching score: %d\n", score);

    // Trace back the optimal alignment and print the resulting sequences
    char *aligned_seq1 = (char *)malloc((2*seq_len+1));
    char *aligned_seq2 = (char *)malloc((2*seq_len+1) * sizeof(char));
    int i = seq_len;
    int j = seq_len;
    int k = 0;
    while (i > 0 || j > 0) {
        if (trace_mat[i][j] == 0) {
            aligned_seq1[k] = seq1[i-1];
            aligned_seq2[k] = seq2[j-1];
            i--;
            j--;
        } 
        else if (trace_mat[i][j] == 1) {
            aligned_seq1[k] = seq1[i-1];
            aligned_seq2[k] = '-';
            i--;
        } 
        else {
            aligned_seq1[k] = '-';
            aligned_seq2[k] = seq2[j-1];
            j--;
        }
        k++;
    }
    aligned_seq1[k] = '\0';
    aligned_seq2[k] = '\0';
    
    //Print Sequence 1
    printf("Aligned sequence 1 : ");
    for (int i = strlen(aligned_seq1)-1; i >= 0; i--) {
        printf("%c", aligned_seq1[i]);
    }
    printf("\n");
    
    // Print Sequence 2
    printf("Aligned sequence 2 : ");
    for (int i = strlen(aligned_seq2)-1; i >= 0; i--) {
        printf("%c", aligned_seq2[i]);
    }
    printf("\n");


    for (int i = 0; i <= seq_len; i++) {
        free(score_mat[i]);
        free(trace_mat[i]);
    }
    free(score_mat);
    free(trace_mat);
    free(aligned_seq1);
    free(aligned_seq2);

    return 0;
}

