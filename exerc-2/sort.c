#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <glib.h>

typedef struct {
	char *data;
	int key;
} data_t;


void destroy_item(gpointer item, gpointer unused_data) {
	free(((data_t*)item)->data);
	free((data_t*)item);
}


void print_item(gpointer data, gpointer user_data) {
	printf("%d: %s\n", ((data_t*)data)->key, ((data_t*)data)->data);
}

gint compare_item(gconstpointer a, gconstpointer b) {
	if(((data_t *) a)->key < ((data_t *) b)->key) { return -1; }
	else if(((data_t *) a)->key > ((data_t *) b)->key) { return 1; }
	else { return 0; }
}

GList *insert_element(GList *list, int key, char *data) {
	data_t *info = (data_t*)malloc(sizeof(data_t));
	info->key = key;
	info->data = data;
	GList *newlist = g_list_append(list, &info);
	return list;
}

data_t *item_init(int key, char *data) {
	data_t *item = malloc(sizeof(data_t));
	item->key = key;
	item->data = strdup(data);
	return item;
}

int main(void) {
	
	GList *list = g_list_append(NULL, item_init(2, "def"));
	list = g_list_append(list, item_init(1, "abc"));

	list = g_list_sort(list, compare_item);
	g_list_foreach(list, print_item, NULL);

	g_list_foreach(list, destroy_item, NULL);
	g_list_free(list);
	return 0;
}

