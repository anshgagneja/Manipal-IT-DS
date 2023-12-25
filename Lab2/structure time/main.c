#include <stdio.h>

// Define the time structure
struct Time {
    int hour;
    int min;
    int sec;
};

// Function to add two time objects
struct Time addTime(struct Time t1, struct Time t2) {
    struct Time result;
    int carry = 0;

    result.sec = t1.sec + t2.sec;
    if (result.sec >= 60) {
        result.sec -= 60;
        carry = 1;
    }

    result.min = t1.min + t2.min + carry;
    carry = 0;
    if (result.min >= 60) {
        result.min -= 60;
        carry = 1;
    }

    result.hour = t1.hour + t2.hour + carry;
    if (result.hour >= 24) {
        result.hour -= 24;
    }

    return result;
}

// Function to find the difference between two time objects
struct Time findDifference(struct Time t1, struct Time t2) {
    struct Time result;

    result.sec = t1.sec - t2.sec;
    if (result.sec < 0) {
        result.sec += 60;
        t1.min--;
    }

    result.min = t1.min - t2.min;
    if (result.min < 0) {
        result.min += 60;
        t1.hour--;
    }

    result.hour = t1.hour - t2.hour;
    if (result.hour < 0) {
        result.hour += 24;
    }

    return result;
}

// Function to read a time object from the user
struct Time readTime() {
    struct Time t;
    printf("Enter time (hh:mm:ss): ");
    scanf("%d:%d:%d", &t.hour, &t.min, &t.sec);
    return t;
}

// Function to display a time object
void displayTime(struct Time t) {
    printf("Time: %02d:%02d:%02d\n", t.hour, t.min, t.sec);
}

int main() {
    struct Time time1, time2, sum, difference;

    printf("Enter the first time:\n");
    time1 = readTime();

    printf("Enter the second time:\n");
    time2 = readTime();

    // Add the times
    sum = addTime(time1, time2);
    printf("Sum of times:\n");
    displayTime(sum);

    // Find the difference between times
    difference = findDifference(time1, time2);
    printf("Difference between times:\n");
    displayTime(difference);

    return 0;
}
