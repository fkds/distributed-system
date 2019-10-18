#include <stdio.h>
#include <pthread.h>
#include <stdatomic.h>
#define N 1000
#define M 5


void *f(void *args) {
    int *value = args;
    for (int i = 0; i < N; i++)
        atomic_fetch_add(value, 1);
}

int main() {
    int value;
    pthread_t ids[M];
    for (int i = 0; i < M; i++)
        pthread_create(ids + i, NULL, &f, &value);
    for (int i = 0; i < M; i++)
        pthread_join(ids[i], NULL);
    printf("%d\n", value);
    return 0;
}
