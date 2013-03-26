#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/queue.h>

/*
 * LIST_HEAD(name, type)
 * LIST_HEAD_INITIALIZER(head)
 * LIST_ENTRY(type)
 * LIST_INIT(head)
 * LIST_INSERT_AFTER(listelm, elm, field)
 * LIST_INSERT_BEFORE(listelm, elm, field)
 * LIST_INSERT_HEAD(head, elm, field)
 * LIST_REMOVE(elm, field)
 * LIST_FOREACH(var, head, field)
 * LIST_EMPTY(head)
 * LIST_FIRST(head)
 * LIST_NEXT(elm, field)
 * */

LIST_HEAD(personHead, person) head;

#define SIZE_PERSON sizeof(struct person)

typedef struct person{
    char *name;
    int age;
    LIST_ENTRY(person) entries;
}persNode, *perNodePtr;

perNodePtr foo_struct(perNodePtr p, char *name, int age)
{
    p = (perNodePtr)malloc(SIZE_PERSON);
    p->name = name;
    p->age = age;
    return p;
}

int main()
{
    LIST_INIT(&head);
    perNodePtr p1 = NULL;
    p1 = foo_struct(p1, "Jim", 12);
    LIST_INSERT_HEAD(&head, p1, entries);

    perNodePtr p2 = NULL;
    p2 = foo_struct(p2, "Tom", 33);
    LIST_INSERT_AFTER(p1, p2, entries);

    perNodePtr p3 = NULL;
    p3 = foo_struct(p2, "Jerry", 21);
    LIST_INSERT_AFTER(p1, p3, entries);

    perNodePtr p;
    while(NULL != (p = LIST_FIRST(&head))) {
        LIST_REMOVE(p, entries);
        free(p);
    }

    LIST_FOREACH(p, &head, entries) {
        printf("%s\n%d\n", p->name, p->age);
    }
    return 0;
}
