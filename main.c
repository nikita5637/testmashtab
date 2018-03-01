#include <stdio.h>

typedef struct list_s {
	struct list_s * next;
	int data;
} list_t;

/*debian 8, 1gb RAM*/ 
const unsigned int countItems = 275555;
list_t * list;

/*int count_list_items(const list_t *head) {
	if (head->next) {
		return count_list_items(head->next) + 1;
	} else {
		return 1;
	}
}*/
int count_list_items(const list_t *head) {
	//correct
	unsigned int i = 0;
	while (head != NULL) {
		head = head->next;
		i++;
	}
	return i;
}

/*void insert_next_to_list(list_t *item, int data) {
	(item->next = malloc(sizeof(list_t)))->next = item->next;
	item->next->data = data;
}*/
void insert_next_to_list(list_t *item, int data) {
	//correct
	if (!item) return;
	list_t * tmpItem = malloc(sizeof(list_t));
	if (tmpItem) {
		if (item->next)
			//Вставка в середину или начало
			tmpItem->next = item->next;
		else
			//Вставка в конец
			tmpItem->next = NULL;
		item->next = tmpItem;
		item->next->data = data;
	} else {
		return;
	}
}

/*void remove_next_from_list(list_t *item) {
	if (item->next) {
		free(item->next);
		item->next = item->next->next;
	}
}*/
void remove_next_from_list(list_t *item) {
	//correct
	if (!item) return;
	if (item->next) {
		list_t * tmp = item->next->next;
		printf("%x %x %x\n", item, item->next, tmp);
		free(item->next);
		item->next = tmp;
		printf("%x %x %x\n", item, item->next, tmp);
	}
}

/*char *item_data(const list_t *list) {
	char buf[12];
	sprintf(buf, "%d", list->data);
	return buf;
}*/
char *item_data(const list_t *list) {
	//correct
	if (!list) return 0;
	static char buf[12];
	sprintf(buf, "%d", list->data);
	return buf;
}

void testunit1(const list_t *item) {
	/*У меня при 275555 упал при вызове функции count_list_items*/
	printf("Count: %d\n", count_list_items(item));
}

void testunit2(list_t *item, int data) {
	insert_next_to_list(item, data);
}

void testunit3(list_t *item) {
	remove_next_from_list(item);
}

void testunit4(const list_t *item) {
	printf("Value: %s\n", item_data(item));
}

void PrintList() {
	//print list
	list_t * head = list;
	while (head) {
		printf("ADDRESS: %x DATA: %d\n", head, head->data);
		head = head->next;
	}
}

int main(int argc, const char *argv[]) {

	list_t * prev = NULL;
	list_t * curr = NULL;
	curr = malloc(sizeof(list_t));
	list = curr;
	prev = curr;
	for (int i = 1; i < countItems; i++) {
		curr = malloc(sizeof(list_t));
		curr->data = i;
		prev->next = curr;
		prev = curr;
	}
	curr->next = NULL;

/*-----------------*/
	/*testunit1(NULL); //segfault*/
/*-----------------*/
	/*testunit1(list); //segfault*/
/*-----------------*/

/*-----------------*/
	/*testunit2(NULL, 1); //segfault*/
/*-----------------*/
	/*testunit2(list, 2); //cycle*/
	/*PrintList();*/
/*-----------------*/

/*-----------------*/
	/*testunit3(NULL); //segfault*/
/*-----------------*/
	/*testunit3(list + 2 * (2)); //access to freed memory*/
	/*PrintList();*/
/*-----------------*/

/*-----------------*/
	/*testunit4(NULL); //segfault*/
/*-----------------*/
	/*testunit4(&list[2]); //access to freed memory*/
/*-----------------*/
	return 0;
}
