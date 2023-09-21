#include <gtest/gtest.h>

#include <ArgumentParser.hpp>

#include <array>

TEST(TestArgumentParser, RegisterFlag)
{
    ArgumentParser argParser;
    const std::string flag = "Teste";

    EXPECT_FALSE(argParser.isFlagRegistered(flag));

    argParser.registerFlag(flag);

    EXPECT_TRUE(argParser.isFlagRegistered(flag));
}

TEST(TestArgumentParser, RegisterFlag_WhiteSpace)
{
    ArgumentParser argParser;
    const std::string flagWithSpace = "Teste Espaco";

    argParser.registerFlag(flagWithSpace);

    EXPECT_TRUE(argParser.isFlagRegistered(flagWithSpace));
}

TEST(TestArgumentParser, RegisterOption)
{
    ArgumentParser argParser;
    const std::string option = "Teste";

    EXPECT_FALSE(argParser.isOptionRegistered(option));

    argParser.registerOption(option);

    EXPECT_TRUE(argParser.isOptionRegistered(option));
}

TEST(TestArgumentParser, Parse)
{
    ArgumentParser argParser;

    std::array<const char*, 5> args = { "ProgramName", "--flag", "--string=TEST", "--number=42", "--float=4.2" };

    argParser.registerFlag("flag");
    argParser.registerOption("string");
    argParser.registerOption("number");
    argParser.registerOption("float");

    argParser.parse(static_cast<int>(args.size()), args.data());

    EXPECT_FALSE(argParser.getFlag("ProgramName"));
    EXPECT_FALSE(argParser.getFlag("unregisteredFlag"));
    EXPECT_TRUE(argParser.getFlag("flag"));

    EXPECT_EQ(argParser.getOptionAs<std::string>("string"), "test");
    EXPECT_NE(argParser.getOptionAs<std::string>("string"), "TEST");
    EXPECT_EQ(argParser.getOptionAs<int>("number"), 42);
    EXPECT_EQ(argParser.getOptionAs<float>("float"), 4.2f);
}
