#include "pe_test.h"

namespace mat_mul_test {
#if ENABLE_EIGEN && PE_HAS_INT128
const int K = 500;
const int64 mod = 1000000007;
const int show = 1;

template <typename E>
void TestEigen(const vector<int>& data, const vector<int>& V) {
  std::vector<E> v(K, 0);
  EigenMatrix<E> m = EigenMatrix<E>::Zero(K, K);

  for (int i = 0; i < K; ++i) v[i] = V[i];
  rep(i, 0, K) rep(j, 0, K) m(i, j) = data[j * K + i];

  TimeRecorder tr;
  v = MatrixPower(m, 4, v);
  int64 s = 0;
  for (auto i : v) s += i.value();
  // cout << s << endl;
  if (show) {
    cout << tr.Elapsed().Format() << endl;
  }
  assert(s == 247446585411LL);
  sort(all(v));
}

template <typename E>
void TestEigen(const vector<int>& data, const vector<int>& V, E mod) {
  std::vector<E> v(K, 0);
  EigenMatrix<E> m = EigenMatrix<E>::Zero(K, K);

  for (int i = 0; i < K; ++i) v[i] = V[i] % mod;
  rep(i, 0, K) rep(j, 0, K) m(i, j) = data[j * K + i] % mod;

  TimeRecorder tr;
  v = MatrixPower(m, 4, v, mod);
  int64 s = 0;
  for (auto i : v) s += i;
  // cout << s << endl;
  if (show) {
    cout << tr.Elapsed().Format() << endl;
  }
  assert(s == 247446585411LL);
  sort(all(v));
}

template <typename E>
void TestPe(const vector<int>& data, const vector<int>& V) {
  std::vector<E> v(K, 0);
  PeMatrix<E> m(K, K);

  for (int i = 0; i < K; ++i) v[i] = V[i];
  rep(i, 0, K) rep(j, 0, K) m(i, j) = data[j * K + i];

  TimeRecorder tr;
  v = MatrixPower(m, 4, v);
  int64 s = 0;
  for (auto i : v) s += i.value();
  // cout << s << endl;
  if (show) {
    cout << tr.Elapsed().Format() << endl;
  }
  assert(s == 247446585411LL);
  sort(all(v));
}

template <typename E>
void TestPe(const vector<int>& data, const vector<int>& V, E mod) {
  std::vector<E> v(K, 0);
  PeMatrix<E> m(K, K);

  for (int i = 0; i < K; ++i) v[i] = V[i] % mod;
  rep(i, 0, K) rep(j, 0, K) m(i, j) = data[j * K + i] % mod;

  TimeRecorder tr;
  v = MatrixPower(m, 4, v, mod);
  int64 s = 0;
  for (auto i : v) s += i;
  // cout << s << endl;
  if (show) {
    cout << tr.Elapsed().Format() << endl;
  }
  assert(s == 247446585411LL);
  sort(all(v));
}

SL void TestEigenHelperMethod() {
  TimeRecorder tr;
  {
    auto res0 = MatrixPowerModEigen<1000000007>(
        [=](auto& m) {
          m(0, 0) = 1;
          m(0, 1) = 1;
          m(1, 0) = 1;
        },
        2, 100000);
    auto res1 = MatrixPowerModEigen<1000000007>(
        [=](auto& m, auto& v) {
          m(0, 0) = 1;
          m(0, 1) = 1;
          m(1, 0) = 1;
          v[0] = 1;
          v[1] = 1;
        },
        2, 100000);
  }

  {
    auto res0 = MatrixPowerModEigen<NMod64<1000000007>>(
        [=](auto& m) {
          m(0, 0) = 1;
          m(0, 1) = 1;
          m(1, 0) = 1;
        },
        2, 100000);
    auto res1 = MatrixPowerModEigen<NMod64<1000000007>>(
        [=](auto& m, auto& v) {
          m(0, 0) = 1;
          m(0, 1) = 1;
          m(1, 0) = 1;
          v[0] = 1;
          v[1] = 1;
        },
        2, 100000);
  }

  {
    auto res0 = MatrixPowerModEigen(
        [=](auto& m) {
          m(0, 0) = 1;
          m(0, 1) = 1;
          m(1, 0) = 1;
        },
        2, 100000, 1000000007);
    auto res1 = MatrixPowerModEigen(
        [=](auto& m, auto& v) {
          m(0, 0) = 1;
          m(0, 1) = 1;
          m(1, 0) = 1;
          v[0] = 1;
          v[1] = 1;
        },
        2, 100000, 1000000007);
  }

  cout << tr.Elapsed().Format() << endl;
}

SL void TestPeHelperMethod() {
  TimeRecorder tr;
  {
    auto res0 = MatrixPowerModPe<1000000007>(
        [=](auto& m) {
          m(0, 0) = 1;
          m(0, 1) = 1;
          m(1, 0) = 1;
        },
        2, 100000);
    auto res1 = MatrixPowerModPe<1000000007>(
        [=](auto& m, auto& v) {
          m(0, 0) = 1;
          m(0, 1) = 1;
          m(1, 0) = 1;
          v[0] = 1;
          v[1] = 1;
        },
        2, 100000);
  }

  {
    auto res0 = MatrixPowerModPe<NMod64<1000000007>>(
        [=](auto& m) {
          m(0, 0) = 1;
          m(0, 1) = 1;
          m(1, 0) = 1;
        },
        2, 100000);
    auto res1 = MatrixPowerModPe<NMod64<1000000007>>(
        [=](auto& m, auto& v) {
          m(0, 0) = 1;
          m(0, 1) = 1;
          m(1, 0) = 1;
          v[0] = 1;
          v[1] = 1;
        },
        2, 100000);
  }

  {
    auto res0 = MatrixPowerModPe(
        [=](auto& m) {
          m(0, 0) = 1;
          m(0, 1) = 1;
          m(1, 0) = 1;
        },
        2, 100000, 1000000007);
    auto res1 = MatrixPowerModPe(
        [=](auto& m, auto& v) {
          m(0, 0) = 1;
          m(0, 1) = 1;
          m(1, 0) = 1;
          v[0] = 1;
          v[1] = 1;
        },
        2, 100000, 1000000007);
  }
  cout << tr.Elapsed().Format() << endl;
}

SL void MatMulTest() {
  DefaultMod::Set(mod);
  vector<int> data;
  for (int i = 0; i < K; ++i)
    for (int j = 0; j < K; ++j) data.push_back(j * K + i);
  vector<int> V;
  for (int i = 0; i < K; ++i) V.push_back(i);
  {
    typedef int64 E;
    std::vector<E> v(K, 0);
    EigenMatrix<E> m = EigenMatrix<E>::Zero(K, K);

    for (int i = 0; i < K; ++i) v[i] = V[i];
    rep(i, 0, K) rep(j, 0, K) m(i, j) = data[j * K + i];

    TimeRecorder tr;
    v = MatrixPower(m, 4, v, mod);
    int64 s = 0;
    for (auto i : v) s += i;
    // cout << s << endl;
    if (show) {
      cout << tr.Elapsed().Format() << endl;
    }
    assert(s == 256670487618LL);
    sort(all(v));
  }
  {
    typedef int128 E;
    std::vector<E> v(K, 0);
    EigenMatrix<E> m = EigenMatrix<E>::Zero(K, K);

    for (int i = 0; i < K; ++i) v[i] = V[i];
    rep(i, 0, K) rep(j, 0, K) m(i, j) = data[j * K + i];

    TimeRecorder tr;
    v = MatrixPower(m, 4, v, mod);
    int64 s = 0;
    for (auto i : v) s += i;
    // cout << s << endl;
    if (show) {
      cout << tr.Elapsed().Format() << endl;
    }
    assert(s == 247446585411LL);
    sort(all(v));
  }
  if (show) {
    cout << endl;
  }

  TimeRecorder tr;
  TestEigen<int128>(data, V, mod);

  if (show) {
    cout << endl;
  }

  TestEigen<NModNumber<CCMod64<mod>, APSB<int64, int64>>>(data, V);
  TestEigen<NModNumber<CCMod64<mod>, APSB<int64, int128>>>(data, V);
  TestEigen<NModNumber<CCMod64<mod>, APSB<int64, fake_int128>>>(data, V);
  TestEigen<NModNumber<CCMod64<mod>, APSB<int128, int128>>>(data, V);
  TestEigen<NModNumber<CCMod64<mod>, APSBL<int128>>>(data, V);

  TestEigen<NModNumber<DefaultMod, APSB<int64, int64>>>(data, V);
  TestEigen<NModNumber<DefaultMod, APSB<int64, int128>>>(data, V);
  TestEigen<NModNumber<DefaultMod, APSB<int64, fake_int128>>>(data, V);
  TestEigen<NModNumber<DefaultMod, APSB<int128, int128>>>(data, V);
  TestEigen<NModNumber<DefaultMod, APSBL<int128>>>(data, V);

  if (show) {
    cout << endl;
  }

  TestEigen<NModNumberM<CCMod64<mod>, APSB<int64, int64>>>(data, V);
  TestEigen<NModNumberM<CCMod64<mod>, APSB<int64, int128>>>(data, V);
  TestEigen<NModNumberM<CCMod64<mod>, APSB<int64, fake_int128>>>(data, V);
  TestEigen<NModNumberM<CCMod64<mod>, APSB<int128, int128>>>(data, V);
  TestEigen<NModNumberM<CCMod64<mod>, APSBL<int128>>>(data, V);

  TestEigen<NModNumberM<DefaultMod, APSB<int64, int64>>>(data, V);
  TestEigen<NModNumberM<DefaultMod, APSB<int64, int128>>>(data, V);
  TestEigen<NModNumberM<DefaultMod, APSB<int64, fake_int128>>>(data, V);
  TestEigen<NModNumberM<DefaultMod, APSB<int128, int128>>>(data, V);
  TestEigen<NModNumberM<DefaultMod, APSBL<int128>>>(data, V);

  if (show) {
    cout << endl;
  }
  TestEigenHelperMethod();
  if (show) {
    cout << endl;
  }
  cout << "Eigen " << tr.Elapsed().Format() << endl;
  if (show) {
    cout << endl;
  }

  tr.Record();
  TestPe<int128>(data, V, mod);

  if (show) {
    cout << endl;
  }

  TestPe<NModNumber<CCMod64<mod>, APSB<int64, int64>>>(data, V);
  TestPe<NModNumber<CCMod64<mod>, APSB<int64, int128>>>(data, V);
  TestPe<NModNumber<CCMod64<mod>, APSB<int64, fake_int128>>>(data, V);
  TestPe<NModNumber<CCMod64<mod>, APSB<int128, int128>>>(data, V);
  TestPe<NModNumber<CCMod64<mod>, APSBL<int128>>>(data, V);

  TestPe<NModNumber<DefaultMod, APSB<int64, int64>>>(data, V);
  TestPe<NModNumber<DefaultMod, APSB<int64, int128>>>(data, V);
  TestPe<NModNumber<DefaultMod, APSB<int64, fake_int128>>>(data, V);
  TestPe<NModNumber<DefaultMod, APSB<int128, int128>>>(data, V);
  TestPe<NModNumber<DefaultMod, APSBL<int128>>>(data, V);

  if (show) {
    cout << endl;
  }
  TestPe<NModNumberM<CCMod64<mod>, APSB<int64, int64>>>(data, V);
  TestPe<NModNumberM<CCMod64<mod>, APSB<int64, int128>>>(data, V);
  TestPe<NModNumberM<CCMod64<mod>, APSB<int64, fake_int128>>>(data, V);
  TestPe<NModNumberM<CCMod64<mod>, APSB<int128, int128>>>(data, V);
  TestPe<NModNumberM<CCMod64<mod>, APSBL<int128>>>(data, V);

  TestPe<NModNumberM<DefaultMod, APSB<int64, int64>>>(data, V);
  TestPe<NModNumberM<DefaultMod, APSB<int64, int128>>>(data, V);
  TestPe<NModNumberM<DefaultMod, APSB<int64, fake_int128>>>(data, V);
  TestPe<NModNumberM<DefaultMod, APSB<int128, int128>>>(data, V);
  TestPe<NModNumberM<DefaultMod, APSBL<int128>>>(data, V);

  if (show) {
    cout << endl;
  }
  TestPeHelperMethod();
  cout << "Pe " << tr.Elapsed().Format() << endl;
}

PE_REGISTER_TEST(&MatMulTest, "MatMulTest", SUPER);
#endif
}  // namespace mat_mul_test
