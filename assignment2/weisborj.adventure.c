#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>

#define MAX_STR_LEN 20
#define DIFF_ROOMS 10
#define NUM_ROOMS 7
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
char* get_room_name(int roomNum);
void init_game(struct Game* adventure);
int randNum(int start, int end);
int check_win(struct Room* possibleEnd);
void add_connection(struct Game *adventure, int index);


int main(int argc, char** argv){


  //Create directory with name: weisborj.rooms.<pid>
  int pid = getpid();
  char directory[MAX_STR_LEN];
  memset(directory, '\0', MAX_STR_LEN);
  char *user_rooms = "weisborj.rooms.";
  snprintf(directory, MAX_STR_LEN, "%s%d", user_rooms, pid);
  printf("%s\n", directory);
  mkdir(directory, 0666);


  struct Room room1, *roomPointer;
  struct Game adventure, *adventurePointer;
  roomPointer = &room1;
  adventurePointer = &adventure;
  // initializing struct member variables
  init_game(adventurePointer);
  //init_room(roomPointer);


  return 0;

}


//get_room_name, room names are based on scary movies//
char* get_room_name(int roomNum){
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
  printf("MIDDLE OF INIT GAME\n");

  int i;
  for (i = 0; i < NUM_ROOMS; ++i) {
    printf("Ahuuh-haaaawuh\n");

    adventure->roomArray[i] = malloc(sizeof(struct Room));
    adventure->roomArray[i]->name = malloc(sizeof(char) * (MAX_STR_LEN+1));
    adventure->roomArray[i]->connection_num = 0;

    adventure->roomArray[i]->connectionArray = malloc(sizeof(int) *50);
    printf("END OF INIT GAME!\n");

    // add_connection(adventurePointer, i);
  }


}

//randNum Function//
int randNum(int start, int end){
  srand(time(NULL));
  int r = rand() % end;
  // This hack isn't as random but will work for the purpose of printing a number in a range.
  if(r+ start <= end)
    r+=start;
  printf("Random Number: %d\n", r);
  return r;
}
//To check if the user is in the end room//
int check_win(struct Room* possibleEnd){
  if (possibleEnd->roomType == END_ROOM){
    printf("YOU HAVE FOUND THE END ROOM. CONGRATULATIONS!\n");
    return 1;
  }
  return 0;
}
//Initialize all connections//
void add_connection(struct Game *adventure, int index){
  //call this function for each room
  int random = randNum(3,6);
  struct Room* room = adventure->roomArray[index];//check this
  while(room->connection_num < random){
    do{
      room->connectionArray[room->connection_num] = randNum(1,NUM_ROOMS);
    }while(room->connectionArray[room->connection_num] == index);
  }

}
