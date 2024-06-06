# perf cache-miss
sudo perf stat -e kmem:kmem_cache_alloc ./a.out

use 'perf list' to see what is enabel in this env.
