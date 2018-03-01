#include <stdio.h>

typedef struct list_s {
	struct list_s * next;
	int data;
} list_t;

/*int count_list_items(const list_t *head) {*/
	/*if (head->next) {*/
		/*return count_list_items(head->next) + 1;*/
	/*} else {*/
		/*return 1;*/
	/*}*/
/*}*/
unsigned int count_list_items(const list_t *head) {
	/*correct*/
	unsigned int i = 0;
	while (head != NULL) {
		head = head->next;
		i++;
	}
	return i;
}

/*void insert_next_to_list(list_t *item, int data) {*/
	/*(item->next = malloc(sizeof(list_t)))->next = item->next;*/
	/*item->next->data = data;*/
/*}*/
void insert_next_to_list(list_t *item, int data) {
	(item->next = malloc(sizeof(list_t)))->next = item->next;
	item->next->data = data;
}

void remove_next_from_list(list_t *item) {
	if (item->next) {
		free(item->next);
		item->next = item->next->next;
	}
}

/*char *item_data(const list_t *list) {*/
	/*char buf[12];*/
	/*sprintf(buf, "%d", list->data);*/
	/*return buf;*/
/*}*/
char *item_data(const list_t *list) {
	/*correct*/
	static char buf[12];
	sprintf(buf, "%d", list->data);
	return buf;
}

void testunit1() {
	/*У меня при 175555 упал при вызове функции count_list_items*/
	const unsigned int countItems = 175555;
	list_t list[countItems];
	for (int i = 0; i < countItems; i++) {
		list[i].data = i + 1;
		list[i].next = &list[i + 1];
	}
	list[countItems - 1].data = countItems;
	list[countItems - 1].next = NULL;

	printf("Count: %d\n", count_list_items(list));
}

void testunit4() {
	const unsigned int countItems = 10;
	list_t list[countItems];
	for (int i = 0; i < countItems; i++) {
		list[i].data = i + 1;
		list[i].next = &list[i + 1];
	}
	list[countItems - 1].data = countItems;
	list[countItems - 1].next = NULL;
	printf("%s\n", item_data(&list[6]));
}

int main(int argc, const char *argv[]) {

	/*testunit1();*/
	/*testunit4();*/
	/*printf("%d\n", count_list_items(list));*/


	return 0;
}
