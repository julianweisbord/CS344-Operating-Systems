#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define MAX_STR_LEN 20




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
}

char* get_room_name(int roomNum);
Room* init_stuff(Room dungeon)



char* get_room_name(int roomNum){
  char* room_name = malloc(sizeof(char) * (MAX_STR_LEN +1));
  memset(room_name, '\0', MAX_STR_LEN);
  // Declare room names
  switch(roomNum){

    case 0:
      strcpy(room_name, "Halloween");
      break;

  }
  printf("%s \n", room_name);
  return room_name;
}

Room* init_room(Room dungeon){
  struct Room* roomPointer = malloc(sizeof(struct Room));
  roomPointer->name = malloc(sizeof(char) * (MAX_STR_LEN+1));
  return roomPointer

}

int main(char **argv, int argc){

  // char halloween[20], the_shining[20], the_purge[20], oculus[20], the_ring[20];
  // char the_strangers[20], prisoners[20], pyscho[20], the_conjuring[20], dead_silence[20];
  int num =0;

  struct Room room1;
  // init_room(Room room1)
  // room1.name = malloc(sizeof(char) * (MAX_STR_LEN+1));
  // strcpy(room1.name, get_room_name(num));
  // printf("%s \n", room1.name);
  return 0;

}
