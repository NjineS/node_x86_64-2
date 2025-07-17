cmd_/workspaces/node_x86_64-2/out/Release/obj.target/v8_libplatform/deps/v8/src/libplatform/worker-thread.o := g++ -o /workspaces/node_x86_64-2/out/Release/obj.target/v8_libplatform/deps/v8/src/libplatform/worker-thread.o ../deps/v8/src/libplatform/worker-thread.cc '-D_GLIBCXX_USE_CXX11_ABI=1' '-D_FILE_OFFSET_BITS=64' '-DNODE_OPENSSL_CONF_NAME=nodejs_conf' '-DICU_NO_USER_DATA_OVERRIDE' '-DV8_GYP_BUILD' '-DV8_TYPED_ARRAY_MAX_SIZE_IN_HEAP=64' '-D__STDC_FORMAT_MACROS' '-DOPENSSL_NO_PINSHARED' '-DOPENSSL_THREADS' '-DV8_TARGET_ARCH_X64' '-DV8_HAVE_TARGET_OS' '-DV8_TARGET_OS_LINUX' '-DV8_EMBEDDER_STRING="-node.16"' '-DENABLE_DISASSEMBLER' '-DV8_PROMISE_INTERNAL_FIELD_COUNT=1' '-DV8_ENABLE_PRIVATE_MAPPING_FORK_OPTIMIZATION' '-DV8_SHORT_BUILTIN_CALLS' '-DOBJECT_PRINT' '-DV8_INTL_SUPPORT' '-DV8_ATOMIC_OBJECT_FIELD_WRITES' '-DV8_ENABLE_LAZY_SOURCE_POSITIONS' '-DV8_USE_SIPHASH' '-DNDEBUG' '-DV8_WIN64_UNWINDING_INFO' '-DV8_ENABLE_REGEXP_INTERPRETER_THREADED_DISPATCH' '-DV8_USE_ZLIB' '-DV8_ENABLE_LEAPTIERING' '-DV8_ENABLE_SPARKPLUG' '-DV8_ENABLE_MAGLEV' '-DV8_ENABLE_TURBOFAN' '-DV8_ENABLE_WEBASSEMBLY' '-DV8_ENABLE_JAVASCRIPT_PROMISE_HOOKS' '-DV8_ENABLE_CONTINUATION_PRESERVED_EMBEDDER_DATA' '-DV8_ALLOCATION_FOLDING' '-DV8_ALLOCATION_SITE_TRACKING' '-DV8_ADVANCED_BIGINT_ALGORITHMS' '-DV8_ENABLE_WASM_SIMD256_REVEC' -I../deps/v8 -I../deps/v8/include -I../deps/v8/third_party/abseil-cpp  -pthread -Wno-unused-parameter -Wno-strict-overflow -Wno-return-type -Wno-int-in-bool-context -Wno-deprecated -Wno-stringop-overflow -Wno-stringop-overread -Wno-restrict -Wno-array-bounds -Wno-nonnull -Wno-dangling-pointer -flax-vector-conversions -m64 -O3 -fno-omit-frame-pointer -fdata-sections -ffunction-sections -O3 -fno-rtti -fno-exceptions -fno-strict-aliasing -std=gnu++20 -Wno-invalid-offsetof -MMD -MF /workspaces/node_x86_64-2/out/Release/.deps//workspaces/node_x86_64-2/out/Release/obj.target/v8_libplatform/deps/v8/src/libplatform/worker-thread.o.d.raw   -c
/workspaces/node_x86_64-2/out/Release/obj.target/v8_libplatform/deps/v8/src/libplatform/worker-thread.o: \
 ../deps/v8/src/libplatform/worker-thread.cc \
 ../deps/v8/src/libplatform/worker-thread.h \
 ../deps/v8/include/libplatform/libplatform-export.h \
 ../deps/v8/src/base/compiler-specific.h ../deps/v8/include/v8config.h \
 ../deps/v8/src/base/platform/platform.h ../deps/v8/include/v8-platform.h \
 ../deps/v8/include/v8-source-location.h ../deps/v8/include/v8config.h \
 ../deps/v8/src/base/abort-mode.h ../deps/v8/src/base/base-export.h \
 ../deps/v8/src/base/build_config.h ../deps/v8/src/base/macros.h \
 ../deps/v8/src/base/logging.h ../deps/v8/src/base/immediate-crash.h \
 ../deps/v8/src/base/template-utils.h \
 ../deps/v8/src/base/platform/semaphore.h \
 ../deps/v8/src/base/lazy-instance.h ../deps/v8/src/base/once.h \
 ../deps/v8/testing/gtest/include/gtest/gtest_prod.h \
 ../deps/v8/third_party/googletest/src/googletest/include/gtest/gtest_prod.h \
 ../deps/v8/src/libplatform/task-queue.h \
 ../deps/v8/src/base/platform/mutex.h \
 ../deps/v8/third_party/abseil-cpp/absl/synchronization/mutex.h \
 ../deps/v8/third_party/abseil-cpp/absl/base/attributes.h \
 ../deps/v8/third_party/abseil-cpp/absl/base/config.h \
 ../deps/v8/third_party/abseil-cpp/absl/base/options.h \
 ../deps/v8/third_party/abseil-cpp/absl/base/policy_checks.h \
 ../deps/v8/third_party/abseil-cpp/absl/base/const_init.h \
 ../deps/v8/third_party/abseil-cpp/absl/base/internal/identity.h \
 ../deps/v8/third_party/abseil-cpp/absl/base/internal/low_level_alloc.h \
 ../deps/v8/third_party/abseil-cpp/absl/base/port.h \
 ../deps/v8/third_party/abseil-cpp/absl/base/optimization.h \
 ../deps/v8/third_party/abseil-cpp/absl/base/internal/thread_identity.h \
 ../deps/v8/third_party/abseil-cpp/absl/base/internal/per_thread_tls.h \
 ../deps/v8/third_party/abseil-cpp/absl/base/internal/tsan_mutex_interface.h \
 ../deps/v8/third_party/abseil-cpp/absl/base/nullability.h \
 ../deps/v8/third_party/abseil-cpp/absl/base/internal/nullability_deprecated.h \
 ../deps/v8/third_party/abseil-cpp/absl/base/thread_annotations.h \
 ../deps/v8/third_party/abseil-cpp/absl/synchronization/internal/kernel_timeout.h \
 ../deps/v8/third_party/abseil-cpp/absl/base/internal/raw_logging.h \
 ../deps/v8/third_party/abseil-cpp/absl/base/internal/atomic_hook.h \
 ../deps/v8/third_party/abseil-cpp/absl/base/log_severity.h \
 ../deps/v8/third_party/abseil-cpp/absl/base/macros.h \
 ../deps/v8/third_party/abseil-cpp/absl/time/clock.h \
 ../deps/v8/third_party/abseil-cpp/absl/time/time.h \
 ../deps/v8/third_party/abseil-cpp/absl/strings/string_view.h \
 ../deps/v8/third_party/abseil-cpp/absl/base/internal/throw_delegate.h \
 ../deps/v8/third_party/abseil-cpp/absl/time/civil_time.h \
 ../deps/v8/third_party/abseil-cpp/absl/time/internal/cctz/include/cctz/civil_time.h \
 ../deps/v8/third_party/abseil-cpp/absl/time/internal/cctz/include/cctz/civil_time_detail.h \
 ../deps/v8/third_party/abseil-cpp/absl/time/internal/cctz/include/cctz/time_zone.h \
 ../deps/v8/third_party/abseil-cpp/absl/synchronization/internal/per_thread_sem.h \
 ../deps/v8/third_party/abseil-cpp/absl/synchronization/internal/create_thread_identity.h
../deps/v8/src/libplatform/worker-thread.cc:
../deps/v8/src/libplatform/worker-thread.h:
../deps/v8/include/libplatform/libplatform-export.h:
../deps/v8/src/base/compiler-specific.h:
../deps/v8/include/v8config.h:
../deps/v8/src/base/platform/platform.h:
../deps/v8/include/v8-platform.h:
../deps/v8/include/v8-source-location.h:
../deps/v8/include/v8config.h:
../deps/v8/src/base/abort-mode.h:
../deps/v8/src/base/base-export.h:
../deps/v8/src/base/build_config.h:
../deps/v8/src/base/macros.h:
../deps/v8/src/base/logging.h:
../deps/v8/src/base/immediate-crash.h:
../deps/v8/src/base/template-utils.h:
../deps/v8/src/base/platform/semaphore.h:
../deps/v8/src/base/lazy-instance.h:
../deps/v8/src/base/once.h:
../deps/v8/testing/gtest/include/gtest/gtest_prod.h:
../deps/v8/third_party/googletest/src/googletest/include/gtest/gtest_prod.h:
../deps/v8/src/libplatform/task-queue.h:
../deps/v8/src/base/platform/mutex.h:
../deps/v8/third_party/abseil-cpp/absl/synchronization/mutex.h:
../deps/v8/third_party/abseil-cpp/absl/base/attributes.h:
../deps/v8/third_party/abseil-cpp/absl/base/config.h:
../deps/v8/third_party/abseil-cpp/absl/base/options.h:
../deps/v8/third_party/abseil-cpp/absl/base/policy_checks.h:
../deps/v8/third_party/abseil-cpp/absl/base/const_init.h:
../deps/v8/third_party/abseil-cpp/absl/base/internal/identity.h:
../deps/v8/third_party/abseil-cpp/absl/base/internal/low_level_alloc.h:
../deps/v8/third_party/abseil-cpp/absl/base/port.h:
../deps/v8/third_party/abseil-cpp/absl/base/optimization.h:
../deps/v8/third_party/abseil-cpp/absl/base/internal/thread_identity.h:
../deps/v8/third_party/abseil-cpp/absl/base/internal/per_thread_tls.h:
../deps/v8/third_party/abseil-cpp/absl/base/internal/tsan_mutex_interface.h:
../deps/v8/third_party/abseil-cpp/absl/base/nullability.h:
../deps/v8/third_party/abseil-cpp/absl/base/internal/nullability_deprecated.h:
../deps/v8/third_party/abseil-cpp/absl/base/thread_annotations.h:
../deps/v8/third_party/abseil-cpp/absl/synchronization/internal/kernel_timeout.h:
../deps/v8/third_party/abseil-cpp/absl/base/internal/raw_logging.h:
../deps/v8/third_party/abseil-cpp/absl/base/internal/atomic_hook.h:
../deps/v8/third_party/abseil-cpp/absl/base/log_severity.h:
../deps/v8/third_party/abseil-cpp/absl/base/macros.h:
../deps/v8/third_party/abseil-cpp/absl/time/clock.h:
../deps/v8/third_party/abseil-cpp/absl/time/time.h:
../deps/v8/third_party/abseil-cpp/absl/strings/string_view.h:
../deps/v8/third_party/abseil-cpp/absl/base/internal/throw_delegate.h:
../deps/v8/third_party/abseil-cpp/absl/time/civil_time.h:
../deps/v8/third_party/abseil-cpp/absl/time/internal/cctz/include/cctz/civil_time.h:
../deps/v8/third_party/abseil-cpp/absl/time/internal/cctz/include/cctz/civil_time_detail.h:
../deps/v8/third_party/abseil-cpp/absl/time/internal/cctz/include/cctz/time_zone.h:
../deps/v8/third_party/abseil-cpp/absl/synchronization/internal/per_thread_sem.h:
../deps/v8/third_party/abseil-cpp/absl/synchronization/internal/create_thread_identity.h:
