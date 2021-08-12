#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct Person{
    int index;
    char name[25];
    char surname[25];
    char telephoneNumber[12];
};
void displayMenu();
void printDirectory(struct Person*);
void addPersonToDirectory(struct Person*);
void saveToFile(struct Person*);
void readFromFile(struct Person*);
void searchPerson(struct Person*);
void updatePerson(struct Person*);

int main(){
    int choiceOfUser;
    int flag = 0;

    struct Person directory[50];
    directory[0].index = -1;
    readFromFile(directory);

    while(flag == 0){
        displayMenu();
        scanf("%d", &choiceOfUser);

        switch(choiceOfUser){
        case 1:
            printDirectory(directory);
            break;
        case 2:
            addPersonToDirectory(directory);
            break;
        case 3:
            searchPerson(directory);
            break;
        case 4:
            updatePerson(directory);
            break;
        case 9:
            flag = 1;
            saveToFile(directory);
            printf("Press any key to exit");
            break;
        default:
            printf("You made a wrong choice!");
        }
        getch();
    }
    return 0;
}
void readFromFile(struct Person *directory){
    FILE *targetFile = fopen("telephoneDirectory.txt", "r+");
    if(targetFile == NULL)
        return;
    int counter;
    for(counter = 0; counter<50; counter++){
        fscanf(targetFile, "%d %s %s %s\n", &(directory[counter].index), directory[counter].name, directory[counter].surname, directory[counter].telephoneNumber);
        if(feof(targetFile))
            break;
    }
    directory[counter+1].index = -1;
}
void saveToFile(struct Person *directory){
    FILE *targetFile = fopen("telephoneDirectory.txt", "w+");

    int counter;
    for(counter = 0; counter < 50; counter++){
        if(directory[counter].index == -1)
            break;
        fprintf(targetFile, "%d %s %s %s\n", directory[counter].index, directory[counter].name, directory[counter].surname, directory[counter].telephoneNumber);
    }
    fclose(targetFile);
}
void printDirectory(struct Person *directory){
    int counter;
    for(counter = 0; counter < 50; counter++){
        if(directory[counter].index == -1)
            break;
        printf("%d- %6s %6s %6s\n", directory[counter].index, directory[counter].name, directory[counter].surname, directory[counter].telephoneNumber);

    }
}
void addPersonToDirectory(struct Person *directory){
    int counter;
    for(counter = 0; counter<50; counter++){
        if(directory[counter].index == -1)
            break;
    }
    printf("Index: ");
    scanf("%d", &(directory[counter].index));
    printf("Person's name: ");
    scanf("%s", directory[counter].name);
    printf("Person's surname: ");
    scanf("%s", directory[counter].surname);
    printf("Telephone Number: ");
    scanf("%s", directory[counter].telephoneNumber);

    directory[counter+1].index = -1;

    printf("The person successfully added!");
}
void searchPerson(struct Person *directory){
    FILE *targetFile=fopen("telephoneDirectory.txt","r");
    int counter;
    char personName[25];
    printf("Enter the name of the person you want to search: ");
    scanf("%s",personName);
    for(counter = 0; counter<50; counter++){
        if(directory[counter].index == -1)
            break;
        fscanf(targetFile,"%d %s %s %s",&directory->index, directory->name,directory->surname, directory->telephoneNumber);
        if(strcmp(directory->name,personName)==0){
            printf("%d- %s %s %s\n" , directory->index, directory->name, directory->surname,directory->telephoneNumber);
        }
    }

    fclose(targetFile);
}
void updatePerson(struct Person *directory){
    FILE *targetFile=fopen("telephoneDirectory.txt","w");
    char personName[25];
    char newName[25];
    char newSurname[25];
    char newTelephoneNumber[25];
    int counter;
    printf("Enter the name of the person you want to update: ");
    scanf("%s",personName);

    for(counter = 0; counter<50; counter++){
        if(directory[counter].index == -1)
            break;
        fscanf(targetFile,"%d %s %s %s",&directory[counter].index, directory[counter].name,directory[counter].surname, directory[counter].telephoneNumber);
        if(strcmp(directory[counter].name,personName)==0){
            printf("Enter a new name for the person you want to update: ");
            scanf("%s",newName);
            printf("Enter a new surname for the person you want to update: ");
            scanf("%s",newSurname);
            printf("Enter a new telephone number for the person you want to update: ");
            scanf("%s",newTelephoneNumber);
            strcpy(directory[counter].name, newName);
            strcpy(directory[counter].surname, newSurname);
            strcpy(directory[counter].telephoneNumber, newTelephoneNumber);
            fprintf(targetFile, "%d %s %s %s\n", directory[counter].index, directory[counter].name, directory[counter].surname, directory[counter].telephoneNumber);
            printf("Current informations of the person : %d- %s %s %s\n" , directory[counter].index, directory[counter].name, directory[counter].surname,directory[counter].telephoneNumber);
        }
    }
    directory[counter+1].index = -1;

    fclose(targetFile);

}
void displayMenu(){
    system("cls");
    printf("TELEPHONE NUMBER DIRECTORY\n");
    printf("-------------------------------\n\n");
    printf("1- Show all contacts\n");
    printf("2- Add person to the directory\n");
    printf("3- Search Person\n");
    printf("4- Update Person\n");
    printf("9- Finish the program\n");
    printf("Enter your choice: \n");
}
