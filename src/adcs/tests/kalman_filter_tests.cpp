#include <src/adcs/kalman_filter.h>
#include <src/util/matrix.h>
#include <test_runners/matrix_tests.h>
#include <test_runners/unity.h>

void TestKalmanPredictAndUpdate() {
    // TODO(dingbenjamin): This test currently causes something similar to a
    // task switch error, need to investigate further
    TEST_ASSERT_TRUE(false);

    //    double r1_data[3][1] = {{0.3554}, {0.0734}, {-0.9318}};
    //    Matrix r1(r1_data);
    //    double r2_data[3][1] = {{0}, {0}, {1}};
    //    Matrix r2(r2_data);
    //    double q0_data[4][1] = {{0}, {0}, {0}, {1}};
    //    Matrix q0(q0_data);
    //    double P0_data[3][3];
    //    Matrix P0(P0_data);
    //    P0.Fill(0);
    //    double Q0_data[3][3];
    //    Matrix Q0(Q0_data);
    //    Q0.Identity();
    //    Q0.MultiplyScalar(Q0, 0.1);
    //    double R0_data[6][6];
    //
    //    Matrix R0(R0_data);
    //    R0.Identity();
    //    R0.MultiplyScalar(R0, 0.1);
    //    double y_data[6][1] = {{-0.366}, {-0.5753}, {-0.7315},
    //                           {0.5844}, {0.2708},  {0.7650}};
    //    Matrix y(y_data);
    //    double omega_data[3][1] = {{0}, {0.4363}, {-0.0873}};
    //    Matrix omega(omega_data);
    //    double q_prior_estimate_expected_data[4][1] = {
    //        {0}, {0.0109}, {-0.0022}, {1}};
    //    Matrix q_prior_estimate_expected(q_prior_estimate_expected_data);
    //    double P_prior_expected_data[3][3];
    //    Matrix P_prior_expected(P_prior_expected_data);
    //    P_prior_expected.Identity();
    //    P_prior_expected.MultiplyScalar(P_prior_expected, 0.005);
    //    double q_posterior_estimate_expected_data[4][1] = {
    //        {0.01947041}, {-0.01670298}, {0.00216513}, {0.99966856}};
    //    Matrix
    //    q_posterior_estimate_expected(q_posterior_estimate_expected_data);
    //    double P_posterior_expected_data[3][3] = {
    //        {0.00457628, 0.00000612, -0.00008373}, { 0.00000612, 0.00454669,
    //        -0.00001576}, {-0.00008373, -0.00001576, 0.00496511}};
    //    Matrix P_posterior_expected(P_posterior_expected_data);
    //
    //    KalmanFilter kf(50, r1, r2, Q0, R0, P0, q0);
    //
    //    kf.Predict(omega);
    //
    //    // Test q_estimate prediction
    //    TEST_ASSERT_TRUE(q_prior_estimate_expected.IsEqual(kf.q_estimate));
    //
    //    // Test P prediction
    //    TEST_ASSERT_TRUE(P_prior_expected.IsEqual(kf.P));
    //
    //    kf.Update(y);
    //
    //    // Test q_estimate update
    //    TEST_ASSERT_TRUE(q_posterior_estimate_expected.IsEqual(kf.q_estimate));
    //
    //    // Test P update
    //    TEST_ASSERT_TRUE(P_posterior_expected.IsEqual(kf.P));
}