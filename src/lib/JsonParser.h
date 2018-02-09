//
// Created by prstys on 2/8/2018.
//

#ifndef CI_TEST_JSONPARSER_H
#define CI_TEST_JSONPARSER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jsmn.h"

class JsonParser
{
public:
    explicit JsonParser(const char* json);

    bool IsParsedOkay() const;
    int GetNumberOfTokens() const;
    jsmntok_t GetToken(int number);

private:
    // NOT FINISHED
    struct CharPair
    {
        const char* Start;
        const char* End;
    };

    // NOT FINISHED
    CharPair Get(const char* pathToLeafNode)
    {
        const char* start = pathToLeafNode;
        const char* end = start;
        while (*end != '\0' && *end++ != '/');

        bool leaf = false;
        if (*end == '\0')
        {
            leaf = true;
        }
        if (jsoneq(m_json, &m_tokens[0], start, end) == 0 && leaf)
        {
            return CharPair { m_json + m_tokens[1].start, m_json + m_tokens[1].end };
        }
    }

    // NOT FINISHED
    static int jsoneq(const char *json, jsmntok_t *tok, const char *start, const char* end)
    {
        if ((tok->type == JSMN_STRING)
            &&
            (end - start == tok->end - tok->start)
            &&
            (strncmp(json + tok->start, start, tok->end - tok->start) == 0))
        {
            return 0;
        }
        return -1;
    }

private:
    jsmntok_t       m_tokens[128]; /* We expect no more than 128 tokens */
    bool            m_parsedOkay = false;
    int             m_numberOfTokens =  0;
    const char*     m_json;
};


#endif //CI_TEST_JSONPARSER_H
