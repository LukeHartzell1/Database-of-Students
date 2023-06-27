#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
	char* name;
	char* id;
	double gpa;
	int creditHours;
} Student;

typedef struct StudentNode{
	Student* pStudent;
	struct StudentNode* pNext;
} StudentNode;

typedef struct {
	StudentNode* pIDList;
	StudentNode* pHonorRollList;
	StudentNode* pAcademicProbationList;
	StudentNode* pFreshmanList;
	StudentNode* pSophomoreList;
	StudentNode* pJuniorList;
	StudentNode* pSeniorList;
} Database;

Database* createDatabase() {
    Database* db = malloc(sizeof(Database));
    db->pIDList = NULL;
    db->pHonorRollList = NULL;
    db->pAcademicProbationList = NULL;
    db->pFreshmanList = NULL;
    db->pSophomoreList = NULL;
    db->pJuniorList = NULL;
    db->pSeniorList = NULL;
    return db;
}

void freeDatabase(Database* db) {
    StudentNode* current;

    // Free the memory used by each student in the ID list
    

    // Free the memory used by each student in the honor roll list
    current = db->pHonorRollList;
    while (current != NULL) {
        //free(current->pStudent->name);
       // free(current->pStudent->id);
        //free(current->pStudent);
        StudentNode* next = current->pNext;
        free(current);
        current = next;
    }

    // Free the memory used by each student in the academic probation list
    current = db->pAcademicProbationList;
    while (current != NULL) {
        //free(current->pStudent->name);
       //free(current->pStudent->id);
        //free(current->pStudent);
        StudentNode* next = current->pNext;
        free(current);
        current = next;
    }

    // Free the memory used by each student in the freshman list
    current = db->pFreshmanList;
    while (current != NULL) {
       // free(current->pStudent->name);
       // free(current->pStudent->id);
       // free(current->pStudent);
        StudentNode* next = current->pNext;
        free(current);
        current = next;
    }

    // Free the memory used by each student in the sophomore list
    current = db->pSophomoreList;
    while (current != NULL) {
       // free(current->pStudent->name);
       // free(current->pStudent->id);
        //free(current->pStudent);
        StudentNode* next = current->pNext;
        free(current);
        current = next;
    }

    // Free the memory used by each student in the junior list
    current = db->pJuniorList;
    while (current != NULL) {
       // free(current->pStudent->name);
       // free(current->pStudent->id);
       // free(current->pStudent);
        StudentNode* next = current->pNext;
        free(current);
        current = next;
    }

    // Free the memory used by each student in the senior list
    current = db->pSeniorList;
    while (current != NULL) {
       // free(current->pStudent->name);
       // free(current->pStudent->id);
       // free(current->pStudent);
        StudentNode* next = current->pNext;
        free(current);
        current = next;
    }
  current = db->pIDList;
    while (current != NULL) {
        free(current->pStudent->name);
        free(current->pStudent->id);
        free(current->pStudent);
        StudentNode* next = current->pNext;
        free(current);
        current = next;
    }

    // Free the memory used by the database struct itself
    free(db);
}

void displayStudentInfo(Student* student) {
    if(student == NULL){
      //printf("There are no students matching that criteria.\n");
      return;
    }
    else{
    printf("%s: \n", student->name);
    printf("\tID - %s\n", student->id);
    printf("\tGPA - %.2f\n", student->gpa);
    printf("\tCredit Hours - %d\n", student->creditHours);
    }
}

void insertStudentByID(Database* database, StudentNode* studentNode) {
    // If the list is empty, add the student to the head of the list
    if (database->pIDList == NULL) {
        database->pIDList = studentNode;
        return;
    }

    // Find the position to insert the new student based on their ID
    StudentNode* currentNode = database->pIDList;
   // currentNode->pStudent->id = NULL;
    StudentNode* prevNode = NULL;
    while (currentNode != NULL && strcmp(studentNode->pStudent->id, currentNode->pStudent->id) >= 0) {
        prevNode = currentNode;
        currentNode = currentNode->pNext;
    }

    // Insert the new student into the list
    studentNode->pNext = currentNode;
    if (prevNode == NULL) {
        database->pIDList = studentNode;
    } else {
        prevNode->pNext = studentNode;
    }
}

void insertStudentByName(Student* student, StudentNode** studentList) {
    // If the list is empty, add the student to the head of the list
    if (*studentList == NULL) {
        StudentNode* newNode = (StudentNode*) malloc(sizeof(StudentNode));
        newNode->pStudent = student;
        newNode->pNext = NULL;
        *studentList = newNode;
        return;
    }
    
    // Find the position to insert the new student based on their name
    StudentNode* currentNode = *studentList;
    StudentNode* prevNode = NULL;
    while (currentNode != NULL && strcmp(student->name, currentNode->pStudent->name) > 0) {
        prevNode = currentNode;
        currentNode = currentNode->pNext;
    }
    
    // Create a new node for the student and insert it into the list
    StudentNode* newNode = (StudentNode*) malloc(sizeof(StudentNode));
    newNode->pStudent = student;
    newNode->pNext = currentNode;
    
    if (prevNode == NULL) {
        // Insert at the head of the list
        *studentList = newNode;
    } else {
        // Insert in the middle or at the end of the list
        prevNode->pNext = newNode;
    }
}

void insertStudentByGPA(Student* student, StudentNode** studentList) {
    // If the list is empty, add the student to the head of the list
    if (*studentList == NULL) {
        StudentNode* newNode = (StudentNode*) malloc(sizeof(StudentNode));
        newNode->pStudent = student;
        newNode->pNext = NULL;
        *studentList = newNode;
        return;
    }
    
    // Find the position to insert the new student based on their GPA
    StudentNode* currentNode = *studentList;
    StudentNode* prevNode = NULL;
    while (currentNode != NULL && student->gpa > currentNode->pStudent->gpa) {
        prevNode = currentNode;
        currentNode = currentNode->pNext;
    }
    
    // Create a new node for the student and insert it into the list
    StudentNode* newNode = (StudentNode*) malloc(sizeof(StudentNode));
    newNode->pStudent = student;
    newNode->pNext = currentNode;
    
    if (prevNode == NULL) {
        // Insert at the head of the list
        *studentList = newNode;
    } else {
        // Insert in the middle or at the end of the list
        prevNode->pNext = newNode;
    }
}

void displayStudentList(StudentNode* studentList, bool displayFullList) {
  if(studentList == NULL){
      printf("There are no students matching that criteria.\n");
      return;  
  }
  StudentNode* currentNode = studentList;
    int counter = 0;
    while (currentNode != NULL) {
        if (displayFullList || counter < 10) {
            displayStudentInfo(currentNode->pStudent);
            //printf("\n");
        }
        currentNode = currentNode->pNext;
        counter++;
    }
}

void removeStudentFromList(Student* pStudent, StudentNode** ppList) {
    StudentNode* pCurrent = *ppList;
    StudentNode* pPrevious = NULL;

    while (pCurrent != NULL) {
        if (pCurrent->pStudent == pStudent) {
            if (pPrevious == NULL) {
                *ppList = pCurrent->pNext;
            } else {
                pPrevious->pNext = pCurrent->pNext;
            }
            free(pCurrent);
            break;
        }
        pPrevious = pCurrent;
        pCurrent = pCurrent->pNext;
    }
}

Student* searchForStudent(char* id, Database* database) {
// Search for the student in the ID list
    StudentNode* currentNode = database->pIDList;
    StudentNode* prevNode = NULL;
    while (currentNode != NULL && strcmp(currentNode->pStudent->id, id) != 0) {
        prevNode = currentNode;
        currentNode = currentNode->pNext;
    }
  if (currentNode == NULL) {
        printf("Sorry, there is no student in the database with the id %s.\n", id);
        return NULL;
    }
  return currentNode->pStudent;
}

// Student* searchForStudentTwo(char* id, Database* database) {
// // Search for the student in the ID list
//     StudentNode* currentNode = database->pIDList;
//     StudentNode* prevNode = NULL;
//     while (currentNode != NULL && strcmp(currentNode->pStudent->id, id) != 0) {
//         prevNode = currentNode;
//         currentNode = currentNode->pNext;
//     }
//   if (currentNode == NULL) {
//        // printf("Sorry, there is no student in the database with the id %s.\n", id);
//         return NULL;
//     }
//   return currentNode->pStudent;
// }

void deleteStudent(char* id, Database* database) {
    // Search for the student in the ID list
    StudentNode* currentNode = database->pIDList;
    StudentNode* prevNode = NULL;
    while (currentNode != NULL && strcmp(currentNode->pStudent->id, id) != 0) {
        prevNode = currentNode;
        currentNode = currentNode->pNext;
    }
    
    // If the student is not found, print an error message and return
    if (currentNode == NULL) {
        printf("Sorry, there is no student in the database with the id %s.\n", id);
        return;
    }
 
  
    // Remove the student from all the other linked lists in the database
    Student* student = currentNode->pStudent;
    removeStudentFromList(student, &(database->pHonorRollList));
    removeStudentFromList(student, &(database->pAcademicProbationList));
    removeStudentFromList(student, &(database->pFreshmanList));
    removeStudentFromList(student, &(database->pSophomoreList));
    removeStudentFromList(student, &(database->pJuniorList));
    removeStudentFromList(student, &(database->pSeniorList));
    
    // Remove the student from the ID list
    if (prevNode == NULL) {
        // Removing the head of the list
        database->pIDList = currentNode->pNext;
    } else {
        prevNode->pNext = currentNode->pNext;
    }
    
    // Free the memory associated with the removed student
    free(currentNode->pStudent->name);
    free(currentNode->pStudent->id);
    free(currentNode->pStudent);
    free(currentNode);
}

void insertStudentAppropriately(StudentNode* newStudentNode, Database* pDatabase){
  double gpa = newStudentNode->pStudent->gpa;
  int creditHours = newStudentNode->pStudent->creditHours;
  // Insert new student into the ID list
  //if(searchForStudentTwo(newStudentNode->pStudent->id, pDatabase) != NULL){ //NEW
    //      return; //NEW
     //   } //NEW
    insertStudentByID(pDatabase, newStudentNode);

    // Insert new student into the appropriate GPA list
    if (gpa >= 3.5) {
        insertStudentByGPA(newStudentNode->pStudent, &pDatabase->pHonorRollList);
    } else if (gpa < 2.0) {
        insertStudentByGPA(newStudentNode->pStudent, &pDatabase->pAcademicProbationList);
    }

    // Insert new student into the appropriate year list
    if (creditHours >= 0 && creditHours < 30) {
        insertStudentByName(newStudentNode->pStudent, &pDatabase->pFreshmanList);
    } else if (creditHours >= 30 && creditHours < 60) {
        insertStudentByName(newStudentNode->pStudent, &pDatabase->pSophomoreList);
    } else if (creditHours >= 60 && creditHours < 90) {
        insertStudentByName(newStudentNode->pStudent, &pDatabase->pJuniorList);
    } else if (creditHours >= 90) {
        insertStudentByName(newStudentNode->pStudent, &pDatabase->pSeniorList);
    }
}

void readAndUseFile(Database* pDatabase, char* filename) {
  char garbage[1000];  
  FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        return;
    }
  
    fgets(garbage, 1000, fp); //gets rid of first line (header line)
    char line[1024];
    while (fgets(line, 1024, fp)) {
      // remove newline character if present
        char* newline = strchr(line, '\n');
        if (newline != NULL) {
            *newline = '\0';
        }
      
        // parse line into student data
        char* name = strtok(line, ",");
        char* id = strtok(NULL, ",");
        char* gpa_str = strtok(NULL, ",");
        char* credit_hours_str = strtok(NULL, ",");

        // check for null values before converting to double/int
        if (name == NULL || id == NULL || gpa_str == NULL || credit_hours_str == NULL) {
            return;
        }

      
        // convert gpa and credit hours to double and int respectively
        double gpa = atof(gpa_str);
        int credit_hours = atoi(credit_hours_str);

        // create new StudentNode and Student
        Student* pStudent = malloc(sizeof(Student));
        pStudent->name = strdup(name);
        pStudent->id = strdup(id);
        pStudent->gpa = gpa;
        pStudent->creditHours = credit_hours;

   //     if(searchForStudentTwo(id, pDatabase) != NULL){ //NEW
   //       continue; //NEW
   //     } //NEW
   //     else{ //NEW
        StudentNode* pNewStudentNode = malloc(sizeof(StudentNode));
        pNewStudentNode->pStudent = pStudent;
        pNewStudentNode->pNext = NULL;
        // insert new student into database
        insertStudentAppropriately(pNewStudentNode, pDatabase);
    //    } //NEW  
    }

    fclose(fp);
}

void createStudent(Database* pDatabase) {
    // Prompt user to enter student information
    char* name = malloc(sizeof(char) * 1000);
    char* id = malloc(sizeof(char) * 1000);
    double gpa;
    int creditHours;
    char garbage[100];

    printf("Enter the name of the new student: ");
    fgets(garbage, 100, stdin); //gets rid of any blank space
    fgets(name, 100, stdin);
    name[strcspn(name, "\n")] = 0;

    printf("Enter the ID of the new student: ");
    scanf(" %s", id);

    printf("Enter the GPA of the new student: ");
    scanf(" %lf", &gpa);

    printf("Enter the credit hours of the new student: ");
    scanf(" %d", &creditHours);

    // Create new student node and populate with data
    StudentNode* newStudentNode = malloc(sizeof(StudentNode));
    newStudentNode->pStudent = malloc(sizeof(Student));
    newStudentNode->pStudent->name = name;
    newStudentNode->pStudent->id = id;
    newStudentNode->pStudent->gpa = gpa;
    newStudentNode->pStudent->creditHours = creditHours;
    newStudentNode->pNext = NULL;

    insertStudentAppropriately(newStudentNode, pDatabase);

    printf("Successfully added the following student to the database!\n");
    displayStudentInfo(newStudentNode->pStudent);
}

void readMenu(Database* database){
    int choice = 0;
    char id[100];
    printf("Select one of the following: \n");
    printf("\t1) Display the head (first 10 rows) of the database\n");
    printf("\t2) Display students on the honor roll, in order of their GPA\n");
    printf("\t3) Display students on academic probation, in order of their GPA\n");
    printf("\t4) Display freshmen students, in order of their name\n");
    printf("\t5) Display sophomore students, in order of their name\n");
    printf("\t6) Display junior students, in order of their name\n");
    printf("\t7) Display senior students, in order of their name\n");
    printf("\t8) Display the information of a particular student\n");
    while(choice > 8 || choice < 1){
      printf("Your choice --> ");
      scanf(" %d", &choice);
      if(choice > 8 || choice < 1){
        printf("Sorry, that input was invalid. Please try again.\n");
      }
    }
    switch (choice) {
        case 1:
            displayStudentList(database->pIDList, false);
            printf("\n");
            break;
        case 2:
            displayStudentList(database->pHonorRollList, true);
            printf("\n");
            break;
        case 3:
            displayStudentList(database->pAcademicProbationList, true);
            printf("\n");
            break;
        case 4:
            displayStudentList(database->pFreshmanList, true);
            printf("\n");
            break;
        case 5:
            displayStudentList(database->pSophomoreList, true);
            printf("\n");
            break;
        case 6:
            displayStudentList(database->pJuniorList, true);
            printf("\n");
            break;
        case 7:
            displayStudentList(database->pSeniorList, true);
            printf("\n");
            break;
        case 8:
                printf("Enter the id of the student to find: ");
                scanf("%s", id);
           // if(searchForStudent(id, database) == NULL){
              //printf("There are no students matching that criteria.");
          //  }
         // else{
            displayStudentInfo(searchForStudent(id, database));
         // }
            break;
        default:
            printf("Sorry, that input was invalid. Please try again.\n");
            break;
    }
}

char choiceMenu(Database* pDatabase) {
    char choice;
    char garbage[100];

    while (1) {
        printf("\nEnter: \tC to create a new student and add them to the database,\n");
        printf("\tR to read from the database,\n");
        printf("\tD to delete a student from the database, or\n");
        printf("\tX to exit the program.\n");
        printf("Your choice --> ");
        scanf(" %c", &choice);
        switch (choice) {
            case 'C':
                createStudent(pDatabase);
                return choice;
            case 'R':
                readMenu(pDatabase);
                return choice;
            case 'D': {
                char id[100];
                printf("Enter the id of the student to be removed: ");
                scanf("%s", id);
                deleteStudent(id, pDatabase);
                return choice;
            }
            case 'X':
                printf("\nThanks for playing!\n");
                printf("Exiting...\n");
                return choice;
            default:
                printf("Invalid option. Try again.\n");
        }
    }
}


int main(){
char emptyChoice = ' ';
char filename[100] = "";  
Database* db = NULL; 
db = createDatabase();
  
printf("CS 211, Spring 2023\n");
printf("Program 4: Database of Students\n\n");
printf("Enter E to start with an empty database, \n");
printf("or F to start with a database that has information on students from a file.\n");
while(emptyChoice != 'E' && emptyChoice != 'F'){ //keep prompting until valid input 'F' or 'E'
  printf("Your choice --> ");  
  scanf(" %c", &emptyChoice);
  if(emptyChoice != 'E' && emptyChoice != 'F'){ //if Invalid
    printf("Sorry, that input was invalid. Please try again.\n"); 
  }
}
if(emptyChoice == 'F'){
  printf("Enter the name of the file you would like to use: ");
  scanf("%s", filename);
  printf("\n");
  readAndUseFile(db, filename);
}

 



  

  //successfully create and display a student using displayStudentList
  
 //  Student* st = malloc(sizeof(Student));
 //  st->creditHours = 10;
 //  st->gpa = 2.20;
 //  st->name = "Joe Shmoe";
 //  st->id = "60XIOSDOJS";
 //  Student* st2 = malloc(sizeof(Student));
 //  st2->creditHours = 60;
 //  st2->gpa = 1.5;
 //  st2->name = "Xornelius Cornwall";
 //  st2->id = "61JIOSDOJS";
 //  Student* st3 = malloc(sizeof(Student));
 //  st3->creditHours = 25;
 //  st3->gpa = 4.0;
 //  st3->name = "Abraham Jeskovic";
 //  st3->id = "61PDSOFF";
 
 // StudentNode* nHead = malloc(sizeof(StudentNode));
 //  nHead->pStudent = st;
 //  nHead->pNext = NULL;
 //  StudentNode* tHead = malloc(sizeof(StudentNode));
 // tHead->pStudent = st2;
 //  tHead->pNext = NULL;
 // StudentNode* jHead = malloc(sizeof(StudentNode));
 // jHead->pStudent = st3;
 //  jHead->pNext = NULL;
 //  insertStudentByID(db, tHead);
 //  insertStudentByID(db, jHead);
 //  insertStudentByID(db, nHead);
  
 //  insertStudentByName(st3, &db->pAcademicProbationList);
 //  insertStudentByName(st, &db->pAcademicProbationList);
 //  insertStudentByName(st2, &db->pAcademicProbationList);
  


  
while(choiceMenu(db) != 'X');

  

  //  SUCCESSFULLY CREATE AND DISPLAY A STUDENT
// Student* st = malloc(sizeof(Student));
//   st->creditHours = 10;
//   st->gpa = 2.20;
//   st->name = "Joe Shmoe";
//   st->id = "60XIOSDOJS";

//   displayStudentInfo(st);





freeDatabase(db);  
}
