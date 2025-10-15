#include <stdlib.h>
#include <stdio.h>
#include <semaphore.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>

int main() {
    shm_unlink("/table");
    sem_unlink("/empty");
    sem_unlink("/full");
    srand(time(NULL));
    sem_t* emp = sem_open("/empty", O_CREAT, S_IWUSR | S_IRUSR, 1);
    if (emp == SEM_FAILED) {
        printf("Semaphore Error\n");
        return 0;
    }
    sem_t* full = sem_open("/full", O_CREAT, S_IWUSR | S_IRUSR, 0);
    if (full == SEM_FAILED) {
        printf("Semaphore Error\n");
        return 0;
    }

    int fd = shm_open("/table", O_CREAT | O_RDWR, S_IWUSR | S_IRUSR);
    if (fd < 0) {
        printf("Error\n");
        return 0;
    }
    ftruncate(fd, 8);
    int* ptr = mmap(0, 8, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    int i = 0;
    while (i < 5) {
        sem_wait(emp);
        *ptr = rand() % 10;
        *(ptr + 1) = rand() % 10;

        printf("Producer Made: %d\n", *ptr);
        printf("Producer Made: %d\n", *(ptr + 1));

        sem_post(full);
        i++;
    }
}