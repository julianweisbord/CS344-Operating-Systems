#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>

#define MAX_STR_LEN 20
#define NUM_OF_ROOMS 10

//How we compare rooms
enum Room_type{
  START_ROOM,
  END_ROOM,
  MID_ROOM
};

struct Room{
  char* name;
  int connections;
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
struct Room* init_stuff(struct Room dungeon);
struct Game* init_game(struct Game adventure);
int randNum(int start, int end);

int main(int argc, char** argv){


  //Create directory
  int pid = getpid();
  char directory[MAX_STR_LEN];
  memset(directory, '\0', MAX_STR_LEN);
  char *user_rooms = "weisborj.rooms.";
  snprintf(directory, MAX_STR_LEN, "%s%d", user_rooms, pid);
  printf("%s\n", directory);
  mkdir(directory, 0555);


  struct Room room1, *roomPointer;
  struct Game adventure, *adventurePointer;
  roomPointer = &room1;
  adventurePointer = &adventure;


  // init_room(Room room1)
  // room1.name = malloc(sizeof(char) * (MAX_STR_LEN+1));
  // strcpy(room1.name, get_room_name(num));
  // printf("%s \n", room1.name);
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
struct Game* init_game(struct Game adventure){
  struct Game* gamePointer = malloc(sizeof(struct Game));
  gamePointer->numSteps =0;
  return gamePointer;
}

//int_room Function//
struct Room* init_room(struct Room dungeon){
  struct Room* roomPointer = malloc(sizeof(struct Room));
  roomPointer->name = malloc(sizeof(char) * (MAX_STR_LEN+1));
  return roomPointer;

}
//randNum Function//
int randNum(int start, int end){
  srand(time(NULL));
  int r = rand() % end;
  // This hack isn't as random but will work for the purpose of printing a number in a range.
  if(r+ start <= end)
    r+=start;
  printf("Random Number: %d", r);
  return r;
}
