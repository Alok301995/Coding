#include <stdio.h>

void antiClockWise(int *matrix[], int N, int M, int layer, int numRotation)
{
    int i = layer - 1;

    for (int rotation = 0; rotation < numRotation; rotation++)
    {
        for (int j = i; j < N - i - 1; j++)
        {
            int tmp = matrix[i][j];
            matrix[i][j] = matrix[i][j + 1];
            matrix[i][j + 1] = tmp;
        }
        for (int j = i; j < M - i - 1; j++)
        {
            int tmp = matrix[j][N - i - 1];
            matrix[j][N - i - 1] = matrix[j + 1][N - i - 1];
            matrix[j + 1][N - i - 1] = tmp;
        }
        for (int j = N - i - 1; j > i; j--)
        {
            int tmp = matrix[M - i - 1][j];
            matrix[M - i - 1][j] = matrix[M - i - 1][j - 1];
            matrix[M - i - 1][j - 1] = tmp;
        }
        for (int j = M - i - 1; j > i + 1; j--)
        {
            int tmp = matrix[j][i];
            matrix[j][i] = matrix[j - 1][i];
            matrix[j - 1][i] = tmp;
        }
    }
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void clockWise(int *matrix[], int N, int M, int layer, int numRotation)
{
    int i = layer - 1;
    for (int rotation = 0; rotation < numRotation; rotation++)
    {
        for (int j = i; j < N - i - 1; j++)
        {
            int tmp = matrix[i][j + 1];
            matrix[i][j + 1] = matrix[i][j];
            matrix[i][j + 1] = tmp;
        }
        for (int j = i; j < M - i - 1; j++)
        {
            int tmp = matrix[j + 1][N - i - 1];
            matrix[j + 1][N - i - 1] = matrix[j][N - i - 1];
            matrix[j][N - i - 1] = tmp;
        }
        for (int j = N - i - 1; j > i; j--)
        {
            int tmp = matrix[M - i - 1][j + 1];
            matrix[M - i - 1][j + 1] = matrix[M - i - 1][j];
            matrix[M - i - 1][j] = tmp;
        }
        for (int j = M - i - 1; j > i + 1; j--)
        {
            int tmp = matrix[j - 1][i];
            matrix[j - 1][i] = matrix[j][i];
            matrix[j][i] = tmp;
        }
    }
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int M, N, layer, numRotation;
    char ch;
    scanf("%d %d", &M, &N);
    int **matrix = new int *[M];
    for (int i = 0; i < M; i++)
    {
        matrix[i] = new int[N];
        for (int j = 0; j < N; j++)
        {
            scanf("%d", matrix[i][j]);
        }
    }
    scanf("%c %d %d", &ch, &numRotation, &layer);
    switch (ch)
    {
    case 'A':
        antiClockWise(matrix, N, M, layer, numRotation);
        break;
    case 'C':
        clockWise(matrix, N, M, layer, numRotation);
        break;
    default:
        break;
    }

    return 0;
}