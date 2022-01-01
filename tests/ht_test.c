#include <extd_cstd/lib.h>

i32 main() {
    ht_t table = ht_create(100);

    ht_insert(NULL, "player_pos", "100;100");
    ht_insert(&table, "enemy_pos", "99;99");
    m4x4_t identity = mk_identity_m4x4();
    ht_insert(&table, "m4x4", &identity);

    log_msg("%s", ht_get(&table, "player_pos"));
    log_msg("%s", ht_get(&table, "enemy_pos"));

    m4x4_t * identity_ptr = ht_get(&table, "m4x4");
    for (i32 x = 0; x < 4; x++) {
        for (i32 y = 0; y < 4; y++) {
            printf("%f ", identity_ptr -> elems[y][x]);
        }
        printf("\n");
    }
}


