#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>
#include <math.h>

#define MAX_STR_LEN 20
#define DIFF_ROOMS 10
#define NUM_ROOMS 7
typedef int bool;
#define TRUE 1
#define FALSE 0
//How we compare rooms
enum Room_type{
  START_ROOM,
  END_ROOM,
  MID_ROOM
};

struct Room{
  char* name;
  int connection_num; //number of connections
  int* connectionArray; //Array of integer indexes to the Game roomArray
  enum Room_type roomType;
};

struct Game{
  struct Room** roomArray;
  int numOfRooms;
  char location[20];
  int numSteps;
};

// Prototypes
char* set_room_name(int roomNum);
void init_game(struct Game* adventure);
int randNum(int start, int end);
int check_win(struct Room* possibleEnd);
void add_connection(struct Game *adventure, int index);
double floorIt(double val);


int main(int argc, char** argv){


  //Create directory with name: weisborj.rooms.<pid>
  int pid = getpid();
  char directory[MAX_STR_LEN];
  memset(directory, '\0', MAX_STR_LEN);
  char *user_rooms = "weisborj.rooms.";
  snprintf(directory, MAX_STR_LEN, "%s%d", user_rooms, pid);
  printf("%s\n", directory);
  mkdir(directory, 0666);


  //struct Room room1, *roomPointer;
  struct Game adventure, *adventurePointer;
  //roomPointer = &room1;
  adventurePointer = &adventure;
  // initializing struct member variables
  init_game(adventurePointer);



  return 0;

}


//set_room_name, room names are based on scary movies//
char* set_room_name(int roomNum){
  char* room_name = malloc(sizeof(char) * (MAX_STR_LEN +1));
  memset(room_name, '\0', MAX_STR_LEN+1);
  // Declare room names
  switch(roomNum){

    case 0:
      strcpy(room_name, "Halloween");
      break;
    case 1:
      strcpy(room_name, "The Shining");
      break;
    case 2:
      strcpy(room_name, "The Purge");
      break;
    case 3:
      strcpy(room_name, "Oculus");
      break;
    case 4:
      strcpy(room_name, "The Ring");
      break;
    case 5:
      strcpy(room_name, "The Strangers");
      break;
    case 6:
      strcpy(room_name, "Prisoners");
      break;
    case 7:
      strcpy(room_name, "Psycho");
      break;
    case 8:
      strcpy(room_name, "The Conjuring");
      break;
    case 9:
      strcpy(room_name, "Dead Silence");
      break;
  }
  printf("%s \n", room_name);
  return room_name;
}

//init_game Function//
void init_game(struct Game* adventure){
  adventure = malloc(sizeof(struct Game));
  adventure->numSteps =0;
  adventure->numOfRooms = NUM_ROOMS;
  adventure->roomArray = malloc(sizeof(struct Room *) * NUM_ROOMS);
  printf("THINK ITS A GAME\n");

  int i, j, random_num;
  int taken[20];
  int check = FALSE;
  for (i = 0; i < NUM_ROOMS; ++i) {
    printf("Ahuuhaa-haaaawuh\n");

    adventure->roomArray[i] = malloc(sizeof(struct Room));
    adventure->roomArray[i]->name = malloc(sizeof(char) * (MAX_STR_LEN+1));
    adventure->roomArray[i]->connection_num = 0;

    adventure->roomArray[i]->connectionArray = malloc(sizeof(int) *50);

    do{
      random_num= randNum(0,7);
      taken[i] = random_num;
      printf("random_num, %d\n", random_num);
      for(j=0; j< 7; ++j){
        printf("CHECK %d\n", check);
        if (j ==i)
          j+=1;
        if (taken[j] ==random_num){
            check = TRUE;
            break;
        }
        else if(taken[j] != random_num){
          check = FALSE;
        }
      }
    }while(check == TRUE);
    check = FALSE;
    adventure->roomArray[i]->name =set_room_name(random_num); //TL;DR this sets the room name
    //The above line calls set_room_name with a random
    //number that hasn't already been taken,
    add_connection(adventure, i);
  }
  //This is just to check the names in the array
  int z;
  for (z = 0; z < NUM_ROOMS; ++z) {
    printf("%s\n",adventure->roomArray[z]->name);
  }

}


//Takes a number and returns the rounded down version of it//
double floorIt(double val){
   int end = (int)val - ((int)val % 1);
  //  printf("End %d\n", end);
  return end;
}

//randNum Function, special thanks to John Andersen//
int randNum(int start, int end){
  srandom(time(NULL));
  int low = start;
  int high = end;
  // Call random
  double res = floorIt((((double)random()/(double)(RAND_MAX)) * (double)1.0)*(high - low + 1) + low);

  printf("Random number is res : %d\n", (int)res);
  return (int)res;
}


//Initialize all connections//
//Index is the position in the roomArray for the current room
void add_connection(struct Game *adventure, int index){
  //call this function for each room
  int random = randNum(3,6);
  printf("Random number of connections for room %d : %d\n",index, random);
  struct Room* room = adventure->roomArray[index];

  while(room->connection_num < random){
    room->connection_num +=1;
    printf("Adding a connection: %d \n", room->connection_num);

    do{

      room->connectionArray[room->connection_num] = randNum(1,NUM_ROOMS);
    }while(room->connectionArray[room->connection_num] == index); //Don't let a connection have a connection to itself
  }

}

//To check if the user is in the end room//
int check_win(struct Room* possibleEnd){
  if (possibleEnd->roomType == END_ROOM){
    printf("YOU HAVE FOUND THE END ROOM. CONGRATULATIONS!\n");
    return 1;
  }
  return 0;
}
//Interface Function To Be Room//
// void interface(){}
