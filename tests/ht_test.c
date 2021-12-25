#include <types.h>
#include <util.h>
#include <ht.h>
#include <prof.h>
#include <me.h>

i32_t main() {
    prof_t profiler;
    start_profiling(&profiler, "hash table test"); 

    ht_t table = create_ht(100);

    insert_to_ht(&table, "player_pos", "100;100");
    insert_to_ht(&table, "enemy_pos", "99;99");
    m4x4_t identity = identity_m4x4();
    insert_to_ht(&table, "m4x4", &identity);

    print_n("%s", get_from_ht(table, "player_pos"));
    print_n("%s", get_from_ht(table, "enemy_pos"));

    m4x4_t * identity_ptr = get_from_ht(table, "m4x4");
    for (i32_t x = 0; x < 4; x++) {
        for (i32_t y = 0; y < 4; y++) {
            print("%f ", identity_ptr -> elems[y][x]);
        }
        print("\n");
    }
    end_profiling(&profiler);
    print_n("%s", profiler.elapsed_string);    

}


