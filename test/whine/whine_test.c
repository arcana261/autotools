#include <locale.h>

#include <whine/whine.h>
#include "config.h"

void test_get_my_name(void) {
	g_assert_cmpstr("Mehdi", ==, get_my_name());
}

int main(int argc, char* argv[]) {
	g_test_init(&argc, &argv, NULL);
	g_test_bug_base(PACKAGE_BUGREPORT);

	g_test_add_func("/whine/get_my_name", test_get_my_name);

	return g_test_run();
}
