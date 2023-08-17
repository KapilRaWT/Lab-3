#include <stdio.h>

#define NUM_TRAIN_CLASSES 3
#define NUM_SEATS 10

typedef struct {
    int availableSeats[NUM_SEATS];
} Train;

void initializeTrain(Train* train) {
    for (int i = 0; i < NUM_SEATS; i++) {
        train->availableSeats[i] = 1; // 1 indicates seat is available, 0 means booked
    }
}

void displayAvailableSeats(Train* train) {
    printf("Available seats: ");
    for (int i = 0; i < NUM_SEATS; i++) {
        if (train->availableSeats[i] == 1) {
            printf("%d ", i + 1); // Seat numbers start from 1
        }
    }
    printf("\n");
}

void bookSeat(Train* train, int seatNumber) {
    if (seatNumber < 1 || seatNumber > NUM_SEATS) {
        printf("Invalid seat number.\n");
        return;
    }

    if (train->availableSeats[seatNumber - 1] == 0) {
        printf("Seat %d is already booked.\n", seatNumber);
    } else {
        train->availableSeats[seatNumber - 1] = 0;
        printf("Seat %d booked successfully.\n", seatNumber);
    }
}

int main() {
    Train trains[NUM_TRAIN_CLASSES];
    for (int i = 0; i < NUM_TRAIN_CLASSES; i++) {
        initializeTrain(&trains[i]);
    }

    int choice, classChoice, seatNumber;

    while (1) {
        printf("\nRailway Reservation System\n");
        printf("1. Display available seats\n");
        printf("2. Book a seat\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Select train class (1-%d): ", NUM_TRAIN_CLASSES);
                scanf("%d", &classChoice);
                if (classChoice < 1 || classChoice > NUM_TRAIN_CLASSES) {
                    printf("Invalid choice.\n");
                    continue;
                }
                displayAvailableSeats(&trains[classChoice - 1]);
                break;

            case 2:
                printf("Select train class (1-%d): ", NUM_TRAIN_CLASSES);
                scanf("%d", &classChoice);
                if (classChoice < 1 || classChoice > NUM_TRAIN_CLASSES) {
                    printf("Invalid choice.\n");
                    continue;
                }
                displayAvailableSeats(&trains[classChoice - 1]);
                printf("Enter seat number to book: ");
                scanf("%d", &seatNumber);
                bookSeat(&trains[classChoice - 1], seatNumber);
                break;

            case 3:
                printf("Exiting the program.\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

