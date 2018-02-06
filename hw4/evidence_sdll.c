/* Melanie Chow
   CS152, Winter 2018
   HW 4
*/

#include "sdll.h"
#include <stdlib.h>

void evidence_listnew()
{
	sdll *testing = list_new();
	fprintf(stdout, "Expecting [ ]\n");
	list_show(stdout,testing,'|');
	fprintf(stdout,"\n");
}

void evidence_node_show(FILE *f, node *nd)
{
	node_show(f,nd);
	fprintf(stdout,"\n");
}

void evidence_list_show(FILE *f, sdll *list, char sep)
{
        list_show(f,list,sep);
	fprintf(stdout,"\n");
}

void evidence_find_first(sdll *list, char *val)
{
	node *retnode = find_first(list,val);
	node_show(stdout,retnode);
	fprintf(stdout,"\n");
}

void evidence_get_first(sdll *list)
{
	node *retnode = get_first(list);
	node_show(stdout,retnode);
	fprintf(stdout,"\n");
}


void evidence_get_last(sdll *list)
{
	node *retnode = get_last(list);
        node_show(stdout,retnode);
	fprintf(stdout,"\n");
}


void evidence_get_next(sdll *list, node *nd)
{
	node_show(stdout, get_next(list,nd));
	fprintf(stdout,"\n");
}

void evidence_get_previous(sdll *list, node *nd)
{
	node_show(stdout, get_previous(list,nd));
	fprintf(stdout,"\n");
}

void evidence_get_at_index(sdll *list, size_t index)
{
	node_show(stdout, get_at_index(list,index));
	fprintf(stdout,"\n");
}

void evidence_insert_after(sdll *list, char *sought_val, char *new_val)
{
	sdll *retlist = insert_after(list, sought_val, new_val);
	list_show(stdout, retlist, '|');
	fprintf(stdout,"\n");
}

void evidence_insert_before(sdll *list, char *sought_val, char *new_val)
{
	sdll *retlist = insert_before(list, sought_val, new_val);
        list_show(stdout, retlist, '|');
	fprintf(stdout,"\n");
}

void evidence_insert_at_index(sdll *list, size_t index, char *new_val)
{
	sdll *retlist = insert_at_index(list, index, new_val);
        list_show(stdout, retlist, '|');
	fprintf(stdout,"\n");
}

void evidence_remove_first(sdll *list, char *sought_val)
{
	sdll *retlist = remove_first(list, sought_val);
        list_show(stdout, retlist, '|');
	fprintf(stdout,"\n");
}

void evidence_remove_all(sdll *list, char *sought_val)
{
	sdll *retlist = remove_all(list, sought_val);
        list_show(stdout, retlist, '|');
	fprintf(stdout,"\n");
}

int main()
{
	//TEST CASES////////////////////////

	//Single Node
	node *node1=malloc(sizeof (node));
        node1->value = "hello";
        node1->next = NULL;
        node1->prev = NULL;


	//5 element list

        sdll *testlist1 = list_new();
        node *list1node1 = malloc(sizeof(node));
        list1node1->value = "Aa";
        node *list1node2 = malloc(sizeof(node));
        list1node2->value = "Bb";
        node *list1node3 = malloc(sizeof(node));
        list1node3->value = "Cc";
        node *list1node4 = malloc(sizeof(node));
        list1node4->value = "Dd";
        node *list1node5 = malloc(sizeof(node));
        list1node5->value = "Dd";

        list1node1->prev = NULL;
        list1node1->next = list1node2;

        list1node2->prev=list1node1;
        list1node2->next =list1node3;

        list1node3->prev=list1node2;
        list1node3->next =list1node4;

        list1node4->prev=list1node3;
        list1node4->next =list1node5;

        list1node5->prev=list1node4;
        list1node5->next = NULL;

        testlist1->first = list1node1;
        testlist1->last  = list1node5;
	
	//empty list--------------------
        sdll *testlist2 = list_new();

        //2 element list----------------
        sdll *testlist3 = list_new();
        node *list3node1 = malloc(sizeof(node));
        list3node1->value = "Hi";
        node *list3node2 = malloc(sizeof(node));
        list3node2->value = "Bye";

        list3node1->prev = NULL;
        list3node1->next = list3node2;

        list3node2->prev=list3node1;
        list3node2->next= NULL;

        testlist3->first = list3node1;
        testlist3->last = list3node2;

	//////TESTING/////////////////////////

	/*------------------------------------*/
	fprintf(stdout, "****Testing list_new\n");
	fprintf(stdout, "Expecting [ ]\n");
	evidence_listnew();
	
	/*------------------------------------*/
	fprintf(stdout, "****Testing node_show\n");
	fprintf(stdout, "Expecting [hello]\n");
	evidence_node_show(stdout,node1);

	/*------------------------------------*/
	fprintf(stdout, "****Testing list_show\n");
	fprintf(stdout, "Expecting [Aa]|[Bb]|[Cc]|[Dd]|[Dd]\n");
	evidence_list_show(stdout,testlist1,'|');
	
	fprintf(stdout, "Expecting [ ]\n");
	evidence_list_show(stdout, testlist2, '|');

	fprintf(stdout, "Expecting [Hi]:[Bye]\n");
        evidence_list_show(stdout, testlist3, ':');

	/*------------------------------------*/
	fprintf(stdout, "****Testing find_first\n");
        fprintf(stdout, "Expecting [Cc]\n");
        evidence_find_first(testlist1,"Cc");

        fprintf(stdout, "Expecting [ ] (Null)\n");
        evidence_find_first(testlist2, "Hi");

        fprintf(stdout, "Expecting [ ] (Null)\n");
        evidence_find_first(testlist3, "bye");

	fprintf(stdout, "Expecting [Bye] \n");
        evidence_find_first(testlist3, "Bye");

	/*------------------------------------*/
	fprintf(stdout, "****Testing get_first\n");
        fprintf(stdout, "Expecting [Aa]\n");
        evidence_get_first(testlist1);

        fprintf(stdout, "Expecting [ ]\n");
        evidence_get_first(testlist2);

        fprintf(stdout, "Expecting [Bye]\n");
        evidence_get_first(testlist3);

	/*------------------------------------*/
	fprintf(stdout, "****Testing get_last\n");
        fprintf(stdout, "Expecting [Dd]\n");
        evidence_get_last(testlist1);

        fprintf(stdout, "Expecting [ ]\n");
        evidence_get_last(testlist2);

        fprintf(stdout, "Expecting [Bye]\n");
        evidence_get_last(testlist3);
	
	/*------------------------------------*/
	fprintf(stdout, "****Testing get_next\n");
	fprintf(stdout, "Expecting [Bb]");
        evidence_get_next(testlist1, list1node1);

	fprintf(stdout, "Expecting [Cc]");
        evidence_get_next(testlist1, list1node2);

	fprintf(stdout, "Expecting [ ](Null)\n");
        evidence_get_next(testlist2,NULL);

        fprintf(stdout, "Expecting [Bye]\n");
        evidence_get_next(testlist3,list3node1);

	fprintf(stdout, "Expecting [ ] (Null)\n");
        evidence_get_next(testlist3,list3node2);

	/*------------------------------------*/
	fprintf(stdout, "****Testing get_previous\n");
        fprintf(stdout, "Expecting [Dd]");
        evidence_get_previous(testlist1, list1node5);

        fprintf(stdout, "Expecting [Aa]");
        evidence_get_previous(testlist1, list1node2);

	fprintf(stdout, "Expecting [ ](Null)\n");
        evidence_get_previous(testlist2,NULL);

        fprintf(stdout, "Expecting [ ](Null)\n");
        evidence_get_previous(testlist3,list3node1);

        fprintf(stdout, "Expecting [Hi]\n");
        evidence_get_previous(testlist3,list3node2);

	/*------------------------------------*/
	fprintf(stdout, "****Testing get_at_index\n");
	fprintf(stdout, "Expecting [Aa]\n");
        evidence_get_at_index(testlist1,0);
	
	fprintf(stdout, "Expecting [ ] (Null)\n");
        evidence_get_at_index(testlist2, 1);

	fprintf(stdout, "Expecting [ ](Null)\n");
        evidence_get_at_index(testlist3,2);

        fprintf(stdout, "Expecting [Bye]\n");
        evidence_get_at_index(testlist3,1);

	/*------------------------------------*/
	fprintf(stdout, "****Testing insert_after\n");
	fprintf(stdout, "Expecting [Aa][Bb][Cc][Dd][Ee][Dd]\n");
	evidence_insert_after(testlist1, "Dd", "Ee");
	
	fprintf(stdout, "Expecting [ ] (Null)\n");
        evidence_insert_after(testlist2, "Hi", "Bye");
	
	fprintf(stdout, "Expecting [ ](Null)\n");
        evidence_insert_after(testlist3,"Hola", "Bienvenido");

	/*------------------------------------*/
	fprintf(stdout, "****Testing insert_before\n");
	fprintf(stdout, "Expecting [Aa][Bb][Cc][Ee][Dd][Ee][Dd]\n");
        evidence_insert_before(testlist1, "Dd", "Ee");
	
	fprintf(stdout, "Expecting [ ] (Null)\n");
        evidence_insert_before(testlist2, "Hi", "Bye");

	fprintf(stdout, "Expecting [ ](Null)\n");
        evidence_insert_before(testlist3,"Hola", "Hola!!");
	/*------------------------------------*/
	fprintf(stdout, "****Testing insert_at_index\n");
	fprintf(stdout, "Expecting [Aa][Bb][Cc][xP][Ee][Dd][Ee][Dd]\n");
	evidence_insert_at_index(testlist1, 3, "xP");

	fprintf(stdout, "Expecting [ ] (null)\n");
        evidence_insert_at_index(testlist2, 3, "xP");

	fprintf(stdout, "Expecting [ ] (null) \n");
        evidence_insert_at_index(testlist3, 2, "xP");

	fprintf(stdout, "Expecting [Greetings:]|[Hi]|[Bye]\n");
        evidence_insert_at_index(testlist3, 0, "Greetings:");

	fprintf(stdout,"\n"); 
	fprintf(stdout, "Expecting [Greetings:]|[Hi]|[Bye]|[Bye]\n");
        evidence_insert_at_index(testlist3, 2, "Bye");
	/*------------------------------------*/

	fprintf(stdout, "****Testing remove_first\n");
	fprintf(stdout, "Expecting [Bb][Cc][xP][Ee][Dd][Ee][Dd]\n");
        evidence_remove_first(testlist1, "Aa");
	
	fprintf(stdout, "\n");
	fprintf(stdout, "Expecting [Bb][Cc][xP][Ee][Ee][Dd]\n");
        evidence_remove_first(testlist1, "Dd");

	fprintf(stdout, "Expecting [ ] (null) \n");
        evidence_remove_first(testlist2,"xP");

	fprintf(stdout, "Expecting [Hi]]|[Bye]|[Bye] \n");
        evidence_remove_first(testlist3,"Greetings:");

	/*------------------------------------*/
	fprintf(stdout, "****Testing remove_all\n");
	fprintf(stdout, "Expecting [Bb][Cc][xP][Dd]\n");
	evidence_remove_all(testlist1,"Ee");

	fprintf(stdout, "Expecting [ ] (null)\n");
        evidence_remove_all(testlist1,"Bye");

	fprintf(stdout, "Expecting [ ] (null)\n");
        evidence_remove_all(testlist2,"WoaH!");

	fprintf(stdout, "Expecting [Hi]\n");
        evidence_remove_all(testlist3,"Bye");
	/*------------------------------------*/
	list_free(testlist1);
	list_free(testlist2);
	list_free(testlist3);
	return 0;
}
