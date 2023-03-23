#include <check.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "../3d_viewer_v1.0/parser/parser.h"

START_TEST(parser_main_vertexes) {
  data_t a = {};
  parse("./obj/cube.obj", &a);

  ck_assert_float_eq_tol(a.vertex[0], 0, 1e-6);
  ck_assert_float_eq_tol(a.vertex[1], 0, 1e-6);
  ck_assert_float_eq_tol(a.vertex[2], 0, 1e-6);
  ck_assert_float_eq_tol(a.vertex[3], 0, 1e-6);
  ck_assert_float_eq_tol(a.vertex[4], 0, 1e-6);
  ck_assert_float_eq_tol(a.vertex[5], 1, 1e-6);
  ck_assert_float_eq_tol(a.vertex[6], 0, 1e-6);
  ck_assert_float_eq_tol(a.vertex[7], 1, 1e-6);
  ck_assert_float_eq_tol(a.vertex[8], 0, 1e-6);
  ck_assert_float_eq_tol(a.vertex[9], 0, 1e-6);
  ck_assert_float_eq_tol(a.vertex[10], 1, 1e-6);
  ck_assert_float_eq_tol(a.vertex[11], 1, 1e-6);
  ck_assert_float_eq_tol(a.vertex[12], 1, 1e-6);
  ck_assert_float_eq_tol(a.vertex[13], 0, 1e-6);
  ck_assert_float_eq_tol(a.vertex[14], 0, 1e-6);
  ck_assert_float_eq_tol(a.vertex[15], 1, 1e-6);
  ck_assert_float_eq_tol(a.vertex[16], 0, 1e-6);
  ck_assert_float_eq_tol(a.vertex[17], 1, 1e-6);
  ck_assert_float_eq_tol(a.vertex[18], 1, 1e-6);
  ck_assert_float_eq_tol(a.vertex[19], 1, 1e-6);
  ck_assert_float_eq_tol(a.vertex[20], 0, 1e-6);
  ck_assert_float_eq_tol(a.vertex[21], 1, 1e-6);
  ck_assert_float_eq_tol(a.vertex[22], 1, 1e-6);
  ck_assert_float_eq_tol(a.vertex[23], 1, 1e-6);
}
END_TEST

START_TEST(parser_main_polygons) {
  data_t a = {};
  parse("./obj/cube.obj", &a);

  ck_assert_uint_eq(a.polygons[0], 0);
  ck_assert_uint_eq(a.polygons[1], 6);
  ck_assert_uint_eq(a.polygons[2], 6);
  ck_assert_uint_eq(a.polygons[3], 4);
  ck_assert_uint_eq(a.polygons[4], 4);
  ck_assert_uint_eq(a.polygons[5], 0);
  ck_assert_uint_eq(a.polygons[6], 0);
  ck_assert_uint_eq(a.polygons[7], 2);
  ck_assert_uint_eq(a.polygons[8], 2);
  ck_assert_uint_eq(a.polygons[9], 6);
  ck_assert_uint_eq(a.polygons[10], 6);
  ck_assert_uint_eq(a.polygons[11], 0);
  ck_assert_uint_eq(a.polygons[12], 0);
  ck_assert_uint_eq(a.polygons[13], 3);
  ck_assert_uint_eq(a.polygons[14], 3);
  ck_assert_uint_eq(a.polygons[15], 2);
  ck_assert_uint_eq(a.polygons[16], 2);
  ck_assert_uint_eq(a.polygons[17], 0);
  ck_assert_uint_eq(a.polygons[18], 0);
  ck_assert_uint_eq(a.polygons[19], 1);
  ck_assert_uint_eq(a.polygons[20], 1);
  ck_assert_uint_eq(a.polygons[21], 3);
  ck_assert_uint_eq(a.polygons[22], 3);
  ck_assert_uint_eq(a.polygons[23], 0);
  ck_assert_uint_eq(a.polygons[24], 2);
  ck_assert_uint_eq(a.polygons[25], 7);
  ck_assert_uint_eq(a.polygons[26], 7);
  ck_assert_uint_eq(a.polygons[27], 6);
  ck_assert_uint_eq(a.polygons[28], 6);
  ck_assert_uint_eq(a.polygons[29], 2);

  ck_assert_float_eq(a.polygons[30], 2);
  ck_assert_float_eq(a.polygons[31], 3);
  ck_assert_float_eq(a.polygons[32], 3);
  ck_assert_float_eq(a.polygons[33], 7);
  ck_assert_float_eq(a.polygons[34], 7);
  ck_assert_float_eq(a.polygons[35], 2);
  ck_assert_float_eq(a.polygons[36], 4);
  ck_assert_float_eq(a.polygons[37], 6);
  ck_assert_float_eq(a.polygons[38], 6);
  ck_assert_float_eq(a.polygons[39], 7);
  ck_assert_float_eq(a.polygons[40], 7);
  ck_assert_float_eq(a.polygons[41], 4);
  ck_assert_float_eq(a.polygons[42], 4);
  ck_assert_float_eq(a.polygons[43], 7);
  ck_assert_float_eq(a.polygons[44], 7);
  ck_assert_float_eq(a.polygons[45], 5);
  ck_assert_float_eq(a.polygons[46], 5);
  ck_assert_float_eq(a.polygons[47], 4);
  ck_assert_float_eq(a.polygons[48], 0);
  ck_assert_float_eq(a.polygons[49], 4);
  ck_assert_float_eq(a.polygons[50], 4);
  ck_assert_float_eq(a.polygons[51], 5);
  ck_assert_float_eq(a.polygons[52], 5);
  ck_assert_float_eq(a.polygons[53], 0);
  ck_assert_float_eq(a.polygons[54], 0);
  ck_assert_float_eq(a.polygons[55], 5);
  ck_assert_float_eq(a.polygons[56], 5);
  ck_assert_float_eq(a.polygons[57], 1);
  ck_assert_float_eq(a.polygons[58], 1);
  ck_assert_float_eq(a.polygons[59], 0);
  ck_assert_float_eq(a.polygons[60], 1);
  ck_assert_float_eq(a.polygons[61], 5);
  ck_assert_float_eq(a.polygons[62], 5);
  ck_assert_float_eq(a.polygons[63], 7);
  ck_assert_float_eq(a.polygons[64], 7);
  ck_assert_float_eq(a.polygons[65], 1);
  ck_assert_float_eq(a.polygons[66], 1);
  ck_assert_float_eq(a.polygons[67], 7);
  ck_assert_float_eq(a.polygons[68], 7);
  ck_assert_float_eq(a.polygons[69], 3);
  ck_assert_float_eq(a.polygons[70], 3);
  ck_assert_float_eq(a.polygons[71], 1);
}
END_TEST

START_TEST(parser_main_counts) {
  data_t a = {};
  parse("./obj/cube.obj", &a);
  ck_assert_uint_eq(a.vertex_size, 24);
  ck_assert_uint_eq(a.polygon_size, 72);
}
END_TEST

START_TEST(parser_rotation_x) {
  data_t a = {};
  parse("./obj/cube.obj", &a);
  rotation_x(&a, 3);

  ck_assert_float_eq_tol(a.vertex[0], 0, 1e-6);
  ck_assert_float_eq_tol(a.vertex[1], 0, 1e-6);
  ck_assert_float_eq_tol(a.vertex[2], 0, 1e-6);
  ck_assert_float_eq_tol(a.vertex[3], 0, 1e-6);
  ck_assert_float_eq_tol(a.vertex[4], -0.052336, 1e-5);
  ck_assert_float_eq_tol(a.vertex[5], 0.99863, 1e-5);
  ck_assert_float_eq_tol(a.vertex[6], 0, 1e-6);
  ck_assert_float_eq_tol(a.vertex[7], 0.99863, 1e-5);
  ck_assert_float_eq_tol(a.vertex[8], 0.052336, 1e-5);
  ck_assert_float_eq_tol(a.vertex[9], 0, 1e-6);
  ck_assert_float_eq_tol(a.vertex[10], 0.946294, 1e-5);
  ck_assert_float_eq_tol(a.vertex[11], 1.05097, 1e-5);
  ck_assert_float_eq_tol(a.vertex[12], 1, 1e-5);
  ck_assert_float_eq_tol(a.vertex[13], 0, 1e-6);
  ck_assert_float_eq_tol(a.vertex[14], 0, 1e-4);
  ck_assert_float_eq_tol(a.vertex[15], 1, 1e-5);
  ck_assert_float_eq_tol(a.vertex[16], -0.052336, 1e-5);
  ck_assert_float_eq_tol(a.vertex[17], 0.99863, 1e-5);
  ck_assert_float_eq_tol(a.vertex[18], 1, 1e-5);
  ck_assert_float_eq_tol(a.vertex[19], 0.99863, 1e-5);
  ck_assert_float_eq_tol(a.vertex[20], 0.052336, 1e-5);
  ck_assert_float_eq_tol(a.vertex[21], 1, 1e-5);
  ck_assert_float_eq_tol(a.vertex[22], 0.946294, 1e-5);
  ck_assert_float_eq_tol(a.vertex[23], 1.05097, 1e-5);
}
END_TEST

START_TEST(parser_rotation_y) {
  data_t a = {};
  parse("./obj/cube.obj", &a);

  rotation_y(&a, 2);

  ck_assert_float_eq_tol(a.vertex[0], 0, 1e-6);
  ck_assert_float_eq_tol(a.vertex[1], 0, 1e-6);
  ck_assert_float_eq_tol(a.vertex[2], 0, 1e-6);
  ck_assert_float_eq_tol(a.vertex[3], 0.0348995, 1e-5);
  ck_assert_float_eq_tol(a.vertex[4], 0, 1e-6);
  ck_assert_float_eq_tol(a.vertex[5], 0.999391, 1e-5);
  ck_assert_float_eq_tol(a.vertex[6], 0, 1e-6);
  ck_assert_float_eq_tol(a.vertex[7], 1, 1e-5);
  ck_assert_float_eq_tol(a.vertex[8], 0, 1e-5);
  ck_assert_float_eq_tol(a.vertex[9], 0.0348995, 1e-5);
  ck_assert_float_eq_tol(a.vertex[10], 1, 1e-5);
  ck_assert_float_eq_tol(a.vertex[11], 0.999391, 1e-5);
  ck_assert_float_eq_tol(a.vertex[12], 0.999391, 1e-5);
  ck_assert_float_eq_tol(a.vertex[13], 0, 1e-4);
  ck_assert_float_eq_tol(a.vertex[14], -0.0348995, 1e-5);
  ck_assert_float_eq_tol(a.vertex[15], 1.03429, 1e-5);
  ck_assert_float_eq_tol(a.vertex[16], 0, 1e-6);
  ck_assert_float_eq_tol(a.vertex[17], 0.964491, 1e-5);
  ck_assert_float_eq_tol(a.vertex[18], 0.999391, 1e-5);
  ck_assert_float_eq_tol(a.vertex[19], 1, 1e-5);
  ck_assert_float_eq_tol(a.vertex[20], -0.0348995, 1e-5);
  ck_assert_float_eq_tol(a.vertex[21], 1.03429, 1e-5);
  ck_assert_float_eq_tol(a.vertex[22], 1, 1e-5);
  ck_assert_float_eq_tol(a.vertex[23], 0.964491, 1e-5);
}
END_TEST

START_TEST(parser_rotation_z) {
  data_t a = {};
  parse("./obj/cube.obj", &a);

  rotation_z(&a, 1);

  ck_assert_float_eq_tol(a.vertex[0], 0, 1e-6);
  ck_assert_float_eq_tol(a.vertex[1], 0, 1e-6);
  ck_assert_float_eq_tol(a.vertex[2], 0, 1e-6);
  ck_assert_float_eq_tol(a.vertex[3], 0, 1e-6);
  ck_assert_float_eq_tol(a.vertex[4], 0, 1e-6);
  ck_assert_float_eq_tol(a.vertex[5], 1, 1e-5);
  ck_assert_float_eq_tol(a.vertex[6], -0.0174524, 1e-5);
  ck_assert_float_eq_tol(a.vertex[7], 0.999848, 1e-5);
  ck_assert_float_eq_tol(a.vertex[8], 0, 1e-5);
  ck_assert_float_eq_tol(a.vertex[9], -0.0174524, 1e-5);
  ck_assert_float_eq_tol(a.vertex[10], 0.999848, 1e-5);
  ck_assert_float_eq_tol(a.vertex[11], 1, 1e-5);
  ck_assert_float_eq_tol(a.vertex[12], 0.999848, 1e-5);
  ck_assert_float_eq_tol(a.vertex[13], 0.0174524, 1e-5);
  ck_assert_float_eq_tol(a.vertex[14], 0, 1e-5);
  ck_assert_float_eq_tol(a.vertex[15], 0.999848, 1e-5);
  ck_assert_float_eq_tol(a.vertex[16], 0.0174524, 1e-5);
  ck_assert_float_eq_tol(a.vertex[17], 1, 1e-5);
  ck_assert_float_eq_tol(a.vertex[18], 0.982395, 1e-5);
  ck_assert_float_eq_tol(a.vertex[19], 1.0173, 1e-5);
  ck_assert_float_eq_tol(a.vertex[20], 0, 1e-4);
  ck_assert_float_eq_tol(a.vertex[21], 0.982395, 1e-5);
  ck_assert_float_eq_tol(a.vertex[22], 1.0173, 1e-5);
  ck_assert_float_eq_tol(a.vertex[23], 1, 1e-5);
}
END_TEST

START_TEST(parser_scale) {
  data_t a = {};
  parse("./obj/cube.obj", &a);

  scale(&a, -2.5);

  ck_assert_float_eq_tol(a.vertex[0], 0, 1e-6);
  ck_assert_float_eq_tol(a.vertex[1], 0, 1e-6);
  ck_assert_float_eq_tol(a.vertex[2], 0, 1e-6);
  ck_assert_float_eq_tol(a.vertex[3], 0, 1e-6);
  ck_assert_float_eq_tol(a.vertex[4], 0, 1e-6);
  ck_assert_float_eq_tol(a.vertex[5], -2.5, 1e-5);
  ck_assert_float_eq_tol(a.vertex[6], 0, 1e-6);
  ck_assert_float_eq_tol(a.vertex[7], -2.5, 1e-5);
  ck_assert_float_eq_tol(a.vertex[8], -0, 1e-5);
  ck_assert_float_eq_tol(a.vertex[9], -0, 1e-5);
  ck_assert_float_eq_tol(a.vertex[10], -2.5, 1e-5);
  ck_assert_float_eq_tol(a.vertex[11], -2.5, 1e-5);
  ck_assert_float_eq_tol(a.vertex[12], -2.5, 1e-5);
  ck_assert_float_eq_tol(a.vertex[13], -0, 1e-5);
  ck_assert_float_eq_tol(a.vertex[14], -0, 1e-5);
  ck_assert_float_eq_tol(a.vertex[15], -2.5, 1e-5);
  ck_assert_float_eq_tol(a.vertex[16], -0, 1e-5);
  ck_assert_float_eq_tol(a.vertex[17], -2.5, 1e-5);
  ck_assert_float_eq_tol(a.vertex[18], -2.5, 1e-5);
  ck_assert_float_eq_tol(a.vertex[19], -2.5, 1e-5);
  ck_assert_float_eq_tol(a.vertex[20], -0, 1e-5);
  ck_assert_float_eq_tol(a.vertex[21], -2.5, 1e-5);
  ck_assert_float_eq_tol(a.vertex[22], -2.5, 1e-4);
  ck_assert_float_eq_tol(a.vertex[23], -2.5, 1e-5);
}
END_TEST

START_TEST(parser_move_x) {
  data_t a = {};
  parse("./obj/cube.obj", &a);

  move_x(&a, 8);

  ck_assert_float_eq_tol(a.vertex[0], 8, 1e-5);
  ck_assert_float_eq_tol(a.vertex[1], 0, 1e-5);
  ck_assert_float_eq_tol(a.vertex[2], 0, 1e-5);
  ck_assert_float_eq_tol(a.vertex[3], 8, 1e-5);
  ck_assert_float_eq_tol(a.vertex[4], 0, 1e-5);
  ck_assert_float_eq_tol(a.vertex[5], 1, 1e-4);
  ck_assert_float_eq_tol(a.vertex[6], 8, 1e-5);
  ck_assert_float_eq_tol(a.vertex[7], 1, 1e-4);
  ck_assert_float_eq_tol(a.vertex[8], 0, 1e-4);
  ck_assert_float_eq_tol(a.vertex[9], 8, 1e-5);
  ck_assert_float_eq_tol(a.vertex[10], 1, 1e-5);
  ck_assert_float_eq_tol(a.vertex[11], 1, 1e-4);
  ck_assert_float_eq_tol(a.vertex[12], 9, 1e-4);
  ck_assert_float_eq_tol(a.vertex[13], 0, 1e-4);
  ck_assert_float_eq_tol(a.vertex[14], 0, 1e-4);
  ck_assert_float_eq_tol(a.vertex[15], 9, 1e-5);
  ck_assert_float_eq_tol(a.vertex[16], 0, 1e-5);
  ck_assert_float_eq_tol(a.vertex[17], 1, 1e-4);
  ck_assert_float_eq_tol(a.vertex[18], 9, 1e-5);
  ck_assert_float_eq_tol(a.vertex[19], 1, 1e-4);
  ck_assert_float_eq_tol(a.vertex[20], 0, 1e-4);
  ck_assert_float_eq_tol(a.vertex[21], 9, 1e-5);
  ck_assert_float_eq_tol(a.vertex[22], 1, 1e-5);
  ck_assert_float_eq_tol(a.vertex[23], 1, 1e-4);
}
END_TEST

START_TEST(parser_move_y) {
  data_t a = {};
  parse("./obj/cube.obj", &a);

  move_y(&a, 4);

  ck_assert_float_eq_tol(a.vertex[0], 0, 1e-4);
  ck_assert_float_eq_tol(a.vertex[1], 4, 1e-4);
  ck_assert_float_eq_tol(a.vertex[2], 0, 1e-5);
  ck_assert_float_eq_tol(a.vertex[3], 0, 1e-5);
  ck_assert_float_eq_tol(a.vertex[4], 4, 1e-5);
  ck_assert_float_eq_tol(a.vertex[5], 1, 1e-4);
  ck_assert_float_eq_tol(a.vertex[6], 0, 1e-5);
  ck_assert_float_eq_tol(a.vertex[7], 5, 1e-4);
  ck_assert_float_eq_tol(a.vertex[8], 0, 1e-4);
  ck_assert_float_eq_tol(a.vertex[9], 0, 1e-5);
  ck_assert_float_eq_tol(a.vertex[10], 5, 1e-5);
  ck_assert_float_eq_tol(a.vertex[11], 1, 1e-4);
  ck_assert_float_eq_tol(a.vertex[12], 1, 1e-4);
  ck_assert_float_eq_tol(a.vertex[13], 4, 1e-4);
  ck_assert_float_eq_tol(a.vertex[14], 0, 1e-4);
  ck_assert_float_eq_tol(a.vertex[15], 1, 1e-5);
  ck_assert_float_eq_tol(a.vertex[16], 4, 1e-5);
  ck_assert_float_eq_tol(a.vertex[17], 1, 1e-4);
  ck_assert_float_eq_tol(a.vertex[18], 1, 1e-5);
  ck_assert_float_eq_tol(a.vertex[19], 5, 1e-4);
  ck_assert_float_eq_tol(a.vertex[20], 0, 1e-4);
  ck_assert_float_eq_tol(a.vertex[21], 1, 1e-5);
  ck_assert_float_eq_tol(a.vertex[22], 5, 1e-5);
  ck_assert_float_eq_tol(a.vertex[23], 1, 1e-4);
}
END_TEST

START_TEST(parser_move_z) {
  data_t a = {};
  parse("./obj/cube.obj", &a);
  move_z(&a, 0);

  ck_assert_float_eq_tol(a.vertex[0], 0, 1e-6);
  ck_assert_float_eq_tol(a.vertex[1], 0, 1e-6);
  ck_assert_float_eq_tol(a.vertex[2], 0, 1e-6);
  ck_assert_float_eq_tol(a.vertex[3], 0, 1e-6);
  ck_assert_float_eq_tol(a.vertex[4], 0, 1e-6);
  ck_assert_float_eq_tol(a.vertex[5], 1, 1e-5);
  ck_assert_float_eq_tol(a.vertex[6], 0, 1e-6);
  ck_assert_float_eq_tol(a.vertex[7], 1, 1e-5);
  ck_assert_float_eq_tol(a.vertex[8], 0, 1e-5);
  ck_assert_float_eq_tol(a.vertex[9], 0, 1e-6);
  ck_assert_float_eq_tol(a.vertex[10], 1, 1e-6);
  ck_assert_float_eq_tol(a.vertex[11], 1, 1e-5);
  ck_assert_float_eq_tol(a.vertex[12], 1, 1e-5);
  ck_assert_float_eq_tol(a.vertex[13], 0, 1e-5);
  ck_assert_float_eq_tol(a.vertex[14], 0, 1e-5);
  ck_assert_float_eq_tol(a.vertex[15], 1, 1e-6);
  ck_assert_float_eq_tol(a.vertex[16], 0, 1e-6);
  ck_assert_float_eq_tol(a.vertex[17], 1, 1e-5);
  ck_assert_float_eq_tol(a.vertex[18], 1, 1e-6);
  ck_assert_float_eq_tol(a.vertex[19], 1, 1e-5);
  ck_assert_float_eq_tol(a.vertex[20], 0, 1e-5);
  ck_assert_float_eq_tol(a.vertex[21], 1, 1e-6);
  ck_assert_float_eq_tol(a.vertex[22], 1, 1e-6);
  ck_assert_float_eq_tol(a.vertex[23], 1, 1e-5);
}
END_TEST

int main(void) {
  Suite *s1 = suite_create("Core");
  TCase *tc1_1 = tcase_create("Core");
  SRunner *sr = srunner_create(s1);
  int nf;

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, parser_main_vertexes);
  tcase_add_test(tc1_1, parser_main_polygons);
  tcase_add_test(tc1_1, parser_main_counts);
  tcase_add_test(tc1_1, parser_rotation_x);
  tcase_add_test(tc1_1, parser_rotation_y);
  tcase_add_test(tc1_1, parser_rotation_z);
  tcase_add_test(tc1_1, parser_scale);
  tcase_add_test(tc1_1, parser_move_x);
  tcase_add_test(tc1_1, parser_move_y);
  tcase_add_test(tc1_1, parser_move_z);

  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}
