//
// Created by prstys on 2/8/2018.
//

#include "JsonParser.h"

JsonParser::JsonParser(const char* json) : m_json(json)
{
    jsmn_parser parser;
    jsmn_init(&parser);
    m_numberOfTokens = jsmn_parse(&parser, json, strlen(json), m_tokens, sizeof(m_tokens)/sizeof(m_tokens[0]));
    if (m_numberOfTokens >= 1 && m_tokens[0].type != JSMN_OBJECT)
    {
        m_parsedOkay = true;
    }
}

bool JsonParser::IsParsedOkay() const
{
    return m_parsedOkay;
}

int JsonParser::GetNumberOfTokens() const
{
    return m_numberOfTokens;
}

jsmntok_t JsonParser::GetToken(int number)
{
    return m_tokens[number];
}