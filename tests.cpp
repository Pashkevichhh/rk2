#include <gtest/gtest.h>
#include <Sheep.h>

TEST(SheepTest, MakeSound) {
    Sheep dolly("Dolly");
    testing::internal::CaptureStdout();
    dolly.makeSound();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "baa\n");
}

TEST(SheepTest, Clone) {
    Sheep dolly("Dolly");
    std::unique_ptr<Animal> clone = dolly.clone();
    EXPECT_NE(clone, nullptr);
}

TEST(SheepTest, CloneMakeSound) {
    Sheep dolly("Dolly");
    std::unique_ptr<Animal> clone = dolly.clone();
    testing::internal::CaptureStdout();
    clone->makeSound();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "baa\n");
}
