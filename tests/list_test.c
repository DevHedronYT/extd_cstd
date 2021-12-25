#include <util.h>
#include <types.h>
#include <list.h>

i32_t main() {
    list_t list = create_list(5);
    push_to_list(&list, 10);
    push_to_list(&list, 20);
    push_to_list(&list, 30);
    push_to_list(&list, 40);
    push_to_list(&list, 50);

    for (i32_t i = 0; i < list.idx; i++) {
        print_n("%d",  *((i32_t*)get_at_list_t(&list, i)));
    }
}
