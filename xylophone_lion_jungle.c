// Program to find the best communities for the sustainable schools project

#include <stdio.h>
#include <stdlib.h>


// Structure to store community data
typedef struct {
    int population; // Population of the community
    float sunlight; // Amount of sunlight per year, in hours
    float temperature; // Average temperature of the community, in degrees Celsius
    int housing; // Number of housing available
    int education; // Number of schools in the community
    int jobs; // Number of jobs available to residents
    float commute; // Average commute time for residents, in minutes
    int pollution; // Level of air pollution 
    int recreation; // Number of recreation facilities available
} community_t;


// Function to initialize a given community data structure
void init_community(community_t * community) {
    community->population = 0;
    community->sunlight = 0;
    community->temperature = 0;
    community->housing = 0;
    community->education = 0;
    community->jobs = 0;
    community->commute = 0;
    community->pollution = 0;
    community->recreation = 0;
}


// Function to print the contents of a given community data structure
void print_community(community_t * community) {
    printf("Population: %d\n", community->population);
    printf("Sunlight: %.2f\n", community->sunlight);
    printf("Temperature: %.2f\n", community->temperature);
    printf("Housing: %d\n", community->housing);
    printf("Education: %d\n", community->education);
    printf("Jobs: %d\n", community->jobs);
    printf("Commute: %.2f\n", community->commute);
    printf("Pollution: %d\n", community->pollution);
    printf("Recreation: %d\n\n", community->recreation);
}


// Function to read data from a file into an array of community data structures
int read_communities(community_t * communities, char * filename) {
    FILE * fp;
    int num_communities = 0; // Keeps track of how many communities were read

    // Open the file
    fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file!\n");
        exit(EXIT_FAILURE);
    }

    // Read data from file into array
    while (fscanf(fp, "%d,%f,%f,%d,%d,%d,%f,%d,%d\n", 
            &communities[num_communities].population, 
            &communities[num_communities].sunlight,
            &communities[num_communities].temperature,
            &communities[num_communities].housing,
            &communities[num_communities].education,
            &communities[num_communities].jobs,
            &communities[num_communities].commute,
            &communities[num_communities].pollution,
            &communities[num_communities].recreation) == 9) {
        num_communities++;
    }

    // Close the file
    fclose(fp);

    return num_communities;
}


// Function to compute the sustainability score of a given community
float compute_score(community_t * community) {
    float score = 0;

    // Add scores for population size, sunlight, temperature, and housing
    if (community->population > 0)
        score += 5 - (community->population / 100000.0);
    if (community->sunlight > 0)
        score += community->sunlight / 3;
    if (community->temperature > 0 && community->temperature < 35)
        score += (35 - community->temperature) / 3;
    if (community->housing > 0)
        score += community->housing / 10;
    
    // Deduct scores for education, jobs, commute, pollution, and recreation
    if (community->education > 0)
        score -= community->education / 10;
    if (community->jobs > 0)
        score -= community->jobs / 10;
    if (community->commute > 0)
        score -= community->commute / 10;
    if (community->pollution > 0)
        score -= community->pollution / 10;
    if (community->recreation > 0)
        score -= community->recreation / 10;

    return score;
}


// Function to find the most suitable community for the sustainable schools project
community_t * find_best_community(community_t * communities, int num_communities) {
    community_t * best_community = NULL;
    float best_score = 0;

    // Iterate through all communities and find the one with the highest score
    for (int i = 0; i < num_communities; i++) {
        float score = compute_score(&communities[i]);
        if (score > best_score) {
            best_community = &communities[i];
            best_score = score;
        }
    }

    // Return a pointer to the best community
    return best_community;
}


int main() {
    // Read data from file into a community structure
    community_t communities[100];
    int num_communities = read_communities(communities, "data.txt");

    // Find the best community for the sustainable schools project
    community_t * best_community = find_best_community(communities, num_communities);
    if (best_community != NULL) {
        // Print the best community
        printf("The best community for the sustainable schools project is:\n");
        print_community(best_community);
    }
    else {
        printf("No suitable community was found.\n");
    }

    return 0;
}