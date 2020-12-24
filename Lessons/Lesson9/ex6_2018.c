#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ENTER_MENU_MESSAGE \
"Welcome! please choose an option\n1 - "\
"Log in\n2 - New member\n3 - Exit\n"
#define MAIN_MENU_MESSAGE "Please choose an option:\n"\
						"1. Find a match\n"\
						"2. I found love, DELETE me\n"\
						"3. Log out\n"


#define ID_SIZE 9
#define FIRST_NAME_MAX_SIZE 15
#define LAST_NAME_MAX_SIZE 15
#define USER_NAME_MAX_SIZE 10
#define PASSWORD_MAX_SIZE 15
#define DESCRIPTION_MAX_SIZE 121
#define LINE_MAX_SIZE 200

typedef struct
{//represent a user in the program
    int age;
    char id[ID_SIZE];
    char* firstName;
    char* lastName;
    char gender;
    char* userName;
    char* password;
    char* description;
    char hobbies;
}User;
struct WomanNode
{//represent a cell in the list of women
    User* value;
    struct WomanNode* next;
};
typedef struct WomanNode WomanNode;
enum hobby {
    BASEBALL = 1, BASKETBALL, BICYCLE, BOOKS,
    DRAWING, GYM, MOVIES, POETRY
};

void addUser(User*** men, int* menLength, WomanNode* women, User* user);
void logIn(User*** men, int* menLength, WomanNode* women);
User* findUserName(User** men, int menLength, WomanNode* women, char* username);
void newMember(User*** men, int* menLength, WomanNode* women);
int idExists(User** men, int menLength, WomanNode* women, char* id);
int isLetter(char ch);
void freeAll(User** men, int menLength, WomanNode* women);
void freeUser(User* user);
void mainMenu(User*** men, int* menLength, WomanNode* women, User* user);
void findMatch(User** men, int menLength, WomanNode* women, User* user);
int isMatch(User* user1, User* user2, int minAge, int maxAge);
void printMatch(User* user);
void printHobby(enum hobby hobby);
void deleteMe(User*** men, int* menLength, WomanNode* women, User* user);
void deleteMan(User*** arr, int* length, User* user);
void deleteWoman(WomanNode* list, User* user);


void addUser(User*** men, int* menLength, WomanNode* women, User* user)
{
    /************************************************************************
    * function name: addUser *
    * The Input: pointers to men array and the length, women list, new user *
    * The output: none *
    * The Function operation: add a user to men array or women list *
    *                         according to it's gender *
    *************************************************************************/
    if (user->gender == 'M')
    {
        if ((*men = (User**)realloc(*men, (*menLength + 1) * sizeof(User*))) == NULL)
        {
            printf("failed to realloc men\n");
            exit(1);
        }
        (*men)[*menLength] = user;
        (*menLength)++;
    }
    else
    {
        WomanNode* newWoman;
        if ((newWoman = (WomanNode*)malloc(sizeof(WomanNode))) == NULL)
        {
            printf("faild to add womanNode\n");
            exit(1);
        }
        newWoman->value = user;
        WomanNode* prev = women;
        WomanNode* next = prev->next;
        while (next != NULL)
        {
            if (strcmp(user->lastName, next->value->lastName) < 0)
                //position found
                break;
            prev = next;
            next = prev->next;
        }
        //adding user to the list
        prev->next = newWoman;
        newWoman->next = next;

    }
}
void newMember(User*** men, int* menLength, WomanNode* women)
{
    /************************************************************************
    * function name: newMember *
    * The Input: men array and it's length, women list *
    * The output: none *
    * The Function operation: create a new user *
    *************************************************************************/
    int age, hobby[4], i;
    char id[ID_SIZE], firstName[FIRST_NAME_MAX_SIZE], lastName[LAST_NAME_MAX_SIZE],
            userName[USER_NAME_MAX_SIZE], password[PASSWORD_MAX_SIZE],
            description[DESCRIPTION_MAX_SIZE], gender, hobbies = 0, dummy;
    User* newUser;
    printf("Please enter your ID:\n");
    scanf("%s", id);
    if (idExists(*men, *menLength, women, id))
    {
        //ID exists
        printf("Error: User already exists\n");
        return;
    }
    //scan data
    printf("Please enter your first name:\n");
    scanf("%s", firstName);
    printf("Please enter your last name:\n");
    scanf("%s", lastName);
    printf("Please enter your age (18 to 100):\n");
    scanf("%d", &age);
    if (age < 18 || age>100)
        //invalid age
        return;
    printf("Please enter your gender (F-female, M-male):\n");
    scanf("%c%c", &dummy, &gender);//the dummy get the \n char
    printf("Choose a username (3-10 characters):\n");
    scanf("%s", userName);
    if ((strlen(userName) < 3) || (!isLetter(userName[0])))
        //invalid username
        return;
    printf("please choose 4 hobbies: Baseball=1, Basketball=2, Bicycle=3, "\
		"Books=4, Drawing=5, Gym=6, Movies=7, Poetry=8\n");
    scanf("%d %d %d %d", hobby, hobby + 1, hobby + 2, hobby + 3);
    for (i = 0; i < 4; i++)
    {
        hobbies += (1 << (hobby[i] - 1));
    }
    printf("Choose a password (attention-minimum 3 characters):\n");
    scanf("%s", password);
    if (strlen(password) < 3)
        return;
    printf("Some words about yourself:\n");
    scanf("%c", &dummy);//the dummy get the \n char
    fgets(description, DESCRIPTION_MAX_SIZE, stdin);
    //creating user
    if ((newUser = (User*)malloc(sizeof(User))) == NULL)
        exit(1);
    newUser->age = age;
    newUser->gender = gender;
    newUser->hobbies = hobbies;
    strcpy(newUser->id, id);
    //first name
    if ((newUser->firstName = (char*)malloc(strlen(firstName) + 1)) == NULL)
        exit(1);
    strcpy(newUser->firstName, firstName);
    //last name
    if ((newUser->lastName = (char*)malloc(strlen(lastName) + 1)) == NULL)
        exit(1);
    strcpy(newUser->lastName, lastName);
    //user name
    if ((newUser->userName = (char*)malloc(strlen(userName) + 1)) == NULL)
        exit(1);
    strcpy(newUser->userName, userName);
    //password
    if ((newUser->password = (char*)malloc(strlen(password) + 1)) == NULL)
        exit(1);
    strcpy(newUser->password, password);
    //description
    if ((newUser->description = (char*)malloc(strlen(description) + 1)) == NULL)
        exit(1);
    strcpy(newUser->description, description);
    addUser(men, menLength, women, newUser);
    printf("Hi %s, lets find love!\n", newUser->firstName);
    mainMenu(men, menLength, women, newUser);
}
void logIn(User*** men, int* menLength, WomanNode* women)
{
    /************************************************************************
    * function name: logIn *
    * The Input: men array and length, women list *
    * The output: none *
    * The Function operation: handle the user log in *
    *************************************************************************/
    char userName[USER_NAME_MAX_SIZE + 1], password[PASSWORD_MAX_SIZE + 1];
    User* user;
    //scan username
    printf("Please enter your username:\n");
    scanf("%s", &userName);
    if ((user = findUserName(*men, *menLength, women, userName)) == NULL)
    {
        //no such username
        printf("User do not exist in the system, please try again\n");
        printf("Please enter your username:\n");
        scanf("%s", &userName);
        if ((user = findUserName(*men, *menLength, women, userName)) == NULL)
            // no such username
            return;
    }
    //scan password
    printf("Please enter your password:\n");
    scanf("%s", password);
    if (strcmp(password, user->password)==0)
    {
        //logged in
        printf("Hello %s!\n", user->firstName);
        mainMenu(men, menLength, women, user);
    }
    else
    {
        //wrong password
        printf("Wrong password\n");
    }
}
User* findUserName(User** men, int menLength, WomanNode* women, char* username)
{
    /************************************************************************
    * function name: findUserName *
    * The Input: men array and it's length, women list, username *
    * The output: a pointer to a user that his userName is username(the parameter) *
    *				return NULL if not found
    * The Function operation: find a user that his userName is username *
    *************************************************************************/
    int i;
    WomanNode* pos = women->next;
    for (i = 0; i < menLength; i++)
        if (strcmp(men[i]->userName, username) == 0)
            return men[i];
    while (pos != NULL)
    {
        if (strcmp(pos->value->userName, username) == 0)
            return pos->value;
        pos = pos->next;
    }
    return NULL;
}
int idExists(User** men, int menLength, WomanNode* women, char* id)
{
    /************************************************************************
    * function name: idExists *
    * The Input: men array and it's length, women list, id *
    * The output: 1 if id exists 0 if no *
    * The Function operation: check if id exists *
    *************************************************************************/
    int i;
    WomanNode* pos = women->next;
    for (i = 0; i < menLength; i++)
        if (!strcmp(men[i]->id, id))
            return 1;
    while (pos != NULL)
    {
        if (!strcmp(pos->value->id, id))
            return 1;
        pos = pos->next;
    }
    return 0;
}
int isLetter(char ch)
{
    /************************************************************************
    * function name: isLetter *
    * The Input: char ch *
    * The output: 1 if ch is letter 0 if not *
    * The Function operation: check if ch is letter *
    *************************************************************************/
    return ((ch >= 'a') && (ch <= 'z') || (ch >= 'A') && (ch <= 'z'));
}
void freeAll(User** men, int menLength, WomanNode* women)
{
    /************************************************************************
    * function name: freeAll *
    * The Input: men array and it'd length, women list *
    * The output: none *
    * The Function operation: free all users and saves them to the output file *
    *************************************************************************/
    int i;
    WomanNode *pos, *next;
    for (i = 0; i < menLength; i++)
    {
        //go over men
        freeUser(men[i]);
    }
    free(men);
    pos = women;
    while (pos != NULL)
    {
        //go over women
        next = pos->next;
        freeUser(pos->value);
        free(pos);
        pos = next;
    }
}
void freeUser(User* user)
{
    /************************************************************************
    * function name: free user *
    * The Input: pointer to user *
    * The output: none *
    * The Function operation: free a user *
    *************************************************************************/
    free(user->firstName);
    free(user->lastName);
    free(user->userName);
    free(user->password);
    free(user->description);
    free(user);
}
void mainMenu(User*** men, int* menLength, WomanNode* women, User* user)
{
    /************************************************************************
    * function name: mainMenu *
    * The Input: men array and it's length, women list, User *
    * The output: none *
    * The Function operation: handle the main menu *
    *************************************************************************/
    int option;
    do
    {
        printf(MAIN_MENU_MESSAGE);
        scanf("%d", &option);
        switch (option)
        {
            case 1:
                findMatch(*men, *menLength, women, user);
                break;
            case 2:
                deleteMe(men, menLength, women, user);
                return ;
            case 3:
                break;
            default:
                printf("Bad choice, please try again ");
                break;
        }
    } while (option != 3);
}
void findMatch(User** men, int menLength, WomanNode* women, User* user)
{
    /************************************************************************
    * function name: findMatch *
    * The Input: men array and it's length, women list, user *
    * The output: none *
    * The Function operation: find and print all the user's matches *
    *************************************************************************/
    int minAge, maxAge;
    printf("Please choose ages range:\n");
    scanf("%d %d", &minAge, &maxAge);
    if (user->gender == 'M')
    {
        WomanNode* pos = women->next;
        while (pos != NULL)
        {
            if (isMatch(user, pos->value, minAge, maxAge))
                printMatch(pos->value);
            pos = pos->next;
        }
    }
    else
    {
        int i;
        for (i = 0; i < menLength; i++)
        {
            if (isMatch(user, men[i], minAge, maxAge))
                printMatch(men[i]);
        }
    }
}
int isMatch(User* user1, User* user2, int minAge, int maxAge)
{
    /************************************************************************
    * function name: isMatch *
    * The Input: 2 users, min and max age *
    * The output: 1 if user2 is match for user1, 0 if not *
    * The Function operation: check if user2 is match for user1 *
    *************************************************************************/
    char hobbies, i;
    int sum = 0;
    if ((user2->age < minAge) || (user2->age > maxAge))
        return 0;
    hobbies = (user1->hobbies)&(user2->hobbies);
    for (i = 1; i != 0; i = i<<1)
    {
        if (i&hobbies)
            sum++;
    }
    return sum >= 2;
}
void printMatch(User* user)
{
    /************************************************************************
    * function name: printMatch *
    * The Input: user *
    * The output: none *
    * The Function operation: print user in the write format *
    *************************************************************************/
    enum hobby hobby;
    int sum = 0;
    printf("Name: %s %s Age: %d Hobbies: ", user->firstName, user->lastName, user->age);
    //print hobbies
    for (hobby = 1; hobby <= 8; hobby++)
    {
        if (user->hobbies&(1 << (hobby - 1)))
        {
            printHobby(hobby);
            sum++;
            if (sum == 4)
                //this is all the hobbies
                break;
            printf(", ");
        }
    }
    //print description
    printf(" Description: %s\n", user->description);
}
void printHobby(enum hobby hobby)
{
    /************************************************************************
    * function name: printHobby *
    * The Input: hobby *
    * The output: none *
    * The Function operation: print the hobby string *
    *************************************************************************/
    switch (hobby)
    {
        case BASEBALL:
            printf("Baseball");
            break;
        case BASKETBALL:
            printf("Basketball");
            break;
        case BICYCLE:
            printf("Bicycle");
            break;
        case BOOKS:
            printf("Books");
            break;
        case DRAWING:
            printf("Drawing");
            break;
        case GYM:
            printf("Gym");
            break;
        case MOVIES:
            printf("Movies");
            break;
        case POETRY:
            printf("Poetry");
            break;
        default:
            break;
    }
}
void deleteMe(User*** men, int* menLength, WomanNode* women, User* user)
{
    /************************************************************************
    * function name: deleteMe *
    * The Input: men array and it's length, women list, user *
    * The output: none *
    * The Function operation: delete user *
    *************************************************************************/
    if (user->gender == 'M')
        deleteMan(men, menLength, user);
    else
        deleteWoman(women, user);
}
void deleteMan(User*** arr, int* length, User* user)
{
    /************************************************************************
    * function name: deletMan *
    * The Input: pointers to men array, length, user *
    * The output: none *
    * The Function operation: delete user from array *
    *************************************************************************/
    int i;
    //find user index
    for (i = 0; (*arr)[i] != user; i++);
    freeUser(user);
    for (; i < *length - 1; i++)
        (*arr)[i] = (*arr)[i + 1];
    (*length)--;
    (*arr) = (User**)realloc(*arr, (*length)*sizeof(User*));
    if (*arr == NULL)
    {
        printf("failed realloc men arr at deleteMan\n");
        exit(1);
    }



}
void deleteWoman(WomanNode* list, User* user)
{
    /************************************************************************
    * function name: women *
    * The Input: what the function input *
    * The output: what the function output *
    * The Function operation: what the function does *
    *************************************************************************/
    WomanNode (*pos) = list, *node;
    while (pos->next->value != user)
    {
        pos = pos->next;
    }
    node = pos->next;
    pos->next = node->next;
    freeUser(node->value);
    free(node);
}
int main()
{
    User** menArray = NULL;//array of pointer to men
    int menArrayLength = 0;
    WomanNode* womenList = NULL;
    int option;
    //enter menu
    do
    {
        printf(ENTER_MENU_MESSAGE);
        scanf("%d", &option);
        switch (option)
        {
            case 1:
                logIn(&menArray, &menArrayLength, womenList);
                break;
            case 2:
                newMember(&menArray, &menArrayLength, womenList);
                break;
            case 3:
                freeAll(menArray, menArrayLength, womenList);
                break;
            default:
                printf("Bad choice, please try again\n");
                break;
        }
    } while (option != 3);
    return 0;
}


