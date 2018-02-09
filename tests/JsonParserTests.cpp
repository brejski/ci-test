// Distributed under the MIT software license, see the accompanying
// file LICENSE or http://www.opensource.org/licenses/mit-license.php.
#include <jsmn.h>
#include "gtest/gtest.h"
#include "lib/JsonParser.h"

namespace
{

TEST(JsonParserTest, Empty)
{
    JsonParser jsonParser("");
    EXPECT_FALSE(jsonParser.IsParsedOkay());
    EXPECT_EQ(0, jsonParser.GetNumberOfTokens());
}

TEST(JsonParserTest, SinglePrimitive)
{
    JsonParser jsonParser("EMPTY");
    EXPECT_TRUE(jsonParser.IsParsedOkay());
    EXPECT_EQ(1, jsonParser.GetNumberOfTokens());
    EXPECT_TRUE(jsonParser.GetToken(0).type == jsmntype_t::JSMN_PRIMITIVE);
}

TEST(JsonParserTest, KeyValuePrimitives)
{
    JsonParser jsonParser("KEY : VALUE");
    EXPECT_TRUE(jsonParser.IsParsedOkay());
    EXPECT_EQ(2, jsonParser.GetNumberOfTokens());
    EXPECT_TRUE(jsonParser.GetToken(0).type == jsmntype_t::JSMN_PRIMITIVE);
    EXPECT_TRUE(jsonParser.GetToken(1).type == jsmntype_t::JSMN_PRIMITIVE);
}

TEST(JsonParserTest, SingleString)
{
    JsonParser jsonParser("\"EMPTY\"");
    EXPECT_TRUE(jsonParser.IsParsedOkay());
    EXPECT_EQ(1, jsonParser.GetNumberOfTokens());
    EXPECT_TRUE(jsonParser.GetToken(0).type == jsmntype_t::JSMN_STRING);
}

TEST(JsonParserTest, KeyValueStrings)
{
    JsonParser jsonParser("\"KEY\" : \"VALUE\"");
    EXPECT_TRUE(jsonParser.IsParsedOkay());
    EXPECT_EQ(2, jsonParser.GetNumberOfTokens());
    EXPECT_TRUE(jsonParser.GetToken(0).type == jsmntype_t::JSMN_STRING);
    EXPECT_TRUE(jsonParser.GetToken(1).type == jsmntype_t::JSMN_STRING);
}

TEST(JsonParserTest, SimpleArray)
{
    JsonParser jsonParser("LIST : [1, 2, 3, 4]");
    EXPECT_TRUE(jsonParser.IsParsedOkay());
    EXPECT_EQ(6, jsonParser.GetNumberOfTokens());
    EXPECT_TRUE(jsonParser.GetToken(0).type == jsmntype_t::JSMN_PRIMITIVE);
    EXPECT_TRUE(jsonParser.GetToken(1).type == jsmntype_t::JSMN_ARRAY);
    EXPECT_TRUE(jsonParser.GetToken(2).type == jsmntype_t::JSMN_PRIMITIVE);
    EXPECT_TRUE(jsonParser.GetToken(3).type == jsmntype_t::JSMN_PRIMITIVE);
    EXPECT_TRUE(jsonParser.GetToken(4).type == jsmntype_t::JSMN_PRIMITIVE);
    EXPECT_TRUE(jsonParser.GetToken(5).type == jsmntype_t::JSMN_PRIMITIVE);
}

TEST(JsonParserTest, MixedArray)
{
    JsonParser jsonParser("LIST : [1, \"Text\", 3, \"Another text\"]");
    EXPECT_TRUE(jsonParser.IsParsedOkay());
    EXPECT_EQ(6, jsonParser.GetNumberOfTokens());
    EXPECT_TRUE(jsonParser.GetToken(0).type == jsmntype_t::JSMN_PRIMITIVE);
    EXPECT_TRUE(jsonParser.GetToken(1).type == jsmntype_t::JSMN_ARRAY);
    EXPECT_TRUE(jsonParser.GetToken(2).type == jsmntype_t::JSMN_PRIMITIVE);
    EXPECT_TRUE(jsonParser.GetToken(3).type == jsmntype_t::JSMN_STRING);
    EXPECT_TRUE(jsonParser.GetToken(4).type == jsmntype_t::JSMN_PRIMITIVE);
    EXPECT_TRUE(jsonParser.GetToken(5).type == jsmntype_t::JSMN_STRING);
}

TEST(JsonParserTest, SimpleObject)
{
    JsonParser jsonParser("vote : "
                                        "{ "
                                        "\"key\" : \"value\", "
                                        "\"another key\" : { "
                                        "\"inner key\" : \"inner value\", "
                                        "\"total\":123 }"
                                        "}");

    EXPECT_TRUE(jsonParser.IsParsedOkay());
    EXPECT_EQ(10, jsonParser.GetNumberOfTokens());
    EXPECT_TRUE(jsonParser.GetToken(0).type == jsmntype_t::JSMN_PRIMITIVE);
    EXPECT_TRUE(jsonParser.GetToken(1).type == jsmntype_t::JSMN_OBJECT);
    EXPECT_TRUE(jsonParser.GetToken(2).type == jsmntype_t::JSMN_STRING);
    EXPECT_TRUE(jsonParser.GetToken(3).type == jsmntype_t::JSMN_STRING);
    EXPECT_TRUE(jsonParser.GetToken(4).type == jsmntype_t::JSMN_STRING);
    EXPECT_TRUE(jsonParser.GetToken(5).type == jsmntype_t::JSMN_OBJECT);
    EXPECT_TRUE(jsonParser.GetToken(6).type == jsmntype_t::JSMN_STRING);
    EXPECT_TRUE(jsonParser.GetToken(7).type == jsmntype_t::JSMN_STRING);
    EXPECT_TRUE(jsonParser.GetToken(8).type == jsmntype_t::JSMN_STRING);
    EXPECT_TRUE(jsonParser.GetToken(9).type == jsmntype_t::JSMN_PRIMITIVE);
}

}
