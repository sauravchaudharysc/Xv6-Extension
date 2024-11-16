#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"
#define SLEEP_TIME 100

lock_t* lk;  // Declare the lock

// Function to be used in threads
void f1(void* arg1, void* arg2) {
  int num = *(int*)arg1;
  if (num) lock_acquire(lk);  // Acquire the lock if num is 1
  printf(1, "1. this should print %s\n", num ? "first" : "whenever");
  printf(1, "1. sleep for %d ticks\n", SLEEP_TIME);
  sleep(SLEEP_TIME);  // Simulate work
  if (num) lock_release(lk);  // Release the lock if num is 1
  exit();
}

void f2(void* arg1, void* arg2) {
  int num = *(int*)arg1;
  if (num) lock_acquire(lk);  // Acquire the lock if num is 1
  printf(1, "2. this should print %s\n", num ? "second" : "whenever");
  printf(1, "2. sleep for %d ticks\n", SLEEP_TIME);
  sleep(SLEEP_TIME);  // Simulate work
  if (num) lock_release(lk);  // Release the lock if num is 1
  exit();
}

void f3(void* arg1, void* arg2) {
  int num = *(int*)arg1;
  if (num) lock_acquire(lk);  // Acquire the lock if num is 1
  printf(1, "3. this should print %s\n", num ? "third" : "whenever");
  printf(1, "3. sleep for %d ticks\n", SLEEP_TIME);
  sleep(SLEEP_TIME);  // Simulate work
  if (num) lock_release(lk);  // Release the lock if num is 1
  exit();
}

int main(int argc, char *argv[]) {
  // Initialize the lock before use
  lock_init(lk);

  int arg1 = 1, arg2 = 1;  // Set arg1 to 1 to demonstrate lock-based sequential execution

  printf(1, "Below should be sequential print statements (lock acquired):\n");
  // Create threads and pass arguments
  thread_create(&f1, (void *)&arg1, (void *)&arg2);
  thread_create(&f2, (void *)&arg1, (void *)&arg2);
  thread_create(&f3, (void *)&arg1, (void *)&arg2);
  // Wait for all threads to complete
  thread_join();
  thread_join();
  thread_join();

  // Modify arg1 to 0 for parallel execution without lock
  arg1 = 0;
  printf(1, "Below should be a mess (no lock, threads run in parallel):\n");
  // Create threads with arg1 = 0 (no lock acquisition)
  thread_create(&f1, (void *)&arg1, (void *)&arg2);
  thread_create(&f2, (void *)&arg1, (void *)&arg2);
  thread_create(&f3, (void *)&arg1, (void *)&arg2);
  // Wait for all threads to complete
  thread_join();
  thread_join();
  thread_join();

  exit();
}
