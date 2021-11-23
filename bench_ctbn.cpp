#include <bench_ctbn.hpp>

sycl::event benchmark_ff_p_t_addition(sycl::queue &q, const uint32_t dim,
                                      const uint32_t wg_size,
                                      const uint32_t itr_count) {
  sycl::event evt = q.parallel_for(
      sycl::nd_range<2>{sycl::range<2>{dim, dim}, sycl::range<2>{1, wg_size}},
      [=](sycl::nd_item<2> it) {
        ff_p_t op1(2147483648_ZL);
        ff_p_t op2(576460752303423488_ZL);

        ff_p_t tmp(0_ZL);
        for (uint64_t i = 0ul; i < itr_count; i++) {
          tmp += (op1 + op2);
        }
      });
  return evt;
}

sycl::event benchmark_ff_p_t_subtraction(sycl::queue &q, const uint32_t dim,
                                         const uint32_t wg_size,
                                         const uint32_t itr_count) {
  sycl::event evt = q.parallel_for(
      sycl::nd_range<2>{sycl::range<2>{dim, dim}, sycl::range<2>{1, wg_size}},
      [=](sycl::nd_item<2> it) {
        ff_p_t op1(2147483648_ZL);
        ff_p_t op2(576460752303423488_ZL);

        ff_p_t tmp(0_ZL);
        for (uint64_t i = 0ul; i < itr_count; i++) {
          tmp += (op1 - op2);
        }
      });
  return evt;
}

sycl::event benchmark_ff_p_t_multiplication(sycl::queue &q, const uint32_t dim,
                                            const uint32_t wg_size,
                                            const uint32_t itr_count) {
  sycl::event evt = q.parallel_for(
      sycl::nd_range<2>{sycl::range<2>{dim, dim}, sycl::range<2>{1, wg_size}},
      [=](sycl::nd_item<2> it) {
        ff_p_t op1(2147483648_ZL);
        ff_p_t op2(576460752303423488_ZL);

        ff_p_t tmp(0_ZL);
        for (uint64_t i = 0ul; i < itr_count; i++) {
          tmp += (op1 * op2);
        }
      });
  return evt;
}
