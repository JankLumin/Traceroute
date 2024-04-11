#include "funcions.h"
#include "gtest/gtest.h"

TEST(ParseCommandLineTest, BasicTest) {
    int first_ttl = 1, max_ttl = MAX_HOPS;
    std::string destination_host;
    char* argv[] = {const_cast<char*>("program_name"), const_cast<char*>("-f"), const_cast<char*>("10"), const_cast<char*>("-m"), const_cast<char*>("20"), const_cast<char*>("example.com")};
    ASSERT_TRUE(parseCommandLine(6, argv, first_ttl, max_ttl, destination_host));
    ASSERT_EQ(first_ttl, 10);
    ASSERT_EQ(max_ttl, 20);
    ASSERT_EQ(destination_host, "example.com");
}

TEST(IsValidTTLTest, ValidTTLReturnsTrue) {
    EXPECT_TRUE(isValidTTL("50"));
    EXPECT_TRUE(isValidTTL("128"));
    EXPECT_TRUE(isValidTTL("255"));
}

TEST(IsValidTTLTest, InvalidTTLReturnsFalse) {
    EXPECT_FALSE(isValidTTL("0"));
    EXPECT_FALSE(isValidTTL("256"));
    EXPECT_FALSE(isValidTTL(""));
}

TEST(IsValidTTLTest, InvalidArgumentExceptionReturnsFalse) {
    EXPECT_FALSE(isValidTTL("abc"));
    EXPECT_FALSE(isValidTTL("12abc"));
}
TEST(IsValidTTLTest, NegativeTTLReturnsFalse) {
    EXPECT_FALSE(isValidTTL("-1"));
    EXPECT_FALSE(isValidTTL("-50"));
}

TEST(CreateSocketTest, SocketCreationSuccessAndClose) {
    int sock = createSocket(IPPROTO_ICMP);
    EXPECT_GE(sock, 0);
    close(sock);
}

TEST(ResolveHostnameTest, ResolveSuccess) {
    struct in_addr address{};
    std::string hostname = "example.com";

    bool result = resolveHostname(hostname, address);

    EXPECT_TRUE(result);
    EXPECT_NE(address.s_addr, INADDR_NONE);
}

TEST(ResolveHostnameTest, ResolveFailure) {
    struct in_addr address{};
    std::string hostname = "nonexistent-host.example.com";

    testing::internal::CaptureStderr();
    bool result = resolveHostname(hostname, address);
    std::string output = testing::internal::GetCapturedStderr();

    EXPECT_FALSE(result);
    EXPECT_EQ(output, "Error resolving destination host.\n");
}

TEST(CurrentTimeMicrosecondsTest, ValidTime) {
    long long start_time = currentTimeMicroseconds();
    usleep(1000);
    long long end_time = currentTimeMicroseconds();

    EXPECT_LE(start_time, end_time);
    EXPECT_LE(end_time - start_time, 10000);
}

TEST(TraceRouteTest, RouteToKnownHost) {
    struct sockaddr_in addr{};
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr("8.8.8.8");
    addr.sin_port = htons(0);

    int fd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    ASSERT_GE(fd, 0);

    traceRoute(fd, addr, 1, 30);

    close(fd);
}
