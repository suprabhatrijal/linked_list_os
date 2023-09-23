#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include <string.h>

int main() {
  // int x;
  printf("Tests for linked list implementation:\n");
  printf("\n");


  // Tests for list_alloc()
  printf("list_alloc():\n");
  list_t* my_list;
  my_list = list_alloc();

  if(strcmp("NULL", listToString(my_list)) != 0)
  {
        printf("Initialize an empty linked list head: FAILED\n");
  }
  else {
    printf("Initialize an empty linked list head: PASSED\n");
  }

  // reset test
  list_free(my_list);
  printf("\n");


  // Tests for list_add_to_back()
  // Initialization
  printf("list_add_to_back():\n");
  my_list = list_alloc();

  list_add_to_back(my_list, 6);
  if(strcmp("6->NULL", listToString(my_list)) != 0)
  {
    printf("Added to an empty list: FAILED\n");
  }
  else {
    printf("Added to an empty list: PASSED\n");
  }

  list_add_to_back(my_list, 5);
  list_add_to_back(my_list, 120);
  if(strcmp("6->5->120->NULL", listToString(my_list)) != 0)
  {
    printf("Added to a list with existing nodes: FAILED\n");
  }
  else {
    printf("Added to a with existing nodes: PASSED\n");
  }
  // reset test
  list_free(my_list);
  printf("\n");


  // Tests for list_length()
  // Initialization
  printf("list_length():\n");
  my_list = list_alloc();

  // Empty List
  if(list_length(my_list) != 0)
  {
    printf("Added to the back of an empty list: FAILED\n");
  }
  else {
    printf("Added to the back of  an empty list: PASSED\n");
  }
  // With members
  list_add_to_back(my_list, 5);
  list_add_to_back(my_list, 120);
  list_add_to_back(my_list, 150);
  list_add_to_back(my_list, 300);
  list_add_to_back(my_list, 220);

  if(list_length(my_list) != 5)
  {
    printf("Added to the back of a list with existing nodes: FAILED\n");
  }
  else {
    printf("Added to added to the back of a with existing nodes: PASSED\n");
  }
  // reset test
  list_free(my_list);
  printf("\n");

  // Tests for list_add_to_front()
  // Initialization
  printf("list_add_to_front():\n");
  my_list = list_alloc();

  list_add_to_front(my_list, 20);
  // Empty List
  if(strcmp("20->NULL",listToString(my_list))!=0)
  {
    printf("Added to the front of an empty list: FAILED\n");
  }
  else {
    printf("Added to the front of an empty list: PASSED\n");
  }
  // With members
  list_add_to_front(my_list, 5);
  list_add_to_front(my_list, 120);
  list_add_to_front(my_list, 150);
  list_add_to_front(my_list, 300);
  list_add_to_front(my_list, 220);

  if(strcmp("220->300->150->120->5->20->NULL",listToString(my_list))!=0)
  {
    printf("Added to the front of a list with existing nodes: FAILED\n");
  }
  else {
    printf("Added to the front of a with existing nodes: PASSED\n");
  }
  // reset test
  list_free(my_list);
  printf("\n");




  // Tests for list_add_at_index()
  // Initialization
  printf("list_add_at_index():\n");
  my_list = list_alloc();

  list_add_at_index(my_list, 20, 0);
  // Empty List
  if(strcmp("20->NULL",listToString(my_list))!=0)
  {
    printf("Added to a given index(index < length(list)) of an empty list: FAILED\n");
  }
  else {
    printf("Added to a given index(index < length(list)) an empty list: PASSED\n");
  }

  //Should add to the end of the list
  list_add_at_index(my_list, 300, 1000);
  // Empty List
  if(strcmp("20->300->NULL",listToString(my_list))!=0)
  {
    printf("Added to a given index(index >= length(list)) of an empty list: FAILED\n");
  }
  else {
    printf("Added to a given index(index >= length(list)) an empty list: PASSED\n");
  }



  // With members
  list_add_at_index(my_list, 420, 0);
  list_add_at_index(my_list, 660, 2);
  list_add_at_index(my_list, 122, 1);
  list_add_at_index(my_list, 330, 4);
  list_add_at_index(my_list, 111, 2);
  list_add_at_index(my_list, 440, 4);
  list_add_at_index(my_list, 110, 4);
  list_add_at_index(my_list, 123, 3);
  
  if(strcmp("420->122->111->123->20->110->440->660->330->300->NULL",listToString(my_list))!=0)
  {
    printf("Added to a list with existing nodes: FAILED\n");
  }
  else {
    printf("Added to a with existing nodes: PASSED\n");
  }
  // reset test
  list_free(my_list);
  printf("\n");


  // Tests for list_remove_from_back()
  // Initialization
  printf("list_remove_from_back():\n");
  my_list = list_alloc();

  elem remove1;
  elem remove2;
  elem remove3;
  elem remove4;

  remove1 = list_remove_from_back(my_list);
  // Empty List
  if(strcmp("NULL",listToString(my_list))!=0 || remove1 != -1)
  {
    printf("Removed from an empty list from the back: FAILED\n");
  }
  else {
    printf("Removed from an empty list from the back: PASSED\n");
  }

  list_add_to_back(my_list, 5);
  list_add_to_back(my_list, 120);
  list_add_to_back(my_list, 150);
  list_add_to_back(my_list, 300);
  list_add_to_back(my_list, 220);

  remove2 = list_remove_from_back(my_list);
  remove3 = list_remove_from_back(my_list);
  remove4 = list_remove_from_back(my_list);

  if(strcmp("5->120->NULL",listToString(my_list))!=0 || remove2 != 220 && remove3 != 300 && remove4 != 150)
  {
    printf("Removed from a populated list from the back: FAILED\n");
  }
  else {
    printf("Removed from a populated list from the back: PASSED\n");
  }
  //
  // reset test
  list_free(my_list);
  printf("\n");

  // Tests for list_remove_from_front()
  // Initialization
  printf("list_remove_from_front():\n");
  my_list = list_alloc();

  remove1 = list_remove_from_front(my_list);
  // Empty List
  if(strcmp("NULL",listToString(my_list))!=0 && remove1 == -1)
  {
    printf("Removed from an empty list from the front: FAILED\n");
  }
  else {
    printf("Removed from an empty list from the front: PASSED\n");
  }

  list_add_to_back(my_list, 5);
  list_add_to_back(my_list, 120);
  list_add_to_back(my_list, 150);
  list_add_to_back(my_list, 300);
  list_add_to_back(my_list, 220);

  remove2 = list_remove_from_front(my_list);
  remove3 = list_remove_from_front(my_list);
  remove4 = list_remove_from_front(my_list);

  if(strcmp("300->220->NULL",listToString(my_list))!=0 || remove2 != 5 || remove3 != 120 || remove4 != 150)
  {
    printf("Removed from a populated list from the front: FAILED\n");
  }
  else {
    printf("Removed from a populated list from the front: PASSED\n");
  }
  // reset test
  list_free(my_list);
  printf("\n");

  // Tests for list_remove_at_index()
  // Initialization
  printf("list_remove_at_index():\n");
  my_list = list_alloc();

  remove1 = list_remove_at_index(my_list, 0);
  //
  // Empty List
  if(strcmp("NULL",listToString(my_list))!=0 || remove1 != -1)
  {
    printf("Remove from a given index(index < length(list)) of an empty list: FAILED\n");
  }
  else {
    printf("Remove from a given index(index < length(list)) an empty list: PASSED\n");
  }


  // // construct the list
  list_add_to_back(my_list, 5);
  list_add_to_back(my_list, 120);
  list_add_to_back(my_list, 150);
  list_add_to_back(my_list, 300);
  list_add_to_back(my_list, 220);
  list_add_to_back(my_list, 210);
  // list_add_to_back(my_list, 310);


  // should remove the last element
  remove1 = list_remove_at_index(my_list, 300);
  if(strcmp("5->120->150->300->220->NULL",listToString(my_list))!=0 || remove1 != 210)
  {
    printf("Remove from a given index(index > length(list)) of a populated list: FAILED\n");
  }
  else {
    printf("Remove from a given index(index > length(list)) a populated list: PASSED\n");
  }

  remove1 = list_remove_at_index(my_list, 2);
  if(strcmp("5->120->300->220->NULL",listToString(my_list))!=0 || remove1 != 150)
  {
    printf("Remove from a given index(index < length(list)) of a populated list: FAILED\n");
  }
  else {
    printf("Remove from a given index(index < length(list)) a populated list: PASSED\n");
  }
  // reset test
  list_free(my_list);
  printf("\n");

// Tests for list_is_in()
  // Initialization
  printf("list_is_in():\n");
  my_list = list_alloc();

  bool is_in_1;
  bool is_in_2;
  bool is_in_3;
  is_in_1 = list_is_in(my_list,500);
  //
  // Empty List
  if(is_in_1 != false)
  {
    printf("Check if it is in an empty list: FAILED\n");
  }
  else {
    printf("Check if it is in an empty list: PASSED\n");
  }


  // construct the list
  list_add_to_back(my_list, 5);
  list_add_to_back(my_list, 120);
  list_add_to_back(my_list, 150);
  list_add_to_back(my_list, 300);
  list_add_to_back(my_list, 220);
  // list_add_to_back(my_list, 210);

  is_in_2 = list_is_in(my_list,210);
  //
  // Empty List
  if(is_in_2 != false)
  {
    printf("Check if it is in a populated list(PRESENT): FAILED\n");
  }
  else {
    printf("Check if it is in a populated list(PRESENT): PASSED\n");
  }

  is_in_2 = list_is_in(my_list,210);
  //
  // Empty List
  if(is_in_2 != false)
  {
    printf("Check if it is in a populated list(ABSENT): FAILED\n");
  }
  else {
    printf("Check if it is in a populated list(ABSENT): PASSED\n");
  }

  // reset test
  list_free(my_list);
  printf("\n");

// Tests for list_is_in()
  // Initialization
  printf("list_get_elem_at():\n");
  my_list = list_alloc();

  elem elem1 = list_get_elem_at(my_list,200);
  //
  // Empty List
  if(elem1 != -1)
  {
    printf("Get element at when list is empty: FAILED\n");
  }
  else {
    printf("Get element at when list is empty: PASSED\n");
  }


  // construct the list
  list_add_to_back(my_list, 5);
  list_add_to_back(my_list, 120);
  list_add_to_back(my_list, 150);
  list_add_to_back(my_list, 300);
  list_add_to_back(my_list, 220);
  // list_add_to_back(my_list, 210);

  is_in_2 = list_is_in(my_list,210);
  //
  // Empty List
  if(is_in_2 != false)
  {
    printf("Check if it is in a populated list(PRESENT): FAILED\n");
  }
  else {
    printf("Check if it is in a populated list(PRESENT): PASSED\n");
  }

  is_in_2 = list_is_in(my_list,210);
  //
  // Empty List
  if(is_in_2 != false)
  {
    printf("Check if it is in a populated list(PRESENT): FAILED\n");
  }
  else {
    printf("Check if it is in a populated list(PRESENT): PASSED\n");
  }


  // // should remove the last element
  // remove1 = list_remove_at_index(my_list, 300);
  // if(strcmp("5->120->150->300->220->NULL",listToString(my_list))!=0 || remove1 != 210)
  // {
  //   printf("Remove from a given index(index > length(list)) of a populated list: FAILED\n");
  // }
  // else {
  //   printf("Remove from a given index(index > length(list)) a populated list: PASSED\n");
  // }

  // remove1 = list_remove_at_index(my_list, 2);
  // if(strcmp("5->120->300->220->NULL",listToString(my_list))!=0 || remove1 != 150)
  // {
  //   printf("Remove from a given index(index < length(list)) of a populated list: FAILED\n");
  // }
  // else {
  //   printf("Remove from a given index(index < length(list)) a populated list: PASSED\n");
  // }





  // //Should add to the end of the list
  // list_add_at_index(my_list, 300, 1000);
  // // Empty List
  // if(strcmp("20->300->NULL",listToString(my_list))!=0)
  // {
  //   printf("Added to a given index(index >= length(list)) of an empty list: FAILED\n");
  // }
  // else {
  //   printf("Added to a given index(index >= length(list)) an empty list: PASSED\n");
  // }



  // // With members
  // list_add_at_index(my_list, 420, 0);
  // list_add_at_index(my_list, 660, 2);
  // list_add_at_index(my_list, 122, 1);
  // list_add_at_index(my_list, 330, 4);
  // list_add_at_index(my_list, 111, 2);
  // list_add_at_index(my_list, 440, 4);
  // list_add_at_index(my_list, 110, 4);
  // list_add_at_index(my_list, 123, 3);
  // 
  // if(strcmp("420->122->111->123->20->110->440->660->330->300->NULL",listToString(my_list))!=0)
  // {
  //   printf("Added to a list with existing nodes: FAILED\n");
  // }
  // else {
  //   printf("Added to a with existing nodes: PASSED\n");
  // }
  // reset test
  // list_free(my_list);
  // printf("\n");


  // // With members
  // list_add_at_index(my_list, 420, 0);
  // list_add_at_index(my_list, 660, 2);
  // list_add_at_index(my_list, 122, 1);
  // list_add_at_index(my_list, 330, 4);
  // list_add_at_index(my_list, 111, 2);
  // list_add_at_index(my_list, 440, 4);
  // list_add_at_index(my_list, 110, 4);
  // list_add_at_index(my_list, 123, 3);
  // 
  // if(strcmp("420->122->111->123->20->110->440->660->330->300->NULL",listToString(my_list))!=0)
  // {
  //   printf("Added to a list with existing nodes: FAILED\n");
  // }
  // else {
  //   printf("Added to a with existing nodes: PASSED\n");
  // }
  // reset test


  // list_add_to_back(mylist, 39);
  // list_print(mylist);
  // list_add_to_back(mylist, 18);
  // list_add_to_back(mylist, 42);
  // list_add_to_back(mylist, 190);
  // list_print(mylist);
  // list_free(mylist);
  // list_print(mylist);
  return 0;
}
