#include <bench_p256_ctbn.hpp>

sycl::event benchmark_ff_p256_t_addition(sycl::queue &q, const uint32_t dim,
                                         const uint32_t wg_size,
                                         const uint32_t itr_count) {
  return q.submit([&](sycl::handler &h) {
    // allocate some space in local memory where I'll write
    // some garbage data, at end of computation so that compiler
    // doesn't end up optimizing too much !
    sycl::accessor<ff_p256_t, 1, sycl::access_mode::read_write,
                   sycl::target::local>
        lds{sycl::range<1>{wg_size}, h};

    h.parallel_for<class kernelFF_p256_Addition>(
        sycl::nd_range<2>{sycl::range<2>{dim, dim}, sycl::range<2>{1, wg_size}},
        [=](sycl::nd_item<2> it) {
          const size_t loc_lid = it.get_local_linear_id();

          ff_p256_t op1(
              3618502788666131106986593281521497120414687020801267626233049500247285301247_ZL);
          ff_p256_t op2(
              904625697166532776746648320380374280103671755200316906558262375061821325304_ZL);

          ff_p256_t tmp(0_ZL);
          for (uint64_t i = 0ul; i < itr_count; i++) {
            tmp += (op1 + op2);
          }

          // every work item writes back to local memory
          lds[loc_lid] = tmp;
        });
  });
}

sycl::event benchmark_ff_p256_t_subtraction(sycl::queue &q, const uint32_t dim,
                                            const uint32_t wg_size,
                                            const uint32_t itr_count) {
  return q.submit([&](sycl::handler &h) {
    // allocate some space in local memory where I'll write
    // some garbage data, at end of computation so that compiler
    // doesn't end up optimizing too much !
    sycl::accessor<ff_p256_t, 1, sycl::access_mode::read_write,
                   sycl::target::local>
        lds{sycl::range<1>{wg_size}, h};

    h.parallel_for<class kernelFF_p256_Subtraction>(
        sycl::nd_range<2>{sycl::range<2>{dim, dim}, sycl::range<2>{1, wg_size}},
        [=](sycl::nd_item<2> it) {
          const size_t loc_lid = it.get_local_linear_id();

          ff_p256_t op1(
              3618502788666131106986593281521497120414687020801267626233049500247285301247_ZL);
          ff_p256_t op2(
              904625697166532776746648320380374280103671755200316906558262375061821325304_ZL);

          ff_p256_t tmp(0_ZL);
          for (uint64_t i = 0ul; i < itr_count; i++) {
            tmp += (op1 - op2);
          }

          // every work item writes back to local memory
          lds[loc_lid] = tmp;
        });
  });
}

sycl::event benchmark_ff_p256_t_multiplication(sycl::queue &q,
                                               const uint32_t dim,
                                               const uint32_t wg_size,
                                               const uint32_t itr_count) {
  return q.submit([&](sycl::handler &h) {
    // allocate some space in local memory where I'll write
    // some garbage data, at end of computation so that compiler
    // doesn't end up optimizing too much !
    sycl::accessor<ff_p256_t, 1, sycl::access_mode::read_write,
                   sycl::target::local>
        lds{sycl::range<1>{wg_size}, h};

    h.parallel_for<class kernelFF_p256_Multiplication>(
        sycl::nd_range<2>{sycl::range<2>{dim, dim}, sycl::range<2>{1, wg_size}},
        [=](sycl::nd_item<2> it) {
          const size_t loc_lid = it.get_local_linear_id();

          ff_p256_t op1(
              3618502788666131106986593281521497120414687020801267626233049500247285301247_ZL);
          ff_p256_t op2(
              904625697166532776746648320380374280103671755200316906558262375061821325304_ZL);

          ff_p256_t tmp(0_ZL);
          for (uint64_t i = 0ul; i < itr_count; i++) {
            tmp += (op1 * op2);
          }

          // every work item writes back to local memory
          lds[loc_lid] = tmp;
        });
  });
}

sycl::event benchmark_ff_p256_t_division(sycl::queue &q, const uint32_t dim,
                                         const uint32_t wg_size,
                                         const uint32_t itr_count) {
  return q.submit([&](sycl::handler &h) {
    // allocate some space in local memory where I'll write
    // some garbage data, at end of computation so that compiler
    // doesn't end up optimizing too much !
    sycl::accessor<ff_p256_t, 1, sycl::access_mode::read_write,
                   sycl::target::local>
        lds{sycl::range<1>{wg_size}, h};

    h.parallel_for<class kernelFF_p256_Division>(
        sycl::nd_range<2>{sycl::range<2>{dim, dim}, sycl::range<2>{1, wg_size}},
        [=](sycl::nd_item<2> it) {
          const size_t loc_lid = it.get_local_linear_id();

          ff_p256_t op1(
              3618502788666131106986593281521497120414687020801267626233049500247285301247_ZL);
          ff_p256_t op2(
              904625697166532776746648320380374280103671755200316906558262375061821325304_ZL);

          ff_p256_t tmp(0_ZL);
          for (uint64_t i = 0ul; i < itr_count; i++) {
            tmp += (op1 / op2);
          }

          // every work item writes back to local memory
          lds[loc_lid] = tmp;
        });
  });
}

sycl::event benchmark_ff_p256_t_inversion(sycl::queue &q, const uint32_t dim,
                                          const uint32_t wg_size,
                                          const uint32_t itr_count) {
  return q.submit([&](sycl::handler &h) {
    // allocate some space in local memory where I'll write
    // some garbage data, at end of computation so that compiler
    // doesn't end up optimizing too much !
    sycl::accessor<ff_p256_t, 1, sycl::access_mode::read_write,
                   sycl::target::local>
        lds{sycl::range<1>{wg_size}, h};

    h.parallel_for<class kernelFF_p256_Inversion>(
        sycl::nd_range<2>{sycl::range<2>{dim, dim}, sycl::range<2>{1, wg_size}},
        [=](sycl::nd_item<2> it) {
          const size_t loc_lid = it.get_local_linear_id();

          ff_p256_t op(
              3618502788666131106986593281521497120414687020801267626233049500247285301247_ZL);

          ff_p256_t tmp(0_ZL);
          for (uint64_t i = 0ul; i < itr_count; i++) {
            tmp += static_cast<ff_p256_t>(cbn::mod_inv(op.data, mod_p256_bn));
          }

          // every work item writes back to local memory
          lds[loc_lid] = tmp;
        });
  });
}

sycl::event benchmark_ff_p256_t_exponentiation(sycl::queue &q,
                                               const uint32_t dim,
                                               const uint32_t wg_size,
                                               const uint32_t itr_count) {
  return q.submit([&](sycl::handler &h) {
    // allocate some space in local memory where I'll write
    // some garbage data, at end of computation so that compiler
    // doesn't end up optimizing too much !
    sycl::accessor<ff_p256_t, 1, sycl::access_mode::read_write,
                   sycl::target::local>
        lds{sycl::range<1>{wg_size}, h};

    h.parallel_for<class kernelFF_p256_Exponentiation>(
        sycl::nd_range<2>{sycl::range<2>{dim, dim}, sycl::range<2>{1, wg_size}},
        [=](sycl::nd_item<2> it) {
          const size_t loc_lid = it.get_local_linear_id();

          ff_p256_t op1(
              3618502788666131106986593281521497120414687020801267626233049500247285301247_ZL);
          ff_p256_t op2(
              904625697166532776746648320380374280103671755200316906558262375061821325304_ZL);

          ff_p256_t tmp(0_ZL);
          for (uint64_t i = 0ul; i < itr_count; i++) {
            tmp += static_cast<ff_p256_t>(
                cbn::mod_exp(op1.data, op2.data, mod_p256_bn));
          }

          // every work item writes back to local memory
          lds[loc_lid] = tmp;
        });
  });
}
