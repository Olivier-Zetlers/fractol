#define _GNU_SOURCE
#include <dlfcn.h>
#include <stddef.h>

static int fail_count = 0;

void *mlx_new_window(void *mlx, int w, int h, char *title)
{
    fail_count++;
    if (fail_count == 1) {
        // First call fails to trigger the leak
        return NULL;
    }
    // Subsequent calls work normally
    void *(*real_mlx_new_window)(void*, int, int, char*);
    real_mlx_new_window = dlsym(RTLD_NEXT, "mlx_new_window");
    return real_mlx_new_window(mlx, w, h, title);
}
