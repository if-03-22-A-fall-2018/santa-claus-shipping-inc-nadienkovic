#include "child_data_mgmt.h"
#include <stdlib.h>

struct _childDataMgmt{
  List* list;
};
/**
 * Creates a structure for child data management
 */
ChildDataMgmt* cdm_create(){
  ChildDataMgmt* crnt = (ChildDataMgmt*)malloc(sizeof(ChildDataMgmt));
  crnt->list = list_create();
  return crnt;
}

/**
 * Uses the child management logic to process child data
 * (hint: insert it, sorted by town into the internal list)
 */
void cdm_add_data(ChildDataMgmt *cdm, ChildData *data){
  Node* crnt_node = list_get_first(cdm->list);
  Node* last_node_of_city = 0;

  while(crnt_node != 0){
    if(((ChildData*)list_get_data(crnt_node))->city == data->city){
      last_node_of_city = crnt_node;
    }
    else if((list_get_next(crnt_node) == 0) && (last_node_of_city == 0)){
      last_node_of_city = crnt_node;
    }
    crnt_node = list_get_next(crnt_node);
  }

  if(last_node_of_city == 0){
    list_add(cdm->list, data);
  }
  else{
    list_insert_after(last_node_of_city, data);
  }
}

/**
 * Returns a pointer to the first element of the properly sorted list
 * (hint: "sorting" should have already happened when inserting)
 */
Node* cdm_get_sorted_data(ChildDataMgmt *cdm){
  return list_get_first(cdm->list);
}

/**
 * Used to clean up memory allocated when creating the child management structure
 */
void cdm_delete(ChildDataMgmt *cdm){
  free(cdm);
}
