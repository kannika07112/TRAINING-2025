// Movie Recommendation System (Sorting by Rating)`  
// `Scenario:`  
// A `movie streaming platform` sorts and suggests movies based on user ratings. The system should:  
// - Sort `movies based on ratings` (descending)  
// - Allow `linear search` for a movie by name  
// - Display `the top 3 movies`  

// `Operations Example:`  
// ```
// Movies: 
// [{"Title": "Movie A", "Rating": 8.5}, 
//  {"Title": "Movie B", "Rating": 9.2}, 
//  {"Title": "Movie C", "Rating": 7.8}]

// Sorted by Rating: Movie B (9.2), Movie A (8.5), Movie C (7.8)
// Search 'Movie A': Found (Rating: 8.5)

#include <stdio.h>
#include <string.h>

typedef struct {
    char title[50];
    float rating;
} Movie;

void bubbleSort(Movie* movies, int size);
void printMovies(Movie* movies, int size);
void swap(Movie* first, Movie* second);
int searchLinear(Movie* movies, int size, char* searchTitle);
void displayTopMovies(Movie* movies, int size, int topCount);

int main() {
    Movie movies[] = {
        {"Movie A", 8.5f},
        {"Movie B", 9.2f},
        {"Movie C", 7.8f}
    };
    int moviesCount = 3;
    char searchTitle[] = "Movie A";

    printf("Before Sort:\n");
    printMovies(movies, moviesCount);

    bubbleSort(movies, moviesCount);

    printf("After Sort:\n");
    printMovies(movies, moviesCount);

    int index = searchLinear(movies, moviesCount, searchTitle);
    if (index != -1) {
        printf("Search '%s': Found (Rating: %.1f)\n", searchTitle, movies[index].rating);
    } else {
        printf("Search '%s': Not Found\n", searchTitle);
    }

    displayTopMovies(movies, moviesCount, 3);

    return 0;
}

void printMovies(Movie* movies, int size) {
    for (int i = 0; i < size; i++) {
        printf("%s (Rating: %.1f)\n", movies[i].title, movies[i].rating);
    }
    printf("\n");
}

void swap(Movie* first, Movie* second) {
    Movie temp = *first;
    *first = *second;
    *second = temp;
}

void bubbleSort(Movie* movies, int size) {
    int isSwapped;
    do {
        isSwapped = 0;
        for (int i = 0; i < (size - 1); i++) {
            if (movies[i].rating < movies[i + 1].rating) {
                swap(&movies[i], &movies[i + 1]);
                isSwapped = 1;
            }
        }
        size--;
    } while (isSwapped);
}

int searchLinear(Movie* movies, int size, char* searchTitle) {
    for (int i = 0; i < size; i++) {
        if (strcmp(movies[i].title, searchTitle) == 0) {
            return i;
        }
    }
    return -1;
}

void displayTopMovies(Movie* movies, int size, int topCount) {
    printf("Top %d Movies:\n", topCount);
    for (int i = 0; i < topCount && i < size; i++) {
        printf("%s (Rating: %.1f)\n", movies[i].title, movies[i].rating);
    }
}
